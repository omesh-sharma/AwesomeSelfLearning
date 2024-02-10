# Raspberry Pi Essential Training - Sense Hat example

# documentation for sense hat python library at https://github.com/astro-pi/python-sense-hat

# from sense_emu import SenseHat # select the sensehat emulator
from sense_hat import SenseHat # select the physical sensehat

sense = SenseHat()

while True:
    cmpToCol = int(sense.compass/360 * 255)
    print(cmpToCol, 255-cmpToCol)
    sense.clear(cmpToCol, 0, 255-cmpToCol)

    
