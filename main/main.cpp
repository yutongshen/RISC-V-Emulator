#include <string.h>
#include <iostream>
#include <vector>
#include "bus/bus.h"
#include "cpu/cluster.h"
#include "cpu/cpu.h"
#include "dev/plic.h"
#include "dev/timer.h"
#include "disk/disk.h"
#include "fesvr/htif.h"
#include "mem/ram.h"
#include "mem/rom.h"
#include "sys/system.h"
#include "util/util.h"
#include "mmap/mmap.h"
using namespace std;

bool verbose(1);

void print_pt(Bus *bus, const uint64_t &base)
{
    if (!base)
        return;
    vector<uint64_t> fifo(0);
    uint64_t pte(0);
    printf("\nPAGE TABLE %08lx\n", base);
    printf("%3s %8s %s %s %s %s %s %s %s\n", "ID", "ADDR", "V", "R", "W", "X",
           "U", "A", "D");
    for (uint16_t i = 0; i < 512; ++i) {
        bus->read(base + (i << 3), DATA_TYPE_DWORD, pte);
        if (pte & PTE_V) {
            printf("%03x %08lx %d %d %d %d %d %d %d\n", i,
                   pte >> PTE_PPN_SHIFT << PAGE_SHIFT, !!(pte & PTE_V),
                   !!(pte & PTE_R), !!(pte & PTE_W), !!(pte & PTE_X),
                   !!(pte & PTE_U), !!(pte & PTE_A), !!(pte & PTE_D));
            if (!(pte & (PTE_X | PTE_W | PTE_R)))
                fifo.push_back(pte >> PTE_PPN_SHIFT << PAGE_SHIFT);
        }
    }
    for (uint16_t i = 0; i < fifo.size(); ++i) {
        print_pt(bus, fifo[i]);
    }
}

int main(int argc, char **argv)
{
    // Arguments
    ArgumentParser argparser;
    argparser.add_argument("-dump", "", "Dump the information about memory.");
    argparser.add_argument("-mem_addr", "MEMADDR",
                           "If you dump the information about memory, it will "
                           "be the start address",
                           "0x10000", 0);
    argparser.add_argument(
        "-mem_len", "MEMLEN",
        "If you dump the information about memory, it will be the size",
        "0x100", 0);
    argparser.add_argument("-sim_end", "SIMEND",
                           "The address is used for check terminate", "0x1fffc",
                           0);
    argparser.add_argument("-sim_end_code", "SIMENDCODE",
                           "The value is used for check terminate", "-1", 0);
    argparser.add_argument("-cycle", "CYCLE", "The max simulation cycles",
                           "0x10000", 0);
    argparser.add_argument("-pc", "PC", "Initialize program count (default: 0)",
                           "0x0", 0);
    argparser.add_argument("-o", "OUTPUT", "The output file", "a.out", 0);
    if (!argparser.parse(argc, argv))
        return 0;

    // Main
    const uint32_t SIM_END(argparser.get_int("SIMEND"));
    const uint32_t SIM_END_CODE(argparser.get_int("SIMENDCODE"));

    // ==========================================================
    //                     Define CPU
    // ==========================================================
    CPU cpu_0(CPU0, argparser.get_int("PC"));
    CPU cpu_1(CPU1);
    CPU cpu_2(CPU2);
    CPU cpu_3(CPU3);
    CPU cpu_4(CPU4);
    CPU cpu_5(CPU5);
    CPU cpu_6(CPU6);
    CPU cpu_7(CPU7);
    cpu_0.set_power_on(true);
    // cpu_1.set_power_on(true);
    // cpu_2.set_power_on(true);
    // cpu_3.set_power_on(true);
    // cpu_4.set_power_on(true);
    // cpu_5.set_power_on(true);
    // cpu_6.set_power_on(true);
    // cpu_7.set_power_on(true);

    // ==========================================================
    //                     Define Cluster
    // ==========================================================
    Cluster cluster_0;
    cluster_0.add(CPU0, &cpu_0);
    cluster_0.add(CPU1, &cpu_1);
    cluster_0.add(CPU2, &cpu_2);
    cluster_0.add(CPU3, &cpu_3);
    cluster_0.add(CPU4, &cpu_4);
    cluster_0.add(CPU5, &cpu_5);
    cluster_0.add(CPU6, &cpu_6);
    cluster_0.add(CPU7, &cpu_7);

    // ==========================================================
    //                     Define PLIC
    // ==========================================================
    PLIC plic_0;
    plic_0.bind_irqdst(cpu_0.get_mip_ptr(), cpu_0.get_cpuid());

    // ==========================================================
    //                     Define Systimer
    // ==========================================================
    Timer timer_0;
    timer_0.set_ip(cpu_0.get_mip_ptr());

    // ==========================================================
    //                     Define BootROM
    // ==========================================================
    ROM boot_rom(argparser.get_str(0).c_str(), 0x1000);

    // ==========================================================
    //                     Define SRAM
    // ==========================================================
    RAM sram_0("64kb");
    RAM sram_1("64kb");

    // ==========================================================
    //                     Define DISK
    // ==========================================================
    Disk disk_0(argparser.get_str(1).c_str(), "2mb");
    Disk disk_1(argparser.get_str(1).c_str(), "2mb");

    // ==========================================================
    //                     Define Bus
    // ==========================================================
    Bus bus_0;
    cluster_0.bus_connect(&bus_0);
    bus_0.s_connect(CLST_0_BASE, &cluster_0);
    bus_0.s_connect(PLIC_BASE,   &plic_0);
    bus_0.s_connect(TIMER_BASE,  &timer_0);
    bus_0.s_connect(BROM_BASE,   &boot_rom);
    bus_0.s_connect(SRAM_0_BASE, &sram_0);
    bus_0.s_connect(SRAM_1_BASE, &sram_1);
    bus_0.s_connect(DISK_0_BASE, &disk_0);
    bus_0.s_connect(DISK_1_BASE, &disk_1);

    System sys_0;
    sys_0.add(&cluster_0);
    sys_0.add(&plic_0);
    sys_0.add(&timer_0);

    HTIF htif_0;
    htif_0.bus_connect(&bus_0);
    htif_0.set_host(0x80001000, 0x80001040);

    // Run
    uint64_t cycle(argparser.get_int("CYCLE"));
    uint64_t end_code;
    while ((bus_0.read(SIM_END, DATA_TYPE_WORD, end_code),
            (uint32_t) end_code) != SIM_END_CODE &&
           cycle-- && !htif_0.exit()) {
        if (!(cycle & 0xf)) plic_0.get_pending()[0] = -1U;
        sys_0.run();
        htif_0.run();
    }

    // Print page-table
    uint64_t pt_base((cpu_0.get_satp() & SATP_PPN) << PAGE_SHIFT);
    print_pt(&bus_0, pt_base);

    // Dump
    if (argparser.get_bool("DUMP")) {
        const uint64_t dump_start(argparser.get_int("MEMADDR"));
        uint64_t idx(dump_start);
        uint64_t dump_len(argparser.get_int("MEMLEN") << 2);
        FILE *output(fopen(argparser.get_str("OUTPUT").c_str(), "w"));
        fprintf(output, "SIMEND\n");
        fprintf(output, "%08x\n",
                (bus_0.read(SIM_END, DATA_TYPE_WORD, end_code),
                 (uint32_t) end_code));
        fprintf(output, "MEMDUMP\n");
        for (; idx < dump_start + dump_len; idx += 4) {
            bus_0.read(idx, DATA_TYPE_WORD, end_code);
            fprintf(output, "%08x\n", (uint32_t) end_code);
        }
    }
    return 0;
}
