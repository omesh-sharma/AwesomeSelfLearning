# Raspberry Pi Essential Training

import machine
import utime

pico_led = machine.Pin(25, machine.Pin.OUT)
pico_pshbtn = machine.Pin(5, machine.Pin.IN)

while True:
    if pico_pshbtn.value() == 1:
        pico_led.value(1)
        print("switch is closed")
    else:
        pico_led.toggle()
        print("switch is open")
        
    utime.sleep(1)
    