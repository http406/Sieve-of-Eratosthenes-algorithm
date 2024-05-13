// Input is the number upto you print the prime
// numbers e.g. 1000
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieve_of_eratosthenes(int limit) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool *prime = (bool *)malloc((limit + 1) * sizeof(bool));
    for (int i = 0; i <= limit; ++i) {
        prime[i] = true;
    }
    
    for (int p = 2; p * p <= limit; ++p) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }

    // Print prime numbers
    printf("Prime numbers up to %d are:\n", limit);
    for (int p = 2; p <= limit; ++p) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");

    free(prime);
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    sieve_of_eratosthenes(limit);
    return 0;
}
