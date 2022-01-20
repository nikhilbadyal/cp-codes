#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 40
int stack[max];
int top = -1;
void push(char );
char pop();
int main()
{
    unsigned int i;
    int flag =1 ;
    char ex[max],temp;
    printf("Enter expression - ");
    gets(ex);
    for(i = 0 ;i<strlen(ex);++i)
    {
        if(ex[i] == '(' || ex[i] == '{' || ex[i] == '['  )
            push(ex[i]);
        if(ex[i] == ')' || ex[i] == '}' || ex[i] == ']'  )
        {
            if(top== -1)
                flag = 0;
            else{
                temp = pop();
                if( ex[i] == ')' &&(temp =='{' || temp == '[' ))
                              flag = 0;
                if( ex[i] == '}' &&(temp =='(' || temp == '[' ))
                              flag = 0;
                if( ex[i] == ']' &&(temp == '(' || temp == '{' ))
                              flag = 0;
            }
        }
    }
    if(top>=0)
        flag = 0;
    if(flag)
        printf("Valid expression.\n");
    else{
        printf("Invalid expression.\n");
    }

    return 0;
}
void push(char c)
{
    if(top == max -1  )
    {
        printf("Stack overflow \n");
        return ;
    }
    top++;
    stack[top] = c;
}
char pop()
{
    if(top == -1)
    {
        printf("Stack underflow\n");
      //  return -1 ;
    }
    return stack[top--];
}

