#include <stdio.h>
#include <stdlib.h>

int countHappyTickets(void)
{
    const int maskArraySize = 28;
    int *maskArray = calloc(maskArraySize, sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                maskArray[i + j + k]++;
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < maskArraySize; i++)
    {
        answer += maskArray[i] * maskArray[i];
    }

    free(maskArray);

    return answer;
}

int main(void)
{
    printf("Happy tickets count is %d\b", countHappyTickets());

    return 0;
}