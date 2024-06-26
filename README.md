[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/2TmiRqwI)
# RoboWave Project

    * Team Name: RoboWave
    * Team Members: Jessi Jha, Truong (Winston) Nguyen
    * Github Repository URL: https://github.com/ese3500/final-project-jessi_winston/tree/main
    * Github Pages Website URL: https://ese3500.github.io/final-project-jessi_winston/
    * Description of hardware: 2 Atmega328PBs, 2 ESP32 Feathers, Accelerometer, 4 Servo Motors, 1 Flex Sensor 

<!-- [comment]: <> ## Final Project Proposal

### 1. Abstract
This project enables users to manipulate a robotic arm through intuitive hand movements. By leveraging sensors embedded within a wearable glove, the system captures and interprets gestures, translating them into precise mechanical responses. The goal is to create a seamless interface that feels like an extension of the user’s body, fostering a natural interaction with the robot arm. 

### 2. Motivation

Robots that mimic human motion in real-time can have exciting and societally beneficial applications - from helping clean hazard sites to assisting individuals with limited mobility, these robots can be utilized in a variety of ways.

Our goal/solution with this project is to create a robot arm that uses a microcontroller, servomotor, accelerometer, and other potential add-ons to mimic human motion. This project would serve as a stepping stone to developing more involved robots that can aid in situations such as disaster/hazard relief or mobile assistance.

### 3. Goals

By the end of the project, we would like to have a robotic arm that utilizes sensor data to create motion.

We will design a system where the robotic arm responds to changes in acceleration of the user's hand, such that when the user moves their hand in a certain way, the servo motors that control the arm change their PWM accordingly.

### 4. Software Requirements Specification (SRS)
#### 4.1 Overview
This project aims to develop a software interface for a gesture-controlled robotic arm. The software will interpret hand gestures captured by a robotic glove equipped with flex sensors and an accelerometer, translating them into precise movements of a six-axis robotic arm

#### 4.2 Users
The primary users of this software will be hobbyists, educators, and researchers interested in robotics, human-machine interaction, and gesture control technologies. Users with a basic understanding of embedded programming and hardware assembly can operate and customize the robotic arm.

#### 4.3 Definitions, Abbreviations
Here you will define any special terms acronyms or abbreviation you plan to use for software

#### 4.4 Functionality

- SRS 01: The system shall measure the bend of flex sensors with a resolution of 10 bits, and the data shall be sampled every 50 milliseconds +/- 5 milliseconds.
  
- SRS 02: The accelerometer shall measure 3-axis acceleration with 16-bit depth every 100 milliseconds +/- 10 milliseconds.
  
- SRS 03: The software shall map the sensor data to servo positions with a precision of 1 degree.
  
- SRS 04: The software shall update the robotic arm’s position in response to gesture changes within 50 milliseconds.
  
- SRS 05: The system shall communicate via Bluetooth (or Wifi for Blynk app control), sending control signals from the glove to the robotic arm with a latency of less than 100 milliseconds.
  
- SRS 06: The system shall implement a hard stop feature to prevent servo motors from exceeding their maximum angle, protecting the gears from stripping.
  
- SRS 07: The software shall not permit gesture commands that would cause the robotic arm to exceed its physical limitations.
  
- SRS 08: The software shall not process input data that falls outside of predefined thresholds for sensor readings.

### 5. Hardware Requirements Specification (HRS)

- HRS 01 – This robotic arm mechaniism shall be based on ATmega328P microcontroller.

-  HRS 02 - This project shall use an ESP32 to receive data from the flex sensors and accelerometer. The sensor shall detect changes in resistace based on the movement of the users fingers. This unit will  communicate with the Atmega.

- HRS 03 – An accelerometer shall be used for to detect the motion of the user's hand. This sensor shall use measurements of gravity and magnetic force of orient the position of the glove. This compment will commnicate with the ESP32.

- HRS 04 – Flex sensors shall be used for to detect the motion of the user's hand.  The sensor shall detect This compment will commnicate with the ESP32.

- HRS 05 - Servo motors shall be used to change the direction and motion of the robotic arm mechanism. These motors shall communicate with the Atmega. The will be poweer

- HRS 06 - A servo motor driver shall be used to power the servo motors. The Atmega328PB will not be able to supply power to each of the motors; the driver shall supply voltages up to 36 V. 

- HRS 07 - This project shall use a 3D printed robotic arm model. This model shall be controlled by the servo motors.

### 6. MVP Demo

