#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *left, *right;
};

struct BinaryTreeNode* newNodeCreate(int value) {
    struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, int target) {
    if (root == NULL || root->key == target) {
        return root;
    }
    if (root->key < target) {
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}

struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value) {
    if (node == NULL) {
        return newNodeCreate(value);
    }
    if (value < node->key) {
        node->left = insertNode(node->left, value);
    } else if (value > node->key) {
        node->right = insertNode(node->right, value);
    }
    return node;
}

void postOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

void inOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct BinaryTreeNode* findMin(struct BinaryTreeNode* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left != NULL) {
        return findMin(root->left);
    }
    return root;
}

struct BinaryTreeNode* delete(struct BinaryTreeNode* root, int x) {
    if (root == NULL)
        return NULL; 
    if (x > root->key) {
        root->right = delete(root->right, x);
    } else if (x < root->key) {
        root->left = delete(root->left, x);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            struct BinaryTreeNode* temp = (root->left == NULL) ? root->right : root->left;
            free(root);
            return temp;
        } else {
            struct BinaryTreeNode* temp = findMin(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }
    return root;
}

int main() {
    struct BinaryTreeNode* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert a node\n2. Search for a node\n3. Delete a node\n4. Print tree (In-order)\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter an integer to search: ");
                scanf("%d", &value);
                if (searchNode(root, value) != NULL) {
                    printf("%d found\n", value);
                } else {
                    printf("%d not found\n", value);
                }
                break;
            case 3:
                printf("Enter an integer to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                printf("Deleted %d (if it was present)\n", value);
                break;
            case 4:
                printf("In-order traversal of the tree:\n");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

