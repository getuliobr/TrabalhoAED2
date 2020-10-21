#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "BufferEntrada.h"

static ITEM_VENDA* iv_Ler_Novo(unsigned int N_registros, FILE** retorno){
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA)*N_registros);
    fread(iv, sizeof(ITEM_VENDA), N_registros, *retorno);
    return iv;
}

BUFF* iv_Criar_E(char* arquivo_entrada ,unsigned int N_registros, FILE** retorno){
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA)*N_registros);
    BUFF* b = malloc(sizeof(BUFF));

    if(*retorno == NULL)
        *retorno = fopen(arquivo_entrada, "r");

    b->iv = iv_Ler_Novo(N_registros, retorno);
    b->pos = 0;
    b->tam = N_registros;
    b->arq = retorno;
    return b;
}

ITEM_VENDA iv_Proximo(BUFF* buffer){
    return buffer->iv[buffer->pos];
}

ITEM_VENDA iv_Consumir(BUFF* buffer){
    if(buffer->pos == buffer->tam){
        free(buffer->iv);
        buffer->iv = iv_Ler_Novo(buffer->tam, buffer->arq);
    }

    return buffer->iv[buffer->pos++];
}

int iv_Vazio(FILE** arq){
    return feof(*arq);
}

void iv_Destruir(FILE** retorno, ITEM_VENDA* registros){
    fclose(*retorno);
    free(registros);
}
