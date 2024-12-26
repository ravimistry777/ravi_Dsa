#include<stdio.h>

int main(){
    char array1[10];
    char array2[10];
    char array3[50];
    int len=0;

    for(int i=0;i<4;i++,len++){
    array3[len]=array1[i];
}
for(int j=0;j<10;j++,len++){
    array3[len]=array2[j];
}
printf("%s",array3);

    return 0;
}