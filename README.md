## 💰 Support My Work

If you find this project helpful and want to support my work, you can contribute through:

### 💎 Crypto Donations
| ![Tether](https://img.shields.io/badge/Tether-50AF95?style=for-the-badge&logo=tether&logoColor=white) | 
|:---:|
| `THaG7n6AdFADW5fqVWBe45uD1xTBiyWd3r` |
| USDT (TRC20 Network) |


### Buy Me a Coffee
[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/hexcode64319)

# 🏗️ Arduino Simple Weighing and Calibration System

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![HX711](https://img.shields.io/badge/HX711-Supported-green.svg)](https://github.com/bogde/HX711)

<div align="center">
  <img src="https://i0.wp.com/circuits4you.com/wp-content/uploads/2016/11/Load_Cell_Interface_Arduino.png?resize=768%2C476&ssl=1" width="400" alt="HX711 Connection Diagram"/>
  <p><em>HX711 Connection Diagram</em></p>
</div>

## 📝 Description

This repository contains Arduino code for implementing a professional weighing system with calibration functionality. The project is designed to work with load cells and provides both calibration and weighing capabilities, making it perfect for DIY scales and industrial applications.

## 🌟 Key Features

- ⚖️ Precise load cell calibration
- 📊 Digital weight measurements
- 🔄 Real-time weight monitoring
- 📱 User-friendly interface
- 💾 Persistent calibration storage
- 🛠️ Easy setup and configuration

## 📁 Project Structure

```
arduino-weighing-system/
├── calibration/
│   └── calibration.ino      # Calibration setup sketch
└── simple_weighing/
    └── simple_weighing.ino  # Main weighing system
```

## 🔧 Hardware Requirements

Component | Purpose
----------|----------
Arduino Board | Main controller (Uno/Nano recommended)
HX711 Module | Load cell amplifier
Load Cell | Weight sensor (max 5kg/10kg/20kg)
LCD Display | Optional for visual output
Jumper Wires | For connections

## 📥 Software Dependencies

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8.x or newer)
- [HX711 Arduino Library](https://github.com/bogde/HX711) (Latest version)

## 🔌 Wiring Diagram

HX711 Pin | Arduino Pin
----------|------------
VCC | 5V
GND | GND
DT  | Digital Pin 2*
SCK | Digital Pin 3*

*Pins can be configured in the code

## 📋 Setup Guide

1. **Hardware Assembly**
   - Connect load cell to HX711 following the color codes
   - Wire HX711 to Arduino according to the table above
   - Power up the system

2. **Software Setup**
   ```bash
   1. Install Arduino IDE
   2. Install HX711 library
   3. Upload calibration sketch
   4. Follow calibration procedure
   ```

## 🎯 Usage Instructions

### 🔍 Calibration Mode
1. Load the calibration sketch
2. Open Serial Monitor (9600 baud)
3. Follow on-screen instructions
4. Save your calibration factor

### ⚖️ Weighing Mode
1. Input calibration factor
2. Upload weighing sketch
3. Begin measurements
4. Monitor through Serial/LCD

## 🤝 Contributing

We welcome contributions! Here's how you can help:

1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Open a Pull Request

## 👥 Credits

Created with ❤️ by [Cracked-oss](https://github.com/Cracked-oss)

## 🆘 Support

Need help? We're here for you!

## 📫 Connect With Me
[![Telegram](https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white)](https://t.me/Hex_Code)
[![Facebook](https://img.shields.io/badge/Facebook-%231877F2.svg?style=for-the-badge&logo=Facebook&logoColor=white)](https://www.facebook.com/hexcode.832203/)

---
<div align="center">
Made with 🛠️ and passion for the Arduino community
</div>
