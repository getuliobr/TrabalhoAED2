#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "BufferSaida.h"

ITEM_VENDA* iv_Criar(unsigned int N_registros){
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA)*N_registros);
}

BUFF* iv_Criar_S(char* arquivo_saida, unsigned int N_registros, FILE** retorno){
    
    if(*retorno == NULL)
        *retorno = fopen(arquivo_saida, "ab+");

    return iv_Criar(N_registros);
}

void iv_Inserir(BUFF* buffer, ITEM_VENDA registro){
    buffer->iv[buffer->pos++] = registro;

    if(buffer->pos == buffer->tam){
        iv_Despejar(buffer);   
    }

}

void iv_Despejar(BUFF* buffer){
    fwrite(buffer->iv, sizeof(ITEM_VENDA), buffer->tam, *buffer->arq);
    free(buffer->iv);
        buffer->iv = iv_Criar(buffer->tam);
        buffer->tam = 0;
}

void iv_Destruir_S(BUFF* buffer){
    free(buffer->iv);
    fclose(*buffer->arq);
    free(buffer);
}
