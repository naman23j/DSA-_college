// Enqueue is costly
#include<stdio.h>
int arr[10];
int brr[10];
int size1 = sizeof(arr)/sizeof(arr[0]);
int size2 = sizeof(brr)/sizeof(brr[0]);
int top1 = -1;
int top2  =-1;

void push1(int val){
    if(top1==(size1-1)){
        printf("Overflow");
    }
    else{
        top1 = top1+1;
        arr[top1]=val;
    }

}

void pop1(){
    if(top1==-1){
        printf("undeflow");
    }
    else{
        top1--;
    }
}

void push2(int val){
    if(top2==(size2-1)){
        printf("Overflow");
    }
    else{
        top2 = top2+1;
        brr[top2]=val;
    }

}

void pop2(){
    if(top2==-1){
        printf("undeflow");
    }
    else{
        top2--;
    }
}

void enqueue(int val){

    while(top1!=-1){
        int ele = arr[top1];
        push2(ele);
        pop1();
    }
    
    push1(val);

    while(top2!=-1){
        int ele = brr[top2];
        push1(ele);
        pop2();
    }
}

void dequeue(){
    

    pop1();

    printf("\nThe element is deleted");

    
}

void show(){
    printf("\nThe element in queue is : \n");
    for(int i=(top1);i>=0;i--){
        printf("%d\t",arr[i]);
    }
}

int main(){

    for(int i=1;i<=5;i++){
        enqueue(i*3);
    }
    show();
    dequeue();
    dequeue();
    show();
    return 0;
}