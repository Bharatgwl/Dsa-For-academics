#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the BST
Node* BuildBST(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = BuildBST(root->left, data);
    } else {
        root->right = BuildBST(root->right, data);
    }
    return root;
}

// Function to take input and build the BST
Node* takeInput() {
    Node *root = NULL;
    int data;
    printf("Enter data for BST (-1 to stop): ");
    scanf("%d", &data);
    while (data != -1) {
        root = BuildBST(root, data);
        scanf("%d", &data);
    }
    return root;
}
int main() {
    Node *root = takeInput(); // Build the BST
    return 0;
}