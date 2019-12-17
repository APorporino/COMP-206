//Anthony Porporino
//260863300
//COMP206 Assignment4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*this function will reverse the string passed*/
char* reverse(char *str, int length);

/*This program takes two input of words and checks if the words
 * are reverses of each other
 */
int main(int argc, char *argv[]){

        //check for right number of inputs.
        //Note: name of file is first argument so we want to check for 3 arguments
        if (argc != 3){
                printf("Wrong number of arguments. Please input: ./reverse WORD1 WORD2.\n");
                exit(1);
        }
        else{
        		char *word1 = argv[1];		//pointer to first word
        		char *word2 = argv[2];		//pointer to second word
        		char *tempWord1 = argv[1];
                int length = strlen(argv[1]);	//length of first string

                word1 = reverse(word1,length);	//word1 is now the reverse of what it was

                if (strcmp(word1,word2) ==  0){	//if strcmp == 0, strings are the same
                	printf("WORD1=%s WORD2=%s – REVERSE\n", tempWord1, word2);
                }
                else{
                	printf("WORD1=%s WORD2=%s – NOT REVERSE\n", tempWord1, word2);
                }
	}

	exit(0);
}

/*this function takes a string and length value and reverses the string*/
char* reverse(char *str, int length){
	char* str2 = (char*)malloc(sizeof(str)*length);	//create new char[] of size length
	int i;
	for (i=0;i<length;i++){							//copy old string into this
		str2[i] = str[length - i - 1];
	}
	return str2;
}

