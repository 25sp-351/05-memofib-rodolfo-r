#include "memo.h"

static unsigned long long results[MAX+1];
static ull_func_ptr original_provider;

unsigned long long cache(int val) {
    if (val > MAX) {
        return (*original_provider)(val);
    }
    
    if (results[val] == NOT_PRESENT) {
        results[val] = (*original_provider)(val);
    }
    
    return results[val];
}

ull_func_ptr init_cache(ull_func_ptr real_provider) {
    for (int ix = 0; ix < MAX + 1; ix++) {
        results[ix] = NOT_PRESENT;
    }
    original_provider = real_provider;
    return cache;
}
