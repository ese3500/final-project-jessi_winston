[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/2TmiRqwI)
# final-project-skeleton

    * Team Name: RoboWave
    * Team Members: Jessi Jha, Winston Nguyen
    * Github Repository URL: 
    * Github Pages Website URL: [for final submission]
    * Description of hardware: (embedded hardware, laptop, etc) 

## Final Project Proposal

### 1. Abstract

In a few sentences, describe your final project. This abstract will be used as the description in the evaluation survey forms.

### 2. Motivation

Robots that mimic human motion in real-time can have exciting and societally beneficial applications - from helping clean hazard sites to assisting individuals with limited mobility, these robots can be utilized in a variety of ways.

Our goal/solution with this project is to create a robot arm that uses a microcontroller, servomotor, accelerometer, and other potential add-ons to mimic human motion. This project would serve as a stepping stone to developing more involved robots that can aid in situations such as disaster/hazard relief or mobile assistance.

### 3. Goals

By the end of the project, we would like to have a robotic arm that utilizes sensor data to create motion.

We will design a system where the robotic arm responds to changes in acceleration of the user's hand, such that when the user moves
their hand in a certain way, the servo motors that control the arm change their PWM accordingly. 

### 4. Software Requirements Specification (SRS)

This project requires the transmission and collection of sensor data from the accelerometers/flex sensors to the Atmega. In addition, we will use PWM changes to control the motors and ADC to convert sensor data to the digital values that will change the PWM; each of these fucntions require the appropriate software componments.

### 5. Hardware Requirements Specification (HRS)

HRS 01 – This robotic arm mechaniism shall be based on ATmega328P microcontroller.

HRS 02 - This project shall use an ESP32 to receive data from the flex sensors and accelerometer. The sensor shall detect changes in resistace based on the movement of the users fingers. This unit will  communicate with the Atmega.

HRS 03 – An accelerometer shall be used for to detect the motion of the user's hand. This sensor shall use measurements of gravity and magnetic force of orient the position of the glove. This compment will commnicate with the ESP32.

HRS 04 – Flex sensors shall be used for to detect the motion of the user's hand.  The sensor shall detect This compment will commnicate with the ESP32.

HRS 05 - Servo motors shall be used to change the direction and motion of the robotic arm mechanism. These motors shall communicate with the Atmega. The will be poweer

HRS 06 - A servo motor driver shall be used to power the servo motors. The Atmega328PB will not be able to supply power to each of the motors; the driver shall supply voltages up to 36 V. 

HRS 07 - This project shall use a 3D printed robotic arm model. This model shall be controlled by the servo motors.


### 6. MVP Demo

By the MVP Demo, the arm will be able to move with respect to the the motion of the user.

### 7. Final Demo

By the final we would like to include fun add ons to the arm. We want to toggle the arm between being motion
controlled and being controlled remotely. Additionally, we want to include a buzzer that will emit frequencies 
based on the position of the arm. 

### 8. Methodology

We will first focus on ensuring we are able to control the servo motors from sensor data. Then we will consider how we want 
the motors to move based on sensor data; at this point we will begin to assemble the arm. Once the main functionality has been 
implemented, we will begin to consider other fun add ons our arm can use. 

### 9. Components

Robotic Arm:
The robotic arm will be controlled by servos, which will be powered by the Atmega. The Atmega will recieve data from the ESP32, which communicates with the flex sensors and accelerometers. The sensors  will determine the PWM of the motors. The robotic arm will be 3D printed.

Glove:
The glove will contain an accelerometer and flex sensors. The flex sensor will be positioned on the fingers of the glove, while accelerometers will be placed on the back of the hand. Both of these sensors will be connected to the ESP32.

### 10. Evaluation

We will use a demonstration where the user needs to control the arm with the glove to pick up the block. If the user is able to control the arms motion in their manner, we will consider the project a success.

### 11. Timeline

This section is to help guide your progress over the next few weeks. Feel free to adjust and edit the table below to something that would be useful to you. Really think about what you want to accomplish by the first milestone.

| **Week**            | **Task** | **Assigned To**    |
|----------           |--------- |------------------- |
| Week 1: 3/24 - 3/31 |          |                    |
| Week 2: 4/1 - 4/7   |          |                    |
| Week 3: 4/8 - 4/14  |          |                    |
| Week 4: 4/15 - 4/21 |          |                    |
| Week 5: 4/22 - 4/26 |          |                    |

### 12. Proposal Presentation

Add your slides to the Final Project Proposal slide deck in the Google Drive.

## Final Project Report

Don't forget to make the GitHub pages public website!
If you’ve never made a Github pages website before, you can follow this webpage (though, substitute your final project repository for the Github username one in the quickstart guide):  <https://docs.github.com/en/pages/quickstart>

### 1. Video

[Insert final project video here]

### 2. Images

[Insert final project images here]

### 3. Results

What were your results? Namely, what was the final solution/design to your problem?

#### 3.1 Software Requirements Specification (SRS) Results

Based on your quantified system performance, comment on how you achieved or fell short of your expected software requirements. You should be quantifying this, using measurement tools to collect data.

#### 3.2 Hardware Requirements Specification (HRS) Results

Based on your quantified system performance, comment on how you achieved or fell short of your expected hardware requirements. You should be quantifying this, using measurement tools to collect data.

### 4. Conclusion

Reflect on your project. Some questions to consider: What did you learn from it? What went well? What accomplishments are you proud of? What did you learn/gain from this experience? Did you have to change your approach? What could have been done differently? Did you encounter obstacles that you didn’t anticipate? What could be a next step for this project?

## References

Fill in your references here as you work on your proposal and final submission. Describe any libraries used here.

## Github Repo Submission Resources

You can remove this section if you don't need these references.

* [ESE5160 Example Repo Submission](https://github.com/ese5160/example-repository-submission)
* [Markdown Guide: Basic Syntax](https://www.markdownguide.org/basic-syntax/)
* [Adobe free video to gif converter](https://www.adobe.com/express/feature/video/convert/video-to-gif)
* [Curated list of example READMEs](https://github.com/matiassingers/awesome-readme)
* [VS Code](https://code.visualstudio.com/) is heavily recommended to develop code and handle Git commits
  * Code formatting and extension recommendation files come with this repository.
  * Ctrl+Shift+V will render the README.md (maybe not the images though)
