//non recursive
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node* left;
    struct node* right;
};

void inorderTraversal(struct node* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d->",root->item);
    inorderTraversal(root->right);
}
int main()
{
    int choice;
    printf("-----Binary Search-----\n");
    printf("Choose an option:");
    printf("\n1.Insert\n2.Inorder\n3.Postorder\n4.Preorder\n5.Display\n6.Exit");
    switch(choice)
    case 1:

}