#include <stdio.h>

/**
* @param fp ponteiro para o arquivo
* @return tamanho do arquivo em bytes
*/
int fsize(FILE *fp);

/**
* @param arquivoentrada caminho para o arquivo de entrada
* @param B número maximo de bytes para armazenar registros em toda execução
* @param S tamanho em bytes do buffer de saída
* @param saida caminho para o arquivo de saída
*/
void ordena(const char* arquivoentrada, unsigned int B, unsigned int S, const char* saida);