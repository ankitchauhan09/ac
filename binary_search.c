#include <stdio.h>
#include <stdlib.h>

void arraySorting(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binary_search(int arr[], int key, int length)
{
    int first = 0, last = length - 1,mid;
    while (first <= last)
    {
        mid=(first+last)/2;
        if (arr[mid] == key)
        {
            printf("Key found at index %d ", mid);
            return mid;
        }
        if (arr[mid] < key)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[100];
    int length;
    printf("Enter the length of the array : ");
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        printf("enter element %d ", i);
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the number you want to search in the array : ");
    scanf("%d", &key);
    arraySorting(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", arr[i]);
    }
    int search_index = binary_search(arr, key, length);
    printf("Key found at index %d ", search_index);
    return 0;
}
