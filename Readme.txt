*******************************************************
*  Name      :  Michael Hoover, Jacob Hutchins      
*  Student ID:  109475011 (Michael)
		106023519 (Jacob)             
*  Class     :  CSC 2421           
*  Due Date  :  December 11, 2019
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program reads in data for Oscar winners/nominees and allows the user to perform a number of operations on the data. The program offers three categories of data, actors-actresses, pictures, and nominations. The program accepts only .csv files for inputting the data. It will read the data from the file and store the information in a binary search tree. Then the user can choose to search the data, add a record, delete a record, modify a record, or save the data to a file. At any point the user can choose to exit and the program will terminate.

Extra credit: This program completes two requirements for extra credit. It offers an option to read nominations data into the program so that the user can perform all the operations on the nominations. The program also offers the user the option of calculating statistics from the nominations data. The two statistics are: 1. The program displays the top 20 individuals who have the most nominations of all time. 2. The program displays the film title with the most nominations for every year of the award.

A note on the nominations.csv file: The nominations.csv file provided for the assignment possessed a number of issues. We modified the file to remove unnecessary commas, parenthesis, and quotation marks. The removal of unnecessary commas was done so that the program could read in the file correctly. We removed parenthesis and quotation marks to make the search options more viable (for many entries the program was reading '(' or '"' as the first character in a record) and to make the records easier to read for the user. We have provided the nominations file as part of our submission. Please use the provided nominations file when testing the program otherwise it will not run properly.

A second note on the nominations.csv file: Even after our adjustments the nominations file contains significan problems. For many of the records the fields are in the wrong position. For instance, in many records the film title field is swapped with the name of the nominees. This means often the search results are not accurate. For example, if the user performs a search for the name of the individual and enters "John Doe" the program will not return an accurate result if "John Doe" is stored as the title of the film. This also affects the result of the statistics calculated for the nominations data. Some film titles appear in the list of top 20 nominated individuals, because the film titles are in the wrong field. Because the number of erroneous entries numbers in the thousands we did not have time to address this problem.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
	Main program file. It calls a function to display the main menu. 

Name: Menu.h
	Header file which declares function that allow the user to navigate the options available to the program.

Name: Menu.cpp
	This file provides function definitions that allow the user to choose from the options the program provides. The functions are broken up into three major sections: those corresponding to navigation of the actor/actress data, those corresponding to the picture data, and those corresponding to the nominations data. The functions call appropriate functions for the ActTree and PicTree class to perform operations on the data. 

Name: ActTree.h
	Header file for ActTree. It provides a class definition for ActTree and declares functions for the class. 

Name ActTree.cpp
	This file provides function definitions for the ActTree class. The major function implementations it provides are functions to sort and search the data, functions to modify or delete records, and a function to save the data in an external file

Name: Nodes.h
	Header file for class ActNode. Provides a class definition and declares functions

Name: Nodes.cpp
	This file provides function definitions for the ActNode class.

Name: PicTree.h
	This header file contains the definition for the PicTree class.

Name: PicTree.cpp
	Defines the functions for the PicTree class, including reading from a file, writing to a file, sorting through the data, partial/complete search, modify records, delete records, and display the data.

Name: PicNode.h
	This header file contains the definition for the PicNode class.

Name: PicNode.cpp
	Defines the functions for the PicNode class, including getting/setting its field data, getting/setting its subtrees, and printing the record to the screen.
   
*******************************************************
*  Status of program
*******************************************************

   The program was tested on the cse grid and runs successfully. The program completes all requirements of the assingment and also completes requirements for extra credit. 

******************************************************
* How to build and run the program
******************************************************

1. uncompress the zip file named HooverMichael_HW4.zip

	You should see a directory named Final Project with the following files:
		ActTree.cpp
		ActTree.h
		main.cpp
		Menu.cpp
		Menu.h
		Nodes.cpp
		Nodes.h
		PicNode.cpp
		PicNodes.h
		PicTree.cpp
		PicTree.h
		Readme.txt
		Makefile
		actor-actress.csv
		nominations.csv
		pictures.csv


2. Compile the program by typing the command:
	make

3. Run the program by typing the command:
	./Final_Project.exe

4. Delete the object files by typing the command:
	make clean
	