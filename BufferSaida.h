#pragma once
#include <stdint.h>
#include "Tipos.h"

BUFF* iv_Criar_S(char* arquivo_saida, unsigned int N_registros, FILE** retorno);
void iv_Inserir(BUFF* buffer, ITEM_VENDA registro);
void iv_Despejar(BUFF* buffer);
void iv_Destruir_S(BUFF* buffer);