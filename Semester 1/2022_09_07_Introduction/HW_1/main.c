#include <stdio.h>

void swapIntegers(int *a, int *b)
{
    *a = (*a ^ *b);
    *b = (*a ^ *b);
    *a = (*a ^ *b);
}

int main(int argc, char *argv[])
{
    int a = 0;
    int b = 0;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    swapIntegers(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}