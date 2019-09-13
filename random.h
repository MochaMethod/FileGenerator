#include <time.h>
#include <stdio.h>

uint32_t randomuint32_teger(uint32_t seed, uint32_t lower, uint32_t upper, uint32_t count) {
    uint32_t i;
    uint32_t num;

    if (seed == 0) {
        srand(time(0)); 
    } else {
        srand(seed);
    }

    uint32_t randomNum = rand();

    for (i=0;i<count;i++) {
        num = (randomNum % (upper - lower + 1)) + lower;
    }

    return num;
}