By the MVP Demo, the arm will be able to move with respect to the the motion of the user.

### 7. Final Demo

By the final we would like to include fun add ons to the arm. We want to toggle the arm between being motion controlled and being controlled remotely. Additionally, we want to include a buzzer that will emit frequencies based on the position of the arm.

### 8. Methodology

We will first focus on ensuring we are able to control the servo motors from sensor data. Then we will consider how we want the motors to move based on sensor data; at this point we will begin to assemble the arm. Once the main functionality has been implemented, we will begin to consider other fun add ons our arm can use. 

### 9. Components

- Robotic Arm:
The robotic arm will be controlled by servos, which will be powered by the Atmega. The Atmega will recieve data from the ESP32, which communicates with the flex sensors and accelerometers. The sensors  will determine the PWM of the motors. The robotic arm will be 3D printed.

- Glove:
The glove will contain an accelerometer and flex sensors. The flex sensor will be positioned on the fingers of the glove, while accelerometers will be placed on the back of the hand. Both of these sensors will be connected to the ESP32.

### 10. Evaluation

- Gesture Recognition Accuracy: The software should correctly interpret hand gestures with an accuracy rate of at least 90%. This will be measured by comparing the intended gesture against the gesture recognized by the system over a series of tests.
- Response Time: The system should respond to human's gestures in a timely manner (less than 5 seconds). This will be quantified by measuring the time elapsed from the gesture initiation to the robotic arm’s movement.
- User Task Completion Rate: Users should be able to complete predefined tasks using the robotic arm with a success rate of 90% or higher (such as picking a block). This metric will be assessed through user testing, where participants attempt to complete tasks and their success rates are recorded.

### 11. Timeline

We will use a demonstration where the user needs to control the arm with the glove to pick up the block. If the user is able to control the arms motion in their manner, we will consider the project a success.

| **Week**            | **Task** | **Assigned To**    |
|----------           |--------- |------------------- |
| Week 1: 3/24 - 3/31 |  Project Kickoff & Requirement gathering    |  Jessi and Winston                  |
| Week 2: 4/1 - 4/7   |  - Create firmware architecture and begin coding for a basic skeleton <br> - Design and print some 3D-printed arm parts        |  Jessi (3D printing)  and Winston (firmware skeleton)               |
| Week 3: 4/8 - 4/14  |  - Assemble all hardware components of robotic arm and the circuit <br>- Conduct testing of the arm response to sensor <br>- Update/ modify prototype     |  Jessi and Winston     |
| Week 4: 4/15 - 4/21 |- Optimize firmware architecture <br> - Improve the response of the arm and add add-on features     |  Jessi and Winston                     |
| Week 5: 4/22 - 4/26 |- Finalize the design           |    Jessi and Winston                |

### 12. Proposal Presentation

Add your slides to the Final Project Proposal slide deck in the Google Drive.

-->

## Final Project Report

### 1. Video

https://drive.google.com/file/d/1YAaOwP5Faa_h7_kkFoD2hJd_nlYyPl-F/view?usp=drivesdk

### 2. Images

![alt text](image.png)

Arm and glove together!

![alt text](image-1.png)

Just Arm configuration. Included in the are the four servos, an Atmega, and an ESP. The ESP recieves data take from the sensors, sends it to the Atmega, and then the Atmega uses the reading to determine the position of the motors.

![alt text](image-3.png)

Just glove configuration. The glove consists of a flex sensor, GPU6050 (accelerometer and gyroscope combined), an Atmega, and an ESP. The sensor readings are sent to the Atmega which are sent to the ESP, which is then transmitted via Wifi communication to the robotic arm. 

### 3. Results

Results for the Demo:
On demo day, we presented  a robotic arms with 4 degrees of freedom controlled by a wired "glove" connected with an accelerometer and flex sensor. 

Results for the Video:
In the video, we presented a robotic arms with 4 degrees of freedom controlled by a wireless "glove" connected with an accelerometer and flex sensor. 

#### 3.1 Software Requirements Specification (SRS) Results


- SRS 01: The system shall measure the bend of flex sensors with a resolution of 10 bits, and the data shall be sampled every 50 milliseconds +/- 5 milliseconds.

   - Final Project Reflection: We sampled the flex sensor every 500 milliseconds to ensure the arm movement is smooth without being reflected by the great variance of sensor readings, but apart from that this requirement was fulfilled.
  
- SRS 02: The accelerometer shall measure 3-axis acceleration with 16-bit depth every 100 milliseconds +/- 10 milliseconds.

  - Final Project Reflection: We sampled the accelerometer every 500 milliseconds, but apart from that this requirement was fulfilled.
  
