#include<stdio.h>
int fibonacci(int n){
    if(n==1||n==0){
        return 1;
    }else {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
int main(){
    int n;
    printf("enter the value of a:");
    scanf("%d",&n);
   for (int i=0;i<n;i++){
    printf("%d,",fibonacci(i));
   }
}