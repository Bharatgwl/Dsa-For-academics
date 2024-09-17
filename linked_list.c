#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *construct(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
}
node *insertatend(node *head, int data)
{
    if (head == NULL)
    {
        node *head = construct(data);
        return head;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *dummy = construct(data);
    temp->next = dummy;
    return head;
}
node *insbeg(node *head, int data)
{
    if (head == NULL)
    {
        return construct(data);
    }
    node *temp = construct(data);
    temp->next = head;
    head = temp;
    return head;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}
int main()
{
    node *head = NULL;
    head = insertatend(head, 5);
    head = insertatend(head, 5);
    head = insertatend(head, 5);
    head = insertatend(head, 5);
    head = insbeg(head, 1);
    display(head);
}