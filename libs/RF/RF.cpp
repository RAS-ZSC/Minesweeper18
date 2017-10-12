#include <RF.h>

RF::RF(uint16_t ce_pin, uint16_t csn_pin): RF24(ce_pin, csn_pin) {

}

void RF::begin(int robot) {
    RF24::begin();
    enableDynamicPayloads();
    setRetries(0, 5);
    //setCRCLength(RF24_CRC_16);
    
    if (robot) {
        openWritingPipe(pipes[1]);
        openReadingPipe(1, pipes[0]);
    } else {
        openWritingPipe(pipes[0]);
        openReadingPipe(1, pipes[1]);
    }

    startListening();
    printDetails();
}

void RF::send(void *buf, size_t len) {
    stopListening();
    write(buf, len);
    startListening();
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int RF::read(void *buf, size_t len) {
    bool timeout = false;

    unsigned long _time = millis();
    while (!available() && !timeout) {
        if (millis() - _time > 500)
            timeout = true;
    }

    if (timeout) {
        return 0;
    } else {
        uint8_t _len = MIN(len, getDynamicPayloadSize());
        read(buf, _len);
        return  _len;
    }
}
