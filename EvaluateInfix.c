/*This C program implements a basic calculator that evaluates infix expressions using stacks.
It utilizes two stacks, one for operands and one for operators.*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 50

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

    }
}

int pop(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; 
    } 
    else {
        int value = stack->items[stack->top--];

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

int peek(const struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; 
    } 
    else {
        return stack->items[stack->top];
    }
}

int isoperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char oper) {
    if (oper == '+' || oper == '-') {
        return 1;
    }
    else if (oper == '*' || oper == '/') {
        return 2;
    }
    return 0;
}

int calculate(int op1, int op2, char oper) {
    switch (oper) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
    default:
      printf("%c - Error! Operator is not correct\n", oper);
      exit(1);
  }
}

int evaluateInfix(char *expr, struct Stack *operands_stack, struct Stack *operators_stack) {
    int i = 0, op1, op2;
    char ch, oper;
    
    while ((ch = expr[i++]) != '\0') {
        if (isdigit(ch)) {
            push(operands_stack, ch - '0');
        }
        else if (ch == '(') {
            push(operators_stack, ch);
        }
        else if (ch == ')') {
            while (peek(operators_stack) != '(') {
                op2 = pop(operands_stack);
                op1 = pop(operands_stack);
                oper = pop(operators_stack);
                push(operands_stack, calculate(op1, op2, oper));
            }
            pop(operators_stack);
        }
        else if (isoperator(ch)) {
            while (!is_empty(operators_stack) && precedence(peek(operators_stack)) >= precedence(ch)) {
                op2 = pop(operands_stack);
                op1 = pop(operands_stack);
                oper = pop(operators_stack);
                push(operands_stack, calculate(op1, op2, oper));
            }
            push(operators_stack, ch);
        }
    }
    
    while (!is_empty(operators_stack)) {
        op2 = pop(operands_stack);
        op1 = pop(operands_stack);
        oper = pop(operators_stack);
        push(operands_stack, calculate(op1, op2, oper));
    }
    
    return peek(operands_stack);
}

int main() {
    struct Stack operands_stack, operators_stack;
    initialize(&operands_stack);
    initialize(&operators_stack);
    char expression[100];
    
    printf("Enter Expression: ");
    scanf("%99s", expression);
    
    int result = evaluateInfix(expression, &operands_stack, &operators_stack);
    
    printf("Result: %d\n", result);

    return 0;
}
