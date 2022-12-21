#include <stdio.h>

#include "checkString.h"

bool testAndReport(char *string, bool correctAnswer) {
    if (checkString(string) != correctAnswer) {
        printf("ERROR: Answer for %s is %s\n", string, (correctAnswer ? "false" : "true"));
        return false;
    }

    printf("Correct!\n");
    return true;
}

int main(void) {
    bool result = true;

    result &= testAndReport("A@A.A", true);
    result &= testAndReport("0@9.A.Z", true);
    result &= testAndReport("0@0.0", false);
    result &= testAndReport("A@@A.Z", false);
    result &= testAndReport("A_B.C+Z-_-@A.BCZ-.S-J-D.Z.XXX.C", true);

    if (!result) {
        printf("Some tests failed.\n");
        return -1;
    }

    printf("All tests passed!");
    return 0;
}
