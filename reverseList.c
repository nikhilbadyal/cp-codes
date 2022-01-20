#include<stdio.h>
#include<stdlib.h>
int stack[10];
int top = -1;
void push(int );
int pop();
int main()
{
    int i ;
    int arr[10];
    for(i=0;i<10;++i)
    {
        arr[i] = i;
    }
    for(i=0;i<10;++i)
    {
        push(arr[i]);
    }
    for(i =0 ;i< 10 ; ++i)
    {
        arr[i] = pop();
    }
    printf("Reversed array is - \n");
    for(i=0;i<10;++i)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
void push(int value)
{
    stack[++top] = value;
}
int pop()
{
    return stack[top--];
}
