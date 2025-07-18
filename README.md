# arduino-proteus-projects
A collection of Arduino-based projects developed during my internship, including voice-controlled home automation systems and an ultrasonic distance meter with Proteus simulations.
---

## 📋 Index

1. [Android + Bluetooth + Arduino Pick and Place Robot](#project-1-android--bluetooth--arduino-pick-and-place-robot)
2. [Voice-Controlled Home Automation](#project-2-voice-controlled-home-automation)
3. [Ultrasonic Distance Meter Using Arduino](#project-3-ultrasonic-distance-meter-using-arduino)

---
## 📌 Project 1: Android + Bluetooth + Arduino Pick and Place Robot

![Three Axis Arm](images/three_axis_arm.png)

### 📝 Description

This bot is controlled by an Android app which sends commands via Bluetooth. Servo motors control a three-axis robotic arm to perform pick-and-place operations.

The project simulates a basic robotic arm structure using servos. Though it is not industrial-grade, it is effective for practice and understanding robotic movement. Enhanced accuracy can be achieved with better servos, more precise control algorithms, and robust components.

### 🧩 Components

- [Arduino Uno](#)  
- [Bluetooth Module (HC-05)](#)  
- [Servo Motors](#)  
- Breadboard  
- Jumper Wires  

### 🔌 Pin Diagram

| Arduino Pin | Connection            |
|-------------|------------------------|
| 9           | Base Arm Servo         |
| 10          | Middle Arm Servo       |
| 11          | Gripper Arm Servo      |
| RX          | TX (HC-05 Bluetooth)   |
| TX          | RX (HC-05 Bluetooth)   |

📷 **Pin Diagram Image:**  
![Pin Diagram](docs/pindiagram/project_1.png)

### 💻 Simulation Output

![Output 1](docs/results/Project_1_Output_1.JPG)  
![Output 2](docs/results/Project_1_Output_2.JPG)

---
