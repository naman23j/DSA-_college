/*
PUSH 
POP
PEEK
*/
#include<stdio.h>
    int max=10;
    int stack[10];
    int top=-1;

int isfull(){
    if(top==(max-1)){
        return 1;
    }

    else{
        return 0;
    }


}

int isempty(){
    if(top==-1){
        return 1;
    }

    else{
        return 0;
    }    
}



void push(int value){
    if(isfull()){
        printf("Stack is full\n");
    }
    else{
        top=top+1;
        stack[top]=value;
    }
}

void pop(){
    if(isempty()){
        printf("Stack is empty\n");
    }
    else{
        top--;
    }
}

void peek(){
    printf("\n%d",stack[top]);
}

void show(){

    for(int i=0;i<(top+1);i++){
        printf("%d\t",stack[i]);
    }
    printf("\n");
}



int main(){

    push(3);
    push(4);
    push(5);
    push(6);
    // printf("%d\n",top);
    show();
    // pop();
    pop();
    show();
    // peek();

}