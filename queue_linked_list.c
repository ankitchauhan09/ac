#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front;
struct node *last;

void inqueue(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Queue overflow...\n");
    }
    else
    {
        new->data = val;
        new->next = NULL;
        if (front == NULL)
        {
            front = last = new;
        }
        else
        {
            last->next = new;
            last = new;
        }
    }
}

int dequeue()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("Queue underflow....\n");
    }
    else
    {
        int a = front->data;
        front = front->next;
        free(ptr);
        return a;
    }
}

void linkeListTraversal()
{
    struct node *ptr;
    ptr = front;
    while (ptr != NULL)
    {
        printf("Element value = %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[])
{

    front = NULL;
    last = NULL;
    inqueue(189);
    inqueue(189);
    inqueue(189);
    inqueue(189);
    inqueue(189);
    inqueue(189);
    inqueue(289);
    inqueue(389);
    inqueue(489);
    inqueue(489);
    inqueue(489);
    inqueue(489);
    inqueue(589);
    printf("Dequeued element %d from the queue..\n", dequeue());
    printf("Remaining element in the queue : \n");
    linkeListTraversal();
    return 0;
}
