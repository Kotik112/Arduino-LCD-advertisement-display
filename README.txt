Disclaimer: This code has only been compiled and tested on Windows OS. 
If you are running linux or any other system architecture, make sure to change makefile to "-o program.out".

Compilation:
A makefile is included in the repository. The output is a Windows executable. Just "make".
Alternatively you can compile with the DOS command:
	g++ -Wall main.cpp ad_manager.cpp company.cpp menu.cpp serial.c -o program.exe


About the program:
The program requires at least 1 arguement to run. This arguement is the COM port you are trying to connect to.
For example: program.exe COM3 COM4
where COM3 and COM4 are the respective COM to send data to.

Main menu:

#############################
####### MAIN MENU ###########
#                           #
#    SELECT OPTION BELOW    #
#   1. Add Adversistment    #
#   2. Export Ads to Ardu   #
#   3. Save to file         #
#   4. Read from file       #
#   5. Flush file           #
#   6. Exit                 #
#                           #
#############################

1 -> Will prompt you to add a new advertisement.
2 -> Send advertisements to the COM specified at compile time.
3 -> Saves all the advertisements to file.
4 -> Reads advertisement from file.
5 -> Flushes the saved file and wipes the saved ads from memory.
6 -> Exits out of the program.

//
23/11-2021
Jakob, Arman & Unn 