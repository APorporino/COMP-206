#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ANTHONY PORPORINO
//260863300

/** This program will be called by other student's pages and will allow them to reach my main HTML page.
 * Since it is not open to edit to the public, this program will allow them to visit my page and still
 * have the same number of gold to be able to continue the game.
**/
int main(){
    //intialize variable 
    int goldpieces;
    char *data = getenv("QUERY_STRING");
    if(data == NULL){   //will not occur but better to be safe
        return -1;
    }
    
    //Assuming QUERY_STRING is in form of gold=$(goldpieces)
    char *goldString = strtok(data, "=");
    goldString = strtok(NULL, "="); //now goldString has the gold passed
    goldpieces = atoi(goldString);  //goldpieces now has int of of gold passed
    
    //open html page and add the hidden input for the gold value
    FILE *ptr = fopen("../index.html", "r");
    char buffer[300];
    printf("Content-Type:text/html\n\n");
    //loop through my index.html page and printf back to the browser each line
    while (fgets(buffer,sizeof(buffer),ptr) != NULL){
        //I need this if statment to make sure that my picture gets found, since this program is in cgi-bin it must go up a 
        //directory to find the picture.
        if (strstr(buffer, "<img src=\"images/kitchen.jpg\" height=\"300\" width=\"300\">") != NULL) {
            printf("<img src=\"../images/kitchen.jpg\" height=\"300\" width=\"300\">");
        }else{
            printf("%s", buffer);   //print exactly what was in the file
        }

        //if we have reached the form tag, after the first input which contains the name 'command'
        //we will print the hidden gold input
        if (strstr(buffer, "name=\"command\">") != NULL) {
            printf("\t\t\t\t<input type=\"hidden\" name=\"gold\" value=\"%d\">\n", goldpieces);
        }
    }
}