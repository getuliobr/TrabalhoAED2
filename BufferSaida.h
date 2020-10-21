#pragma once
#include <stdint.h>
#include "Tipos.h"

ITEM_VENDA* iv_Criar_S(char* arquivo_saida, unsigned int N_registros, FILE** retorno);
void iv_Inserir(char* arqvivo, ITEM_VENDA* buffer, ITEM_VENDA registro);
void iv_Despejar(char* arquivo, ITEM_VENDA* buffer);
void iv_Destruir_S(char* arquivo, ITEM_VENDA* buffer);