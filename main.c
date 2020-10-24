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
    Abrir um arquivo, ordernar de X em Xmb e criar um vários arquivos menores de Xmb
    Obs: Antes de salvar já faz a ordenação
    */
   /*
   
   */
    FILE* arq_principal = NULL;
    char** arq_ordenados = malloc(sizeof(char*)*1); // Guarda nome dos arquivos já ordenados
    int arq_ordenados_count;                              // Guarda a quantidade de arquivos ordenados
    while(1){
        BUFF* entrada = iv_Criar_E("teste.dat", 10, &arq_principal);
        if(feof(arq_principal)) break;
        qsort(entrada->iv, 10, sizeof(ITEM_VENDA), compare);
        char* arqsaida = calloc(14,sizeof(char)); // Cria nome do arquivo de saida
        strcpy(arqsaida, "arqsaida");            // ^
        char x = i+'0';                         // ^
        strncat(arqsaida, &x, 1);                   
        strcat(arqsaida, ".dat");              // ^

        FILE* novo = NULL;                             // Referencia novo ponteiro de file
        BUFF* saida = iv_Criar_S(arqsaida, 10, &novo); // Cria um BUFFER de saida com o ponteiro e nome criados
        arq_ordenados[i] =  arqsaida;
        i++;
        arq_ordenados_count = i;
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
    FILE* arq_saida_principal = NULL;
    BUFF* arq_saida_p = iv_Criar_S("teste.txt", 10, &arq_saida_principal);

    FILE** arq_entrada_ordenados = malloc(sizeof(FILE*)*arq_ordenados_count);
    BUFF* arq_entrada_ord = malloc(sizeof(BUFF*)*arq_ordenados_count);
    while(1){
        for( i = 0; i < arq_ordenados_count; i++){
            arq_entrada_ordenados[i] = NULL;
            arq_entrada_ord = iv_Criar_E(arq_ordenados[i], 10, &arq_entrada_ordenados[i]);
        }
        int x;
        for( i = 0; i < arq_ordenados_count; i++){
            if(i == 0){
                x = feof(arq_entrada_ordenados[i]);
                continue;
            }
            x = x && feof(arq_entrada_ordenados[i]);
        }
        if(x)
            break;
    }
}