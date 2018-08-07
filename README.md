
# CJMCU-3212

![CJMCU-3212](https://i.imgur.com/z7lX4eF.jpg)

## Description 

Guide to flash ESP8266 in CJMCU-3212. 

For the guide we are going to use https://github.com/spacehuhn/wifi_ducky 

## Resources used

https://github.com/spacehuhn/wifi_ducky

https://github.com/espressif/esptool


## 1: Put the CJMCU as ESP programmer

The first thing to do is put the arduino as a programmer, so, in Arduino put 

  *Tools-> Board-> Arduino Leonardo*

  *Tools-> Port -> (the corresponding port)*

And upload this [sketch](https://github.com/puckk/CJMCU-3212/blob/master/step1.ino)


## 2: Upload the sketch on the ESP

download the 4m binary from [here](https://github.com/spacehuhn/wifi_ducky/releases)

Now, the Magic (or the solution that worked for me):

Disconnect the CJMCU.

Bridge the two metal circles on the top right before connect the CJMCU to the USB. (image)

![](https://i.imgur.com/5ght4Uu.jpg)

Once connected, run in esptool:

```
python esptool.py --trace   --baud 150200 --port /dev/ttyACM0 write_flash 0x00000 ../esp8266_wifi_duck.ino.generic.bin --flash_size 4MB --flash_mode dio --flash_freq 40m
```

Now, disconnect the bridge.


## 3: Upload the wifi ducky sketch

Now, upload https://github.com/spacehuhn/wifi_ducky/blob/master/arduino_wifi_duck/arduino_wifi_duck.ino

Ready, wifi_ducky is working =)

I hope this solution works for you, any problem ask me
