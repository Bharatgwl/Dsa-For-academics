#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;

} stack;
void push(stack *st, int data)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->data = data;
    nn->next = st->top;
    st->top = nn;
}
int isEmpty(stack *st)
{
    return st->top == NULL;
}
void pop(stack *st)
{
    if (isEmpty(st))
    {

        printf("Stack is empty\n");
        return;
    }
    else
    {
        node *temp = st->top;
        st->top = st->top->next;
        free(temp);
    }
}

int peek(stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return st->top->data;
}
int main()
{
    stack(*st) = (stack *)malloc(sizeof(stack));
    st->top = NULL;
    push(st, 2);
    push(st, 3);
    push(st, 4);
    push(st, 5);
    push(st, 1);
    push(st, 10);
    push(st, 115);
    printf("%d\n", peek(st));
    pop(st);
    printf("%d\n", peek(st));
    pop(st);
    printf("%d\n", peek(st));
}