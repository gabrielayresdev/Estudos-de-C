#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    char itens[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack *stack, char item) {
    if(isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }

    stack->itens[++stack->top] = item;
}

int pop(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    return(stack->itens[stack->top--]);
}

void printStack(Stack * stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    int i = stack->top;
    while(i >= 0) {
        printf(" %d ", stack->itens[i]);
        i--;
    }
    printf("\n");
}


int main()
{

    Stack* stack = (Stack*)malloc(sizeof(Stack));
    init_stack(stack);

    printStack(stack);

    push(stack, 10);
    push(stack, 15);
    push(stack, -1);
    push(stack, 0);
    printStack(stack);
    pop(stack);
    printStack(stack);
    return 0;
}
