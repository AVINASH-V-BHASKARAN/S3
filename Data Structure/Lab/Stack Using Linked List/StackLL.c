#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

typedef struct Stack {
    Node* head;
} Stack;
void initializeStack(Stack* stack) {
    stack->head = NULL;
}
int isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void push(Stack* stack, int new_data)
{
    Node* new_node = createNode(new_data);
    if (!new_node)
    {
        printf("\nStack Overflow");
        return;
    }
    new_node->next = stack->head;
    stack->head = new_node;
}

void pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack Underflow\n");
        return;
    } else{
        Node* temp = stack->head;
        stack->head = stack->head->next;
        free(temp);
    }
}

int peek(Stack* stack)
{
    if (!isEmpty(stack))
        return stack->head->data;
    else
    {
        printf("\nStack is empty");
        return INT_MIN;
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);
    int choice, value;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                printf("Top element is %d\n", peek(&stack));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

