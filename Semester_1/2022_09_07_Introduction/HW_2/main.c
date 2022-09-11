#include <stdio.h>
#include <stdlib.h>

int countZeros(int *array, int arraySize)
{
    int counter = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == 0)
        {
            counter++;
        }
    }

    return counter;
}

int main(void)
{
    printf("Enter array size: ");
    int arraySize = 0;
    scanf("%d", &arraySize);
    if (arraySize < 0)
    {
        printf("ERROR! Array size can't be less than 0.\n");
        return -1;
    }
    
    printf("Enter array:\n");
    int *array = malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Count of zeros: %d", countZeros(array, arraySize));
    
    return 0;
}