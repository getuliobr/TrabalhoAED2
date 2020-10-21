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

BUFF* iv_Criar_E(char* arquivo_entrada ,unsigned int N_registros, FILE** retorno);
ITEM_VENDA iv_Proximo(BUFF* buffer);
ITEM_VENDA iv_Consumir(BUFF* buffer);
int iv_Vazio(FILE** arq);
void iv_Destruir(FILE** retorno, ITEM_VENDA* registros);
