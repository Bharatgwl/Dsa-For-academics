#include <stdio.h>
#include <stdlib.h>
int MAX = 5;
typedef struct Stack
{
    int arr[10];
    int top;
} stack;
void push(stack *st, int data)
{
    if (st->top == MAX - 1)
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
        printf("stack underrflow\n");
        return -1;
    }
    return st->arr[st->top--];
}
int main()
{
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    int input;
    int size = MAX;
    int arr[size], i = 0;
    while (size--)
    {
        scanf("%d", &input);
        if (input == 0)
        {
            arr[i] = st->arr[st->top];
            i++;
        }
        else if (input == -1)
        {
            int save = pop(st);
            arr[i++] = save;
        }
        else
        {
            push(st, input);
        }
    }
    for (int j = 0; j < 4; j++)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}