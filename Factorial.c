#include <stdio.h>
int fact(int); // function definition

int main()
{
    int n, f;
    printf("enter number\n"); // Ask user for the input and store it in n
    scanf("%d", &n);
    f = fact(n);                  // function call
    printf("factorial is %d", f); // displaying factorial of number
}

int fact(int n) // function declaration
{
    int result;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        result = n * fact(n - 1); // function calling itself(Recursion)
        return result;
    }
}
