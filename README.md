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

- 

## Assignment 6:

- 

## Assignment 7:

- 

