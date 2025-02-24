#include <stdio.h>
#include <assert.h>
#include "fib.h"

// Function to check if a value is in cache
unsigned long long search_cache(int n) {
    if (n > 93) return 0;
    return (*fibby_provider)(n);
}

int test_given_input(int input, unsigned long long expected_value) {
    printf("--------------------\n");
    printf("Running test_given_input(%d)...\n", input);
    
    // First calculation
    unsigned long long result = (*fibby_provider)(input);
    printf("Running: fibonacci(%d)\n", input);
    printf("Expected Output: Fibonacci(%d) = %llu\n", input, expected_value);
    printf("Actual Output: Fibonacci(%d) = %llu\n", input, result);
    
    if (result == expected_value)
        printf("fibonacci(%d) passed.\n", input);
    else
        printf("fibonacci(%d) failed.\n", input);

    // Check cache
    printf("Checking cache for input and expected output ...\n");
    printf("Running search_cache(%d)\n", input);
    unsigned long long cache_result = search_cache(input);
    printf("Expected Output: %llu\n", expected_value);
    printf("Actual Output: %llu\n", cache_result);
    
    if (cache_result == expected_value)
        printf("search_cache(%d) passed.\n", input);
    else
        printf("search_cache(%d) failed.\n", input);
    
    return 0;
}

void run_all_tests() {
    fibby_provider = init_cache(fibonacci);
    
    // Test base cases
    test_given_input(0, 0);
    test_given_input(1, 1);
    test_given_input(2, 1);
    test_given_input(3, 2);
    test_given_input(4, 3);
    test_given_input(5, 5);
    test_given_input(6, 8);
    test_given_input(10, 55);
    test_given_input(20, 6765);
    test_given_input(30, 832040);
    test_given_input(40, 102334155);
    test_given_input(50, 12586269025);
    test_given_input(92, 7540113804746346429);
    
    printf("\nAll test cases completed!\n");
}

int main() {
    run_all_tests();
    return 0;
}