#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createLL(struct node *head, int n)
{
    struct node *temp, *nextNode;
    int data, i;
    printf("Enter the data for node 1 : ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (int i = 1; i < n; i++)
    {
        nextNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d : ", i + 1);
        scanf("%d", &data);
        nextNode->data = data;
        nextNode->next = NULL;
        temp->next = nextNode;
        temp = temp->next;
    }
}

void reverseLL(struct node *head)
{
    struct node *prevNode, *curNode;
 
    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;
 
        prevNode->next = NULL; //convert the first node as last
 
        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;
 
            prevNode = curNode;
            curNode = head;
        }
        head = prevNode; //convert the last node as head
    }
}

void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("Enter total no. of nodes : ");
    scanf("%d", &n);
    createLL(head, n);
    display(head);
    printf("\nAfter reversing....\n");
    reverseLL(head);
    display(head);
    return 0;
}
