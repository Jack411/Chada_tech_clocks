# Chada_tech_clocks

This is a C++ program which displays the current local time in 12 hour and 24 hour format. If the user doesn't press any key the clock works normally, but if any key is pressed a user menu is displayed. The user menu contains 4 options as follows, Adding 1 hour to the current time, Adding 1 minute to the current time, Adding 1 second to the current clock and last is to Exit the program.

I created an array of Hour, Minute, and Second. after every second the second Array increases by 1, if it reaches 59 it is set to 0 and minute Array increases by 1 and if it also reaches 59 it is set to 0 and hour array is increased by 1, if 12 hour clock reaches 12 it is set to 1 and when 24 hour clock reaches 23 it is set to 0. There is also a keyboard hit listener which keeps track if any key is pressed or not, if a key is pressed the screen is cleared and the user menu is displayed. If the user press 1, 1 hour is added to current time, if 2 is pressed 1 minute is added to current time, if 3 is pressed 1 second is added to current time and if 4 is pressed the loop ends and the program terminates.

The current program can be enhanced and optimised by using mathematical calculation instead of using array and loops. The program will become fast and will consume less memory. Hence the space and time complexity of the program will reduce to a great extent.

Although the program was easy but extracting the required amount of data from the built in time funtion to a string was a bit challenging but it didn't took much time to implement.

I learned many things while doing this project a few of them are as follows,

a. When the code of the program gets bigger, its wise to divide the project into small functions which can be called when required. It makes the code readable and easy to understand.

b. Comment the code wherever possible, it also increases the readability of the project, it will make easy for everyone to understand the code.

c. Using standard naming convention of the variables and functions.

d. First comming up with a simple solution to a problem and optimize it later when needed.
