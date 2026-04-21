#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    struct Node* newNode = createNode(value);
    
    if (root == NULL) {
        return newNode;
    }
    
    struct Node* current = root;
    struct Node* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            free(newNode);
            return root;
        }
    }
    
    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int value) {
    struct Node* parent = NULL;
    struct Node* current = root;
    
    while (current != NULL && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (current == NULL) {
        printf("Value not found\n");
        return root;
    }
    
    if (current->left == NULL && current->right == NULL) {
        if (current == root) {
            free(root);
            return NULL;
        }
        if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    }
    else if (current->left == NULL || current->right == NULL) {
        struct Node* child = (current->left != NULL) ? current->left : current->right;
        
        if (current == root) {
            free(root);
            return child;
        }
        
        if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(current);
    }
    else {
        struct Node* successor = findMin(current->right);
        int successorValue = successor->data;
        root = deleteNode(root, successorValue);
        current->data = successorValue;
    }
    
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    
    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);
        
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    printf("\n");
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    
    stack1[++top1] = root;
    
    while (top1 >= 0) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;
        
        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }
    
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");
}

void displayTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }
    
    space += 5;
    displayTree(root->right, space);
    
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    displayTree(root->left, space);
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    
    while (1) {
        printf("\n---- Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder\n");
        printf("4. Preorder\n");
        printf("5. Postorder\n");
        printf("6. Display Tree\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            
            case 3:
                printf("Inorder: ");
                inorder(root);
                break;
            
            case 4:
                printf("Preorder: ");
                preorder(root);
                break;
            
            case 5:
                printf("Postorder: ");
                postorder(root);
                break;
            
            case 6:
                printf("\nTree:\n");
                displayTree(root, 0);
                break;
            
            case 7:
                exit(0);
            
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}