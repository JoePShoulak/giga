FQBN = arduino:mbed_giga:giga
FILE = giga.ino
PORT = COM3

all: compile upload

compile:
	arduino-cli compile --fqbn $(FQBN) $(FILE)

upload:
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(FILE)
