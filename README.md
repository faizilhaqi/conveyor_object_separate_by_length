# conveyor_object_separate_by_length
This is a arduino project that can be use separate object by its length.
I use two pairs of infrared sensors to detect object with receiver and transmitter facing each other.
when the object pass between them sensor will detect them,and send binary number to microcontroller.
To get the object length value,we can multiple the speed of object with the time the object take to pass the first pair of infrared sensors.
To get the Speed of object in the conveyor, We can calculate the speed of the object on the conveyor by dividing the distance of to pairs of infrared sensors with the time it takes the object to pass through the two pairs of infrared sensors. 
After we get the length of object, so now we can selecting object by its lengths.
To selecting object i use two Servo Motors
The Servo Motor will rotate to the idle position or change positions based on the set point of the lengths of the object that we made.
