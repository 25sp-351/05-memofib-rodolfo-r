#include <stdio.h>
#include "fib.h"
#include "memo.h"

ull_func_ptr fibby_provider;

unsigned long long fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    return (*fibby_provider)(n - 1) + (*fibby_provider)(n - 2);
}

#ifndef TESTING
int main() {
    fibby_provider = init_cache(fibonacci);
    int n;
    printf("enter a number: ");
    scanf("%d", &n);
    if(n < 0 || n > MAX) {
        printf("Try again. (0 and 93)");
        return 0;
    }
    printf("fibonacci of %d is %llu\n", n, (*fibby_provider)(n));
    return 0;
}
#endif