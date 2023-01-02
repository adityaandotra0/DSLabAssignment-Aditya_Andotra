/*Program for evaluation of Prefix expression*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int intStack[25]; //for max size of stack
int intTop=-1; // declare stack and its top pointer to be used during postfix


void pushInt(int item) //define push
{
intStack[++intTop]=item;
}


int popInt()   //define pop
{
return intStack[intTop--];
}

int evaluate(char *prefix) //defining function for evaluation of prefix
{
char ch;
int i, operand1, operand2;
for(i=strlen(prefix)-1; i>-1; i--)
{
ch=prefix[i];
if(isdigit(ch))
{
pushInt(ch-'0');
}
else
{
operand1 = popInt();
operand2 = popInt();
switch(ch)     //using switch statement
{
case '+':
pushInt(operand1+operand2);
break;
case '-':
pushInt(operand1-operand2);
break;
case '*':
pushInt(operand1*operand2);
break;
case '/':
pushInt(operand1/operand2);
break;
case '^':
pushInt(operand1^operand2);
break;
}
}
}
return intStack[intTop];
}

void main()  //call main function 
{
char prefix[]="*-123";
printf("Postfix expression is: %s\n", prefix);
printf("Evaluated value is: %d\n", evaluate(prefix));
}
Output
