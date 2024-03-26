FQBN = arduino:mbed_giga:giga
FILE = giga.ino
PORT = COM21

all: compile upload

install:
	@arduino-cli lib install ArduinoGraphics
	@arduino-cli lib install Arduino_GigaDisplay

compile:
	@arduino-cli compile --fqbn $(FQBN) $(FILE)

upload:
	@arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(FILE)
