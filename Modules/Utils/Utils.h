#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdio.h>


// Area para os tipos
typedef struct ITEM_VENDA {
    uint32_t id;
    uint32_t id_venda;
    uint32_t data;
    float desconto;
    char obs[1008];
} ITEM_VENDA;

typedef struct BUFF{
    ITEM_VENDA* iv;
    unsigned int totalIv;
    unsigned int tam;
    unsigned int pos;
    FILE** arq;
}BUFF;

/**
* @param fp ponteiro para o arquivo
* @return tamanho do arquivo em bytes
*/
unsigned int fsize(FILE *fp);

/**
* @param arquivoentrada caminho para o arquivo de entrada
* @param B número maximo de bytes para armazenar registros em toda execução
* @param S tamanho em bytes do buffer de saída
* @param saida caminho para o arquivo de saída
*/
void ordena(const char* arquivoentrada, unsigned int B, unsigned int S, const char* saida);