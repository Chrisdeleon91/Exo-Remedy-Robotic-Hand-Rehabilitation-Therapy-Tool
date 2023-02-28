# Exo-Remedy-Robotic-Hand-Rehabilitation-Therapy-Tool
Integrated an Arduino Uno microcontroller into a mixed-signal circuit with use of linear actuators, motor controllers, force sensors and flex sensors. 
The routine is ran through the code diagram (https://sites.google.com/view/exoremedy/how-it-works/). We first instantiate our variable, which are the flex sensors, actuators, force sensors, and our pins that are being used. then we apply the "routine" method that takes in the respective actuator, force sensor, flex sensor, and the digital pins for the actuator,. The routine begins pressing down the finger and actively checks for any force, and when it is detected, the routine stops and the flex sensor reports its angle. Then, the same routine is applied to the next finger and so on.

Exo-Remedy is a tool to use for hand therapy, a patient can soothe or even perform complete therapy advised by their doctor right at home. Then, the results of their therapy are relayed to their doctor. 
Project website: https://sites.google.com/view/exoremedy/
