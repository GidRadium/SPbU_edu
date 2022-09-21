#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    int quotient = 0;
    int remainder = dividend;
    while (remainder < 0 || remainder >= abs(divisor))
    {
        quotient += ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        remainder = dividend - divisor * quotient;
    }
    
    return quotient;
}

int main(void) {
    printf("dividend = ");
    int dividend = 0;
    scanf("%d", &dividend);

    printf("divisor = ");
    int divisor = 0;
    scanf("%d", &divisor);
    if (divisor == 0) {
        printf("Error! Can't divide by 0.\n");
        return 0;
    }

    printf("%d / %d = %d\n", dividend, divisor, divide(dividend, divisor));

    return 0;
}