#include<stdio.h>
void move(int  , char  , char  , char );
int count = 0;
int main()
{
    char A = 'A' , B = 'B' , C = 'C';
    move(6,A,C,B);
    printf("%d",count);
    return 0;
}
void move(int n , char source , char destination,char aux)
{
    if(n==1){
        count++;
       // printf("Move rod from %c to %c\n",source,destination);
        return;
    }
    move(n-1,source,aux,destination);
    move(1,source,destination,aux);
    move(n-1,aux,destination,source);
}
