#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    return 0;
}
