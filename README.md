# ASL Flex Glove

![Arduino](https://img.shields.io/badge/microcontroller-Arduino-blue)
![C++](https://img.shields.io/badge/code-C++-brightgreen)
![PCB](https://img.shields.io/badge/design-PCB-orange)

## 📑 Table of Contents
- [Overview](#overview)
- [Hardware](#hardware)
- [Code](#code)
- [PCB & Circuit Schematic](#pcb--circuit-schematic)
- [Future Improvements](#future-improvements)
- [Author](#author)

---

## Overview
The **ASL Flex Glove** is a personal project translating **American Sign Language (ASL)** letters using **flex sensors** and a **microcontroller**.  
It demonstrates how sensor data and embedded programming can be applied to create **assistive technology** for improved communication and accessibility.

---

## Hardware
- Flex sensors (5x, one per finger)  
- Microcontroller: Arduino Nano (or equivalent)  
- 10kΩ resistors for voltage dividers  
- Power source (USB or battery pack)  
- PCB (final version replaces breadboard)  
- Optional: Bluetooth/Wi-Fi module  

---

## Code
Arduino code is included in the ASL-Translation-Project.ino file.
It reads flex sensor values and maps them to ASL letters.

---

## PCB & Circuit Schematic
- Circuit Schematic: see `hardware/circuit_schematic.png`  
- PCB Layout: see `hardware/pcb_layout.png`  
- 3D PCB Simulation: see `hardware/pcb_3d_view.png`  

---

## Future Improvements
- Calibrate flex sensors for higher accuracy  
- Expand recognition from letters to full words/phrases  
- Add wireless data transfer to a mobile app  
- Develop a wearable glove using 3D printing  
- Miniaturize PCB for a portable, production-ready design  

---

## Author
**Sai Nelluri** – Personal engineering project focused on embedded systems, sensor integration, and assistive technology.
