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
        // root = root->right;
        printf("%d\t", root->data);
        InOrder_Traversal(root->right);
        // printf("%d\t", root->data);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
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
    insertionBST_recursive(root, 33);
    printf("Nodes created successfully....\n\n");
    printf("%d", root->left->left->right->data);
    return 0;
}
