#include<stdio.h>
#define n 5

int a[n];
int i;
int top=-1;
 
void push(int value){
    if (top>=n-1)
    {
        printf("stack is full\n");
    }else{
        top++;
        a[top]=value;
    }
}
void display(){
    if (top==-1)
    {
     printf("empty\n") ;  
    }else{
        for (i=0; i<=top; i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\n");
    }   
}
void pop(){
    if (top==-1)
    {
        printf("stack is empty\n");
    }else{
        top--;
    }
    
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();

}