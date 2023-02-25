#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("%d inserted at beginning.\n", data);
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("%d inserted at end.\n", data);
        return;
    }
    struct Node *tempNode = head;
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    newNode->prev = tempNode;
    printf("%d inserted at end.\n", data);
}

void insertAtPosition(int data, int position) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("%d inserted at position %d.\n", data, position);
        return;
    }
    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        printf("%d inserted at position %d.\n", data, position);
        return;
    }
    struct Node *tempNode = head;
    for (int i = 1; i < position - 1 && tempNode != NULL; i++) {
        tempNode = tempNode->next;
    }
    if (tempNode == NULL) {
        printf("Position %d is out of range.\n", position);
        return;
    }
    newNode->next = tempNode->next;
    newNode->prev = tempNode;
    if (tempNode->next != NULL) {
        tempNode->next->prev = newNode;
    }
    tempNode->next = newNode;
    printf("%d inserted at position %d.\n", data, position);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *tempNode = head;
    head = tempNode->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("%d deleted from beginning.\n", tempNode->data);
    free(tempNode);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *tempNode = head;
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    if (tempNode == head) {
        head = NULL;
        printf("%d deleted from end.\n", tempNode->data);
        free(tempNode);
        return;
    }
    tempNode->prev->next = NULL;
    printf("%d deleted from end.\n", tempNode->data);
    free(tempNode);
}

void deleteFromPosition(int position) {
if (head == NULL) {
printf("List is empty.\n");
return;
}
struct Node *tempNode = head;
if (position == 1) {
head = tempNode->next;
if (head != NULL) {
head->prev = NULL;
}
printf("%d deleted from position %d.\n", tempNode->data, position);
free(tempNode);
return;
}
for (int i = 1; i < position && tempNode != NULL; i++) {
tempNode = tempNode->next;
}
if (tempNode == NULL) {
printf("Position %d is out of range.\n", position);
return;
}
if (tempNode->next == NULL) {
tempNode->prev->next = NULL;
printf("%d deleted from position %d.\n", tempNode->data, position);
free(tempNode);
return;
}
tempNode->prev->next = tempNode->next;
tempNode->next->prev = tempNode->prev;
printf("%d deleted from position %d.\n", tempNode->data, position);
free(tempNode);
}

void displayList() {
if (head == NULL) {
printf("List is empty.\n");
return;
}
struct Node *tempNode = head;
printf("List: ");
while (tempNode != NULL) {
printf("%d ", tempNode->data);
tempNode = tempNode->next;
}
printf("\n");
}

int main() {
int choice, data, position;
while (1) {
printf("\n");
printf("1. Insert at beginning\n");
printf("2. Insert at end\n");
printf("3. Insert at position\n");
printf("4. Delete from beginning\n");
printf("5. Delete from end\n");
printf("6. Delete from position\n");
printf("7. Display list\n");
printf("8. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert at beginning: ");
scanf("%d", &data);
insertAtBeginning(data);
break;
case 2:
printf("Enter data to insert at end: ");
scanf("%d", &data);
insertAtEnd(data);
break;
case 3:
printf("Enter data to insert at position: ");
scanf("%d", &data);
printf("Enter position to insert at: ");
scanf("%d", &position);
insertAtPosition(data, position);
break;
case 4:
deleteFromBeginning();
break;
case 5:
deleteFromEnd();
break;
case 6:
printf("Enter position to delete from: ");
scanf("%d", &position);
deleteFromPosition(position);
break;
case 7:
displayList();
break;
case 8:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}