#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int countHappyTickets()
{
    const int maskArraySize = 28;
    int *maskArray = malloc(maskArraySize * sizeof(int));
    
    for (int i = 0; i < maskArraySize; i++)
    {
        maskArray[i] = 0;
    }

    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 10; c++)
                maskArray[a + b + c]++;
    
    int answer = 0;
    for (int i = 0; i < maskArraySize; i++)
    {
        answer += maskArray[i] * maskArray[i];
    }           

    return answer;
}

int main(int argc, char *argv[])
{
    printf("Happy tickets count is %d\b", countHappyTickets());
    return 0;
}