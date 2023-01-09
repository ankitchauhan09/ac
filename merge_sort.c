//Gand mar denge

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int *first = (int *)malloc(len1 * sizeof(int));
    int *second = (int *)malloc(len2 * sizeof(int));

    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    //merge
    int index1 = 0;
    int index2 = 0; 
    k = start;
    while(index1 < len1 && index2 < len2){
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[k++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

void main()
{
    int arr[20];
    int len;
    printf("Enter the length of the array : ");
    scanf("%d",&len);

    for (int i = 0; i < len; i++)
    {
        printf("element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    printf("Unsorted Array : \n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    mergeSort(arr,0,len-1);
    printf("\nSorted Array : \n");
    for (int i = 0; i < len; i++)
    {
        printf("element %d\n",arr[i]);
    }
    
}
