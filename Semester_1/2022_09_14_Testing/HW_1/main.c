#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swapLongs(long long *a, long long *b) {
    *a = (*a ^ *b);
    *b = (*a ^ *b);
    *a = (*a ^ *b);
}

long long fibonacciLinear(int number) {
    if (number == 0) {
        return 0;
    }

    long long a = 0;
    long long b = 1;

    if (number > 0) {
        for (int i = 1; i < number; i++) {
            a += b;
            swapLongs(&a, &b);
        }
    } else {
        for (int i = -1; i > number; i--) {
            a -= b;
            swapLongs(&a, &b);
        }
    }

    return b;
}

long long fibonacciRecursive(int number) {
    if (number == 0) {
        return 0;
    }
    if (number == 1 || number == -1) {
        return 1;
    }

    if (number > 0) {
        return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2);
    } else {
        return fibonacciRecursive(number + 2) - fibonacciRecursive(number + 1);
    }
}

bool testCorrection(void) {
    bool testsComleted = true;

    size_t testArraySize = 13;
    int testArray[13] = {-10, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 10};
    int resultArray[13] = {-55, 5, -3, 2, -1, 1, 0, 1, 1, 2, 3, 5, 55};

    for (int i = 0; i < testArraySize; i++) {
        if (fibonacciLinear(testArray[i]) != resultArray[i]) {
            printf("ERROR! fibonacciLinear(%d) = %lld, but right answer is %lld.\n", 
                testArray[i], fibonacciLinear(testArray[i]), resultArray[i]);
            testsComleted = false;
        }

        if (fibonacciRecursive(testArray[i]) != resultArray[i]) {
            printf("ERROR! fibonacciRecursive(%d) = %lld, but right answer is %lld.\n", 
                testArray[i], fibonacciRecursive(testArray[i]), resultArray[i]);
            testsComleted = false;
        }
    }

    return testsComleted;
}

void testDuration(void) {
    clock_t startLinear = 0;
    clock_t stopLinear = 0;
    clock_t startRecursive = 0;
    clock_t stopRecursive = 0;

    printf("Linear VS Recursive:\n");

    for (int i = 0; i <= 40; i++) {
        startLinear = clock();
        fibonacciLinear(i);
        stopLinear = clock();
        startRecursive = clock();
        fibonacciRecursive(i);
        stopRecursive = clock();

        printf("N = %d) %2.3f | %2.3f seconds\n", i, 
            (double)(stopLinear - startLinear) / CLOCKS_PER_SEC, 
            (double)(stopRecursive - startRecursive) / CLOCKS_PER_SEC);
    }
}

int main(void) {
    if (!testCorrection()) {
        return -1;
    }

    testDuration();

    printf("Enter number: ");
    int number = 0;
    scanf("%d", &number);
    printf("Fibonacci(%d) = %lld\n", number, fibonacciLinear(number));

    return 0;
}