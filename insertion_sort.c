#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int temp = arr[i];
        for (j ; j >= 0 && arr[i] < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int arr[100], n;
    printf("Enter the length of the array : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    printf("\nAfter sorting\n");
    InsertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
