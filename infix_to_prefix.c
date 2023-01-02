#include <stdio.h>
#include<string.h>
#include <ctype.h>
#define SIZE 50 

char stack[SIZE];
int top = -1;

void push(char element)       // Function to Push the element from the stack
{
    	stack[++top] = element;
}

char pop()            // Function to pop the element from the stack
{
    	return(stack[top--]);
}

int priority(char element)         // Check the Priority of the String
{
    	switch(element)
    	{
        		case '#': return 0;
        		case ')': return 1;
        		case '+':
        		case '-': return 2;
        		case '*':
        		case '/': return 3;
    	}
}

int main()
{
    	char infix[50], prefix[50], ch, element;
    	int i = 0, j = 0;
    	printf("Enter the Infix Expression:\n");
    	scanf("%s", infix);      // Input Infix Expression from the user
push( '#' );
    	strrev (infix);
    	while( (ch = infix[i++] ) != '\0' )
    	{
        		if ( ch == ')' )
		{
         	 	push(ch);
        		else
        		{
            		if ( isalnum (ch) )     // Check if Numeric
                			prefix[j++] = ch;
            		else
            		{
                			if ( ch == '(' )
                			{
                    			while ( stack[top] != ')' )
                        				prefix[j++] = pop();
                    			element = pop();         // Remove ')'
                			}
                			else
                			{       // Operator
                    			while(priority(stack[top]) >= priority(ch))
                        				prefix[j++] = pop();
                    			push(ch);
                			}
            		}
        		}
    	}
    	while(stack[top] != '#')     // Pop from stack till empty
        		prefix[j++] = pop();
    	prefix[j] = '\0';          // Make prefix as valid string
    	strrev (prefix);
    	printf("Prefix Expression: %s", prefix);
}
