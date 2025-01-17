#include<stdio.h>

struct node
{
    int data;
    char ch;
    struct node *ptr;
    
};

int main(){
    struct node s1,s2,s3;

    s1.data = 65;
    s1.ch = 'A';
    s2.data = 97;
    s2.ch = 'a';
    s3.data = 10;
    s3.ch = 'z';
    
    printf("object s1 :- %d\t%c\n",s1.data,s1.ch);
    printf("object s2 :- %d\t%c\n",s2.data,s2.ch);
    printf("object s3 :- %d\t%c\n",s3.data,s3.ch);
    printf("\n");
    printf("s1's adress :- %d\n",s1.ptr);
    printf("s2's adress :- %d\n",s2.ptr);
    printf("s3's adress :-%d\n",s3.ptr);
    printf("\n");
    s1.ptr=&s2;
    s2.ptr=&s3;

    printf("s2's address saved in s1 :- %d\n",s1.ptr->data);
    printf("s2's address saved in s1 :- %c\n",s1.ptr->ch); 
    printf("s3's address saved in s2 :- %d\n",s2.ptr->data);
    printf("s3's address saved in s2 :- %c\n",s2.ptr->ch); 
    

}
