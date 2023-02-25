#include<stdio.h>
#define max 5

int front = -1, rear = -1, q[max], i, j, choice;
void insert(){
    if(rear == max -1){
        printf("Queue Overflow");
    } else if(front == -1){
        front = 0;
    } else {
        printf("Enter element : ");
        scanf("%d",&i);
        rear++;
        q[rear] = i;
    }
}
void delete(){
    if(front == -1 || front > rear){
        printf("Queue Underflow");
    } else {
        printf("Deleted element is %d ",q[front]);
        front++;
    }
}
void display(){
    if(front == -1){
        printf("Queue is empty");
    } else {
        for(j = front;j<=rear;j++){
            printf("%d",q[j]);
            printf("\t");
        }
    }
}
int main(){
    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            delete();
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