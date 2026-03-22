// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
uint64_t result = num;
    while (num != 1) {
        if (num % 2 == 0)
            num /= 2;
        else
            num = 3 * num + 1;
        if (num > result)
            result = num;
    }
    return result;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int result = 1;
    while (num != 1) {
        if (num % 2 == 0)
            num /= 2;
        else
            num = num * 3 + 1;
        result++;
    }
    return result;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int result = static_cast<unsigned int>(lbound);
    *maxlen = 0;
    for (uint64_t i = lbound; i <= rbound; i++) {
        unsigned int l = collatzLen(i);
        if (l > *maxlen) {
            *maxlen = l;
            result = static_cast<unsigned int>(i);
        }
    }
    return result;
}
