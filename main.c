#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "BufferEntrada.h"
#include "BufferSaida.h"
#include "Tipos.h"

int main(){
    int i = 0;
    /*
    1ª Parte:
    Abrir um arquivo, ordernar de 100 em 100mb e criar um vários arquivos menores de 100mb
    Obs: Antes de salvar já faz a ordenação, e já salva no mesmo arquivo anterior.
    */
   /*
   
   */
    FILE* arq_principal = NULL;
    char** arq_ordenados = malloc(sizeof(char*)*1);
    while(1){
        BUFF* entrada = iv_Criar_E("teste.dat", 10, &arq_principal);
        if(feof(arq_principal)) break;
        /*qsort*/
        char* arqsaida = calloc(14,sizeof(char)); // Cria nome do arquivo de saida
        strcpy(arqsaida, "arqsaida");            // ^
        char x = i+'0';                         // ^
        strncat(arqsaida, &x, 1);                   
        strcat(arqsaida, ".txt");              // ^

        FILE* novo = NULL;                             // Referencia novo ponteiro de file
        BUFF* saida = iv_Criar_S(arqsaida, 10, &novo); // Cria um BUFFER de saida com o ponteiro e nome criados
        arq_ordenados[i] =  arqsaida;
        i++;
        realloc(arq_ordenados, sizeof(char*)*i);
        free(saida->iv);            // Copia o Buffer de entrada já ordenado, o tamanho e posição
        saida->iv = entrada->iv;    // ^
        saida->tam = entrada->tam;
        iv_Despejar(saida); // Despeja

        iv_Destruir_S(saida);
    };
   /*
    2ª Parte:
    Criar um novo arquivo e vai colocando de N em N MB fazendo o mergeSort
    Obs: O Buffer vai se atualizando sozinho
    */
}