- SRS 03: The software shall map the sensor data to servo positions with a precision of 1 degree.

  - Final Project Reflection: We decided to map the sensor data using discrete intervals as opposed to a continuous interval. This design choice was to reduce noise/variation in the sensor readings (we didn't want the arm to be too sensitive). 
  
- SRS 04: The software shall update the robotic arm’s position in response to gesture changes within 50 milliseconds.

  - Final Project Reflection: The response to gesture changes was about 500 milliseconds, but apart from that this requirement was fulfilled.
  
- SRS 05: The system shall communicate via Bluetooth (or Wifi for Blynk app control), sending control signals from the glove to the robotic arm with a latency of less than 100 milliseconds.

  - Final Project Reflection: SRS 05 was not fulfilled for the final demp. We decided to omit this portion to ensure that the data coming from the sensors and being sent to the servos was correctly synchronized. 
  
- SRS 06: The system shall implement a hard stop feature to prevent servo motors from exceeding their maximum angle, protecting the gears from stripping.

  - Final Project Reflection: Although we don't have a "hard stop" feature, based on the range of the servo and arm motion, we limited the OCRnA and OCRnB values (which determine the angles of the servos). 
  
- SRS 07: The software shall not permit gesture commands that would cause the robotic arm to exceed its physical limitations.

  - Similar to SRS specification 07 - we don't have a "gesture commands" feature, however, bosed on the range of the servo and arm motion, we limited the OCRnA/OCRnB values (which determine the angles of the servos). This is also related to our use of discrete OCRnA/OCRnB values (as opposed to a continuous range). 
  
- SRS 08: The software shall not process input data that falls outside of predefined thresholds for sensor readings.

  - Final Project Reflection: SRS 08 was fulfilled


#### 3.2 Hardware Requirements Specification (HRS) Results

- HRS 01 – This robotic arm mechanism shall be based on Atmega328PB microcontroller.

   - Final Project Reflection: HRS 01 was fulfilled.
  
- HRS 02 - This project shall use an ESP32 to receive data from the flex sensors and accelerometer. The sensor shall detect changes in resistace based on the movement of the users fingers. This unit will communicate with the Atmega.

   - Final Project Reflection: HRS 02 was modified. We used another Atmega to recieve data from the flex sensor and the accelerometer, which then send the data to the ESP 32. This was done to add complexity to the project, using bare metal serial communication. However, during the final demo, this requirement was not implemented due to last minute complications. However, in the demo video, the full functionality of this requirement is demonstrated. 

- HRS 03 – An accelerometer shall be used for to detect the motion of the user's hand. This sensor shall use measurements of gravity and magnetic force of orient the position of the glove. This compment will commnicate with the ESP32.

   - Final Project Reflection: HRS 03 was fulfilled.

- HRS 04 – Flex sensors shall be used for to detect the motion of the user's hand.  The sensor shall detect This compment will commnicate with the ESP32.

   - Final Project Reflection: HRS 04 was fulfilled.

- HRS 05 - Servo motors shall be used to change the direction and motion of the robotic arm mechanism. These motors shall communicate with the Atmega.

   - Final Project Reflection: HRS 05 was fulfilled.

- HRS 06 - A servo motor driver shall be used to power the servo motors. The Atmega328PB will not be able to supply power to each of the motors; the driver shall supply voltages up to 36 V.

   - Final Project Reflection: HRS 06 was not fulfilled. It turns out that the servo driver was not nessecarily needed. We used a wall power supply to power the motors, while the atmega controlled their PWM.  

- HRS 07 - This project shall use a 3D printed robotic arm model. This model shall be controlled by the servo motors.

   - Final Project Reflection: HRS 07 was fulfilled.

- NEW: HRS 08 - This project shall use a logic level shifter to ensure functional communication between the ESP32 and the Atmega328PB; these two devices have different power levels, 3.3V and 5V, respectively. 

### 4. Conclusion

This project taught us a lot about communication between deveices - mainly, I2C communication, which we used to send data from the accelerometer to the Atmega, and UART communication, which was used to send data in between the ESP32 and ATmega. These two communication protocols were probably the least utilized in the prior labs, so there was a lot of learning on the fly with respect to these concepts. As can be expected, we encountered challenges with regards to these aspects. Our primary struggles related to utlizing different serial ports to print and send data; it was nessecary to configure two different ports to have include these functionalities, and this required editing the UART library code. Additionally, we had to learn the structure of I2C protocals, which requires an IMU driver to communicate with I2C Driver (we used a I2C library and an IMU Driver found on git, more on this later). The I2C driver is hardware specific, and was implemented to read and write data between the accelerometer and the Atmega.

We also ran into some challenges regarding the servo motors. Initially, we anticipated using a servo motor driver, however, because we recieved the driver later than expected, we decided to use seperate power supplies for the motors. Additionally, since we were driving four motors, we needed to the utilize two timers, since each timer has two output compare registers - OCRnA and OCRnB. Taken together, these solutions allowed us to drive 4 motors to control the arm.  

By Demo day, the communication between the sensors and the Atmega was relatively smooth. And we were proud that we were able to ensure solid functionality of these protocols, since these are vital processes to the control of the arm. The PWM of the motors are controlled by the sensor readings, so ensuring realible connection from sensor to servo was critical. That being said, by demo day, there were ways in which we fell short. Mainly, we did not include wifi communication in the final demo. While we did have wifi communcation between the glove and arm before our demo, there were sychronization issues, so we decided to temporarily omit wireless communication. We brought Wifi communication back for the final video, which can be seen at the link above. 

In terms of project next steps, it would be useful to add remote control communication, perhaps through Blynk IOT. Additionally, making the arm more strucurally sound would also add to the longevity of the project. 

## References

Fill in your references here as you work on your proposal and final submission. Describe any libraries used here.

3D Printed Arm: https://www.instructables.com/EEZYbotARM/

### IMU Driver: 

The IMU driver we used was designed to interface with our accelerometer (the MPU6050). There are 7 methods in this library, with each method functionality listed below:

- Initialization (MPU_init()): This function initializes communication with the MPU6050 sensor via the I2C protocol. It sets the power management register (PWR_MGMT_1) to ensure the sensor is ready for communication.


- Write Data (MPU_write(uint8_t u8addr, uint8_t u8data)): This function writes data to a specific register within the MPU6050 sensor. It utilizes I2C communication to send the address of the register followed by the data to be written.


- Read Data (MPU_read(uint8_t u8addr, int16_t *int16data)): This function reads data from a specified register within the MPU6050 sensor. It initiates communication with the sensor, requests data from the desired register, and then retrieves the data. The data is returned as a 16-bit integer.


- Timer Initialization (timer2_initialize()): This function initializes Timer 2, setting it up to generate interrupts at regular intervals. This is commonly used for timing purposes in microcontroller applications.


- =Overflow Interrupt Service Routine (ISR(TIMER2_OVF_vect)): This interrupt service routine is executed when Timer 2 overflows. It then increments the overflow counter variable.


- Reading MPU6050 Data (get_MPU_readings()): This function reads accelerometer and gyroscope data from specific registers within the MPU6050 sensor. It then converts the raw sensor data into meaningful units (e.g., acceleration in meters per second squared and angular velocity in degrees per second). Additionally, it calculates the rotational angles around the X and Y axes (Roll and Pitch) using trigonometric functions.


- Yaw Calculation (yaw_calculation()): This function calculates the yaw angle (rotation around the Z-axis) using data from the gyroscope. It updates the yaw angle based on the gyroscope readings and elapsed time between updates, providing continuous tracking of the device's orientation.


### I2C Library:

The I2C library we used provided 7 functions which initalized I2C on the Atmega, allowing the microcontoller to interact with our sensor. Each method is listed below.

- I2C_init(void): Initializes the I2C interface with a 100 kHz clock frequency by setting the appropriate prescaler and bit rate registers.

- I2C_start(void): Generates a START condition on the I2C bus, indicating the microcontroller's intention to communicate as a master device. This function waits for the START condition to be successfully transmitted.


- I2C_stop(void): Generates a STOP condition on the I2C bus, signaling the end of the communication session.


- I2C_write(uint8_t data): Writes a byte of data to the I2C bus. The data is loaded into the data register, and transmission begins after clearing the TWI interrupt flag. This function waits for the transmission to complete.


- I2C_readACK(): Reads a byte of data from the I2C bus and sends an acknowledgment signal to the server device to indicate successful reception. This function waits for the data to be received and the acknowledgment signal to be sent.


- I2C_readNACK(): Reads a byte of data from the I2C bus without sending an acknowledgment signal to the slave device. This function is typically used when reading the last byte of data from a server device.


- I2C_status(void): Retrieves the status of the I2C interface by masking and returning the relevant bits from the status register.