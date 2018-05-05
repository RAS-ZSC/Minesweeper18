
ARDUINO_HOME := /home/hazem/Downloads/arduino-1.8.5

ARDUINO_HARDWARE := $(ARDUINO_HOME)/hardware
ARDUINO_BUILDER := $(ARDUINO_HOME)/arduino-builder
ARDUINO_TOOLS := $(ARDUINO_HOME)/tools-builder 
ARDUINO_TOOLS_AVR := $(ARDUINO_HARDWARE)/tools/avr
ARDUINO_CONFIG := $(ARDUINO_TOOLS_AVR)/etc/avrdude.conf
AVRDUDE := $(ARDUINO_TOOLS_AVR)/bin/avrdude
ARDUINO_FQBN = "arduino:avr:mega:cpu=atmega2560"
#ARDUINO_FQBN = "arduino:avr:uno:cpu=atmega328p"
#PART_NO = m328p
PART_NO = atmega2560
BAUDRATE = 115200
PORT = /dev/ttyACM0
PROGRAMMER = wiring
#PROGRAMMER = arduino    

ARDBLD_FLAGS = -hardware $(ARDUINO_HARDWARE) -tools $(ARDUINO_TOOLS) -tools $(ARDUINO_TOOLS_AVR) -fqbn $(ARDUINO_FQBN) -compile -verbose -libraries ./libs/ -build-path $(PWD)/build

all: Minesweeper  Controller

.PHONY: Minesweeper Controller upload-robot upload-controller clean
Minesweeper: Robot/Minesweeper.ino
	@$(ARDUINO_BUILDER) $(ARDBLD_FLAGS) $<

Controller: Controller/Controller.ino
	@$(ARDUINO_BUILDER) $(ARDBLD_FLAGS) $<

upload-robot:
	@$(AVRDUDE) -C $(ARDUINO_CONFIG) -p $(PART_NO) -c $(PROGRAMMER) -b $(BAUDRATE) -D -U flash:w:build/Minesweeper.ino.with_bootloader.hex:i -P $(PORT) -v
upload-controller:
	@$(AVRDUDE) -C $(ARDUINO_CONFIG) -p $(PART_NO) -c $(PROGRAMMER) -b $(BAUDRATE) -D -U flash:w:build/Controller.ino.with_bootloader.hex:i  -P $(PORT) -v

clean:
	@rm -rf build/*
