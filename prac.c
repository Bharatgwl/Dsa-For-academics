#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int coeff;
    int pow;
    struct Node *next;
} node;
node *createnode(int coeff, int pow)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->coeff = coeff;
    nn->pow = pow;
    nn->next = NULL;
    return nn;
}
node *creatpolynomial(node *poly, int coeff, int pow)
{
    if (poly == NULL)
    {
        node *newnode = createnode(coeff, pow);
        return newnode;
    }
    node *curr = poly;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    node *newnode = createnode(coeff, pow);
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->next = NULL;
    curr->next = newnode;
    return poly;
}
void print(node *poly)
{
    node *curr = poly;
    while (curr)
    {
        printf("%dx^%d ", curr->coeff, curr->pow);
        if (curr->next != NULL)
        {
            printf("+ ");
        }
        curr = curr->next;
    }
}
int main()
{
    node *poly = NULL;
    poly = creatpolynomial(poly, 3, 2);
    poly = creatpolynomial(poly, 4, 3);
    print(poly);
}