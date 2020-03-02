#ifdef CSR_DECLARE
// User Trap Setup
uint64_t ustatus;
uint64_t uie;
uint64_t utvec;
// User Trap Handling
uint64_t uscratch;
uint64_t uepc;
uint64_t ucause;
uint64_t utval;
uint64_t uip;
// User Floating-Point CSRs
uint64_t fflags;
uint64_t frm;
uint64_t fcsr;
// User Counter/Timers
uint64_t cycle;
uint64_t time;
uint64_t instret;
uint64_t hpmcounter[29];

// Supervisor Trap Setup
// uint64_t sstatus; reference mstatus
uint64_t sedeleg;
uint64_t sideleg;
uint64_t sie;
uint64_t stvec;
uint64_t scounteren;
// Supervisor Trap Handling
uint64_t sscratch;
uint64_t sepc;
uint64_t scause;
uint64_t stval;
uint64_t sip;
// Supervisor Protection and Translation
uint64_t satp;

// Machine Information Registers
uint64_t mvendorid;
uint64_t marchid;
uint64_t mimpid;
uint64_t mhartid;
// Machine Trap Setup
uint64_t mstatus;
uint64_t misa;
uint64_t medeleg;
uint64_t mideleg;
uint64_t mie;
uint64_t mtvec;
uint64_t mcounteren;
// Machine Trap Handling
uint64_t mscratch;
uint64_t mepc;
uint64_t mcause;
uint64_t mtval;
uint64_t mip;
// Machine Protection and Translation
uint8_t pmpcfg[16];
uint64_t pmpaddr[16];
// Machine Counter/Timers
uint64_t mcycle;
uint64_t minstret;
uint64_t mhpmcounter[29];
// Machine Counter Setup
uint64_t mhpmevent[29];
// Debug/Trace Registers (shared with Debug Mode)
uint64_t tselect;
uint64_t tdata[3];
// Debug Mode Registers
uint64_t dcsr;
uint64_t dpc;
uint64_t dscratch;
#endif

#define PRV_U 0x0
#define PRV_S 0x1
#define PRV_H 0x2
#define PRV_M 0x3

#define CSR_USTATUS_ADDR 0x000
#define CSR_UIE_ADDR 0x004
#define CSR_UTVEC_ADDR 0x005
#define CSR_USCRATCH_ADDR 0x040
#define CSR_UEPC_ADDR 0x041
#define CSR_UCAUSE_ADDR 0x042
#define CSR_UTVAL_ADDR 0x043
#define CSR_UIP_ADDR 0x044
#define CSR_FFLAGS_ADDR 0x001
#define CSR_FRM_ADDR 0x002
#define CSR_FCSR_ADDR 0x003
#define CSR_CYCLE_ADDR 0xc00
#define CSR_TIME_ADDR 0xc01
#define CSR_INSTRET_ADDR 0xc02
#define CSR_HPMCOUNTER3_ADDR 0xc03
#define CSR_HPMCOUNTER4_ADDR 0xc04
#define CSR_HPMCOUNTER5_ADDR 0xc05
#define CSR_HPMCOUNTER6_ADDR 0xc06
#define CSR_HPMCOUNTER7_ADDR 0xc07
#define CSR_HPMCOUNTER8_ADDR 0xc08
#define CSR_HPMCOUNTER9_ADDR 0xc09
#define CSR_HPMCOUNTER10_ADDR 0xc0a
#define CSR_HPMCOUNTER11_ADDR 0xc0b
#define CSR_HPMCOUNTER12_ADDR 0xc0c
#define CSR_HPMCOUNTER13_ADDR 0xc0d
#define CSR_HPMCOUNTER14_ADDR 0xc0e
#define CSR_HPMCOUNTER15_ADDR 0xc0f
#define CSR_HPMCOUNTER16_ADDR 0xc10
#define CSR_HPMCOUNTER17_ADDR 0xc11
#define CSR_HPMCOUNTER18_ADDR 0xc12
#define CSR_HPMCOUNTER19_ADDR 0xc13
#define CSR_HPMCOUNTER20_ADDR 0xc14
#define CSR_HPMCOUNTER21_ADDR 0xc15
#define CSR_HPMCOUNTER22_ADDR 0xc16
#define CSR_HPMCOUNTER23_ADDR 0xc17
#define CSR_HPMCOUNTER24_ADDR 0xc18
#define CSR_HPMCOUNTER25_ADDR 0xc19
#define CSR_HPMCOUNTER26_ADDR 0xc1a
#define CSR_HPMCOUNTER27_ADDR 0xc1b
#define CSR_HPMCOUNTER28_ADDR 0xc1c
#define CSR_HPMCOUNTER29_ADDR 0xc1d
#define CSR_HPMCOUNTER30_ADDR 0xc1e
#define CSR_HPMCOUNTER31_ADDR 0xc1f
#define CSR_CYCLEH_ADDR 0xc80
#define CSR_TIMEH_ADDR 0xc81
#define CSR_INSTRETH_ADDR 0xc82
#define CSR_HPMCOUNTER3H_ADDR 0xc83
#define CSR_HPMCOUNTER4H_ADDR 0xc84
#define CSR_HPMCOUNTER5H_ADDR 0xc85
#define CSR_HPMCOUNTER6H_ADDR 0xc86
#define CSR_HPMCOUNTER7H_ADDR 0xc87
#define CSR_HPMCOUNTER8H_ADDR 0xc88
#define CSR_HPMCOUNTER9H_ADDR 0xc89
#define CSR_HPMCOUNTER10H_ADDR 0xc8a
#define CSR_HPMCOUNTER11H_ADDR 0xc8b
#define CSR_HPMCOUNTER12H_ADDR 0xc8c
#define CSR_HPMCOUNTER13H_ADDR 0xc8d
#define CSR_HPMCOUNTER14H_ADDR 0xc8e
#define CSR_HPMCOUNTER15H_ADDR 0xc8f
#define CSR_HPMCOUNTER16H_ADDR 0xc90
#define CSR_HPMCOUNTER17H_ADDR 0xc91
#define CSR_HPMCOUNTER18H_ADDR 0xc92
#define CSR_HPMCOUNTER19H_ADDR 0xc93
#define CSR_HPMCOUNTER20H_ADDR 0xc94
#define CSR_HPMCOUNTER21H_ADDR 0xc95
#define CSR_HPMCOUNTER22H_ADDR 0xc96
#define CSR_HPMCOUNTER23H_ADDR 0xc97
#define CSR_HPMCOUNTER24H_ADDR 0xc98
#define CSR_HPMCOUNTER25H_ADDR 0xc99
#define CSR_HPMCOUNTER26H_ADDR 0xc9a
#define CSR_HPMCOUNTER27H_ADDR 0xc9b
#define CSR_HPMCOUNTER28H_ADDR 0xc9c
#define CSR_HPMCOUNTER29H_ADDR 0xc9d
#define CSR_HPMCOUNTER30H_ADDR 0xc9e
#define CSR_HPMCOUNTER31H_ADDR 0xc9f

#define CSR_SSTATUS_ADDR 0x100
#define CSR_SEDELEG_ADDR 0x102
#define CSR_SIDELEG_ADDR 0x103
#define CSR_SIE_ADDR 0x104
#define CSR_STVEC_ADDR 0x105
#define CSR_SCOUNTEREN_ADDR 0x106
#define CSR_SSCRATCH_ADDR 0x140
#define CSR_SEPC_ADDR 0x141
#define CSR_SCAUSE_ADDR 0x142
#define CSR_STVAL_ADDR 0x143
#define CSR_SIP_ADDR 0x144
#define CSR_SATP_ADDR 0x180

