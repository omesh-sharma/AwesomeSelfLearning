# Raspberry Pi Essential Training

import machine
import utime

pico_led = machine.Pin(25, machine.Pin.OUT)

while True:
    pico_led.toggle()
    utime.sleep(1)
    