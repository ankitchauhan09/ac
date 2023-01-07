#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int top;
    int bottom;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->bottom == q->top){
        return 1;
    }
    else{
        return 0;
    }
}

void inqueue(struct queue *q,int val){
    if ((q->bottom+1)%q->size == q->top)
    {
        printf("queue overflow...\n");
    }
    else{
        q->bottom = (q->bottom+1)%q->size;
        q->arr[q->bottom] = val;
    }
}

void dequeue(struct queue *q){
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else{
        q->top = (q->top+1)%q->size;
    }
}

int main(int argc, char const *argv[])
{
    struct queue q;
    q.bottom = q.top = -1;
    q.size = 1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    inqueue(&q,89);
    inqueue(&q,89);
    dequeue(&q);
if (isEmpty(&q))
{
    printf("Queue is empty...\n");
}
else{
    printf("Queue is not empty.....\n");
}

    return 0;
}
