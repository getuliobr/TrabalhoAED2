#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "./Modules/Utils/Utils.h"
#include "./Modules/Utils/Utils.h"
#include "./Modules/Gerador/big_file.h"

int main(int argc, const char* argv[]){
    unsigned int registroCount = atoi(argv[1]);
    unsigned int bytes = atoi(argv[2]);
    int i = atoi(argv[3]);
    
    gerar_array_iv("in.dat", registroCount, 42);

    int curr = pow(2, i);
    printf("Bytes/%d\n", curr);
    clock_t t = clock();
    ordena("in.dat", bytes, bytes/curr, "out.dat");
    t = clock() - t;
    printf("Tempo: %f\n", (((float)t)/CLOCKS_PER_SEC));
}