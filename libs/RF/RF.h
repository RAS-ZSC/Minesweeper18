#ifndef _RF_H
#define _RF_H

#include <nRF24L01.h>
#include <RF24.h>

class RF: RF24 {
private:
    enum {RF_MASTER, RF_SLAVE} type;
    enum {RF_TX, RF_RX} role;

    uint64_t pipes[2] = {0xABCDABCD71LL, 0x544d52687CLL};
    uint32_t packet_id = 0;
    bool synchronized = 0;

public:
    RF(uint16_t, uint16_t);
    void begin(int);
    void send(void *, size_t);
    int  read(void *, size_t);
};

#endif
