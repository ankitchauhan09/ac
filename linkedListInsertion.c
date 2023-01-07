#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insertInBetween(struct node *head, int index, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    p = head;
    int i = 0;
    while (i != index)
    {
        p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;
    return head;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main(int argc, char const *argv[])
{
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    second->data = 2100;
    second->next = third;
    third->data = 808;
    third->next = NULL;
    linkedListTraversal(head);
    printf("\nInsertion at beginnning");
    head = insertAtBeginning(head, 100);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");
    printf("Insertion At given indexes\n");
    head = insertInBetween(head, 2, 30303);
    linkedListTraversal(head);
    printf("\n");
    printf("Insertion at the end of the Linked List\n");
    head = insertAtEnd(head, 101010);
    linkedListTraversal(head);
    return 0;
}
