#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int arr[50];
    int top;
} stack;
void push(stack *st, int data)
{
    if (st->top == 50 - 1)
    {
        printf("stack overflow\n");
        return;
    }
    st->top++;
    st->arr[st->top] = data;
    return;
}
void peek(stack *st)
{
    if (st->top == -1)
    {
        printf("stack is empty");
        return;
    }
    else
    {
        printf("%d\n", st->arr[st->top]);
        return;
    }
}
int pop(stack *st)
{
    if (st->top == -1)
    {
        return -1;
    }
    return st->arr[st->top--];
}
int main()
{
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    push(st, 2);
    push(st, 3);
    push(st, 4);
    push(st, 5);
    push(st, 1);
    push(st, 10);
    push(st, 115);
    peek(st);
    pop(st);
    peek(st);
    pop(st);
    peek(st);
    return 0;
}