#include <stdio.h>
#include <stdlib.h>
#include "./Modules/Utils/Utils.h"

int main(int argc, char* argv[]) {
  FILE* f = fopen(argv[1],"rb+");
  ITEM_VENDA* iv;
  int i = 0;
  while(1) {
    iv = (ITEM_VENDA*) malloc(sizeof(ITEM_VENDA));
    fread(iv, 1024, 1, f);
    if(feof(f)) break;
    if(iv->id != i) {
      printf("ID: %d era para ser %d\n", iv->id, i);
      break;
    }
    printf("id = %u, id_venda = %u, desconto = %.2f, data: %u\n", iv->id, iv->id_venda, iv->desconto, iv->data);
    free(iv);
    i++;
  }
  printf("%d\n", i);
}