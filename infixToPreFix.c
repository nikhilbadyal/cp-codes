#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"infixToPostFix.h"
void changeparen(char *);

int main()
{
    char expression[] = "(A-B/C)*(A/K-L)";
    char  *expression1 = strrev(expression);
    strcpy(expression,expression1);
    changeparen(expression);
  //  expression[(strlen(expression))] = ')';
  //  expression1=convert(expression);
  //  expression1 = strrev(expression1);
    printf("%s " , expression);
    
    return 0;
}
void changeparen(char * expression)
{
    int i ;
    for(i = 0;i<strlen(expression);i++)
    {
    	if(expression[i]== ')')
		{
            expression[i] = '(';
            continue;
		}
        if(expression[i]== '(')
		{
            expression[i] = ')';
            continue;
        }
    }
}
