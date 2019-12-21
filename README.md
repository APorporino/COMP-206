# COMP-206
Assignments completed for COMP206 at McGill University. Bash and C


## Assignment 2:

**Contains 2 bash scripts:**<br/>

1. ***backup*** script will make a backup of FILES (must be one line) into DEST with a log that contains MESSAGE
    
                                    backup SWITCH FILES DEST MESSAGE
                                    
    • SWITCH is optional: -D for delete original files. If not present the files to be backed-up are not deleted.<br/>
    • FILES is the path, using wild cards, of the files to be backed-up.<br/>
    • DEST is the path to the backup directory.<br/>
    • MESSAGE is a multiword description about the backup. It will be added to a log file.
    
2. ***mkproj*** script will make a Projects folder in current dir (if didn't already exist) and then create a new dir with name ARGUMENT. It will have the format:<br/>
    └── ARGUMENT<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── archive<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── assets<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── backup<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── database<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── docs<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│   └── readme.txt<br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── source<br/>
        
                                    mkproj ARGUMENT OWNER
                                    
the readme.txt will contain the OWNER input.


## Assignment 3:

**Contains a bash script and c file.**
    
1. Bash script is a hidden login script (***.bash_profile***) that will peronalize shell environment on login

2. ***triangles.c*** is a c program that will print asteirx in shape of a triangle with the size of the base that user inputed from the command line. For example if the executable's name is triangles (you can do this by running the compile.sh) running the command: <br/>
    ./triangles 3 , would result in:<br/>
      &nbsp;&nbsp;&nbsp;&nbsp;* <br/>
     &nbsp;&nbsp;** <br/>
    *** <br/>


## Assignment 4:

**Contains two c programs:**

1. ***reverse.c*** is a c program that takes command line input two words and returns whether or not these two words are reverses of each other. For example if reverse is the name of the executable (again you can just run compile.sh to make this) then the command: <br/>
./reverse RACECAR RACECAR , would result in an output that says they are reverses.

2. ***matrix.c*** is a c program that implements functions fillMatrix(), printMatrix(), transposeMatrix(), and multiplyMatrix() for a matrix created by a double array (5x5). The main function will call fillMatrix() to randomly create a new matrix and then call printMatrix() to print it. It finds the transpose of the matrix using transposeMatrix() and prints it again. Lastly it will multiply the matrix by another matrix (that has been hardcoded), and print it to the screen once more.

    The main program just illustrates the power of the function. If needed could be used by another program that requires these functions.


## Assignment 5:

**Contains one c program called database.c**

***database.c*** will read and write from a databse.csv file records of students in the form : ID,NAME,AGE,GPA

                                    ./database CMD OPT1 OPT2 OPT3 OPT4
                                    
The argument CMD can have the following values:<br/>
• SHOW : - displays all the records from the database.<br/>
• DELETE : - OPT1 = ID, that record in removed from the database.<br/>
• ADD : - OPT1=ID, OPT2=NAME, OPT3=AGE, OPT4=GPA, a new record with these fields are added to the database.


## Assignment 6:

***Contains 3 c programs***

The goal of this assignment was to get us familiar with modular programming. Similarly to the last assignment we read from a students.ssv (space seperated value) file in the form of: Account_Number Amount.
We were required to use .h files and compile using a makefile 

The makefile compiled the two modules (linked.c and ssv.c) into object files and the compiled the whole project using those object files. This way it only compiles what files have been changed.

1. ***main.c*** will read every file in students.ssv and call the function parse() function is ssv.c to get the fields in the record. It then calls findUpdate() in the linked.c file that adds the record to the linked list global to all files. It lastly will print all the records by searching through the linked.c linked list.

2. ***ssv.c*** Contains the parse() function which returns the account_number and amount.

3. ***linked.c*** Contains findUpdate() function which adds record to the linked list as well as the linked list global to all files.

There are two header files linked.h and ssv.h so main only has to include those files.


## Assignment 7:

The goal of this assignment was to get familiar with HTML, and CGI.<br/>

As a class the goal was to create a game where each student created their own web page on a McGill cs server: https://www.cs.mcgill.ca/~studentUsername/. <br/>

Each page had a question related to c that the person playing the game could try to answer to win gold. Once the answer was submitted, the CGI part in the HTML document called the executble made from answer.c to process the answer and either award or remove gold. Once 100 gold is reached the user wins and a WIN page is shown, and once the user runs out of gold a GAME OVER page is shown.<br/>

The web page also allows a user to move to 4 other students pages. The idea was to link everyone in the classes pages together. Using CGI to call the executable made from addgold.c from another student, one could display the web page of another student. We also had to implement our own addgold.c to allow other students to link to our page.



