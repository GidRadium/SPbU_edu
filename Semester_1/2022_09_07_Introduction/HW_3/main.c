#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int devide(int a, int b) {
    bool isNegative = (a < 0) ^ (b < 0);
    a = abs(a);
    b = abs(b);

    int quotient = 0;
    while ((quotient + 1) * b <= a) {
        quotient++;
    }

    if (isNegative) {
        if (quotient * b < a) {
            quotient++;
        }

        quotient = -quotient;
    }

    return quotient;
}

int main(void) {
    printf("a = ");
    int a = 0;
    scanf("%d", &a);

    printf("b = ");
    int b = 0;
    scanf("%d", &b);
    if (b == 0) {
        printf("Error! Can't divide by 0.\n");
        return 0;
    }

    printf("a / b = %d\n", devide(a, b));

    return 0;
}