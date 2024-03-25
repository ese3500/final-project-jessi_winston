[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/2TmiRqwI)
# final-project-skeleton

    * Team Name: 
    * Team Members: 
    * Github Repository URL: 
    * Github Pages Website URL: [for final submission]
    * Description of hardware: (embedded hardware, laptop, etc) 

## Final Project Proposal

### 1. Abstract

In a few sentences, describe your final project. This abstract will be used as the description in the evaluation survey forms.

### 2. Motivation

What is the problem that you are trying to solve? Why is this project interesting? What is the intended purpose?

### 3. Goals

These are to help guide and direct your progress.

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

Formulate key hardware requirements here.

### 6. MVP Demo

What do you expect to accomplish by the first milestone?

### 7. Final Demo

What do you expect to achieve by the final demonstration or after milestone 1?

### 8. Methodology

What is your approach to the problem?

### 9. Components

What major components do you need and why?

### 10. Evaluation

What is your metric for evaluating how well your product/solution solves the problem? Think critically on this section. Having a boolean metric such as “it works” is not very useful. This is akin to making a speaker and if it emits sound, albeit however terrible and ear wrenching, declare this a success.
It is recommended that your project be something that you can take pride in. Oftentimes in interviews, you will be asked to talk about projects you have worked on.

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
