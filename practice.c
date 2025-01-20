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

    printf("%d\t%c\n",s1.data,s1.ch);
    printf("%d\t%c\n",s2.data,s2.ch);
    printf("%d\t%c\n",s3.data,s3.ch);
    s1.ptr = &s2;
    s2.ptr = &s3;

    printf("%d\n",s1.ptr->data);
    printf("%c\n",s1.ptr->ch);
    printf("%d\n",s2.ptr->data);
    printf("%c\n",s2.ptr->ch);

}
