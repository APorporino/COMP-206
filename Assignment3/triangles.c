//Anthony Porporino
//260863300

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Take integer input and print a right trangle made from * with base equal
 * to input*/
int main(int argc, char *argv[]) 
{
	int size; //Define size variable
 	char asterix[1000] = "*"; //define a character array initializing with one asterix. Max size is 1000	
	
	//check if user inputted size otherwise prompt user for it
	if (argc > 1){
		size = atoi(argv[1]);
	}
	else{
		printf("Enter an integer number for the size of the base of the triangle");
		scanf("%d", &size);
	}
	
	//If size is less than one print error message
	if (size < 1){
		printf("An incorrect triangle size was inputted. The size must be greater than 0 and an integer number. Syntax: ./triangles SIZE\n");
		exit(2);
	}

	//print asterix n = size times but concatenate another * to that array each time 
	for (int i=1 ; i <= size ; i++){
		printf("%*s\n",size,asterix);
		strcat(asterix,"*");
	}	

	
}
