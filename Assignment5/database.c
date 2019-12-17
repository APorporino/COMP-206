//ANTHONY PORPORINO
//260863300

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants
#define MAX_RECORD_LEN 105
#define MAX_ID_LEN 50
#define MAX_NAME_LEN 50
#define MAX_AGE_LEN 3
#define MAX_GPA_LEN 2

//function prototypes
void showDatabase();
int deleteById(int id);
void updateDatabase(int size);
void addRecord(char* id, char* name, char* age, char* gpa);

int main(int argc, char* argv[]){
    //check to see user inputted at least one command line argument
    if (argc == 1){
        printf("You did not provide any arguments. Please enter: ./database CMD OPT1 OPT2 OPT3 OPT4.\n");
        exit(-1);
    }
    //check to see user inputted correct first command line argument
    if ((strcmp(argv[1], "SHOW") != 0) & (strcmp(argv[1], "DELETE") != 0) & (strcmp(argv[1], "ADD") != 0)){
        printf("The command you requested in invalid. Please select from one of these: SHOW, DELETE, ADD.\n");
        exit(-2);
    }

    //if command line argument is show, delete or add call appropriate functions 
    if (strcmp(argv[1], "SHOW") == 0){
        showDatabase();
    }
    if (strcmp(argv[1], "DELETE") == 0){
        if (argc >= 3){ //>= allows for gracefule execution
            if(deleteById(atoi(argv[2])) == -3){          //if id was not found deleteById does not call updateDatabase()
                printf("Sorry, that user was not found. Nothing was deleted.\n");
                exit(-3);
            }
        }else{
            printf("Name of record to delete is missing\n");
            exit(-4);
        }
    }
    if (strcmp(argv[1], "ADD") == 0){
        if (argc >= 6){ //>= allows for gracefule execution
            addRecord(argv[2],argv[3],argv[4],argv[5]);
        }else{
            printf("Missing ID, Name, AGE, and GPA arguments\n");
            exit(-5);
        }
    }
    return 0;
}

//this method will parse through each record (line) in database
//and display it to the user
void showDatabase(){
    //create variables needed
    int recordNumber=1;
    char buffer[MAX_RECORD_LEN];                  //create a buffer array to store record
    FILE *csvDatabase = fopen("database.csv", "rt");  //open database
    
    //loops through each line of databased and places line in buffer string
    while((fgets(buffer, MAX_RECORD_LEN - 1, csvDatabase))!=0){
        //strtok will tokenize each substring in the record by commas
        char *token = strtok(buffer, ",");
        char* fields[4];    //this will store the 4 strings for a record (id,name,age,gpa)
        int i=0;
        do
        {
            fields[i] = "";
            fields[i] = token;
            i++;
        }while ((token = strtok(NULL, ",")));

        //change to correct type (automatically removes spaces)
        int id = atoi(fields[0]);
        int age = atoi(fields[2]);
        float gpa = atof(fields[3]);
        
        // get rid of all spaces in string fields[1]
        int len=strlen(fields[1]);
        for(int j=0; j<len; j++){
            if(fields[1][j]==' '){
                for(int k=j; k<len; k++){
                    fields[1][k]=fields[1][k+1];
                }
            len--;
            }
        }

        printf("Record %d: ID=%-10d NAME=%-20s AGE=%-3d GPA=%-3.1f\n",recordNumber,id,fields[1],age,gpa);
        recordNumber++;
    }
}

int deleteById(int id){

    int line_to_delete = 1;
    char buffer[MAX_RECORD_LEN];                  //create a buffer array to store record
    FILE *csvDatabase = fopen("database.csv", "rt");  //open database
    
    //loops through each line of databased and places line in buffer string
    while((fgets(buffer, MAX_RECORD_LEN - 1, csvDatabase))!=0){
        //strtok will tokenize each substring in the record by commas
        char *token = strtok(buffer, ",");
        char* fields[4];    //this will store the 4 strings for a record (id,name,age,gpa)
        int i=0;
        do
        {
            fields[i] = "";
            fields[i] = token;
            i++;
        }while ((token = strtok(NULL, ",")));

        //change to correct type (automatically removes spaces)
        int student_id = atoi(fields[0]);

        //if student id wished to be deleted is found, call updateDatabase passing line to delete
        if (student_id == id){
            updateDatabase(line_to_delete);
            return 0;
        }else{
            line_to_delete++;
        }
    }
    fclose(csvDatabase);
    return -3;
}

//given the line to delete this function will copy all lines except the line passed
//to the function to a new file.
//It then replaces database.csv with the new file
void updateDatabase(int line_to_delete){
    
    int line_index = 1;
    char buffer[MAX_RECORD_LEN];                  //create a buffer array to store record
    FILE *csvDatabase = fopen("database.csv", "rt");  //open database
    FILE *tempDatabase = fopen("database.tmp", "wt");

    while (fgets(buffer, 100, csvDatabase) != NULL){
        if (line_index != line_to_delete){
            fputs(buffer, tempDatabase);
        }
        line_index++;
    }
    system("rm database.csv");
    system("mv database.tmp database.csv ");
    fclose(tempDatabase);
    fclose(csvDatabase);
}

//Given arguments needed for a record in char* form
//this function will add that record to database.csv in proper form
void addRecord(char* id, char* name, char* age, char* gpa){
    char buffer2[MAX_RECORD_LEN] = "";
    strcat(buffer2, id);
    strcat(buffer2, ",");
    strcat(buffer2,name);
    strcat(buffer2, ",");
    strcat(buffer2,age);
    strcat(buffer2, ",");
    strcat(buffer2,gpa);
    strcat(buffer2, "\n");
    FILE *csvDatabase = fopen("database.csv", "at");  //open database
    fprintf(csvDatabase, "%s",buffer2);
    fclose(csvDatabase);
}