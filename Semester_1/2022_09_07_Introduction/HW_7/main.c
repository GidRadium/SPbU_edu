#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int countNumberOfOccurrences(char* string, int stringSize, char* string1, int string1Size)
{
    int* zArray = calloc(stringSize, sizeof(int));
    for (int i = 0; i < stringSize; i++)
    {
        for (int j = 0; j < string1Size; j++)
        {
            if (i + j < stringSize && string[i + j] == string1[j])
            {
                zArray[i]++;
            }
            else
            {
                break;
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < stringSize; i++)
    {
        counter += (zArray[i] == string1Size);
    }

    return counter;
}

int main(void)
{
    printf("Enter S size: ");
    int stringSize = 0;
    scanf("%d", &stringSize);
    if (stringSize < 0)
    {
        printf("ERROR! S size can't be less than 0!\n");
        return -1;
    }

    printf("Enter S: ");
    char *string = malloc((stringSize + 1) * sizeof(char));
    string[stringSize] = '\0';
    fflush(stdin);
    fgets(string, stringSize + 1, stdin);

    printf("Enter S1 size: ");
    int string1Size = 0;
    scanf("%d", &string1Size);
    if (string1Size < 0)
    {
        printf("ERROR! S1 size can't be less than 0!\n");
        return -1;
    }

    printf("Enter S1: ");
    char *string1 = malloc((string1Size + 1) * sizeof(char));
    string1[string1Size] = '\0';
    fflush(stdin);
    fgets(string1, string1Size + 1, stdin);

    printf("The number of occurrences of S1 in S is: %d\n", countNumberOfOccurrences(string, stringSize, string1, string1Size));
    
    return 0;
}