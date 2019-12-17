
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "../inc/ssv.h"
#include "../inc/linked.h"

//Anthony Porporino
//260863300

//Function prototype
int isEmpty(const char *s);

int main(){
    //Check if a file named students.ssv exists, exit if it does not
    if( access( "students.ssv", F_OK ) == -1 ) {
        printf("File students.ssv not found\n");
        return -1;
    }
    //open students.ssv file
    FILE* f = fopen("students.ssv", "r");

    //use string line to store each line of file
    char line[100] = "";
    int account;            
    float amount;
    //loop through each line of the ssv file and call parse only if line is not empty
    while (fgets(line,99,f)!=NULL){
        if (isEmpty(line) == 0){
            parse(line, &account,&amount);  //call parse from ssv.c
            findUpdate(account,amount);     //call findUpdate from linked.c
        }
    }
    prettyPrint();  //call pretty print from linked.c
    fclose(f);
    return 0;
}

/** This function will test if the string passed to the function
 * is just empty spaces. It returns 0 if not and 1 if it is just
 * empty spaces.
 **/
int isEmpty(const char *s) {
    int i=0;
    //loop first 100 characters or untill end of string
    while ((*s != '\0')&(i<=100)) {
        if (!isspace((unsigned char)*s)){   //if not a whitespace exit and return 0
            return 0;
            s++;
        }
        i++;
    }
    return 1;
}

