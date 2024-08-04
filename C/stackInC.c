/* Stack in C
Code by - Daksh Verma - 231210036*/

#include <stdio.h>

#define MAX_SIZE 20

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int is_full(const struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int is_empty(const struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack is full. Cannot push.\n");
    }
    else {
        stack->items[++stack->top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

int pop(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; 
    } 
    else {
        int value = stack->items[stack->top--];
        printf("%d popped from the stack.\n", value);
        return value;
    }
}

void display(const struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
    } 
    else {
        printf("Stack items: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}


int peek(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; 
    } 
    else {
        printf("\nElement at top of the stack: %d\n", stack->items[stack->top]);
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, value;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	int num;
        switch (choice) {
            case 1:
            	 
               printf("Enter the number of values you want to enter : ");
               scanf("%d",&num);
               for(num;num>0;num--){
               printf("\nEnter value to push: ");
               scanf("%d", &value);
               push(&stack, value);}
               break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
            	peek(&stack);
            	break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

