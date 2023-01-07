#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int top;
    int bottom;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->bottom == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q){
    if (q->top == q->bottom)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int inqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        return 0;
    }
    else
    {
        q->bottom++;
        q->arr[q->bottom] = data;
        return 1;
    }
}

int dequeue(struct queue *q){
    if (isEmpty(q))
    {
        printf("Queue underflow....\n");
        return 0;
    }
    else{
        q->top++;
        return 1;
    }
}

void seek(struct queue *q,int position){
    if (position < q->top && position > q->bottom)
    {
        printf("Position out of range....\n");
    }
    else{
        printf("Element at position %d is %d",position,q->arr[position-1]);
    }
}

int main(int argc, char const *argv[])
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    int size;
    printf("Enter the size of the queue : ");
    scanf("%d", &size);
    q->size = size;
    q->bottom = -1;
    q->top = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    int choice, data, position;
    do
    {
        printf("\n<------------- Queue Implementation using Linear Array --------------------->\n");
        printf("1 for Inqueue\n2 for Dequeue\n3 for seeking at desired position\n4 or more to exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inqueued in the queue : ");
            scanf("%d", &data);
            if (inqueue(q, data))
            {
                printf("Insertion successfull...\n");
            }
            else
            {
                printf("Insertion unsuccessfull...\n");
            }
            break;
        case 2:
            if (dequeue(q))
            {
                printf("Dequeued successfully...");
            }
            else
            {
                printf("Dequeuing unsuccesfull...\n");
            }
            break;
        case 3:
            printf("Enter the position you want to seek : ");
            scanf("%d", &position);
            seek(q,position);
            break;

        default:
            break;
        }
    } while (choice < 4);
    return 0;
}
