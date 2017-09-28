ARD_BLD = arduino-builder

ARD_HW = /usr/share/arduino/hardware/
ARD_BLD_FQBN = "arduino:avr:mega:cpu=atmega1280"

ARD_BLD_FLAGS = -hardware $(ARD_HW) -fqbn $(ARD_BLD_FQBN) -compile -verbose -libraries ./libs/ -build-path $(PWD)/build

all: Minesweeper.ino
	@$(ARD_BLD) $(ARD_BLD_FLAGS) $<
clean:
	@rm -rf build/*
