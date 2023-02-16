#include<stdio.h>

int main() {
    int x =0,y=0,sum=0;
    printf("enter a number: ");
    scanf("%d", &x);
    printf("enter a second number: ");
    scanf("%d", &y);
    sum = x+y;
    printf("The sum of your 2 numbers is: %d \n",sum);
    return 0;
}