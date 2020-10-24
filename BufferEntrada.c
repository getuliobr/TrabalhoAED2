#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "BufferEntrada.h"

static ITEM_VENDA* iv_Ler_Novo(unsigned int N_registros, FILE** retorno){
    ITEM_VENDA* iv = calloc(N_registros,sizeof(ITEM_VENDA));
    fread(iv, 1024, N_registros, *retorno);
    return iv;
}

BUFF* iv_Criar_E(char* arquivo_entrada ,unsigned int N_registros, FILE** retorno){
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA)*N_registros);
    BUFF* b = malloc(sizeof(BUFF));


    /*
    *Verifica se N_Registros é maior que a quantidade de registros que existem no arquivo
    Pega a posição inicial e guarda na posi
    Procura o eof e guarda no posf
    retorna para a posição inicial
    faz a comparação
    */

    if(*retorno == NULL)
        *retorno = fopen(arquivo_entrada, "rb+");

    // long int posi = ftell(*retorno);
    // fseek(*retorno, 0, SEEK_END);
    // long int posf = ftell(*retorno);
    // fseek(*retorno, posi, SEEK_SET);
    // if(N_registros > (posi-posf)/1024)
    //     N_registros = (posi-posf)/1024;

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
        buffer->pos = 0;
    }

    return buffer->iv[buffer->pos++];
}

int iv_Vazio(FILE** arq){
    return feof(*arq);
}

void iv_Destruir_E(BUFF* buffer){
    free(buffer->iv);
    fclose(*buffer->arq);
    free(buffer);
}

int compare(const void *a, const void *b){
    ITEM_VENDA *a1 = (ITEM_VENDA*)a;
    ITEM_VENDA *b1 = (ITEM_VENDA*)b;
    return (a1->id - b1->id);
}
