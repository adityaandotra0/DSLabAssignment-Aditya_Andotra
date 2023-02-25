// Circular Queue implementation using array in C
#include<stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1, element;

// Adding an element
void enQueue(){
  if((front == rear + 1) || (front == 0 && rear == SIZE - 1)){
    printf("\n Queue is full!! \n");
  } else {
    if (front == -1) 
    front = 0;
    rear = (rear + 1) % SIZE;
    printf("Enter no : ");
    scanf("%d",&element);
    cq[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// Removing an element
void deQueue(){
  if(front == -1) {
    printf("\n Queue is empty !! \n");
  } else if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      printf("\n Deleted element -> %d \n", cq[front]);
      front = (front + 1) % SIZE;
    } 
  }

// Display the queue
void display() {
  int i;
  if (front == -1)
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", cq[i]);
    }
    printf("%d ", cq[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
    int choice;
do {
        printf("\n1.enQueue\n2.deQueue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enQueue();
            break;
            case 2:
            deQueue();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("You Exit");
            break;
            default:
            printf("Enter No. btw 1-4 \n");
        }
    }
    while(choice!=4);
    return 0;
}