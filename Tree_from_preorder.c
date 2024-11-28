#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the BST
Node *BuildBST(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = BuildBST(root->left, data);
    }
    else
    {
        root->right = BuildBST(root->right, data);
    }
    return root;
}

// Function to take input and build the BST
Node *takeInput()
{
    Node *root = NULL;
    int data;
    printf("Enter data for BST (-1 to stop): ");
    scanf("%d", &data);
    while (data != -1)
    {
        root = BuildBST(root, data);
        scanf("%d", &data);
    }
    return root;
}
Node *tree_from_preorder(int pre[], int n)

{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = BuildBST(root, pre[i]);
    }
    return root;
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
   
    printf("%d ", root->data);
     postorder(root->right);
}
int main()
{
    int preorder[] = {8, 5, 1, 4, 6, 10, 12, 14, 13, 15};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    Node *result = tree_from_preorder(preorder, n);
    postorder(result);
    return 0;
}