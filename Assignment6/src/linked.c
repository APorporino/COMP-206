#include <stdio.h>
#include <stdlib.h>

//Anthony Porporino
//260863300

//Define an account structure to be able to create a linked list
struct ACCOUNT {
    int accountNumber;
    float balance;
    struct ACCOUNT *next;
};

//A private ACCOUNT variable to be used as head of linked list
static struct ACCOUNT *head = NULL;

/** This function takes an integer and a float as input: account and amount.
 * It will search the linked list for an account with the account number passed,
 * If found it will update its amount variable with the amount passed to the function.
 * If not found it will create a new node at the end of the list with the passed variables.
 **/
void findUpdate(int account, float amount){
    if (head == NULL){  //If head is null nothing is in list
        //Add the first node in the list
        head = (struct ACCOUNT*) malloc(sizeof(struct ACCOUNT));
        head->accountNumber = account;
        head->balance = amount;
        head->next = NULL;
        
    }else{
        //Use a temp variable to search through the list
        struct ACCOUNT* temp = (struct ACCOUNT*) malloc(sizeof(struct ACCOUNT));
        temp = head;
        while (temp->next != NULL){
            //Account number is found so update amount and exit function
            if (temp->accountNumber == account){
                temp->balance += amount;
                return;
            }
            temp = temp->next;
        }
        //The while loop does not check the last element so we must do it outside the loop.
        if (temp->accountNumber == account){
                temp->balance += amount;
                return;
        }
        //If no node was found with account number make a new node at the end of list
        //It is ok to use temp or head in this case since temp and head both point to same node and it will update list by reference
        temp->next = (struct ACCOUNT*) malloc(sizeof(struct ACCOUNT));
        temp->next->accountNumber = account;
        temp->next->balance = amount;
        temp->next->next = NULL;  
    }
}

/**
 * This function will search through the linked list
 * and print the account ID and balance for each node in a pretty way.
 **/
void prettyPrint(){
    struct ACCOUNT *temp = head;
    while (temp != NULL){
        printf("ACCOUNT ID: %5d BALANCE: $ %9.2f\n", temp->accountNumber, temp->balance);
        temp = temp->next;
    }
}