#define CSR_MVENDORID_ADDR 0xf11
#define CSR_MARCHID_ADDR 0xf12
#define CSR_MIMPID_ADDR 0xf13
#define CSR_MHARTID_ADDR 0xf14
#define CSR_MSTATUS_ADDR 0x300
#define CSR_MISA_ADDR 0x301
#define CSR_MEDELEG_ADDR 0x302
#define CSR_MIDELEG_ADDR 0x303
#define CSR_MIE_ADDR 0x304
#define CSR_MTVEC_ADDR 0x305
#define CSR_MCOUNTEREN_ADDR 0x306
#define CSR_MSCRATCH_ADDR 0x340
#define CSR_MEPC_ADDR 0x341
#define CSR_MCAUSE_ADDR 0x342
#define CSR_MTVAL_ADDR 0x343
#define CSR_MIP_ADDR 0x344
#define CSR_PMPCFG0_ADDR 0x3a0
#define CSR_PMPCFG1_ADDR 0x3a1
#define CSR_PMPCFG2_ADDR 0x3a2
#define CSR_PMPCFG3_ADDR 0x3a3
#define CSR_PMPADDR0_ADDR 0x3b0
#define CSR_PMPADDR1_ADDR 0x3b1
#define CSR_PMPADDR2_ADDR 0x3b2
#define CSR_PMPADDR3_ADDR 0x3b3
#define CSR_PMPADDR4_ADDR 0x3b4
#define CSR_PMPADDR5_ADDR 0x3b5
#define CSR_PMPADDR6_ADDR 0x3b6
#define CSR_PMPADDR7_ADDR 0x3b7
#define CSR_PMPADDR8_ADDR 0x3b8
#define CSR_PMPADDR9_ADDR 0x3b9
#define CSR_PMPADDR10_ADDR 0x3ba
#define CSR_PMPADDR11_ADDR 0x3bb
#define CSR_PMPADDR12_ADDR 0x3bc
#define CSR_PMPADDR13_ADDR 0x3bd
#define CSR_PMPADDR14_ADDR 0x3be
#define CSR_PMPADDR15_ADDR 0x3bf
#define CSR_MCYCLE_ADDR 0xb00
#define CSR_MINSTRET_ADDR 0xb02
#define CSR_MHPMCOUNTER3_ADDR 0xb03
#define CSR_MHPMCOUNTER4_ADDR 0xb04
#define CSR_MHPMCOUNTER5_ADDR 0xb05
#define CSR_MHPMCOUNTER6_ADDR 0xb06
#define CSR_MHPMCOUNTER7_ADDR 0xb07
#define CSR_MHPMCOUNTER8_ADDR 0xb08
#define CSR_MHPMCOUNTER9_ADDR 0xb09
#define CSR_MHPMCOUNTER10_ADDR 0xb0a
#define CSR_MHPMCOUNTER11_ADDR 0xb0b
#define CSR_MHPMCOUNTER12_ADDR 0xb0c
#define CSR_MHPMCOUNTER13_ADDR 0xb0d
#define CSR_MHPMCOUNTER14_ADDR 0xb0e
#define CSR_MHPMCOUNTER15_ADDR 0xb0f
#define CSR_MHPMCOUNTER16_ADDR 0xb10
#define CSR_MHPMCOUNTER17_ADDR 0xb11
#define CSR_MHPMCOUNTER18_ADDR 0xb12
#define CSR_MHPMCOUNTER19_ADDR 0xb13
#define CSR_MHPMCOUNTER20_ADDR 0xb14
#define CSR_MHPMCOUNTER21_ADDR 0xb15
#define CSR_MHPMCOUNTER22_ADDR 0xb16
#define CSR_MHPMCOUNTER23_ADDR 0xb17
#define CSR_MHPMCOUNTER24_ADDR 0xb18
#define CSR_MHPMCOUNTER25_ADDR 0xb19
#define CSR_MHPMCOUNTER26_ADDR 0xb1a
#define CSR_MHPMCOUNTER27_ADDR 0xb1b
#define CSR_MHPMCOUNTER28_ADDR 0xb1c
#define CSR_MHPMCOUNTER29_ADDR 0xb1d
#define CSR_MHPMCOUNTER30_ADDR 0xb1e
#define CSR_MHPMCOUNTER31_ADDR 0xb1f
#define CSR_MCYCLEH_ADDR 0xb80
#define CSR_MINSTRETH_ADDR 0xb82
#define CSR_MHPMCOUNTER3H_ADDR 0xb83
#define CSR_MHPMCOUNTER4H_ADDR 0xb84
#define CSR_MHPMCOUNTER5H_ADDR 0xb85
#define CSR_MHPMCOUNTER6H_ADDR 0xb86
#define CSR_MHPMCOUNTER7H_ADDR 0xb87
#define CSR_MHPMCOUNTER8H_ADDR 0xb88
#define CSR_MHPMCOUNTER9H_ADDR 0xb89
#define CSR_MHPMCOUNTER10H_ADDR 0xb8a
#define CSR_MHPMCOUNTER11H_ADDR 0xb8b
#define CSR_MHPMCOUNTER12H_ADDR 0xb8c
#define CSR_MHPMCOUNTER13H_ADDR 0xb8d
#define CSR_MHPMCOUNTER14H_ADDR 0xb8e
#define CSR_MHPMCOUNTER15H_ADDR 0xb8f
#define CSR_MHPMCOUNTER16H_ADDR 0xb90
#define CSR_MHPMCOUNTER17H_ADDR 0xb91
#define CSR_MHPMCOUNTER18H_ADDR 0xb92
#define CSR_MHPMCOUNTER19H_ADDR 0xb93
#define CSR_MHPMCOUNTER20H_ADDR 0xb94
#define CSR_MHPMCOUNTER21H_ADDR 0xb95
#define CSR_MHPMCOUNTER22H_ADDR 0xb96
#define CSR_MHPMCOUNTER23H_ADDR 0xb97
#define CSR_MHPMCOUNTER24H_ADDR 0xb98
#define CSR_MHPMCOUNTER25H_ADDR 0xb99
#define CSR_MHPMCOUNTER26H_ADDR 0xb9a
#define CSR_MHPMCOUNTER27H_ADDR 0xb9b
#define CSR_MHPMCOUNTER28H_ADDR 0xb9c
#define CSR_MHPMCOUNTER29H_ADDR 0xb9d
#define CSR_MHPMCOUNTER30H_ADDR 0xb9e
#define CSR_MHPMCOUNTER31H_ADDR 0xb9f
#define CSR_MHPMEVENT3_ADDR 0x323
#define CSR_MHPMEVENT4_ADDR 0x324
#define CSR_MHPMEVENT5_ADDR 0x325
#define CSR_MHPMEVENT6_ADDR 0x326
#define CSR_MHPMEVENT7_ADDR 0x327
#define CSR_MHPMEVENT8_ADDR 0x328
#define CSR_MHPMEVENT9_ADDR 0x329
#define CSR_MHPMEVENT10_ADDR 0x32a
#define CSR_MHPMEVENT11_ADDR 0x32b
#define CSR_MHPMEVENT12_ADDR 0x32c
#define CSR_MHPMEVENT13_ADDR 0x32d
#define CSR_MHPMEVENT14_ADDR 0x32e
#define CSR_MHPMEVENT15_ADDR 0x32f
#define CSR_MHPMEVENT16_ADDR 0x330
#define CSR_MHPMEVENT17_ADDR 0x331
#define CSR_MHPMEVENT18_ADDR 0x332
#define CSR_MHPMEVENT19_ADDR 0x333
#define CSR_MHPMEVENT20_ADDR 0x334
#define CSR_MHPMEVENT21_ADDR 0x335
#define CSR_MHPMEVENT22_ADDR 0x336
#define CSR_MHPMEVENT23_ADDR 0x337
#define CSR_MHPMEVENT24_ADDR 0x338
#define CSR_MHPMEVENT25_ADDR 0x339
#define CSR_MHPMEVENT26_ADDR 0x33a
#define CSR_MHPMEVENT27_ADDR 0x33b
#define CSR_MHPMEVENT28_ADDR 0x33c
#define CSR_MHPMEVENT29_ADDR 0x33d
#define CSR_MHPMEVENT30_ADDR 0x33e
#define CSR_MHPMEVENT31_ADDR 0x33f

