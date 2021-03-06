#pragma once
#include <stdint.h>
#include "../Utils/Utils.h"

BUFF* iv_Criar_E(const char* arquivo_entrada ,unsigned int N_registros, FILE** retorno);
ITEM_VENDA iv_Proximo(BUFF* buffer);
ITEM_VENDA iv_Consumir(BUFF* buffer);
int iv_Vazio(BUFF* buffer);
void iv_Destruir_E(BUFF* buffer);
//Quicksort
int compare(const void *a, const void *b);
