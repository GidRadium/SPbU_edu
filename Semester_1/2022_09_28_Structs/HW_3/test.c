#include "PhoneBook.h"

#include <stdbool.h>
#include <stdio.h>

bool testPhoneBookCorrectness() {
    return true;
}

int main(void) {
    bool testsCompleted = true;

    printf("Testsing PhoneBook correctness...\n");
    bool phoneBookTestFeedback = testPhoneBookCorrectness();
    printf("%s\n", phoneBookTestFeedback ? "Success!" : "Failed!");
    testsCompleted &= phoneBookTestFeedback;

    // Space for more tests

    if (!testsCompleted) {
        printf("ERROR! Some tests failed.\n");

        return -1;
    }

    printf("Success! All tests have been passed.\n");

    return 0;
}
