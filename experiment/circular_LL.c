#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* pre;
    int data;
    struct node* next;

}node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        printf("jagah nahi mili");
    }
    else{
        newNode->pre = NULL;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}