#define CAUSE_MISALIGNED_FETCH 0x0
#define CAUSE_FETCH_ACCESS 0x1
#define CAUSE_ILLEGAL_INSTRUCTION 0x2
#define CAUSE_BREAKPOINT 0x3
#define CAUSE_MISALIGNED_LOAD 0x4
#define CAUSE_LOAD_ACCESS 0x5
#define CAUSE_MISALIGNED_STORE 0x6
#define CAUSE_STORE_ACCESS 0x7
#define CAUSE_USER_ECALL 0x8
#define CAUSE_SUPERVISOR_ECALL 0x9
#define CAUSE_HYPERVISOR_ECALL 0xa
#define CAUSE_MACHINE_ECALL 0xb
#define CAUSE_FETCH_PAGE_FAULT 0xc
#define CAUSE_LOAD_PAGE_FAULT 0xd
#define CAUSE_STORE_PAGE_FAULT 0xf

#define CSR_TSELECT_ADDR 0x7a0
#define CSR_TDATA1_ADDR 0x7a1
#define CSR_TDATA2_ADDR 0x7a2
#define CSR_TDATA3_ADDR 0x7a3
#define CSR_DCSR_ADDR 0x7b0
#define CSR_DPC_ADDR 0x7b1
#define CSR_DSCRATCH_ADDR 0x7b2

#define MSTATUS_SIE (0x1UL << 1)
#define MSTATUS_MIE (0x1UL << 3)
#define MSTATUS_SPIE (0x1UL << 5)
#define MSTATUS_MPIE (0x1UL << 7)
#define MSTATUS_SPP (0x1UL << 8)
#define MSTATUS_MPP (0x3UL << 11)
#define MSTATUS_FS (0x3UL << 13)
#define MSTATUS_XS (0x3UL << 15)
#define MSTATUS_MPRV (0x1UL << 17)
#define MSTATUS_SUM (0x1UL << 18)
#define MSTATUS_MXR (0x1UL << 19)
#define MSTATUS_TW (0x1UL << 21)
#define MSTATUS_TVM (0x1UL << 20)
#define MSTATUS_TSR (0x1UL << 22)
#define MSTATUS_UXL (0x3UL << 32)
#define MSTATUS_SXL (0x3UL << 34)

#define SSTATUS_MASK (MSTATUS_SIE | MSTATUS_SPIE | MSTATUS_SPP | MSTATUS_FS | MSTATUS_XS | MSTATUS_SUM | MSTATUS_MXR | MSTATUS_UXL)

#define MIP_SSIP (0x1UL << 1)
#define MIP_MSIP (0x1UL << 3)
#define MIP_STIP (0x1UL << 5)
#define MIP_MTIP (0x1UL << 7)
#define MIP_SEIP (0x1UL << 9)
#define MIP_MEIP (0x1UL << 11)

#define PMP_R (0x1UL << 0)
#define PMP_W (0x1UL << 1)
#define PMP_X (0x1UL << 2)
#define PMP_A (0x3UL << 3)
#define PMP_L (0x1UL << 7)

#define PMP_TOR 1
#define PMP_NA4 2
#define PMP_NAPOT 3

#define PMPADDR_MASK ((0x1UL << 54) - 1UL)

#define IRQ_NONSTANDARD 12

#ifdef CSR_NAME_DECLARE
CSR_NAME_DECLARE(CSR_USTATUS_ADDR, ustatus)
CSR_NAME_DECLARE(CSR_UIE_ADDR, uie)
CSR_NAME_DECLARE(CSR_UTVEC_ADDR, utvec)
CSR_NAME_DECLARE(CSR_USCRATCH_ADDR, uscratch)
CSR_NAME_DECLARE(CSR_UEPC_ADDR, uepc)
CSR_NAME_DECLARE(CSR_UCAUSE_ADDR, ucause)
CSR_NAME_DECLARE(CSR_UTVAL_ADDR, utval)
CSR_NAME_DECLARE(CSR_UIP_ADDR, uip)
CSR_NAME_DECLARE(CSR_FFLAGS_ADDR, fflags)
CSR_NAME_DECLARE(CSR_FRM_ADDR, frm)
CSR_NAME_DECLARE(CSR_FCSR_ADDR, fcsr)
CSR_NAME_DECLARE(CSR_CYCLE_ADDR, cycle)
CSR_NAME_DECLARE(CSR_TIME_ADDR, time)
CSR_NAME_DECLARE(CSR_INSTRET_ADDR, instret)
CSR_NAME_DECLARE(CSR_HPMCOUNTER3_ADDR, hpmcounter3)
CSR_NAME_DECLARE(CSR_HPMCOUNTER4_ADDR, hpmcounter4)
CSR_NAME_DECLARE(CSR_HPMCOUNTER5_ADDR, hpmcounter5)
CSR_NAME_DECLARE(CSR_HPMCOUNTER6_ADDR, hpmcounter6)
CSR_NAME_DECLARE(CSR_HPMCOUNTER7_ADDR, hpmcounter7)
CSR_NAME_DECLARE(CSR_HPMCOUNTER8_ADDR, hpmcounter8)
CSR_NAME_DECLARE(CSR_HPMCOUNTER9_ADDR, hpmcounter9)
CSR_NAME_DECLARE(CSR_HPMCOUNTER10_ADDR, hpmcounter10)
CSR_NAME_DECLARE(CSR_HPMCOUNTER11_ADDR, hpmcounter11)
CSR_NAME_DECLARE(CSR_HPMCOUNTER12_ADDR, hpmcounter12)
CSR_NAME_DECLARE(CSR_HPMCOUNTER13_ADDR, hpmcounter13)
CSR_NAME_DECLARE(CSR_HPMCOUNTER14_ADDR, hpmcounter14)
CSR_NAME_DECLARE(CSR_HPMCOUNTER15_ADDR, hpmcounter15)
CSR_NAME_DECLARE(CSR_HPMCOUNTER16_ADDR, hpmcounter16)
CSR_NAME_DECLARE(CSR_HPMCOUNTER17_ADDR, hpmcounter17)
CSR_NAME_DECLARE(CSR_HPMCOUNTER18_ADDR, hpmcounter18)
CSR_NAME_DECLARE(CSR_HPMCOUNTER19_ADDR, hpmcounter19)
CSR_NAME_DECLARE(CSR_HPMCOUNTER20_ADDR, hpmcounter20)
CSR_NAME_DECLARE(CSR_HPMCOUNTER21_ADDR, hpmcounter21)
CSR_NAME_DECLARE(CSR_HPMCOUNTER22_ADDR, hpmcounter22)
CSR_NAME_DECLARE(CSR_HPMCOUNTER23_ADDR, hpmcounter23)
CSR_NAME_DECLARE(CSR_HPMCOUNTER24_ADDR, hpmcounter24)
CSR_NAME_DECLARE(CSR_HPMCOUNTER25_ADDR, hpmcounter25)
CSR_NAME_DECLARE(CSR_HPMCOUNTER26_ADDR, hpmcounter26)
CSR_NAME_DECLARE(CSR_HPMCOUNTER27_ADDR, hpmcounter27)
CSR_NAME_DECLARE(CSR_HPMCOUNTER28_ADDR, hpmcounter28)
CSR_NAME_DECLARE(CSR_HPMCOUNTER29_ADDR, hpmcounter29)
CSR_NAME_DECLARE(CSR_HPMCOUNTER30_ADDR, hpmcounter30)
CSR_NAME_DECLARE(CSR_HPMCOUNTER31_ADDR, hpmcounter31)
CSR_NAME_DECLARE(CSR_CYCLEH_ADDR, cycleh)
CSR_NAME_DECLARE(CSR_TIMEH_ADDR, timeh)
CSR_NAME_DECLARE(CSR_INSTRETH_ADDR, instreth)
CSR_NAME_DECLARE(CSR_HPMCOUNTER3H_ADDR, hpmcounter3h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER4H_ADDR, hpmcounter4h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER5H_ADDR, hpmcounter5h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER6H_ADDR, hpmcounter6h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER7H_ADDR, hpmcounter7h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER8H_ADDR, hpmcounter8h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER9H_ADDR, hpmcounter9h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER10H_ADDR, hpmcounter10h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER11H_ADDR, hpmcounter11h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER12H_ADDR, hpmcounter12h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER13H_ADDR, hpmcounter13h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER14H_ADDR, hpmcounter14h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER15H_ADDR, hpmcounter15h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER16H_ADDR, hpmcounter16h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER17H_ADDR, hpmcounter17h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER18H_ADDR, hpmcounter18h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER19H_ADDR, hpmcounter19h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER20H_ADDR, hpmcounter20h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER21H_ADDR, hpmcounter21h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER22H_ADDR, hpmcounter22h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER23H_ADDR, hpmcounter23h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER24H_ADDR, hpmcounter24h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER25H_ADDR, hpmcounter25h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER26H_ADDR, hpmcounter26h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER27H_ADDR, hpmcounter27h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER28H_ADDR, hpmcounter28h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER29H_ADDR, hpmcounter29h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER30H_ADDR, hpmcounter30h)
CSR_NAME_DECLARE(CSR_HPMCOUNTER31H_ADDR, hpmcounter31h)

