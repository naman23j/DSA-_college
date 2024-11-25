#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}


void insertTerm(struct Node* header, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    struct Node* temp = header;


    while (temp->next != NULL && temp->next->exponent > exponent) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void displayPolynomial(struct Node* header) {
    struct Node* temp = header; 
    if (temp == NULL) {
        printf("Bhai Khali Hai \n");
        return;
    }

    while (temp != NULL) {
        printf("%d*x^%d", temp->coefficient, temp->exponent);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

void sum(struct Node* header , struct Node* header1 ){
    struct Node* temp = header;
    struct Node* temp2 = header1;
    printf("\nA: ");
    //displayPolynomial(temp);
   // printf("\nB: ");
   // displayPolynomial(temp2);
    struct Node* result = (struct Node*)malloc(sizeof(struct Node));
    result->next = NULL; 
    // insertTerm(result, 4, 3);  
    // insertTerm(result, 3, 2);  
    // displayPolynomial(result);
    while (temp != NULL && temp2 != NULL) {
        if(temp->exponent > temp2->exponent){
            insertTerm(result,temp->coefficient,temp->exponent);
            temp = temp->next;
            // printf("\nB:");
            // displayPolynomial(result);

        }
        else if(temp->exponent < temp2->exponent){
            insertTerm(result,temp2->coefficient,temp2->exponent);
            temp2 = temp2->next;
        }
        else{
            int sumcoeff= (temp->coefficient) + (temp2->coefficient);
            if(sumcoeff!=0)
            insertTerm(result,sumcoeff,temp->exponent);
            temp = temp->next;
            temp2 = temp2->next;

        }
}
//printf("\n\nXYZ");
        while(temp!=NULL){
            insertTerm(result,temp->coefficient,temp->exponent);
            temp = temp->next;
        }
        while(temp2!=NULL){
           insertTerm(result,temp2->coefficient,temp2->exponent);
           temp2 = temp2->next;
        }
displayPolynomial(result);
}

int main() {
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));
    header = NULL; 
    insertTerm(header, 4, 3);  
    insertTerm(header, 3, 2);  
    insertTerm(header, 5, 1);  
    insertTerm(header, 2, 0);
    struct Node* header1 = (struct Node*)malloc(sizeof(struct Node));
    header1->next = NULL; 
    printf("The polynomial is: ");
    displayPolynomial(header);
    insertTerm(header1,3,2);
    insertTerm(header1,4,1);
    insertTerm(header1,1,0);

    printf("The polynomial is: ");
    displayPolynomial(header1);


    printf("The Sum of  polynomial is: ");
    sum(header,header1);

    return 0;
}