#pragma once
#include <stdint.h>

typedef struct ITEM_VENDA{
    uint32_t id;
    uint32_t id_venda;
    uint32_t data;
    float desconto;
    char obs[1008];
}ITEM_VENDA;

typedef struct BUFF{
    ITEM_VENDA* iv;
    int tam;
    int pos;
    FILE** arq;
}BUFF;

BUFF* iv_Criar_S(char* arquivo_saida, unsigned int N_registros, FILE** retorno);
void iv_Inserir(BUFF* buffer, ITEM_VENDA registro);
void iv_Despejar(BUFF* buffer);
void iv_Destruir_S(BUFF* buffer);