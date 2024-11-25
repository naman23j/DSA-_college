#include<stdio.h>
long front = -1;  //to delete
long rear = -1;   // to insert
long queue[5];
long size = 5;

long is_full(){
    if(rear==size-1){
        return 1;
    }
    else{
        return 0;
    }
}

long is_empty(){
    if(front==-1 || (front>rear)){
        return 1;
    }
    else{
        return 0;
    }
}



void enqueue(long val){
    if(is_full()){
        printf("Overflow\n");
    }
    else{
        rear = rear +1;
        queue[rear] = val;
        if(front==-1){
            front = 0;
        }
    }
}

long dequeue(){
    if(is_empty()){
        printf("Underflow\n");
    }
    else{
        long ele = queue[front];
        printf(" The deleted element is : %d\n",ele);
        front = front + 1;
        return ele;
    }
}


void peek(){
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        printf(" The peek element is : %d\n",queue[front]);
    }
}

void show(){
    printf("The element in queue is : \n");
    for(int i=front;i<(rear+1);i++){
        printf("%d\t",queue[i]);
    }
}



int main(){

    for(int i=1;i<=5;i++){
        enqueue(i*3);
    }
    dequeue();
    dequeue();
    peek();
    show();



    return 0;
}