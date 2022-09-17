#include <stdio.h>
#include <stdlib.h>

int countHappyTickets(void) {
    const size_t maskArraySize = 28;
    size_t *maskArray = calloc(maskArraySize, sizeof(size_t));

    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            for (size_t k = 0; k < 10; k++) {
                maskArray[i + j + k]++;
            }
        }
    }
    
    size_t answer = 0;
    for (size_t i = 0; i < maskArraySize; i++) {
        answer += maskArray[i] * maskArray[i];
    }

    free(maskArray);

    return answer;
}

int main(void) {
    printf("Happy tickets count is %d\n", countHappyTickets());

    return 0;
}