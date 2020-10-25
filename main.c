#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "./Modules/Utils/Utils.h"
#include "./Modules/Utils/Utils.h"

int main(int argc, const char* argv[]){
    unsigned int bytes = 268435456; // atoi(argv[1]);
    unsigned int dividoPor = 4; // atoi(argv[2]);

    printf("Bytes/%u B: %u\n", dividoPor, bytes);
    clock_t t = clock();
    ordena("in.dat", bytes, bytes/dividoPor, "out.dat");
    t = clock() - t;
    printf("Tempo: %f\n", (((float)t)/CLOCKS_PER_SEC));
}