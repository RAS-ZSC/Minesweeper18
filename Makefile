ARD_BLD = arduino-builder

ARD_HW = /usr/share/arduino/hardware/
#ARD_BLD_FQBN = "arduino:avr:mega:cpu=atmega2560"
ARD_BLD_FQBN = "arduino:avr:uno:cpu=atmega328p"
PART_NO = m328p
#PART_NO = atmega2560
BAUDRATE = 115200
PORT = /dev/ttyACM1
CONFIG = /etc/avrdude/avrdude.conf
#PROGRAMMER = wiring
PROGRAMMER = arduino

ARD_BLD_FLAGS = -hardware $(ARD_HW) -fqbn $(ARD_BLD_FQBN) -compile -verbose -libraries ./libs/ -build-path $(PWD)/build

all: Minesweeper Controller

.PHONY: Minesweeper Controller upload-robot upload-controller clean
Minesweeper: Robot/Minesweeper.ino
	@$(ARD_BLD) $(ARD_BLD_FLAGS) $<

Controller: Controller/Controller.ino
	@$(ARD_BLD) $(ARD_BLD_FLAGS) $<

upload-robot:
	@avrdude -C $(CONFIG) -p $(PART_NO) -c $(PROGRAMMER) -b $(BAUDRATE) -D -U flash:w:build/Minesweeper.ino.with_bootloader.hex:i -P $(PORT) -v
upload-controller:
	@avrdude -C $(CONFIG) -p $(PART_NO) -c $(PROGRAMMER) -b $(BAUDRATE) -D -U flash:w:build/Controller.ino.with_bootloader.hex:i  -P $(PORT) -v

clean:
	@rm -rf build/*