CSR_NAME_DECLARE(CSR_SSTATUS_ADDR, sstatus)
CSR_NAME_DECLARE(CSR_SEDELEG_ADDR, sedeleg)
CSR_NAME_DECLARE(CSR_SIDELEG_ADDR, sideleg)
CSR_NAME_DECLARE(CSR_SIE_ADDR, sie)
CSR_NAME_DECLARE(CSR_STVEC_ADDR, stvec)
CSR_NAME_DECLARE(CSR_SCOUNTEREN_ADDR, scounteren)
CSR_NAME_DECLARE(CSR_SSCRATCH_ADDR, sscratch)
CSR_NAME_DECLARE(CSR_SEPC_ADDR, sepc)
CSR_NAME_DECLARE(CSR_SCAUSE_ADDR, scause)
CSR_NAME_DECLARE(CSR_STVAL_ADDR, stval)
CSR_NAME_DECLARE(CSR_SIP_ADDR, sip)
CSR_NAME_DECLARE(CSR_SATP_ADDR, satp)

CSR_NAME_DECLARE(CSR_MVENDORID_ADDR, mvendorid)
CSR_NAME_DECLARE(CSR_MARCHID_ADDR, marchid)
CSR_NAME_DECLARE(CSR_MIMPID_ADDR, mimpid)
CSR_NAME_DECLARE(CSR_MHARTID_ADDR, mhartid)
CSR_NAME_DECLARE(CSR_MSTATUS_ADDR, mstatus)
CSR_NAME_DECLARE(CSR_MISA_ADDR, misa)
CSR_NAME_DECLARE(CSR_MEDELEG_ADDR, medeleg)
CSR_NAME_DECLARE(CSR_MIDELEG_ADDR, mideleg)
CSR_NAME_DECLARE(CSR_MIE_ADDR, mie)
CSR_NAME_DECLARE(CSR_MTVEC_ADDR, mtvec)
CSR_NAME_DECLARE(CSR_MCOUNTEREN_ADDR, mcounteren)
CSR_NAME_DECLARE(CSR_MSCRATCH_ADDR, mscratch)
CSR_NAME_DECLARE(CSR_MEPC_ADDR, mepc)
CSR_NAME_DECLARE(CSR_MCAUSE_ADDR, mcause)
CSR_NAME_DECLARE(CSR_MTVAL_ADDR, mtval)
CSR_NAME_DECLARE(CSR_MIP_ADDR, mip)
CSR_NAME_DECLARE(CSR_PMPCFG0_ADDR, pmpcfg0)
CSR_NAME_DECLARE(CSR_PMPCFG1_ADDR, pmpcfg1)
CSR_NAME_DECLARE(CSR_PMPCFG2_ADDR, pmpcfg2)
CSR_NAME_DECLARE(CSR_PMPCFG3_ADDR, pmpcfg3)
CSR_NAME_DECLARE(CSR_PMPADDR0_ADDR, pmpaddr0)
CSR_NAME_DECLARE(CSR_PMPADDR1_ADDR, pmpaddr1)
CSR_NAME_DECLARE(CSR_PMPADDR2_ADDR, pmpaddr2)
CSR_NAME_DECLARE(CSR_PMPADDR3_ADDR, pmpaddr3)
CSR_NAME_DECLARE(CSR_PMPADDR4_ADDR, pmpaddr4)
CSR_NAME_DECLARE(CSR_PMPADDR5_ADDR, pmpaddr5)
CSR_NAME_DECLARE(CSR_PMPADDR6_ADDR, pmpaddr6)
CSR_NAME_DECLARE(CSR_PMPADDR7_ADDR, pmpaddr7)
CSR_NAME_DECLARE(CSR_PMPADDR8_ADDR, pmpaddr8)
CSR_NAME_DECLARE(CSR_PMPADDR9_ADDR, pmpaddr9)
CSR_NAME_DECLARE(CSR_PMPADDR10_ADDR, pmpaddr10)
CSR_NAME_DECLARE(CSR_PMPADDR11_ADDR, pmpaddr11)
CSR_NAME_DECLARE(CSR_PMPADDR12_ADDR, pmpaddr12)
CSR_NAME_DECLARE(CSR_PMPADDR13_ADDR, pmpaddr13)
CSR_NAME_DECLARE(CSR_PMPADDR14_ADDR, pmpaddr14)
CSR_NAME_DECLARE(CSR_PMPADDR15_ADDR, pmpaddr15)
CSR_NAME_DECLARE(CSR_MCYCLE_ADDR, mcycle)
CSR_NAME_DECLARE(CSR_MINSTRET_ADDR, minstret)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER3_ADDR, mhpmcounter3)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER4_ADDR, mhpmcounter4)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER5_ADDR, mhpmcounter5)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER6_ADDR, mhpmcounter6)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER7_ADDR, mhpmcounter7)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER8_ADDR, mhpmcounter8)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER9_ADDR, mhpmcounter9)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER10_ADDR, mhpmcounter10)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER11_ADDR, mhpmcounter11)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER12_ADDR, mhpmcounter12)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER13_ADDR, mhpmcounter13)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER14_ADDR, mhpmcounter14)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER15_ADDR, mhpmcounter15)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER16_ADDR, mhpmcounter16)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER17_ADDR, mhpmcounter17)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER18_ADDR, mhpmcounter18)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER19_ADDR, mhpmcounter19)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER20_ADDR, mhpmcounter20)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER21_ADDR, mhpmcounter21)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER22_ADDR, mhpmcounter22)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER23_ADDR, mhpmcounter23)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER24_ADDR, mhpmcounter24)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER25_ADDR, mhpmcounter25)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER26_ADDR, mhpmcounter26)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER27_ADDR, mhpmcounter27)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER28_ADDR, mhpmcounter28)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER29_ADDR, mhpmcounter29)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER30_ADDR, mhpmcounter30)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER31_ADDR, mhpmcounter31)
CSR_NAME_DECLARE(CSR_MCYCLEH_ADDR, mcycleh)
CSR_NAME_DECLARE(CSR_MINSTRETH_ADDR, minstreth)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER3H_ADDR, mhpmcounter3h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER4H_ADDR, mhpmcounter4h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER5H_ADDR, mhpmcounter5h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER6H_ADDR, mhpmcounter6h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER7H_ADDR, mhpmcounter7h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER8H_ADDR, mhpmcounter8h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER9H_ADDR, mhpmcounter9h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER10H_ADDR, mhpmcounter10h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER11H_ADDR, mhpmcounter11h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER12H_ADDR, mhpmcounter12h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER13H_ADDR, mhpmcounter13h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER14H_ADDR, mhpmcounter14h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER15H_ADDR, mhpmcounter15h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER16H_ADDR, mhpmcounter16h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER17H_ADDR, mhpmcounter17h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER18H_ADDR, mhpmcounter18h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER19H_ADDR, mhpmcounter19h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER20H_ADDR, mhpmcounter20h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER21H_ADDR, mhpmcounter21h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER22H_ADDR, mhpmcounter22h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER23H_ADDR, mhpmcounter23h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER24H_ADDR, mhpmcounter24h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER25H_ADDR, mhpmcounter25h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER26H_ADDR, mhpmcounter26h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER27H_ADDR, mhpmcounter27h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER28H_ADDR, mhpmcounter28h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER29H_ADDR, mhpmcounter29h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER30H_ADDR, mhpmcounter30h)
CSR_NAME_DECLARE(CSR_MHPMCOUNTER31H_ADDR, mhpmcounter31h)
CSR_NAME_DECLARE(CSR_MHPMEVENT3_ADDR, mhpmevent3)
CSR_NAME_DECLARE(CSR_MHPMEVENT4_ADDR, mhpmevent4)
CSR_NAME_DECLARE(CSR_MHPMEVENT5_ADDR, mhpmevent5)
CSR_NAME_DECLARE(CSR_MHPMEVENT6_ADDR, mhpmevent6)
CSR_NAME_DECLARE(CSR_MHPMEVENT7_ADDR, mhpmevent7)
CSR_NAME_DECLARE(CSR_MHPMEVENT8_ADDR, mhpmevent8)
CSR_NAME_DECLARE(CSR_MHPMEVENT9_ADDR, mhpmevent9)
CSR_NAME_DECLARE(CSR_MHPMEVENT10_ADDR, mhpmevent10)
CSR_NAME_DECLARE(CSR_MHPMEVENT11_ADDR, mhpmevent11)
CSR_NAME_DECLARE(CSR_MHPMEVENT12_ADDR, mhpmevent12)
CSR_NAME_DECLARE(CSR_MHPMEVENT13_ADDR, mhpmevent13)
CSR_NAME_DECLARE(CSR_MHPMEVENT14_ADDR, mhpmevent14)
CSR_NAME_DECLARE(CSR_MHPMEVENT15_ADDR, mhpmevent15)
CSR_NAME_DECLARE(CSR_MHPMEVENT16_ADDR, mhpmevent16)
CSR_NAME_DECLARE(CSR_MHPMEVENT17_ADDR, mhpmevent17)
CSR_NAME_DECLARE(CSR_MHPMEVENT18_ADDR, mhpmevent18)
CSR_NAME_DECLARE(CSR_MHPMEVENT19_ADDR, mhpmevent19)
CSR_NAME_DECLARE(CSR_MHPMEVENT20_ADDR, mhpmevent20)
CSR_NAME_DECLARE(CSR_MHPMEVENT21_ADDR, mhpmevent21)
CSR_NAME_DECLARE(CSR_MHPMEVENT22_ADDR, mhpmevent22)
CSR_NAME_DECLARE(CSR_MHPMEVENT23_ADDR, mhpmevent23)
CSR_NAME_DECLARE(CSR_MHPMEVENT24_ADDR, mhpmevent24)
CSR_NAME_DECLARE(CSR_MHPMEVENT25_ADDR, mhpmevent25)
CSR_NAME_DECLARE(CSR_MHPMEVENT26_ADDR, mhpmevent26)
CSR_NAME_DECLARE(CSR_MHPMEVENT27_ADDR, mhpmevent27)
CSR_NAME_DECLARE(CSR_MHPMEVENT28_ADDR, mhpmevent28)
CSR_NAME_DECLARE(CSR_MHPMEVENT29_ADDR, mhpmevent29)
CSR_NAME_DECLARE(CSR_MHPMEVENT30_ADDR, mhpmevent30)
CSR_NAME_DECLARE(CSR_MHPMEVENT31_ADDR, mhpmevent31)

