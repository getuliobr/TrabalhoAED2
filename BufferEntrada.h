#pragma once
#include <stdint.h>

typedef struct ITEM_VENDA{
    uint32_t id;
    uint32_t id_venda;
    uint32_t data;
    float desconto;
    char obs[1008];
}ITEM_VENDA;

ITEM_VENDA* iv_Criar_E(char* arquivo_entrada ,unsigned int N_registros, FILE** retorno);
ITEM_VENDA iv_Proximo(ITEM_VENDA* buffer);
ITEM_VENDA iv_Consumir(ITEM_VENDA* buffer);
int iv_Vazio(char* arquivo_entrada);
void iv_Destruir(FILE** retorno, ITEM_VENDA* registros);
