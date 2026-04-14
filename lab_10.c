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

// Function to find LCA
struct TreeNode* findLCA(struct TreeNode* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches root
    if (root->data == n1 || root->data == n2)
        return root;

    // Look in left and right subtrees
    struct TreeNode* leftLCA = findLCA(root->left, n1, n2);
    struct TreeNode* rightLCA = findLCA(root->right, n1, n2);

    // If both sides return non-null, this is LCA
    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    // Otherwise return non-null child
    return (leftLCA != NULL) ? leftLCA : rightLCA;
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

    int n1 = 4, n2 = 5;

    struct TreeNode* lca = findLCA(tree.root, n1, n2);

    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);
    else
        printf("LCA not found\n");

    return 0;
}