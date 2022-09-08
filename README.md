# Bachelor's Final Project
*Presented on Wednesday, September 6, 2017*

Gyroscopes detect, measure, and maintain orientation and angular velocity; their applications range from aircraft to smartphones. To better understand how these devices work, this project was completed by simulating their performance and wiring and programming an MPU6050 module, an integrated 6-axis Motion Tracking device combining a 3-axis gyroscope and a 3-axis accelerometer, using an Arduino Nano board. 

After researching gyroscope sensors, existing elements in Proteus Design Suite were used to simulate their performance. Three variable resistances, whose changes represented rotation along one of the three axes, x, y, and z, were connected to an ATMEGA 16A microcontroller. Also, three stepper motors connected to the microcontroller showed these rotations by moving clockwise or counter-clockwise according to the resistances' changes. These elements were coded in the C language, using CodeVisionAVR, an Integrated Development Environment for the XMEGA Micro-controllers. 

Finally, an MPU6050 module was wired to an Arduino Nano board, with an ATmega328 as its microcontroller, through the Inter-integrated Circuit (I2C) interface. After installing the necessary libraries on Arduino IDE, the code to operate the MPU6050 and give a visual presentation was uploaded and run. As a result, a small 3-D plane schematic appeared on the screen that moved according to the module's movements. 

### Notes:
`simulation.c` : codes for the simulation using three variable resistances and stepper motors </br>
`mpu.c` : codes for the simulation of MPU6050 </br>
`simulation.png` and `mpu.png` : screenshots of the Proteus Design Suite environment </br>
`Arduino Circuit Schematic.png` : Wiring of the Arduino Nano board to theMPU6050 module (Source of Image: https://www.instructables.com/MPU-6050-Tutorial-How-to-Program-MPU-6050-With-Ard/)</br>
*Source code for Arduino*: https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050
