# Autonomous Recylable Trash Sorting System (ARTSS)

## Introduction

This is a project I completed in secondary school between May 2018 to to March 2020, where we built an Autonomous Recyclable Trash Sorting System built by arduiono. 

### Awards

ARTSS has been recognized with several accolades:

- People’s Choice Award, Robofest 2019 World Championship Exhibition Senior
- Best Design Award, 20th Consumer Cultural Study Award: Innovative Design for Sustainable Consumption
- Best Innovation Award, 20th Consumer Cultural Study Award: Innovative Design for Sustainable Consumption
- Exhibitions: London BETT Show, Learning and Teaching Expo 2018

### Background
In recent years, Hong Kong has struggled with recycling efficiency. With three primary types of recycling bins—blue for paper, brown for plastic, and yellow for aluminium cans—the system lacks a provision for tin cans. Observations from liberal studies courses have shown that the recycling habits of Hong Kong's citizens are not effective, with recyclable materials often not being sorted properly, exacerbating the situation.

### Aim
The Automated Recycling Trash Sorting System (ARTSS) was developed with the goal of improving the recycling process in Hong Kong, making it more user-friendly and automating the sorting stage for recycling companies. By addressing issues such as the inaccurate separation of recyclables by citizens and the costly sorting process for the recycling industry, ARTSS aims to provide a comprehensive solution to enhance sustainability efforts in the region.

## Features

ARTSS offers a variety of features to automate and improve the recycling process:

- **Size Sorting**: It sorts out completely non-recyclable trash based on smaller sizes.
- **Metal Separation**: Using a combination of metal detection and magnetism, it can sort tin cans from aluminium cans, which are often incorrectly grouped together.
- **Plastic Sorting**: The system identifies plastic materials, such as bottles, based on their electrical insulation characteristics.
- **Default Sorting**: All other inserted objects are sorted as aluminium cans, ensuring maximal recycling efficiency.

## Technologies Used

The ARTSS project utilized a range of technologies to achieve its recycling automation goals:

- **Arduino**: The core of the system's control logic was programmed using Arduino, a versatile open-source electronics platform based on easy-to-use hardware and software.

- **Tinkercad**: For 3D modeling, Tinkercad was employed. This browser-based program allowed for the creation and editing of the digital prototypes for various components of ARTSS.

- **3D Printing**: Critical components of ARTSS were brought to life using 3D printing technology. This allowed for rapid prototyping and testing of parts, ensuring that each piece met the necessary specifications for optimal performance.


### Images


## Installation

To set up the ARTSS system, follow these steps:

1. **Assemble the hardware**: Connect the Arduino board, ultrasonic sensor, metal detector, servo motors, and reed switch according to the wiring diagram provided in the ARTSS Handbook.

2. **Check wire conditions**: Use a multimeter to ensure all wires are in good condition and can transmit electricity properly, as outlined in the handbook.

3. **Load the Arduino sketch**: Connect your computer to the Arduino board using the appropriate cable, open the Arduino IDE, and upload the provided `.ino` file to the board.

4. **Test individual components**: Follow the testing procedures in the ARTSS Handbook to verify the functionality of each component, including the ultrasonic sensor, metal detector, servo motors, and reed switch.

5. **Finalize assembly**: Secure all components in their designated positions as per the design specifications, ensuring that all moving parts are free of obstructions and the system is stable.

## Usage

Once the ARTSS system is installed, initiate the sorting process with the following steps:

1. **Power up the system**: Ensure that the Arduino board and all connected components are powered.

2. **Start the sorting program**: The main program, 'Finalize presentation 3.0', will manage the sorting process. Monitor the serial output for status updates and any error messages.

3. **Insert waste items**: Add waste items into the system. The ARTSS will sort plastic bottles, aluminum cans, and tin cans into their corresponding recycling bins.

4. **Maintenance checks**: Regularly perform maintenance checks as detailed in the handbook to ensure the system continues to function optimally.
   
## Design

![ARTSS System Diagram](/path/to/image.png)
*Figure 1: ARTSS System Component Diagram*

The ARTSS system utilizes a combination of rotating and non-rotating parts to sort recyclables:

- **Metal Detector**: Identifies and separates metals from non-metals.
- **Main Wheel**: Equipped with magnets to separate tin (ferrous) from aluminum (non-ferrous).
- **Servo Motors**: Control the movement of the main wheel and the trapdoor for accurate sorting.
- **Reed Switch**: Ensures precise positioning of the main wheel for the sorting process.

## Troubleshooting

Refer to the ARTSS Handbook for detailed troubleshooting steps for each component. Common issues and their solutions include:

- **Wiring Issues**: If the system is not functioning correctly, check all connections and replace any faulty wires.
- **Sensor Problems**: Use the Arduino IDE to upload test sketches and verify the functionality of the ultrasonic sensor and metal detector.
- **Servo Motor Malfunctions**: If a servo motor is not moving, check the wiring and replace the motor if necessary.

## Contributors

- **Supervisors**: Mr. Jerome Tam, Mr. Eric Chen
- **Project Leader**: Enoch Cheng
- **Team Members**: Karen Zhang, Jun Chan, Cheuck Kin Chan, Aidan Chan, Joshua Yung

