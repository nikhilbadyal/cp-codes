#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>
int rem;
int gcd(int, int );
int  main()
{
    printf("%d",gcd(20,400));
    return 0;
}
int gcd(int x , int y)
{
    rem = x % y ;
    if(rem==0)
        return y;
    return gcd(y,rem);
}
