# Custom Macros Bluetooth Keyboard

## Table of Contents

- [Overview](#overview)
- [Firmware](#firmware)
- [Hardware](#hardware)
- [Mechanical and 3D Models](#mechanical)

## Overview <a name = "overview"></a>

This is an ESP32 project, in which a custom bluetooth macro keypad was made. The idea here is to put as many "akwards shortcuts" in the OS or some custom software, such as CTRL+ALT+T, CTRL+ALT+I, and so on. The user's ability to change the shortcuts associated with the keys might be an feature later in the project.


Since it still in the making, some of the topics below are incomplete by now.

## Firmware <a name = "firmware"></a>

The embedded firmware is the simplest part of this project, the hardest tasks are done by the BleKeyboard ESP library. The main routine consists in a loop checking if the keypad has been pressed and triggering one of the twelve shortcuts and displaying it on the Oled display. 
Since I was getting some erroneous readings using the Vkey library I made some changes on their files to better work with ESP's ADC.

## Electronic Hardware <a name = "hardware"></a>

Electronic hardware used on this project:


* ESP32 WROOM Module
* Vkey Voltage keypad
* Oled Display (128x64)
* USB to Uart Bridge (CP2102) [Not yet implemented]
* Battery Manager Module [Not yet implemented]
* LiIon Battery Pack [Not yet implemented]

> (Schematics and PCB layout soon)

## Mechanical and 3D Models <a name = "mechanical"></a>

The basic 3D design was created using the Vkey dimensions. The STL files will be availble once the final product is made.