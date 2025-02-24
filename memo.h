#ifndef MEMO_H
#define MEMO_H

#define MAX 93
#define NOT_PRESENT -1ULL

typedef unsigned long long (*ull_func_ptr)(int n);

ull_func_ptr init_cache(ull_func_ptr real_provider);
unsigned long long cache(int val);

#endif