CSR_NAME_DECLARE(CSR_TSELECT_ADDR, tselect)
CSR_NAME_DECLARE(CSR_TDATA1_ADDR, tdata1)
CSR_NAME_DECLARE(CSR_TDATA2_ADDR, tdata2)
CSR_NAME_DECLARE(CSR_TDATA3_ADDR, tdata3)
CSR_NAME_DECLARE(CSR_DCSR_ADDR, dcsr)
CSR_NAME_DECLARE(CSR_DPC_ADDR, dpc)
CSR_NAME_DECLARE(CSR_DSCRATCH_ADDR, dscratch)
#endif

#ifdef CSR_READ_DECLARE
CSR_READ_DECLARE(CSR_USTATUS_ADDR, ustatus)
CSR_READ_DECLARE(CSR_UIE_ADDR, uie)
CSR_READ_DECLARE(CSR_UTVEC_ADDR, utvec)
CSR_READ_DECLARE(CSR_USCRATCH_ADDR, uscratch)
CSR_READ_DECLARE(CSR_UEPC_ADDR, uepc)
CSR_READ_DECLARE(CSR_UCAUSE_ADDR, ucause)
CSR_READ_DECLARE(CSR_UTVAL_ADDR, utval)
CSR_READ_DECLARE(CSR_UIP_ADDR, uip)
CSR_READ_DECLARE(CSR_FFLAGS_ADDR, fflags)
CSR_READ_DECLARE(CSR_FRM_ADDR, frm)
CSR_READ_DECLARE(CSR_FCSR_ADDR, fcsr)
CSR_READ_DECLARE(CSR_CYCLE_ADDR, cycle)
CSR_READ_DECLARE(CSR_TIME_ADDR, time)
CSR_READ_DECLARE(CSR_INSTRET_ADDR, instret)
CSR_READ_DECLARE(CSR_HPMCOUNTER3_ADDR, hpmcounter[0])
CSR_READ_DECLARE(CSR_HPMCOUNTER4_ADDR, hpmcounter[1])
CSR_READ_DECLARE(CSR_HPMCOUNTER5_ADDR, hpmcounter[2])
CSR_READ_DECLARE(CSR_HPMCOUNTER6_ADDR, hpmcounter[3])
CSR_READ_DECLARE(CSR_HPMCOUNTER7_ADDR, hpmcounter[4])
CSR_READ_DECLARE(CSR_HPMCOUNTER8_ADDR, hpmcounter[5])
CSR_READ_DECLARE(CSR_HPMCOUNTER9_ADDR, hpmcounter[6])
CSR_READ_DECLARE(CSR_HPMCOUNTER10_ADDR, hpmcounter[7])
CSR_READ_DECLARE(CSR_HPMCOUNTER11_ADDR, hpmcounter[8])
CSR_READ_DECLARE(CSR_HPMCOUNTER12_ADDR, hpmcounter[9])
CSR_READ_DECLARE(CSR_HPMCOUNTER13_ADDR, hpmcounter[10])
CSR_READ_DECLARE(CSR_HPMCOUNTER14_ADDR, hpmcounter[11])
CSR_READ_DECLARE(CSR_HPMCOUNTER15_ADDR, hpmcounter[12])
CSR_READ_DECLARE(CSR_HPMCOUNTER16_ADDR, hpmcounter[13])
CSR_READ_DECLARE(CSR_HPMCOUNTER17_ADDR, hpmcounter[14])
CSR_READ_DECLARE(CSR_HPMCOUNTER18_ADDR, hpmcounter[15])
CSR_READ_DECLARE(CSR_HPMCOUNTER19_ADDR, hpmcounter[16])
CSR_READ_DECLARE(CSR_HPMCOUNTER20_ADDR, hpmcounter[17])
CSR_READ_DECLARE(CSR_HPMCOUNTER21_ADDR, hpmcounter[28])
CSR_READ_DECLARE(CSR_HPMCOUNTER22_ADDR, hpmcounter[29])
CSR_READ_DECLARE(CSR_HPMCOUNTER23_ADDR, hpmcounter[20])
CSR_READ_DECLARE(CSR_HPMCOUNTER24_ADDR, hpmcounter[21])
CSR_READ_DECLARE(CSR_HPMCOUNTER25_ADDR, hpmcounter[22])
CSR_READ_DECLARE(CSR_HPMCOUNTER26_ADDR, hpmcounter[23])
CSR_READ_DECLARE(CSR_HPMCOUNTER27_ADDR, hpmcounter[24])
CSR_READ_DECLARE(CSR_HPMCOUNTER28_ADDR, hpmcounter[25])
CSR_READ_DECLARE(CSR_HPMCOUNTER29_ADDR, hpmcounter[26])
CSR_READ_DECLARE(CSR_HPMCOUNTER30_ADDR, hpmcounter[27])
CSR_READ_DECLARE(CSR_HPMCOUNTER31_ADDR, hpmcounter[28])

