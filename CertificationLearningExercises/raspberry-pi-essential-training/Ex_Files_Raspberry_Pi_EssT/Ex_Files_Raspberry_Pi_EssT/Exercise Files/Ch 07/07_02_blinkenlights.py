# Code for LinkedIn Learning Raspberry Pi Essential Training
# 07_02 First GPIO project

from gpiozero import LED, Button
from time import sleep

pushButton = Button(3)
blinkenlight = LED(21)

while True:
    sleep(1)
    if pushButton.is_pressed :
        blinkenlight.on()
        print("Button is pressed")
    else:
        blinkenlight.toggle()
        print("button is NOT pressed")
