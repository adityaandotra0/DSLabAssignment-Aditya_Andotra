/* Program for evaluation of postfix expression */

#include<stdio.h>
  int stack[20];                        //   for max size of stack 
  int top = -1 ;                          // declare stack and its top pointer to be used during postfix 

void push(int x)                    // define push operation
{
    stack[++top] = x;
}

int pop()                          // define pop operation
{
    return stack[top--];
}

int main()                           // call main function
{
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')                      // using while loop
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)                                 // using switch statement
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}