CSR_READ_DECLARE(CSR_SEDELEG_ADDR, sedeleg)
CSR_READ_DECLARE(CSR_SIDELEG_ADDR, sideleg)
CSR_READ_DECLARE(CSR_SIE_ADDR, sie)
CSR_READ_DECLARE(CSR_STVEC_ADDR, stvec)
CSR_READ_DECLARE(CSR_SCOUNTEREN_ADDR, scounteren)
CSR_READ_DECLARE(CSR_SSCRATCH_ADDR, sscratch)
CSR_READ_DECLARE(CSR_SEPC_ADDR, sepc)
CSR_READ_DECLARE(CSR_SCAUSE_ADDR, scause)
CSR_READ_DECLARE(CSR_STVAL_ADDR, stval)
CSR_READ_DECLARE(CSR_SIP_ADDR, sip)
CSR_READ_DECLARE(CSR_SATP_ADDR, satp)

CSR_READ_DECLARE(CSR_MVENDORID_ADDR, mvendorid)
CSR_READ_DECLARE(CSR_MARCHID_ADDR, marchid)
CSR_READ_DECLARE(CSR_MIMPID_ADDR, mimpid)
CSR_READ_DECLARE(CSR_MHARTID_ADDR, mhartid)
CSR_READ_DECLARE(CSR_MSTATUS_ADDR, mstatus)
CSR_READ_DECLARE(CSR_MISA_ADDR, misa)
CSR_READ_DECLARE(CSR_MEDELEG_ADDR, medeleg)
CSR_READ_DECLARE(CSR_MIDELEG_ADDR, mideleg)
CSR_READ_DECLARE(CSR_MIE_ADDR, mie)
CSR_READ_DECLARE(CSR_MTVEC_ADDR, mtvec)
CSR_READ_DECLARE(CSR_MCOUNTEREN_ADDR, mcounteren)
CSR_READ_DECLARE(CSR_MSCRATCH_ADDR, mscratch)
CSR_READ_DECLARE(CSR_MEPC_ADDR, mepc)
CSR_READ_DECLARE(CSR_MCAUSE_ADDR, mcause)
CSR_READ_DECLARE(CSR_MTVAL_ADDR, mtval)
CSR_READ_DECLARE(CSR_MIP_ADDR, mip)
CSR_READ_DECLARE(CSR_PMPCFG0_ADDR, ((uint64_t *)pmpcfg)[0])
CSR_READ_DECLARE(CSR_PMPCFG2_ADDR, ((uint64_t *)pmpcfg)[1])
CSR_READ_DECLARE(CSR_PMPADDR0_ADDR, pmpaddr[0])
CSR_READ_DECLARE(CSR_PMPADDR1_ADDR, pmpaddr[1])
CSR_READ_DECLARE(CSR_PMPADDR2_ADDR, pmpaddr[2])
CSR_READ_DECLARE(CSR_PMPADDR3_ADDR, pmpaddr[3])
CSR_READ_DECLARE(CSR_PMPADDR4_ADDR, pmpaddr[4])
CSR_READ_DECLARE(CSR_PMPADDR5_ADDR, pmpaddr[5])
CSR_READ_DECLARE(CSR_PMPADDR6_ADDR, pmpaddr[6])
CSR_READ_DECLARE(CSR_PMPADDR7_ADDR, pmpaddr[7])
CSR_READ_DECLARE(CSR_PMPADDR8_ADDR, pmpaddr[8])
CSR_READ_DECLARE(CSR_PMPADDR9_ADDR, pmpaddr[9])
CSR_READ_DECLARE(CSR_PMPADDR10_ADDR, pmpaddr[10])
CSR_READ_DECLARE(CSR_PMPADDR11_ADDR, pmpaddr[11])
CSR_READ_DECLARE(CSR_PMPADDR12_ADDR, pmpaddr[12])
CSR_READ_DECLARE(CSR_PMPADDR13_ADDR, pmpaddr[13])
CSR_READ_DECLARE(CSR_PMPADDR14_ADDR, pmpaddr[14])
CSR_READ_DECLARE(CSR_PMPADDR15_ADDR, pmpaddr[15])
CSR_READ_DECLARE(CSR_MCYCLE_ADDR, mcycle)
CSR_READ_DECLARE(CSR_MINSTRET_ADDR, minstret)
CSR_READ_DECLARE(CSR_MHPMCOUNTER3_ADDR, mhpmcounter[0])
CSR_READ_DECLARE(CSR_MHPMCOUNTER4_ADDR, mhpmcounter[1])
CSR_READ_DECLARE(CSR_MHPMCOUNTER5_ADDR, mhpmcounter[2])
CSR_READ_DECLARE(CSR_MHPMCOUNTER6_ADDR, mhpmcounter[3])
CSR_READ_DECLARE(CSR_MHPMCOUNTER7_ADDR, mhpmcounter[4])
CSR_READ_DECLARE(CSR_MHPMCOUNTER8_ADDR, mhpmcounter[5])
CSR_READ_DECLARE(CSR_MHPMCOUNTER9_ADDR, mhpmcounter[6])
CSR_READ_DECLARE(CSR_MHPMCOUNTER10_ADDR, mhpmcounter[7])
CSR_READ_DECLARE(CSR_MHPMCOUNTER11_ADDR, mhpmcounter[8])
CSR_READ_DECLARE(CSR_MHPMCOUNTER12_ADDR, mhpmcounter[9])
CSR_READ_DECLARE(CSR_MHPMCOUNTER13_ADDR, mhpmcounter[10])
CSR_READ_DECLARE(CSR_MHPMCOUNTER14_ADDR, mhpmcounter[11])
CSR_READ_DECLARE(CSR_MHPMCOUNTER15_ADDR, mhpmcounter[12])
CSR_READ_DECLARE(CSR_MHPMCOUNTER16_ADDR, mhpmcounter[13])
CSR_READ_DECLARE(CSR_MHPMCOUNTER17_ADDR, mhpmcounter[14])
CSR_READ_DECLARE(CSR_MHPMCOUNTER18_ADDR, mhpmcounter[15])
CSR_READ_DECLARE(CSR_MHPMCOUNTER19_ADDR, mhpmcounter[16])
CSR_READ_DECLARE(CSR_MHPMCOUNTER20_ADDR, mhpmcounter[17])
CSR_READ_DECLARE(CSR_MHPMCOUNTER21_ADDR, mhpmcounter[18])
CSR_READ_DECLARE(CSR_MHPMCOUNTER22_ADDR, mhpmcounter[19])
CSR_READ_DECLARE(CSR_MHPMCOUNTER23_ADDR, mhpmcounter[20])
CSR_READ_DECLARE(CSR_MHPMCOUNTER24_ADDR, mhpmcounter[21])
CSR_READ_DECLARE(CSR_MHPMCOUNTER25_ADDR, mhpmcounter[22])
CSR_READ_DECLARE(CSR_MHPMCOUNTER26_ADDR, mhpmcounter[23])
CSR_READ_DECLARE(CSR_MHPMCOUNTER27_ADDR, mhpmcounter[24])
CSR_READ_DECLARE(CSR_MHPMCOUNTER28_ADDR, mhpmcounter[25])
CSR_READ_DECLARE(CSR_MHPMCOUNTER29_ADDR, mhpmcounter[26])
CSR_READ_DECLARE(CSR_MHPMCOUNTER30_ADDR, mhpmcounter[27])
CSR_READ_DECLARE(CSR_MHPMCOUNTER31_ADDR, mhpmcounter[28])
CSR_READ_DECLARE(CSR_MHPMEVENT3_ADDR, mhpmevent[0])
CSR_READ_DECLARE(CSR_MHPMEVENT4_ADDR, mhpmevent[1])
CSR_READ_DECLARE(CSR_MHPMEVENT5_ADDR, mhpmevent[2])
CSR_READ_DECLARE(CSR_MHPMEVENT6_ADDR, mhpmevent[3])
CSR_READ_DECLARE(CSR_MHPMEVENT7_ADDR, mhpmevent[4])
CSR_READ_DECLARE(CSR_MHPMEVENT8_ADDR, mhpmevent[5])
CSR_READ_DECLARE(CSR_MHPMEVENT9_ADDR, mhpmevent[6])
CSR_READ_DECLARE(CSR_MHPMEVENT10_ADDR, mhpmevent[7])
CSR_READ_DECLARE(CSR_MHPMEVENT11_ADDR, mhpmevent[8])
CSR_READ_DECLARE(CSR_MHPMEVENT12_ADDR, mhpmevent[9])
CSR_READ_DECLARE(CSR_MHPMEVENT13_ADDR, mhpmevent[10])
CSR_READ_DECLARE(CSR_MHPMEVENT14_ADDR, mhpmevent[11])
CSR_READ_DECLARE(CSR_MHPMEVENT15_ADDR, mhpmevent[12])
CSR_READ_DECLARE(CSR_MHPMEVENT16_ADDR, mhpmevent[13])
CSR_READ_DECLARE(CSR_MHPMEVENT17_ADDR, mhpmevent[14])
CSR_READ_DECLARE(CSR_MHPMEVENT18_ADDR, mhpmevent[15])
CSR_READ_DECLARE(CSR_MHPMEVENT19_ADDR, mhpmevent[16])
CSR_READ_DECLARE(CSR_MHPMEVENT20_ADDR, mhpmevent[17])
CSR_READ_DECLARE(CSR_MHPMEVENT21_ADDR, mhpmevent[18])
CSR_READ_DECLARE(CSR_MHPMEVENT22_ADDR, mhpmevent[19])
CSR_READ_DECLARE(CSR_MHPMEVENT23_ADDR, mhpmevent[20])
CSR_READ_DECLARE(CSR_MHPMEVENT24_ADDR, mhpmevent[21])
CSR_READ_DECLARE(CSR_MHPMEVENT25_ADDR, mhpmevent[22])
CSR_READ_DECLARE(CSR_MHPMEVENT26_ADDR, mhpmevent[23])
CSR_READ_DECLARE(CSR_MHPMEVENT27_ADDR, mhpmevent[24])
CSR_READ_DECLARE(CSR_MHPMEVENT28_ADDR, mhpmevent[25])
CSR_READ_DECLARE(CSR_MHPMEVENT29_ADDR, mhpmevent[26])
CSR_READ_DECLARE(CSR_MHPMEVENT30_ADDR, mhpmevent[27])
CSR_READ_DECLARE(CSR_MHPMEVENT31_ADDR, mhpmevent[28])

