int countLeafNodes(struct Node* root) 
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
 
int countNodes(struct Node* root) 
{
    if (root == NULL) 
{
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
 
 
int findMax(struct Node* root) 
{
    if (root == NULL) 
{
        printf("Tree is empty!\n");
        exit(1);
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}
 
int findMin(struct Node* root) 
{
    if (root == NULL) {
        printf("Tree is empty!\n");
        exit(1);
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
 
int height(struct Node* root) 
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
   return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}