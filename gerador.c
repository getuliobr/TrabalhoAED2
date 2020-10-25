#include "./Modules/Gerador/big_file.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char* argv[]){
  unsigned int registroCount = atoi(argv[1]);
  gerar_array_iv("in.dat", registroCount, 42);
}