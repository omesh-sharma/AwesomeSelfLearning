#!/bin/bash

# don't forget to install libgpiod
# sudo apt-get install gpiod libgpiod-dev libgpiod-doc

pushButton=21
blinkenLight=3
bl_state=0

#chipName=$(awk -F"[][]" '/gpiochip0/ {print $2}' <( gpiodetect))
chipName=gpiochip0

while :
do
sleep 1
if [[ $(gpioget $chipName $pushButton) == "0" ]]
then
echo "Button is pressed"
gpioset $chipName $blinkenLight=1
else
echo "Button not pressed"
if [ $bl_state == 0 ]
then
gpioset $chipName $blinkenLight=1
bl_state=1
else
gpioset $chipName $blinkenLight=0
bl_state=0
fi
fi
done
