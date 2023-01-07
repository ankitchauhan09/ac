#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void createLinkedList(struct node *head,int n){
    struct node *temp,*nextNode;
    int data,i;
    printf("Enter the data for fist node : ");
    scanf("%d",&data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (int i = 1; i < n; i++)
    {
       nextNode = (struct node *)malloc(sizeof(struct node));
       printf("Enter the date for node %d : ",i+1);
       scanf("%d",&data);
       nextNode->data = data;
       nextNode->next = NULL;
       temp->next = nextNode;
       temp = temp->next;
    }
}

void displayLinkedList(struct node *head){
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    struct node * head = (struct node *)malloc (sizeof (struct node));
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    createLinkedList(head,n);
    displayLinkedList(head);
    return 0;
}
