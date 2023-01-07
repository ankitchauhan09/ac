#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * createNodeList(int n)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (head == NULL)
    {
        printf("Memory not allocated for the linked list....\n");
        exit(0);
    }
    else
    {
        int data, i;
        printf("Enter the data for node 1 : ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        struct node *new;
        for (int i = 1; i < n; i++)
        {
            new = (struct node *)malloc(sizeof(struct node));
            if (new == NULL)
            {
                printf("Memory not allocated for the remaining nodes....\n");
                exit(0);
            }
            else
            {
                printf("Enter data for node %d : ", i + 1);
                scanf("%d", &data);
                new->data = data;
                new->next = NULL;
                temp->next = new;
                temp = temp->next;
            }
        }
        printf("Linked List created successfully....\n");
        return head;
    }
}

void display_linked_list(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

struct node * deletion_at_beginning(struct node *head){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node * deletion_at_index(struct node *head,int index){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    temp = head;
    ptr = head->next;
    int i = 1;
    while (i != index)
    {
        temp = temp->next;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    free(ptr);
    return head;
}

int main(int argc, char const *argv[])
{
    int n;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("How many nodes you want to create : ");
    scanf("%d", &n);
    head = createNodeList(n);
    display_linked_list(head);
    printf("\n");
    head = deletion_at_beginning(head);
    display_linked_list(head);
    printf("\n");
    head = deletion_at_index(head,3);
    return 0;
}
