#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Structure for Binary Tree
struct BinaryTree {
    struct TreeNode* root;
};

// Function to insert a node (level-order insertion)
void insert(struct BinaryTree* tree, int data) {
    struct TreeNode* newNode = createNode(data);

    // If tree is empty
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    // Queue for level order traversal
    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = tree->root;

    while (front < rear) {
        struct TreeNode* temp = queue[front++];

        // Insert in left if empty
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            queue[rear++] = temp->left;
        }

        // Insert in right if empty
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
}

// Pre-order traversal (Root -> Left -> Right)
void preOrderTraversal(struct TreeNode* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

// Main function
int main() {
    struct BinaryTree tree;
    tree.root = NULL;

    // Insert elements
    insert(&tree, 1);
    insert(&tree, 2);
    insert(&tree, 3);
    insert(&tree, 4);
    insert(&tree, 5);

    // Pre-order traversal
    printf("Pre-order Traversal:\n");
    preOrderTraversal(tree.root);

    return 0;
}