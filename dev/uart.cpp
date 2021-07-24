#include "uart.h"
#include <iostream>
#include "mmap/uart_reg.h"
#include "util/util.h"

int8_t Uart::end = 0;
int8_t Uart::rx_rptr = 0;
int8_t Uart::rx_wptr = 0;
uint32_t Uart::rxfifo[] = {0};

void Uart::getch() {
    system("stty raw");
    while (!end) {
        rxfifo[rx_wptr++] = getchar();
        rx_wptr %= UART_RXFIFO_DEPTH;
    }
    system("stty cooked");
}

void Uart::_init() {}

Uart::Uart()
    : txctrl(0),
      rxctrl(0),
      ie(0),
      ip(0),
      div(0),
      txfifo{0},
      tx_rptr(0),
      tx_wptr(0),
      t_getch(getch),
      Device(),
      Slave(0x1000)
{}

Uart::~Uart() {
    printf("\r\nPress any key to exit ... \r\n");
    end = 1;
    t_getch.join();
    // for (int i = 0; i < UART_RXFIFO_DEPTH; ++i)
    //     printf("%d: 0x%x\n", i, rxfifo[i]);
}

void Uart::run()
{
    if (txctrl & UART_TXEN) {
        if (tx_rptr - tx_wptr) {
            if (txfifo[tx_rptr] == '\n')
                putchar('\r');
            putchar((uint8_t) txfifo[tx_rptr++]);
            tx_rptr %= UART_RXFIFO_DEPTH;
        }
    }
}

bool Uart::write(const Addr &addr,
                 const DataType &data_type,
                 const uint64_t &wdata)
{
    uint64_t mask, _wdata;

    switch (data_type) {
    case DATA_TYPE_DWORD:
        mask = -1UL;
        break;
    case DATA_TYPE_WORD:
    case DATA_TYPE_WORD_UNSIGNED:
        mask = -1U;
        break;
    case DATA_TYPE_HWORD:
    case DATA_TYPE_HWORD_UNSIGNED:
        mask = 0xffff;
        break;
    case DATA_TYPE_BYTE:
    case DATA_TYPE_BYTE_UNSIGNED:
        mask = 0xff;
        break;
    default:
        abort();
    }

    _wdata = wdata & mask;

    //printf("write [%lx] = %lx\n", addr, _wdata);
    switch (addr) {
    case RG_TXFIFO:
        if (txctrl & UART_TXEN) {
            if ((tx_rptr - tx_wptr) % UART_TXFIFO_DEPTH != 1) {  // check non-full
                txfifo[tx_wptr++] = _wdata;
                tx_wptr %= UART_TXFIFO_DEPTH;
            }
        }
        break;
    case RG_RXFIFO:
        // if (rxctrl & UART_RXEN) {
        //     if ((rx_rptr - rx_wptr) % UART_RXFIFO_DEPTH != 1) {  // check non-full
        //         rxfifo[rx_wptr++] = _wdata;
        //         rx_wptr %= UART_RXFIFO_DEPTH;
        //     }
        // }
        break;
    case RG_TXCTRL:
        txctrl = _wdata;
        break;
    case RG_RXCTRL:
        rxctrl = _wdata;
        break;
    case RG_IE:
        ie = _wdata;
        break;
    case RG_IP:
        ip = _wdata;
        break;
    case RG_DIV:
        div = _wdata;
        break;
    }

    return 1;
}

bool Uart::read(const Addr &addr, const DataType &data_type, uint64_t &rdata)
{
    rdata = 0L;
    switch (addr) {
    case RG_TXFIFO:
        rdata = ((tx_rptr - tx_wptr) % UART_TXFIFO_DEPTH == 1) ? -1 : 0;
        break;
    case RG_RXFIFO:
        if (rxctrl & UART_RXEN) {
            if (rx_rptr - rx_wptr) {  // check non-empty
                rdata = rxfifo[rx_rptr++];
                rx_rptr %= UART_RXFIFO_DEPTH;
            } else {
                rdata = -1;
            }
        }
        break;
    case RG_TXCTRL:
        rdata = txctrl;
        break;
    case RG_RXCTRL:
        rdata = rxctrl;
        rxctrl = -1;
        break;
    case RG_IE:
        rdata = ie;
        break;
    case RG_IP:
        rdata = ip;
        break;
    case RG_DIV:
        rdata = div;
        break;
    }

    switch (data_type) {
    case DATA_TYPE_DWORD:
        break;
    case DATA_TYPE_WORD:
        rdata = sext(rdata, 32);
        break;
    case DATA_TYPE_WORD_UNSIGNED:
        rdata = zext(rdata, 32);
        break;
    case DATA_TYPE_HWORD:
        rdata = sext(rdata, 16);
        break;
    case DATA_TYPE_HWORD_UNSIGNED:
        rdata = zext(rdata, 16);
        break;
    case DATA_TYPE_BYTE:
        rdata = sext(rdata, 8);
        break;
    case DATA_TYPE_BYTE_UNSIGNED:
        rdata = zext(rdata, 8);
        break;
    default:
        abort();
    }

    // printf("read [%lx] = %lx\n", addr, rdata);

    return 1;
}
