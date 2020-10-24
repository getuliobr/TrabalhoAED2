#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include "BufferEntrada.h"
#include "BufferSaida.h"
#include "Tipos.h"

int main(){
    int i = 0;
    int j, k;
    /*
    1ª Parte:
    Abrir um arquivo, ordernar de X em Xmb e criar um vários arquivos menores de Xmb
    Obs: Antes de salvar já faz a ordenação
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
    FILE* arq_saida_principal = NULL;                                           // FILE do arquivo de saida principal(Todos os elementos ordenados)
    BUFF* arq_saida_p = iv_Criar_S("teste.txt", 10, &arq_saida_principal);      // Criação do Buffer de saida principal

    FILE** arq_entrada_ordenados = malloc(sizeof(FILE*)*arq_ordenados_count);   // Vetor de FILES dos arquivos já ordenados
    BUFF** arq_entrada_ord = malloc(sizeof(BUFF*)*arq_ordenados_count);         // Vetor de Buffers dos arquivos já ordenados
    for( i = 0; i < arq_ordenados_count; i++){                                              // Abertura de arquivos ordenados
        arq_entrada_ordenados[i] = NULL;                                                    // ^
        arq_entrada_ord[i] = iv_Criar_E(arq_ordenados[i], 10, &arq_entrada_ordenados[i]);   // ^
    }

    for(i = 0; i < 100/*tamanho de elementos no arquivo*/; i++){ // Coloca os itens no arquivo
        int menor;                                          // Guarda o maior id de N Buffer lidos 
        ITEM_VENDA menor_iv;   // ^
        menor_iv.id = 100+20;
        for(k = 0; k < arq_ordenados_count; k++){               // ^
            ITEM_VENDA a = iv_Proximo(arq_entrada_ord[k]);      // ^
            if(a.id < menor_iv.id){                             // ^
                menor = k;                                      // ^
                menor_iv = a;                                   // ^
            }                                                   // ^
        }                                                       // ^
        menor_iv = iv_Consumir(arq_entrada_ord[menor]);
        iv_Inserir(arq_saida_p, menor_iv);
    }
    iv_Destruir_S(arq_saida_p); // Destruição da Saida

    for(i = 0; i < arq_ordenados_count; i++)    // Destruição dos arquivos de entrada
        iv_Destruir_E(arq_entrada_ord[i]);        // ^
}