#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int arr[100], len, flag = 0;
    printf("Enter the length of the array : ");
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        printf("enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < len - 1; i++)
    {
        printf("            i = %d : \n", i);
        for (int j = 0; j < len - i-1; j++)
        {
                flag = 1;
            if (arr[j] > arr[j + 1])
            {
                flag = 0;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printf("j = %d\n", j);
        }
        printf("\n\t%d\t\n",flag);
        if (flag == 1)
        {
        break;
        }
        
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
