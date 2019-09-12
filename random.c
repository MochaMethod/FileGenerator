#include <time.h>
#include <stdio.h>

int randomInteger(int seed, int lower, int upper, int count) {
    int i;
    int num;

    if (seed == 0) {
        srand(time(0)); 
    } else {
        srand(seed);
    }

    int randomNum = rand();

    for (i=0;i<count;i++) {
        num = (randomNum % (upper - lower + 1)) + lower;
    }

    return num;
}