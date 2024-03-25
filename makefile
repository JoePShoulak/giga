FQBN = arduino:mbed_giga:giga
FILE = giga.ino

all: compile upload

compile:
	arduino-cli compile --fqbn $(FQBN) $(FILE)

upload:
	arduino-cli upload -p COM3 --fqbn $(FQBN) $(FILE)
