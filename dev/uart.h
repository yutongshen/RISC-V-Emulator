#ifndef __UART__
#define __UART__
#include <thread>
#include "bus/slave.h"
#include "dev/device.h"
#include "dev/irqsrc.h"
#include "dev/plic.h"

#define UART_TXEN (1 << 0)
#define UART_RXEN (1 << 0)

#define UART_TXIE (1 << 0)
#define UART_RXIE (1 << 1)

#define UART_RXFIFO_DEPTH 128
#define UART_TXFIFO_DEPTH 8

#define STDIN_BUFF_SIZE 128

#define FIFO_FULL(x, depth) ((x##_rptr - x##_wptr + depth) % depth == 1)
#define FIFO_EMPT(x) (x##_rptr == x##_wptr)

class Uart : public Device, public Slave, public IRQSource
{
    virtual void _init();
    void _update();

    uint32_t txctrl;
    uint32_t rxctrl;
    uint32_t nstop;
    uint32_t txcnt;
    uint32_t rxcnt;
    uint32_t ie;
    uint32_t ip;
    uint32_t div;

    uint32_t txfifo[UART_TXFIFO_DEPTH];
    int8_t tx_rptr;
    int8_t tx_wptr;

    uint32_t rxfifo[UART_RXFIFO_DEPTH];
    int8_t rx_rptr;
    int8_t rx_wptr;

    std::thread t_getch;
    static void getch(Uart *uart);

public:
    Uart(uint32_t irq_id = -1, PLIC *plic = NULL);
    ~Uart();
    virtual void single_step();
    virtual bool write(const Addr &addr,
                       const DataType &data_type,
                       const uint64_t &wdata);
    virtual bool read(const Addr &addr,
                      const DataType &data_type,
                      uint64_t &rdata);
};


#endif
