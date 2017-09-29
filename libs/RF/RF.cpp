#include <RF.h>

RF::RF(uint16_t ce_pin, uint16_t csn_pin): RF24(ce_pin, csn_pin) {

}

void RF::begin() {
    RF24::begin();
    setChannel(1);
    setAutoAck(1);
    setRetries(0, 5);
    setCRCLength(RF24_CRC_16);
    openWritingPipe(pipes[0]);
    openReadingPipe(1, pipes[1]);
    startListening();
    powerUp();
}
