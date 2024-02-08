#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to search for a key in the inorder array
int search(int inorder[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == key) {
            return i;
        }
    }
    return -1;
}

// Function to construct a binary tree from given postorder and inorder traversals
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd) {
    if (inStart > inEnd) {
        return NULL;
    }
    static int idx = 5;
    int curr = postorder[idx];
    idx--;

    // Create a new node with the data from postorder
    struct Node* root = createNode(curr);
    

    // Search the root in the inorder array
    int pos = search(inorder, inStart, inEnd, root->data);

    // Recur to build the right and left subtrees
    root->right = buildTree(inorder, postorder, pos+ 1, inEnd);
    root->left = buildTree(inorder, postorder, inStart, pos -1);

    return root;
}

// Function to print the inorder traversal of a binary tree
void printInorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    // Example arrays of postorder and inorder traversals
    int inorder[] = {4,2,1,5,3};
    int postorder[] = {4,2,5,3,1};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    int postIndex = n - 1;

    // Construct the binary tree
    struct Node* root = buildTree(inorder, postorder, 0, n-1);

    // Print the inorder traversal of the constructed tree
    printf("Inorder traversal of the constructed tree is:\n");
    printInorder(root);

    return 0;
}
