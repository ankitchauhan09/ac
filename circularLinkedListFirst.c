#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void createList(int n){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    int data,i=0;
    if (head == NULL)
    {
        printf("Memory not allocated...");
        exit(0);
    }
    else{
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&data);
        head->data = data;
        head->next = NULL;
        temp = head;
        struct node *new_node;
        for (int i = 1; i < n; i++)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            printf("Enter data for node %d: ",i+1);
            scanf("%d",&data);
            new_node->data = data;
            new_node = new_node->next;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Total number of nodes : ");
    scanf("%d",&n);
    createList(n);
    return 0;
}
