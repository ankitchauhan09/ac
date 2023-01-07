#include <stdio.h>
#include <stdlib.h>

typedef int* pointer;
struct myArray{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArray(struct myArray *a){
    int tSize;
    printf("Enter the size of the array : ");
    scanf("%d",&tSize);
    a->totalSize = tSize;
    a->ptr = (int *) malloc(a->totalSize * sizeof(int));
}

void setValue(struct myArray *a){
    int uSize;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&uSize);
    a->usedSize = uSize;
    int n;
    for (int i = 0; i < (a->usedSize); i++)
    {
        printf("enter element %d ",i);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
}

void display(struct myArray *a){
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}

void insert_element(struct myArray *a){
    pointer key,index;
    key = (int *) malloc(1*sizeof(int));
    index = (int *) malloc(1*sizeof(int));
    printf("Enter the number you want to insert in the array : ");
    scanf("%d",*key);
    printf("Enter the index at which you want to insert the number : ");
    scanf("%d",*index);

    for (int i = a->usedSize; i >= *index; i--)
    {
        (a->ptr)[i+1] = (a->ptr)[i]; 
    }
    (a->ptr)[*(index)] = *key;
    free(key);
    free(key);
}

int main(int argc, char const *argv[])
{
    struct myArray arr;
    createArray(&arr);
    setValue(&arr);
    display(&arr);
    insert_element(&arr);
    display(&arr);
    return 0;
}
