#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//ANTHONY PORPORINO
//260863300

/** This program will be called using CGI get protocol. It will read the QUERY_STRING from environment variables,
 * to know how to respond. ALl responses will be of the form of HTML document. NOTE when using printf it sends it to 
 * the browser. So by writing HTML through printf we can send a response back for any request.
**/
int main(){
    //initialize variables
    int gold = 10;
    char *data = getenv("QUERY_STRING");
    char response [20];

    //If there is no payload make page an error however there will alwasy be one. Better to be safe
    if(data == NULL){
        printf("Content-Type:text/html\n\n");
        printf("<html><body><p style=\"color: red;\">Error no input!!</p></body></html>");
        return -1;
    }
    
    sscanf(data,"%s",response); //response now holds the payload as well

    //Find out how much gold player has and store it in gold variable
    //Assuming payload (QUERY_STRING) is of form command=$(command)&gold=$(gold)
    char *token = strtok(response, "=");
    char* fields[3];    //this will store the 3 strings: command, $(command) and $(gold) value
    int i=0;
    do{
        fields[i] = "";
        fields[i] = token;
        i++;
    }while ((token = strtok(NULL, "=")));
    //if this looped 2 times, it means gold parameter was not present.
    //if this looped once, it means command is empty and gold parameter was not present
    if ((i==2)||(i==1)){
        gold = 10;
    }else{
        gold = atoi(fields[2]);   //if looped 3 times, all arguments were present
    }
    //This will isolate the 'command' value. Either NORTH, SOUTH, WEST, EAST, GOLD or an answer to question.
    if (i > 1) fields[1] = strtok(fields[1],"&");   //i must be greater than 1 of else it will tokenize nothing
    

    //Read the what the command is and act accordingly
    if (strcmp(fields[1], "NORTH") == 0) {
        //Return a HTML page with a link that
        //Calls addgold from cgi-bin of my north neighbor with correct amount of gold passed 
        printf("Content-Type:text/html\n\n");
        printf("<html><body><a href='http:cs.mcgill.ca/~twatso5/cgi-bin/addgold.cgi?gold=%d'>Press HERE to go North</a></body><html>",gold);
   
    }else if (strcmp(fields[1], "SOUTH") == 0) {
        //Return a HTML page with a link that
        //Calls addgold from cgi-bin of my south neighbor with correct amount of gold passed 
        printf("Content-Type:text/html\n\n");
        printf("<html><body><a href='http:cs.mcgill.ca/~fsimar6/cgi-bin/addgold.cgi?gold=%d'>Press HERE to go SOUTH</a></body><html>",gold);
    
    }else if (strcmp(fields[1], "WEST") == 0) {
        printf("Content-Type:text/html\n\n");
        printf("<html><body><a href='http:cs.mcgill.ca/~cbourb5/cgi-bin/addgold.cgi?gold=%d'>Press HERE to go WEST</a></body><html>",gold);
    
    }else if (strcmp(fields[1], "EAST") == 0) {
        printf("Content-Type:text/html\n\n");
        printf("<html><body><a href='http:cs.mcgill.ca/~mstron1/cgi-bin/addgold.cgi?gold=%d'>Press HERE to go EAST</a></body><html>",gold);
   
    }else if (strcmp(fields[1], "GOLD") == 0) {
        //If command is gold return a HTML page displaying current amount of gold
        printf("Content-Type:text/html\n\n");
        printf("<html><body><h1 style=\"text-align: center; background-color:goldenrod;\" >CURRENT GOLD: %d</h1><br>",gold);
        printf("<a href='http:cs.mcgill.ca/~aporpo/cgi-bin/addgold.cgi?gold=%d'>Press HERE to go back</a></body><html>",gold);
    
    }else{
        //If it was none of the above, it was an attempt to answer the question
        printf("Content-Type:text/html\n\n");
        //If answer is correct we will display a HTML page saying that with a link back to my home page (using addgold executable)
        if ((strcmp(fields[1], "FFFF") == 0) || (strcmp(fields[1], "ffff") == 0) || (strcmp(fields[1], "0xffff") == 0) || (strcmp(fields[1], "0xFFFF") == 0)){
            gold += 10;
            if (gold >= 100){
                //in this case the user wins so display win page with no links
                printf("<html><body>");
                printf("<div style=\"text-align: center; background-color: green; height: 100%%; width: 100%%\"><h1>YOU WIN!</h1></div></body></html>");
            }else{
                printf("<html><body>");
                printf("<h1>CORRECT!</h1>");
                printf("<a href='http:cs.mcgill.ca/~aporpo/cgi-bin/addgold.cgi?gold=%d'>Press HERE to go back</a></body><html>",gold);
            }
        
        }else{
            //answer is incorrect so display a HTML page saying that with a link back to my home page (using addgold executable)
            gold -= 5;
            if (gold <= 0){
                //in this case the user loses so display a lose page with no links
                printf("<html><body>");
                printf("<div style=\"text-align: center; background-color: red; height: 100%%; width: 100%%\"><h1>YOU LOSE</h1></div></body></html>");
            }else{
                printf("<html><body>");
                printf("<h1>INCORRECT.</h1>");
                printf("<a href='http:cs.mcgill.ca/~aporpo/cgi-bin/addgold.cgi?gold=%d'>Press HERE to go back</a></body></html>",gold);
            } 
        }
    }

    return 0;
}