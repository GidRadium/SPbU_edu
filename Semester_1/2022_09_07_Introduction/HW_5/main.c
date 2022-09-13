#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isBracketSequenceCorrect(char* bracketSequence, int bracketSequenceSize)
{
    int counter = 0;
    for (int i = 0; i < bracketSequenceSize; i++)
    {
        if (bracketSequence[i] == '(')
        {
            counter++;
        }
        else if (bracketSequence[i] == ')')
        {
            counter--;
        }
        else
        {
            return false;
        }
        
        if (counter < 0)
        {
            return false;
        }
    }

    if (counter != 0)
    {
        return false;
    }

    return true;
}

int main(void)
{
    printf("Enter bracket sequence size: ");
    int bracketSequenceSize = 0;
    scanf("%d", &bracketSequenceSize);
    if (bracketSequenceSize < 0)
    {
        printf("ERROR! Bracket sequence size can't be less than 0.\n");
        return -1;
    }

    printf("Enter bracket sequence: ");
    char *bracketSequence = malloc((bracketSequenceSize + 1) * sizeof(char));
    bracketSequence[bracketSequenceSize] = '\0';
    fflush(stdin);
    fgets(bracketSequence, bracketSequenceSize + 1, stdin);
    
    printf(isBracketSequenceCorrect(bracketSequence, bracketSequenceSize) ? "Bracket sequence is correct!\n" : "Bracket sequence is NOT correct!\n");
    
    return 0;
}