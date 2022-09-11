#include <stdio.h>

void swapIntegers(int *a, int *b)
{
    *a = (*a ^ *b);
    *b = (*a ^ *b);
    *a = (*a ^ *b);
}

int main(void)
{
    printf("a = ");
    int a = 0;
    scanf("%d", &a);
    printf("b = ");
    int b = 0;
    scanf("%d", &b);

    swapIntegers(&a, &b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}