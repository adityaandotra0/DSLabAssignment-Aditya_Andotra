#include <stdio.h>
#include <stdlib.h>
#define size 4

int top = -1;
int arr[size];
void push();
void pop();
void show();

int main()
{
    int choice;
    while (1)
    {
        printf(“Select the operation\n”);
        printf(“1.Push\n 2.Pop\n 3.Display\n 4.Exit\n”);
        scanf(“% d”, &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf(“Invalid Choice\n”);
        }
    }
}
//pushes the item into the stack
void push()
{
    int n;
    if (top == size - 1)
    {
        printf(“Overflow”);
    }
    else
    {
        printf(“Enter the element to be inserted\n”);
        scanf(“% d”, &n);
        top++;
        arr[top] = n;
    }
}
//pulls out the item from the stack
void pop()
{
    if (top == -1)
    {
        printf(“Underflow”);
    }
    else
    {
        printf(“Removed element % d\n”, arr[top]);
        top--;
    }
}
//displays the stack item
void show()
{
    int i;
    if (top != 1)
    {
        for (i = 0; i < top; i++)
        {
            printf(“% d\t”, arr[i]);
        }
        printf(“\n”);
    }
    else
    {
        printf(“Stack is empty\n”);
    }
}
