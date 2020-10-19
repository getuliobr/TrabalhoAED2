#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "BufferEntrada.h"

ITEM_VENDA* iv_Criar_E(char* arquivo_entrada ,unsigned int N_registros, FILE** retorno){
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA)*N_registros);
    *retorno = fopen(arquivo_entrada, "r");

    fread(iv,sizeof(ITEM_VENDA), N_registros, *retorno);

    return iv;
}


/*
    Pra busca do próximo dá pra fazer uma struct com a posição atual ou
    fazer uma váriavel a mais em cada função(Próximo, Consumir e Vazio)
*/
ITEM_VENDA iv_Proximo(ITEM_VENDA* buffer){}
ITEM_VENDA iv_Consumir(ITEM_VENDA* buffer){}
int iv_Vazio(char* arquivo_entrada);


void iv_Destruir(FILE** retorno, ITEM_VENDA* registros){
    fclose(*retorno);
    free(registros);
}
