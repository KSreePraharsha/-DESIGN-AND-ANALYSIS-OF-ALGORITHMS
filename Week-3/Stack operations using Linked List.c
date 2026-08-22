#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
void pop() {
    struct Node *temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        temp = top;
        printf("%d element popped\n", top->data);
        top = top->next;
        free(temp);
    }
}
void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}
void display() {
    struct Node *temp = top;
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push  2. Pop  3. Peek  4. Display  5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
      
        switch (choice) {
            case 1: printf("Enter value: ");
                    scanf("%d", &value);
                    push(value);
                    printf("%d element pushed\n", value);
                    break;

            case 2: pop(); break;

            case 3: peek(); break;

            case 4: display(); break;

            case 5: exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
