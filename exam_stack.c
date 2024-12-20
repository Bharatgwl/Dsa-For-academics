#include <stdio.h>
#include <stdlib.h>
typedef struct Stack
{
    int *arr;
    int top;
    int size;
} stack;
void init(stack *st, int size)
{
    st->top = -1;
    st->size = size;
    st->arr = (int *)malloc(sizeof(int) * size);
}
int size(stack *st)
{
    return st->top + 1;
}
void push(stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        st->top++;
        st->arr[st->top] = x;
    }
}
int pop(stack *st)
{
    if (st->top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    return st->arr[st->top--];
}

int peek(stack *st)
{
    if (st->top == -1)
    {
        printf("stack is empty");
        return -1;
    }
    return st->arr[st->top];
}
void display_stack(stack *st, int size)
{
    if (size == 0)
    {
        return;
    }
    printf("%d ", peek(st));
    int save = pop(st);
    display_stack(st, size-1);
    push(st, save);
}
int main()
{
    stack *st;
    init(st, 5);
    push(st, 2);
    push(st, 21);
    push(st, 3);
    push(st, 4);
    push(st, 7);
    printf("%d\n", size(st));
    display_stack(st, size(st));
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct node
// {
//     int data;
//     struct node *next;
// } node;
// typedef struct stack
// {
//     node *top;
// } stack;
// void init(stack *st)
// {
//     st->top = NULL;
// }
// void push(stack *st, int data)
// {
//     node *nn = (node *)malloc(sizeof(data));
//     nn->data = data;
//     nn->next = st->top;
//     st->top = nn;
// }
// void pop(stack *st)
// {
//     if (st->top == NULL)
//     {
//         printf("stack underflow\n");
//         return;
//     }
//     node *temp = st->top;
//     st->top = st->top->next;
//     free(temp);
// }
// int peek(stack *st)
// {
//     if (st->top == NULL)
//     {
//         printf("stack is empty");
//         return -1;
//     }
//     return st->top->data;
// }
// int main(){
//     stack *st;
//     init(st);
//     push(st, 2);
//     push(st, 21);
//     push(st, 3);
//     push(st, 4);
//     push(st, 7);
//     pop(st);
//     printf("%d", peek(st));
//     pop(st);
//     printf("%d", peek(st));
//     return 0;
// }