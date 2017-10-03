ARD_BLD = arduino-builder

ARD_HW = /usr/share/arduino/hardware/
#ARD_BLD_FQBN = "arduino:avr:mega:cpu=atmega1280"
ARD_BLD_FQBN = "arduino:avr:uno:cpu=atmega328p"

ARD_BLD_FLAGS = -hardware $(ARD_HW) -fqbn $(ARD_BLD_FQBN) -compile -verbose -libraries ./libs/ -build-path $(PWD)/build

all: Minesweeper.ino
	@$(ARD_BLD) $(ARD_BLD_FLAGS) $<
upload:
	@avrdude -C /etc/avrdude/avrdude.conf -p m328p -c arduino -b 115200 -U flash:w:build/Minesweeper.ino.with_bootloader.hex:i -P /dev/ttyACM0
clean:
	@rm -rf build/*