CSR_READ_DECLARE(CSR_TSELECT_ADDR, tselect)
CSR_READ_DECLARE(CSR_TDATA1_ADDR, tdata[1])
CSR_READ_DECLARE(CSR_TDATA2_ADDR, tdata[2])
CSR_READ_DECLARE(CSR_TDATA3_ADDR, tdata[3])
CSR_READ_DECLARE(CSR_DCSR_ADDR, dcsr)
CSR_READ_DECLARE(CSR_DPC_ADDR, dpc)
CSR_READ_DECLARE(CSR_DSCRATCH_ADDR, dscratch)
#endif

#ifdef CSR_WRITE_DECLARE
CSR_WRITE_DECLARE(CSR_USTATUS_ADDR, ustatus, -0x1L)
CSR_WRITE_DECLARE(CSR_UIE_ADDR, uie, -0x1L)
CSR_WRITE_DECLARE(CSR_UTVEC_ADDR, utvec, -0x1L)
CSR_WRITE_DECLARE(CSR_USCRATCH_ADDR, uscratch, -0x1L)
CSR_WRITE_DECLARE(CSR_UEPC_ADDR, uepc, -0x1L)
CSR_WRITE_DECLARE(CSR_UCAUSE_ADDR, ucause, -0x1L)
CSR_WRITE_DECLARE(CSR_UTVAL_ADDR, utval, -0x1L)
CSR_WRITE_DECLARE(CSR_UIP_ADDR, uip, -0x1L)
CSR_WRITE_DECLARE(CSR_FFLAGS_ADDR, fflags, -0x1L)
CSR_WRITE_DECLARE(CSR_FRM_ADDR, frm, -0x1L)
CSR_WRITE_DECLARE(CSR_FCSR_ADDR, fcsr, -0x1L)
CSR_WRITE_DECLARE(CSR_CYCLE_ADDR, cycle, 0x0)
CSR_WRITE_DECLARE(CSR_TIME_ADDR, time, 0x0)
CSR_WRITE_DECLARE(CSR_INSTRET_ADDR, instret, 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER3_ADDR, hpmcounter[0], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER4_ADDR, hpmcounter[1], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER5_ADDR, hpmcounter[2], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER6_ADDR, hpmcounter[3], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER7_ADDR, hpmcounter[4], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER8_ADDR, hpmcounter[5], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER9_ADDR, hpmcounter[6], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER10_ADDR, hpmcounter[7], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER11_ADDR, hpmcounter[8], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER12_ADDR, hpmcounter[9], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER13_ADDR, hpmcounter[10], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER14_ADDR, hpmcounter[11], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER15_ADDR, hpmcounter[12], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER16_ADDR, hpmcounter[13], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER17_ADDR, hpmcounter[14], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER18_ADDR, hpmcounter[15], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER19_ADDR, hpmcounter[16], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER20_ADDR, hpmcounter[17], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER21_ADDR, hpmcounter[28], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER22_ADDR, hpmcounter[29], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER23_ADDR, hpmcounter[20], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER24_ADDR, hpmcounter[21], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER25_ADDR, hpmcounter[22], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER26_ADDR, hpmcounter[23], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER27_ADDR, hpmcounter[24], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER28_ADDR, hpmcounter[25], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER29_ADDR, hpmcounter[26], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER30_ADDR, hpmcounter[27], 0x0)
CSR_WRITE_DECLARE(CSR_HPMCOUNTER31_ADDR, hpmcounter[28], 0x0)

