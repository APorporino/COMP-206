#include <stdio.h>

//Anthony Porporino
//260863300

/**
 * This function takes an array of characters as well as two integer pointers as input.
 * It will read the array of characters and change the value that the two integer pointers point too
 * since they are passed by reference.
 * This function does not return anything.
 * 
 **/
void parse(char record[], int *acct, float *amnt){
    sscanf(record, "%d %f", acct, amnt);
}