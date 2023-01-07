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

int isBST(struct node * root){
    static struct node * prev = NULL;
    if (root != NULL)
    {
        if(!isBST(root->left)){
            return 0;
        }
        if( prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
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
    printf("Nodes created successfully....\n\n");
    printf("Printing nodes of the tree\n\n");
    InOrder_Traversal(root);
    printf("\nChecking binary tree\n");
    if (isBST(root))
    {
        printf("Yes");
    }
    else printf("No");
    
    return 0;
}
