#include<stdio.h>
int fact(int );
int main()
{
    unsigned long long int x = 1;
    printf("%d",fact(x));
    return 0;
}
int fact(int n)
{
    /*if(x ==1)
        return 1;
    return (x*fact(x-1));}*/
    return n ? n*fact(n-1) : 1;
}
