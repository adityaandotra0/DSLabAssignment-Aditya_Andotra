#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = front;

    if (front == NULL) {
        front = node;
        rear = node;
    }
    else {
        rear->next = node;
        rear = node;
    }
}

int dequeue() {
    int data = 0;

    if (front == NULL) {
        printf("Error: Queue is empty\n");
        return data;
    }

    if (front == rear){
        data = front->data;
        free(front);
        front = NULL;
        rear = NULL;
    }
    else {
        Node* temp = front;
        data = temp->data;
        front = front->next;
        rear->next = front;
        free(temp);
    }

    return data;
}

void printQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = front;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    int choice, data;
    do {
        printf("Circular Queue Menu:\n1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                printf("Dequeued element: %d\n", data);
                break;
            case 3:
                printQueue();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}