# Autonomous Robot

![Tools](https://skillicons.dev/icons?i=arduino,cpp)

This project is my first robot, built and coded from scratch with no prior robotics experience. While I had a background in C/C++, I had never worked with Arduino, servos, or sensors before. I wanted to challenge myself by building something tangible and functional — this robot is the result.  

It marks the beginning of my robotics journey, combining coding, electronics, and 3D printing into a single project.  

---

## Project Overview

The robot is an Arduino Uno–based autonomous car that uses:  
- Two continuous rotation servos for movement  
- An ultrasonic sensor for obstacle detection  
- Simple decision logic to move forward and turn when an object is detected  

When the sensor detects an obstacle within a set distance, the robot automatically turns right to avoid it, then continues moving forward.

---

## Features

- Autonomous forward movement with obstacle avoidance  
- Ultrasonic distance sensing  
- Servo motor control for basic navigation  
- My introduction to robotics and embedded systems  

---

## Code

The robot is programmed in C++ using the Arduino framework.  
Key functions include:  
- **`readDistanceCm()`** – reads the distance from the ultrasonic sensor  
- **`forward()`** – drives both wheels forward  
- **`turnRight()`** – executes a right turn maneuver  
- **`ensureAttached()` / `ensureDetached()`** – safely manage servo states  

The full source code is included in this repository under [`main.cpp`](./main.cpp).

---

## Photos & Videos  
  ![Robot](./assets/IMG_0052.png)
  Click to watch:
  [![Watch the robot in action](https://img.youtube.com/vi/Cd_WDKgfvsY/0.jpg)](https://www.youtube.com/shorts/Cd_WDKgfvsY)

---

## Summary

This robot is where I started learning robotics. 

Through this project I learned how to:  
- Control servo motors using Arduino  
- Read sensor input and react in real time  
- Combine 3D printing, hardware, and software into a single system  

This is just the start for me

---
See the video of me making the robot here: https://www.youtube.com/watch?v=83ekn_0ZCv4
**Made by Cole Puls**
