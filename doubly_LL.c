#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertFront(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);    
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    return newNode; 
}

struct Node *insertBack(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *last = head;

    if (head == NULL)
    {
        return newNode; 
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;

    return head; 
    
}


struct Node *deleteNode(struct Node *head, int key)
{
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found\n");
        return head; // Return the unchanged head if the node was not found
    }

    if (head == temp)
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
        temp->prev=NULL;
    }

    free(temp);
    return head; // Return the updated head
}

// Function to print the list in forward direction
void printForward(struct Node *node)
{
    printf("List in forward direction: ");
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertBack(head, 30);
    head = insertBack(head, 40);

    printForward(head);
    deleteNode(head, 40);
    printForward(head);
    return 0;
}
