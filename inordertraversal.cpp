#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    struct Node* newNode = createNode(data);
    if (root->left == NULL) {
        root->left = newNode;
    } else if (root->right == NULL) {
        root->right = newNode;
    } else {
       
        printf("Cannot insert node. Both left and right nodes are occupied.\n");
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, item;
    do {
        printf("Enter choice: \n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &item);
                root = insertNode(root, item);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
