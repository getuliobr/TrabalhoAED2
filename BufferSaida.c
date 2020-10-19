#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "BufferSaida.h"


ITEM_VENDA* iv_Criar_S(char* arquivo_saida, unsigned int N_registros, FILE** retorno){
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA)*N_registros);
    *retorno = fopen(arquivo_saida, "a+");

    return iv;
}
