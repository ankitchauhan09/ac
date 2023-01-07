#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    printf("Data : %d\n",root->data);
    printf("\nAt the left node of %d\n",root->data);
    //Left traversal
    preorder_traversal(root->left);
    //right traversal
    printf("\nAt the right node of %d\n",root->data);
    preorder_traversal(root->right);
}

struct node *createNode(int val)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(int argc, char const *argv[])
{
    struct node *root = createNode(4);
    struct node *p1 = createNode(5);
    struct node *p2 = createNode(52);
    struct node *p3 = createNode(51);
    struct node *p4 = createNode(35);
    struct node *p5 = createNode(545);

    // linking nodes together
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    printf("Nodes created successfully....\n\n");
    printf("Printing nodes of the tree\n\n");
    preorder_traversal(root);
    return 0;
}
