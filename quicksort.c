#include<stdio.h>

int partiotion(int a[],int lb,int ub){
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    int temp;

    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start<end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    temp=a[lb];
    a[lb]=a[end];
    a[end]=temp;
    
    return end;
}

void quicksort(int a[],int lb,int ub){
    if (lb<ub)
    {
        int loc=partiotion(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }   
}

int main(){
    int arr[5]={8,5,21,9,2};
    for (int v = 0; v < 5; v++)
    {
        printf("|%d|\t",arr[v]);
    } printf("\n");
    quicksort(arr,0,4);
    for (int v = 0; v < 5; v++)
    {
        printf("|%d|\t",arr[v]);
    }
    printf("\n");
    
    return 0;
}