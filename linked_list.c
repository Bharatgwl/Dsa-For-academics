#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
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
node *delete(node *head, int d)
{
    if (head == NULL)
    {
        return head;
    }
    node *temp = head;
    node *prev = NULL;
    if (head->data == d)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp->data != d)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    temp->next = NULL;
    free(temp);

    return head;
}
node *insertatbeg(node *head, int data)
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
    head = insertatend(head, 12);
    head = insertatend(head, 14);
    head = insertatend(head, 16);
    head = insertatend(head, 11);
    head = insertatbeg(head, 1);
    display(head);
    printf("\n");
    head = delete(head,14);
    display(head);
}