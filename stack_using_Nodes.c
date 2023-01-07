#include <stdio.h>
#include <stdlib.h>
#define MAX 100;

struct node
{
    int data;
    struct node *next;
};

int total_nodes_count = 0;

int isEmpty(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Stack overflow");
    }
    else
    {
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        total_nodes_count++;
        return top;
    }
}

struct node *pop(struct node *top){
    struct node *ptr;
    ptr = top;
    top = top->next;
    free(ptr);
    total_nodes_count--;
    return top;
}

void peek_stack(struct node *top, int position)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = top;
    for (int i = 1; i < total_nodes_count + 1 - position; i++)
    {
        ptr = ptr->next;
    }
    printf("The element at position %d is %d\n", position, ptr->data);
}

int main(int argc, char const *argv[])
{
    struct node *top = (struct node *)malloc(sizeof(struct node));
    // top = push(top,1);
    // top = push(top,2);
    // top = push(top,3);
    // top = push(top,4);
    // top = push(top,5);
    // top = push(top,6);
    // top = push(top,7);
    // top = push(top,8);
    // top = push(top,9);
    // top = push(top,10);
    // printf("Data pushed successfully...\n");
    // printf("Data pushed is = %d\nAnd total nodes are %d\n",top->data,total_nodes_count);
    // top = pop(top);
    // printf("Data popped successfully from the stack...%d\nAnd total nodes are %d\n",top->data,total_nodes_count);
    // peek_stack(top,8);
    int choice, data;
    printf("<----------- Stack Operations using Nodes ----------------->\n");
    printf("1 for Push\n2 for Pop\n3 for seek\n4 or more to exit : ");
    scanf("%d", &choice);
    switch (data)
    {
    case 1:
        printf("Enter data you want to push in the stack : ");
        scanf("%d", &data);
        top = push(top, data);
        break;
    case 2:
    
        top = pop(top);
        break;
    case /* constant-expression */:
        /* code */
        break;

    default:
        break;
    }
    return 0;
}
