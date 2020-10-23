#include <stdio.h>
#include <stdlib.h>
#include "Tipos.h"

int main(int argc, char* argv[]) {
  FILE* f = fopen(argv[1],"rb+");
  ITEM_VENDA* iv = (ITEM_VENDA*) malloc(sizeof(ITEM_VENDA));
  while(!feof(f)) {
    fread(iv, 1024, 1, f);
    if(feof(f)) break;
    printf("id = %u, id_venda = %u, desconto = %.2f, data: %u\n", iv->id, iv->id_venda, iv->desconto, iv->data);
  } 
}