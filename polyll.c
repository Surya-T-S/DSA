#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;

};

// create node function
struct Node* createNode(int coeff, int pow){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// insert terms in descending order of the power
void insertTerm(struct Node** poly, int coeff, int pow){
    struct Node* newNode = createNode(coeff,pow);
    if(*poly == NULL ||(*poly)->pow < pow){
        newNode->next = *poly;
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while(temp->next != NULL && temp->next->pow > pow){
        temp = temp->next;
    }

    if(temp->next != NULL && temp->next->pow == pow){
        temp->next->coeff += coeff;
        free(newNode);
    }
    else{
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Display polynomial method
void display(struct Node* poly){
    if(poly == NULL){
        printf("0");
        return ;
    }
    while(poly != NULL){
        printf("%dx^d%",poly->coeff,poly->pow);
        poly = poly->next;
        if(poly != NULL && poly->coeff >= 0){
            printf(" + ");
        }
        else if(poly != NULL){
            printf(" ");
        }
    }
    printf("\n");
    
    
}
