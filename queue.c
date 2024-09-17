#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{

    int front;
    int rear;
    int size;
    int arr[];
} Queue;
void init(Queue *q1, int size)
{
    q1->size = size;

    q1->arr[q1->size];
    q1->front = 0;
    q1->rear = 0;
}
void push(Queue *q1, int data)
{
    if (q1->rear == q1->size)
    {
        printf("queue is full\n");
        return;
    }
    q1->arr[q1->rear++] = data;
}
void pop(Queue *q1)
{
    if (q1->front == q1->rear)
    {
        printf("queue is empty\n");
        return;
    }
    q1->front++;
}
int peek(Queue *q1)
{
    if (q1->front == q1->rear)
    {
        printf("queue is empty\n");
        return -1;
    }
    else
    {
        return (q1->arr[q1->front]);
    }
}
int main()
{
    Queue(*q1) = (Queue *)malloc(sizeof(Queue));
    init(q1, 8);
    push(q1, 22);
    push(q1, 2);
    push(q1, 3);
    push(q1, 4);
    push(q1,51);pop(q1);
    printf("%d", peek(q1));
}