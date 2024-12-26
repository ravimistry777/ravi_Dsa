#include <stdio.h>

int main() {
    
    int array1[1];
    int array2[1];

    for(int i=0;i<1;i++){
        printf("enter the component of array 1:- %d\n",i);
        scanf("%d",&array1[i]);
    
    for(int j=0;j<1;j++){
        printf("enter the component of array 2:- %d\n",j);
        scanf("%d",&array2[j]);
    
    printf("after swapping:\n");

    array1[i]=array1[i]+array2[j];
    array2[j]=array1[i]-array2[j];
    array1[i]=array1[i]-array2[j];

    printf("array1=%d\n",array1[i]);
    printf("array2=%d\n",array2[j]);
    }
    }
    return 0;
}
