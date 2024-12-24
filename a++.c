#include <stdio.h>
int main(){
int a = 15;
printf("a:- %d, a:- %d, a:- %d, a:- %d, a:- %d, a:- %d, a:- %d\n",a++,++a,a,++a,a++,a,++a);
printf("a:- %d, a:- %d, a:- %d, a:- %d\n", a++, ++a, a++, ++a);
printf("a:- %d, a:- %d, a:- %d, a:- %d\n", a, a++, a++, ++a);
printf("a:- %d, a:- %d, a:- %d, a:- %d\n", a, a++, a++, a++);
printf("a:- %d, a:- %d, a:- %d\n", ++a, ++a, ++a);
printf("a:- %d, a:- %d, a:- %d\n", a++, ++a, a++);
printf("a:- %d, a:- %d, a:- %d\n", a++, a++, a++);
printf("a:- %d, a:- %d, a:- %d\n", a, a++, a++);
printf("a:- %d, a:- %d\n", ++a, ++a);
printf("a:- %d, a:- %d\n",a++, ++a);
printf("a:- %d, a:- %d\n",a++, a++);
printf("a:- %d, a:- %d\n",a, a++);
printf("a:- %d\n", ++a);
}