#include <time.h>
#include <stdio.h>

/*
    The "randomInteger" function returns an integer between
    a given range of numbers.

    @param seed - Used to seed the rand() function.

    @param lower - The minimum range (floor).

    @param upper - The maximum range (ceiling).

    @param count - Iterations to run before returning integer.
*/
uint32_t randominteger(uint32_t seed, uint32_t lower, uint32_t upper, uint32_t count) {
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