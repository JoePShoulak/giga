FQBN = arduino:mbed_giga:giga
FILE = giga.ino
PORT = COM3
BAUDRATE = 9600

.PHONY: all install compile upload monitor
.PHONY: a i c u m

all: compile upload monitor

install:
	arduino-cli lib install ArduinoGraphics
	arduino-cli lib install Arduino_GigaDisplay

compile:
	arduino-cli compile --fqbn $(FQBN) $(FILE)

upload:
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(FILE)

monitor:
	arduino-cli monitor -p $(PORT) --config baudrate=$(BAUDRATE)

a: all
i: install
c: compile
u: upload
m: monitor
