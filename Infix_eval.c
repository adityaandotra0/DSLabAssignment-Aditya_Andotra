#include <stdio.h>               // header files are included

int main() {                   //main function

  char op;                  //operator op is declared
  int a,b;                //operands a and b are declared
  int res;                //res to store the result
  printf("Enter an operator (+, -, *, /):\n");
  scanf("%c", &op);           //user enters the opertor and specifies the operation to be performed
  printf("Enter two operands:\n");
  scanf("%d %d",&a,&b);         //user enters the operands

  switch (op) {
    case '+':res=a+b;
             break;            //switch statement to perform the operations
    case '-':res= a-b;
             break;
    case '*':res=a*b;
             break;
    case '/':res=a/b;
             break;
    // operator doesn't match any case constant
    default:
      printf("Error! operator is not correct\n");  //invalid operator
  }
    
    printf("The result is %d",res);     //result is printed.

  return 0;
}
