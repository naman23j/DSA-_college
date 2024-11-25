#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}node;

typedef struct HeaderNode {
    int count;
    int maxi;
    int mini;
    node* next;
}Hnode;

Hnode* createHeadernode(){
    Hnode* nodeH = (Hnode*)malloc(sizeof(Hnode));
    nodeH->count = 0;
    nodeH->maxi = -1;
    nodeH->mini = 1000;
    nodeH->next = NULL;
    return nodeH;
}

void addnode(Hnode* header,int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(header->next == NULL){
        header->next = newnode;
        header->count++;
    }
    else{
        node* current = header->next;
        while(current->next !=NULL){
            current = current->next;
        }
        current->next = newnode;
        header->count++;
    }
    if(data>header->maxi){
        header->maxi = data;
    }
    if(data<header->mini){
        header->mini = data;
    }
}

void print(Hnode* header){
    node* current = header->next;
    printf("The linked list is:");
    while(current!=NULL){
        printf("%d\n",current->data);
        current = current->next;
    }
    printf("\n");
    printf("count: %d\n",header->count);
    printf("maxi: %d\n",header->maxi);
    printf("mini: %d\n",header->mini);
}


int main(){
    Hnode* header = createHeadernode();
    addnode(header,10);
    addnode(header,20);
    addnode(header,30);
    addnode(header,40);
    print(header);
return 0;
}