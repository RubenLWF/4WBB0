# 4WBB0 - Engineering Design, Group 6

This repo was used for keeping and maintaining the software for our engineering desing project.

## About the project

In the project our group was tasked with designing and creating an innovative product related to sustainability. We came up with a device that would automatically open or close your blinds based on the temperature and sun intensity.

## Implementation

### Hardware
To realize our idea we have developed two seperate units.
- **Inside unit:** This unit exists of an ESP32 micro-controller with an AM2320 temperature sensor and a stepper motor to move the blinds in a 3D printed housing. 
- **Outside unit:** This unit exists of an ESP32 micro-controller with an AM2320 temperature sensor and an BH1750 light intensity meter.

### Software
The device is controlled using a webapp mounted on a Google Firebase realtime database. After logging in you can monitor the inside and outside temperature and the sun intensity in real time on the control panel. You can set a target temperature at which you want the blinds to close to prevent the room from heating up any further. You can also see the real time status of the blinds (Open/Closed). It is also possible to open or close the blinds remotely from our control panel.</br>

**Login Page:**</br>
![Login Page](/images/login.PNG)</br>

**Control Panel:**</br>
![Control Panel](/images/controlPanel.PNG)