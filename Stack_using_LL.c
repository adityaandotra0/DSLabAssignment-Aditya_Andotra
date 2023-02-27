#include<stdio.h>
#include<stdlib.h>

// Define the stack node
struct node {
    int data;
    struct node *next;
};

// Define the top pointer
struct node *top = NULL;

// Define the push function
void push(int item) {
    // Create a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->next = top;
    top = new_node;
    printf("%d pushed to stack\n", item);
}

// Define the pop function
int pop() {
    // Check if the stack is empty
    if(top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    else {
        struct node *temp = top;
        int item = temp->data;
        top = top->next;
        free(temp);
        return item;
    }
}

// Define the display function
void display() {
    // Check if the stack is empty
    if(top == NULL) {
        printf("Stack is empty\n");
    }
    else {
        struct node *temp = top;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Define the main function
int main() {
    // Push elements into the stack
    push(10);
    push(20);
    push(30);

    // Display the elements in the stack
    printf("Stack elements: ");
    display();

    // Pop an element from the stack
    int popped_item = pop();
    printf("Popped item: %d\n", popped_item);

    // Display the elements in the stack
    printf("Stack elements: ");
    display();

    return 0;
}