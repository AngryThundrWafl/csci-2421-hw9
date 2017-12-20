*******************************************************
*  Name      :  Brian Pina
*  Student ID:  104790387
*  Class     :  CSC 2421           
*  HW#       :  9
*  Due Date  :  april,25 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
This program will spell check the users input by putting a dictionary into a hash table we will enter the input into functions that will check if the word was correctly spelled there is also an option to insert the word into the dictionary

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions,creates all the objects and also calls all the functions through a menu
Name:  Linked list.h 
	has all the declarations for a linke list and node called item that will handel the linked list portion of the hashtable
Name: LinkedList.cpp
   Declares and implements all the functions in the linked list 
Name:HashTable.h
	Has the declarations for the hashtable and also includes linked list where we have a array declare in hashtable and make it of linked list
Name: HashTable.cpp
	Implements all the functions in hashtable.h and also other declareations that will get called in main
   
*******************************************************
*  Circumstances of programs
*******************************************************

   Program Compiles and runs on csegrid
developed on cLion using mingw
*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [PinaHW9]

   Now you should see a directory named homework with the files:
        main.cpp
        HashTable.cpp
	HashTable.h
	LinkeList.cpp
	LinkedList.h
	    makefile

2. Build the program.

    Change to the directory that contains the file by:
    % cd [PinaHW9]

    Compile the program by:
    % make

3. Run the program by:
   % ./[Homework9]

4. Delete the obj files, executables, and core dump by
   %./make clean
