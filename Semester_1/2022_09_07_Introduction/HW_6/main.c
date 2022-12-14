#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printPrimes(size_t limit) {
    bool *mask = calloc((limit + 1), sizeof(bool));
    for (size_t i = 2; i <= limit; i++) {
        if (!mask[i]) {
            printf("%d ", i);
            for (size_t j = i; j <= limit; j += i) {
                mask[j] = true;
            }
        }
    }

    free(mask);
}

int main(void) {
    printf("Enter limit: ");
    int limit = 0;
    scanf("%d", &limit);
    if (limit < 2) {
        printf("There are no primes less than %d!", limit + 1);
        return 0;
    }

    printf("Primes less than %d:\n", limit + 1);
    printPrimes(limit);
    printf("\n");
    
    return 0;
}