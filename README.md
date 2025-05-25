# Arduino Simple Weighing and Calibration System

This repository contains Arduino code for implementing a simple weighing system with calibration functionality. The project is designed to work with load cells and provides both calibration and weighing capabilities.

## Project Structure

The project is organized into two main components:

- `calibration/` - Contains the calibration sketch for setting up the load cell
- `simple_weighing/` - Contains the main weighing system implementation

## Features

- Load cell calibration functionality
- Simple weighing system
- Digital weight measurements
- Easy-to-use interface

## Hardware Requirements

- Arduino board (e.g., Arduino Uno, Nano, or similar)
- HX711 load cell amplifier
- Load cell sensor
- LCD display (optional for visual output)
- Connecting wires

## Software Dependencies

- [HX711 Arduino Library](https://github.com/bogde/HX711)
- Arduino IDE

## Setup Instructions

1. Connect the load cell to the HX711 amplifier
2. Wire the HX711 to your Arduino:
   - VCC to 5V
   - GND to GND
   - DT to digital pin (specified in code)
   - SCK to digital pin (specified in code)

3. Install the required libraries through Arduino IDE
4. Upload the calibration sketch first to calibrate your load cell
5. Once calibrated, upload the simple_weighing sketch for regular use

## Usage

### Calibration Mode
1. Upload the calibration sketch
2. Follow the serial monitor instructions
3. Place known weights on the load cell
4. Note down the calibration factor

### Weighing Mode
1. Update the calibration factor in the simple_weighing sketch
2. Upload the sketch
3. Place items on the load cell to measure their weight

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is open source and available under the MIT License.

## Credits

Created and maintained by [Cracked-oss](https://github.com/Cracked-oss)

## Support

For issues, questions, or contributions, please open an issue in the GitHub repository.
