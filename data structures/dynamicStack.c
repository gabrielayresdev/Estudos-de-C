#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int data;
    struct Node * next;
} Node;

struct Node* createNode(int value) {
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

int isEmpty(Node* root) {
    return root == NULL;
}

void push(Node **root, int value) {
    Node * newNode = createNode(value);

    newNode->next = *root;
    *root = newNode;
}

int pop(Node **root) {
    if(isEmpty(root)) {
        printf("Stack is empty\n");
        return;
    }

    Node* temp = *root;
    int value = (*root)->data;
    *root = (*root)->next;
    free(temp);
    return value;
}

void printStack(Node* root) {
    if (isEmpty(root)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Elementos da pilha: ");
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}


int main()
{

    Node * node = NULL;

    printStack(node);

    push(&node, 10);
    push(&node, 15);
    push(&node, -1);
    push(&node, 0);
    printStack(node);
    pop(&node);
    printStack(node);
    return 0;
}
