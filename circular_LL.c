#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;


Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertNode(Node *tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *temp = createNode(d);
        tail = temp;
        temp->next = temp; 
    }
    else
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *newNode = createNode(d);
        newNode->next = curr->next; 
        curr->next = newNode;
    }
    return tail;
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *curr = tail;
    do
    {
        printf("%d ", tail->data);
        tail = tail->next;
    } while (tail != curr);
    printf("\n");
}

Node *deleteNode(Node *tail, int value)
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return tail;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    if (prev == curr && curr->data == value)
    {
        free(curr);
        tail = NULL;
        return tail;
    }

    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
        if (curr == tail->next)
        { 
            printf("Element %d not found\n", value);
            return tail;
        }
    }

    prev->next = curr->next;

    if (curr == tail)
    {
        tail = prev; 
    }

    free(curr);
    return tail;
}

int main()
{
    Node *tail = NULL;

    tail = insertNode(tail, 0, 10);
    tail = insertNode(tail, 10, 5);
    tail = insertNode(tail, 5, 11);
    tail = insertNode(tail, 11, 20);

    printf("Circular Linked List before deletion: ");
    print(tail);

    tail = deleteNode(tail, 11);
    printf("After deleting node with value 11: ");
    print(tail);

    tail = deleteNode(tail, 5);
    printf("After deleting node with value 5: ");
    print(tail);  

    tail = deleteNode(tail, 10);
    printf("After deleting node with value 10: ");
    print(tail);

    tail = deleteNode(tail, 20);
    printf("After deleting node with value 20: ");
    print(tail);

    return 0;
}
