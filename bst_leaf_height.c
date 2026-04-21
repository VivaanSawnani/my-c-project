#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
 
struct Node* create(int val) { 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = val; 
    node->left = NULL; 
    node->right = NULL; 
    return node; 
} 
 
struct Node* insert(struct Node* root, int key) { 
    if (root == NULL) { 
        printf("Inserted.\n"); 
        return create(key); 
    } 
 
    if (key < root->data) { 
        root->left = insert(root->left, key); 
    } else if (key > root->data) { 
        root->right = insert(root->right, key); 
    } else { 
        printf("Exists.\n"); 
    } 
 
    return root; 
} 
 
struct Node* del(struct Node* root, int key) { 
    if (root == NULL) { 
        printf("Not found.\n"); 
        return root; 
    } 
 
    if (key < root->data) { 
        root->left = del(root->left, key); 
    } else if (key > root->data) { 
        root->right = del(root->right, key); 
    } else { 
        if (root->left == NULL) { 
            struct Node* temp = root->right; 
            free(root); 
            return temp; 
        } else if (root->right == NULL) { 
            struct Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
 
        struct Node* temp = root->right; 
        while (temp->left != NULL) { 
            temp = temp->left; 
        } 
 
        root->data = temp->data; 
        root->right = del(root->right, temp->data); 
    } 
    return root; 
} 

void inorder(struct Node* root) { 
    if (root == NULL) return; 
    inorder(root->left); 
    printf("%d ", root->data); 
    inorder(root->right); 
} 

void preorder(struct Node* root) { 
    if (root == NULL) return; 
    printf("%d ", root->data); 
    preorder(root->left); 
    preorder(root->right); 
} 

void postorder(struct Node* root) { 
    if (root == NULL) return; 
    postorder(root->left); 
    postorder(root->right); 
    printf("%d ", root->data); 
} 

void display(struct Node* root, int space) { 
    int i; 
    if (root == NULL) return; 
    
    space += 10; 
    
    display(root->right, space); 
    
    printf("\n"); 
    for (i = 10; i < space; i++) { 
        printf(" "); 
    } 
    printf("%d", root->data); 
    
    display(root->left, space); 
} 

int countLeaves(struct Node* root) { 
    if (root == NULL) return 0; 
    if (root->left == NULL && root->right == NULL) return 1; 
    return countLeaves(root->left) + countLeaves(root->right); 
} 

struct Node* getMin(struct Node* root) { 
    if (root == NULL) return NULL; 
    if (root->left == NULL) return root; 
    return getMin(root->left); 
} 

struct Node* getMax(struct Node* root) { 
    if (root == NULL) return NULL; 
    if (root->right == NULL) return root; 
    return getMax(root->right); 
} 
 
int getHeight(struct Node* root) { 
    if (root == NULL) return -1; 
    int leftH = getHeight(root->left); 
    int rightH = getHeight(root->right); 
    if (leftH > rightH) { 
        return leftH + 1; 
    } else { 
        return rightH + 1; 
    } 
} 
 
int main() { 
    struct Node* root = NULL; 
    struct Node* temp = NULL; 
    int choice, val; 
    do { 
        printf("\n--- Menu ---\n"); 
        printf("1. Insert\n"); 
        printf("2. Delete\n"); 
        printf("3. Inorder\n"); 
        printf("4. Preorder\n"); 
        printf("5. Postorder\n"); 
        printf("6. Display Tree\n"); 
        printf("7. Count Leaf Nodes\n"); 
        printf("8. Smallest Number\n"); 
        printf("9. Biggest Number\n"); 
        printf("10. Height\n"); 
        printf("11. Exit\n"); 
        printf("Choice: "); 
        scanf("%d", &choice); 
        switch(choice) { 
            case 1: 
                printf("Value: "); 
                scanf("%d", &val); 
                root = insert(root, val); 
                break; 
            case 2: 
                printf("Value: "); 
                scanf("%d", &val); 
                root = del(root, val); 
                break; 
            case 3: 
                inorder(root); 
                printf("\n"); 
                break; 
            case 4: 
                preorder(root); 
                printf("\n"); 
                break; 
            case 5: 
                postorder(root); 
                printf("\n"); 
                break; 
            case 6: 
                printf("\n--- Tree Structure ---"); 
                display(root, 0); 
                printf("\n\n----------------------\n"); 
                break; 
            case 7: 
                printf("Leaf nodes: %d\n", countLeaves(root)); 
                break; 
            case 8: 
                temp = getMin(root); 
                if (temp != NULL) printf("Smallest: %d\n", temp->data); 
                else printf("Tree is empty.\n"); 
                break; 
            case 9: 
                temp = getMax(root); 
                if (temp != NULL) printf("Biggest: %d\n", temp->data); 
                else printf("Tree is empty.\n"); 
                break; 
            case 10: 
                printf("Height: %d\n", getHeight(root)); 
                break; 
            case 11: 
                exit(0); 
            default: 
                printf("Invalid.\n"); 
        } 
    } while(choice != 11); 
    return 0; 
}