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
    else{
        struct Node* temp = *poly;
        while(temp->next != NULL && temp->next->pow >= pow){
            temp = temp->next;
        }
    
        if(temp->pow == pow){
            temp->coeff += coeff;
            free(newNode);
        }
        else{
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Display polynomial method
void display(struct Node* poly){
    if(poly == NULL){
        printf("0");
        return ;
    }
    while(poly != NULL){
        printf("%dx^%d",poly->coeff,poly->pow);
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

// add two polynomials
struct Node* addPolynomials(struct Node* poly1,struct Node* poly2){
    struct Node* result = NULL;

    while(poly1 != NULL && poly2 != NULL){
        if(poly1->pow > poly2->pow){
            insertTerm(&result,poly1->coeff,poly1->pow);
            poly1 = poly1->next;
        }
        else if(poly1->pow < poly2->pow){
            insertTerm(&result,poly2->coeff,poly2->pow);
            poly2 = poly2->next;
        }
        else{
            insertTerm(&result,poly1->coeff + poly2->coeff,poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while(poly1 != NULL){
        insertTerm(&result,poly1->coeff,poly1->pow);
        poly1 = poly1->next;
    }
    while(poly2 != NULL){
        insertTerm(&result,poly2->coeff,poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2){
    struct Node* result = NULL;
    for(struct Node* p1 = poly1; p1 != NULL; p1=p1->next){
        for(struct Node* p2 = poly2; p2 != NULL; p2=p2->next){
            int coeffProduct = p1->coeff * p2->coeff;
            int powSum = p1->pow + p2->pow;
            insertTerm(&result,coeffProduct,powSum);
        }
    }
    return result;
}

int main(){
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    struct Node* product = NULL;

    // Polynomial 1: 3x^3 + 2x^2 + 1
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 1, 0);

    // Polynomial 2: 4x^2 + 1x^1 + 2
    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 1, 1);
    insertTerm(&poly2, 2, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);
    printf("\nSum of Polynomials: ");
    display(sum);

    
    // Multiplication
    product = multiplyPolynomials(poly1, poly2);
    printf("Product of Polynomials: ");
    display(product);

    return 0;
}