CSR_WRITE_DECLARE(CSR_SEDELEG_ADDR, sedeleg, -0x1L)
CSR_WRITE_DECLARE(CSR_SIDELEG_ADDR, sideleg, -0x1L)
CSR_WRITE_DECLARE(CSR_SIE_ADDR, sie, -0x1L)
CSR_WRITE_DECLARE(CSR_STVEC_ADDR, stvec, -0x1L)
CSR_WRITE_DECLARE(CSR_SCOUNTEREN_ADDR, scounteren, -0x1L)
CSR_WRITE_DECLARE(CSR_SSCRATCH_ADDR, sscratch, -0x1L)
CSR_WRITE_DECLARE(CSR_SEPC_ADDR, sepc, -0x1L)
CSR_WRITE_DECLARE(CSR_SCAUSE_ADDR, scause, -0x1L)
CSR_WRITE_DECLARE(CSR_STVAL_ADDR, stval, -0x1L)
CSR_WRITE_DECLARE(CSR_SIP_ADDR, sip, -0x1L)
CSR_WRITE_DECLARE(CSR_SATP_ADDR, satp, -0x1L)

CSR_WRITE_DECLARE(CSR_MVENDORID_ADDR, mvendorid, 0x0)
CSR_WRITE_DECLARE(CSR_MARCHID_ADDR, marchid, 0x0)
CSR_WRITE_DECLARE(CSR_MIMPID_ADDR, mimpid, 0x0)
CSR_WRITE_DECLARE(CSR_MHARTID_ADDR, mhartid, 0x0)
CSR_WRITE_DECLARE(CSR_MCOUNTEREN_ADDR, mcounteren, -0x1L)
CSR_WRITE_DECLARE(CSR_MSCRATCH_ADDR, mscratch, -0x1L)
CSR_WRITE_DECLARE(CSR_MCAUSE_ADDR, mcause, -0x1L)
CSR_WRITE_DECLARE(CSR_MTVAL_ADDR, mtval, -0x1L)
CSR_WRITE_DECLARE(CSR_MCYCLE_ADDR, mcycle, -0x1L)
CSR_WRITE_DECLARE(CSR_MINSTRET_ADDR, minstret, -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER3_ADDR, mhpmcounter[0], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER4_ADDR, mhpmcounter[1], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER5_ADDR, mhpmcounter[2], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER6_ADDR, mhpmcounter[3], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER7_ADDR, mhpmcounter[4], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER8_ADDR, mhpmcounter[5], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER9_ADDR, mhpmcounter[6], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER10_ADDR, mhpmcounter[7], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER11_ADDR, mhpmcounter[8], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER12_ADDR, mhpmcounter[9], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER13_ADDR, mhpmcounter[10], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER14_ADDR, mhpmcounter[11], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER15_ADDR, mhpmcounter[12], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER16_ADDR, mhpmcounter[13], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER17_ADDR, mhpmcounter[14], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER18_ADDR, mhpmcounter[15], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER19_ADDR, mhpmcounter[16], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER20_ADDR, mhpmcounter[17], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER21_ADDR, mhpmcounter[18], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER22_ADDR, mhpmcounter[19], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER23_ADDR, mhpmcounter[20], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER24_ADDR, mhpmcounter[21], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER25_ADDR, mhpmcounter[22], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER26_ADDR, mhpmcounter[23], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER27_ADDR, mhpmcounter[24], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER28_ADDR, mhpmcounter[25], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER29_ADDR, mhpmcounter[26], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER30_ADDR, mhpmcounter[27], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMCOUNTER31_ADDR, mhpmcounter[28], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT3_ADDR, mhpmevent[0], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT4_ADDR, mhpmevent[1], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT5_ADDR, mhpmevent[2], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT6_ADDR, mhpmevent[3], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT7_ADDR, mhpmevent[4], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT8_ADDR, mhpmevent[5], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT9_ADDR, mhpmevent[6], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT10_ADDR, mhpmevent[7], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT11_ADDR, mhpmevent[8], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT12_ADDR, mhpmevent[9], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT13_ADDR, mhpmevent[10], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT14_ADDR, mhpmevent[11], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT15_ADDR, mhpmevent[12], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT16_ADDR, mhpmevent[13], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT17_ADDR, mhpmevent[14], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT18_ADDR, mhpmevent[15], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT19_ADDR, mhpmevent[16], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT20_ADDR, mhpmevent[17], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT21_ADDR, mhpmevent[18], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT22_ADDR, mhpmevent[19], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT23_ADDR, mhpmevent[20], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT24_ADDR, mhpmevent[21], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT25_ADDR, mhpmevent[22], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT26_ADDR, mhpmevent[23], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT27_ADDR, mhpmevent[24], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT28_ADDR, mhpmevent[25], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT29_ADDR, mhpmevent[26], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT30_ADDR, mhpmevent[27], -0x1L)
CSR_WRITE_DECLARE(CSR_MHPMEVENT31_ADDR, mhpmevent[28], -0x1L)

CSR_WRITE_DECLARE(CSR_TSELECT_ADDR, tselect, -0x1L)
CSR_WRITE_DECLARE(CSR_TDATA1_ADDR, tdata[1], -0x1L)
CSR_WRITE_DECLARE(CSR_TDATA2_ADDR, tdata[2], -0x1L)
CSR_WRITE_DECLARE(CSR_TDATA3_ADDR, tdata[3], -0x1L)
CSR_WRITE_DECLARE(CSR_DCSR_ADDR, dcsr, -0x1L)
CSR_WRITE_DECLARE(CSR_DPC_ADDR, dpc, -0x1L)
CSR_WRITE_DECLARE(CSR_DSCRATCH_ADDR, dscratch, -0x1L)
#endif
