#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define EPSILON 0.00001

double powLinear(double number, int power) {
    if (power == 0) {
        return 1;
    }

    bool isLessThanZero = (power < 0);
    power = abs(power);
    double result = 1;
    for (int i = 0; i < power; i++) {
        result *= number;
    }

    return (isLessThanZero ? 1 / result : result);
}

double powRecursive(double number, int power) {
    if (power == 0) {
        return 1;
    }

    double preresult = powRecursive(number, power / 2);
    return preresult * preresult * (power % 2 ? (power < 0 ? 1 / number : number) : 1);
}

struct CorrectTest {
    double number;
    int power;
    double result;
};

struct CorrectTest createCorrectTest(double number, int power, double result) {
    struct CorrectTest test;
    test.number = number;
    test.power = power;
    test.result = result;
    return test;
}

bool handleTest(struct CorrectTest test, double result, char* functionName) {
    if (result < test.result - EPSILON || result > test.result + EPSILON) {
        printf("ERROR! %s(%lf, %d) = %lf, but right answer is between %lf and %lf.\n", 
            functionName, test.number, test.power, result, test.result - EPSILON, test.result + EPSILON);
        return false;
    }

    return true;
}

bool testCorrectness(void) {
    const size_t testArraySize = 20;
    struct CorrectTest testArray[20] = {
        createCorrectTest(1, 1, 1),
        createCorrectTest(1, 100, 1),
        createCorrectTest(2, 0, 1),
        createCorrectTest(100, 0, 1),

        createCorrectTest(2, 1, 2),
        createCorrectTest(2, 2, 4),
        createCorrectTest(2, 10, 1024),
        createCorrectTest(10, 6, 1000000),

        createCorrectTest(0.5, 0, 1),
        createCorrectTest(0.5, 1, 0.5),
        createCorrectTest(0.5, 2, 0.25),
        createCorrectTest(0.5, 10, 0.0009765625),

        createCorrectTest(1, -1, 1),
        createCorrectTest(0.1, -1, 10),
        createCorrectTest(10, -5, 0.00001),
        createCorrectTest(1.0/1024, -1, 1024),

        createCorrectTest(-1, 1, -1),
        createCorrectTest(-10, 4, 10000),
        createCorrectTest(-0.5, -5, -32),
        createCorrectTest(-0.1, 10, 0.0000000001)
    };

    bool testsComleted = true;
    for (int i = 0; i < testArraySize; i++) {
        testsComleted &= 
            handleTest(testArray[i], powLinear(testArray[i].number, testArray[i].power), "powLinear") ||
            handleTest(testArray[i], powRecursive(testArray[i].number, testArray[i].power), "powRecursive");
    }

    return testsComleted;
}

int main(void) {
    if (!testCorrectness()) {
        return -1;
    }
    printf("Tests completed!\n");

    printf("Enter number: ");
    double number = 0;
    scanf("%lf", &number);
    printf("Enter power: ");
    int power = 0;
    scanf("%d", &power);

    printf("pow(%lf, %d) = %lf\n", number, power, powRecursive(number, power));

    return 0;
}