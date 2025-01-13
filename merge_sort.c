#include<stdio.h>

void merge(int arr[],int lb,int mid,int ub){
    
    printf("lb:-%d mid:-%d ub:-%d\n",lb,mid,ub);

    int i = lb;
    int j = mid + 1;
    int k = lb;
    int arr1[50];

    while (i <= mid && j <= ub)
    {
        if (arr[i]<=arr[j])
        {
            arr1[k] = arr[i];
            printf("data:-%d\n",arr[k]);
            i++;
        }else{
            arr1[k] = arr[j];
            printf("data:-%d\n",arr[k]);
            j++;
        }   
        k++;
    }
    if (i>mid)
    {
        while (j <= ub)
        {
            arr1[k] = arr[j];
            printf("data:-%d\n",arr[k]);
            j++;
            k++;
        }
    }else{
        while (i <= mid)
        {
            arr1[k] = arr[i];
            printf("data:-%d\n",arr[k]);
            i++;
            k++;
        }
    }
    for ( k = lb; k <= ub; k++)
    {
        arr[k] = arr1[k];
        printf("data:%d\n",arr[k]);
    }
}

void mergesort(int arr[],int lb,int ub){
    if (lb<ub)
    {
        int mid = (lb+ub)/2;
        printf("mid is:- %d\n",mid);
        mergesort(arr,lb,mid);
        printf("call:-\n");
        mergesort(arr,mid+1,ub);
        printf("call:- \n");
        merge(arr,lb,mid,ub);
    }
}


int main(){
    int arr[5]={50,5,30,4,80};
    for (int v = 0; v < 5; v++)
    {
        printf("%d\t",arr[v]);
    } printf("\n");
    mergesort(arr,0,4);
    for (int v = 0; v < 5; v++)
    {
        printf("%d\t",arr[v]);
    }
    printf("\n");
    
    return 0;
}















