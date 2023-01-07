#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow....\n");
    }
    else
    {
        ptr->top += 1;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow....\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top -= 1;
        return val;
    }
}

int seek(struct stack *ptr, int index)
{
    if (index - 1 > ptr->top)
    {
        printf("No elements at given index...\n");
        return -1;
    }
    else
    {
        return ptr->arr[index - 1];
    }
}

int main(int argc, char const *argv[])
{
    int choice;
    int val;
    int index;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 10;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack created successfully....\n");
    do
    {
        printf("\n<------------------ Stack Operations --------------------->\n");
        printf("1 for Push\n2 for Pop\n3 for seeking\n4 or more to exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter the value you want to push in the stack : ");
            scanf("%d", &val);
            push(s, val);
            printf("Value %d pushed in the stack successfully....\n", val);
            break;
        case 2:
            printf("Value %d popped out from the stack successfully.....", pop(s));
            break;
        case 3:

            printf("Enter the index you want to seek : ");
            scanf("%d", &index);
            printf("Value at index %d of the stack is %d\n", index, seek(s, index));
            break;

        default:
            break;
        }
    } while (choice < 4);
    return 0;
}
