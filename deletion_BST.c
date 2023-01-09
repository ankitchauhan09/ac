#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void InOrder_Traversal(struct node *root)
{
    if (root != NULL)
    {
        InOrder_Traversal(root->left);
        printf("%d\t", root->data);
        InOrder_Traversal(root->right);
    }
}

int searchingBST(struct node *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
        {
            return 1;
        }
        if (key < root->data)
        {
            return searchingBST(root->left, key);
        }
        if (key > root->data)
        {
            return searchingBST(root->right, key);
        }
        return 0;
    }
}

void insertionBST_iterative(struct node *root, int val)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (val == root->data)
        {
            return;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct node *new = createNode(val);
    if (val < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

void insertionBST_recursive(struct node *root, int val)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        prev = root;
        if (val == root->data)
        {
            return;
        }
        if (val < root->data)
        {
            return insertionBST_recursive(root->left, val);
        }
        if (val > root->data)
        {
            return insertionBST_recursive(root->right, val);
        }
    }
    struct node *new = createNode(val);
    if (val > prev->data)
    {
        prev->right = new;
    }
    else
    {
        prev->left = new;
    }
}

struct node * predecessor_BST(struct node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node *deletionBST(struct node *root, int val)
{
    struct node *i_pre;

    if(root == NULL){
        return NULL;
    }
    if(root->left != NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    // searching the node to be deleted....
    if (val > root->data)
    {
        root->right = deletionBST(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = deletionBST(root->left, val);
    }
    // deleting the node after it is found
    else
    {
        i_pre = predecessor_BST(root);
        root->data = i_pre->data;
        root->left = deletionBST(root->left,val);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    struct node *root = createNode(50);
    struct node *p1 = createNode(40);
    struct node *p2 = createNode(60);
    struct node *p3 = createNode(20);
    struct node *p4 = createNode(45);
    struct node *p5 = createNode(55);
    struct node *p6 = createNode(70);

    // linking nodes together
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    // insertionBST_iterative(root, 33);
    // insertionBST_recursive(root, 33);
    printf("Nodes created successfully....\n\n");
    InOrder_Traversal(root);
    printf("\nAfter deletion\n");
    deletionBST(root,50);
    InOrder_Traversal(root);
    return 0;
}
