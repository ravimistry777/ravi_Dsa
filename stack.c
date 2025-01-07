#include<stdio.h>
#define n 5

int a[n];
int i;
int top=-1;

void push(int value){
    if (top>=n-1)
    {
        printf("stack is full");
    }else{
        top++;
        a[top]=value;
    }
    
}

void display(){
    if (top==-1)
    {
        printf("empty");
    }else{
        for ( i = 0; i <= top; i++)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
    
}

void pop(){
    if (top==-1)
    {
        printf("stack is empty");
    }else{
        top--;
    }
    
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();
}