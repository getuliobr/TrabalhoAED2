#pragma once
#include <stdint.h>
#include "Tipos.h"

BUFF* iv_Criar_E(char* arquivo_entrada ,unsigned int N_registros, FILE** retorno);
ITEM_VENDA iv_Proximo(BUFF* buffer);
ITEM_VENDA iv_Consumir(BUFF* buffer);
int iv_Vazio(FILE** arq);
void iv_Destruir(FILE** retorno, ITEM_VENDA* registros);
//Quicksort
int compare(const void *a, const void *b);
