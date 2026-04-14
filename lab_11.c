#include <stdio.h>
#include <stdlib.h>

// Structure for Tree Node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Binary Tree structure
struct BinaryTree {
    struct TreeNode* root;
};

// Insert (level-order)
void insert(struct BinaryTree* tree, int data) {
    struct TreeNode* newNode = createNode(data);

    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = tree->root;

    while (front < rear) {
        struct TreeNode* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
}

// Function to find a node by value
struct TreeNode* findNode(struct TreeNode* root, int value) {
    if (root == NULL)
        return NULL;

    if (root->data == value)
        return root;

    struct TreeNode* left = findNode(root->left, value);
    if (left != NULL)
        return left;

    return findNode(root->right, value);
}

// Function to print grandchildren
void findGrandChildren(struct TreeNode* root, int value) {
    struct TreeNode* node = findNode(root, value);

    if (node == NULL) {
        printf("Node not found\n");
        return;
    }

    printf("Grandchildren of %d: ", value);

    // Left child's children
    if (node->left != NULL) {
        if (node->left->left != NULL)
            printf("%d ", node->left->left->data);
        if (node->left->right != NULL)
            printf("%d ", node->left->right->data);
    }

    // Right child's children
    if (node->right != NULL) {
        if (node->right->left != NULL)
            printf("%d ", node->right->left->data);
        if (node->right->right != NULL)
            printf("%d ", node->right->right->data);
    }

    printf("\n");
}

// Main function
int main() {
    struct BinaryTree tree;
    tree.root = NULL;

    // Build tree
    insert(&tree, 1);
    insert(&tree, 2);
    insert(&tree, 3);
    insert(&tree, 4);
    insert(&tree, 5);
    insert(&tree, 6);
    insert(&tree, 7);

    // Find grandchildren
    findGrandChildren(tree.root, 1);

    return 0;
}