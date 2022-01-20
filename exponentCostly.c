#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>
int exponent(int , int );
int main()
{
    printf("%d",exponent(3,8));
    return 0;
}
int exponent(int x , int y )
{
    if(y==0)
        return 1;
    return (x*exponent(x,y-1));
}
