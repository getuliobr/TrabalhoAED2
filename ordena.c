#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "BufferEntrada.h"
#include "BufferSaida.h"
#include "Tipos.h"
#include "Utils.h"
#include "Ordena.h"

void ordena(const char* arquivoentrada, unsigned int B, unsigned int S, const char* saida){
    int i = 0;
    int j, k;
    /*
    1ª Parte:
    Abrir um arquivo, ordernar de X em Xmb e criar um vários arquivos menores de Xmb
    Obs: Antes de salvar já faz a ordenação
    */
    FILE* arq_principal = fopen(arquivoentrada, "rb+");

    int tamanhoDoArquivo = fsize(arq_principal);       // E
    int quantidadeArquivos = ceil(tamanhoDoArquivo/B); // K
    int quantidade_elementos_max = (tamanhoDoArquivo/quantidadeArquivos)/1024; // Tamanho de cada arquivo temporário
    printf("E = %d\t K = %d\t Tamanho de cada arquivo: %d\n",tamanhoDoArquivo, quantidadeArquivos, quantidade_elementos_max);


    fclose(arq_principal);
    arq_principal = NULL;

    char** arq_ordenados = calloc(sizeof(char*), quantidadeArquivos); // Guarda nome dos arquivos já ordenados
    int arq_ordenados_count;                            // Guarda a quantidade de arquivos ordenados

    while(1){
        BUFF* entrada = iv_Criar_E("teste.dat", quantidade_elementos_max, &arq_principal);
        if(feof(arq_principal)) break;
        qsort(entrada->iv, quantidade_elementos_max, sizeof(ITEM_VENDA), compare);

        char* arqsaida = calloc(14,sizeof(char));
        strcpy(arqsaida, "s");
        char snum[5];
        sprintf(snum, "%d", i);
        strncat(arqsaida, snum, 1);
        strcat(arqsaida, ".dat");

        FILE* novo = NULL;                             // Referencia novo ponteiro de file
        BUFF* saida = iv_Criar_S(arqsaida, quantidade_elementos_max, &novo); // Cria um BUFFER de saida com o ponteiro e nome criados
        arq_ordenados[i] = arqsaida;
        i++;
        arq_ordenados_count = i;

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

    int qtdeElementos = tamanhoDoArquivo / 1024;// Quantidade de elementos que existem no arquivo;
    int tamanho_buffer_saida = S/1024; // Tamanho do buffer de saida
    int tamanho_buffer_entrada_ordenado = floor(((B-S)/quantidadeArquivos)/1024);// Tamanho buffer da entrada dos ordenados

    printf("Qtde elementos = %d\n",qtdeElementos);
    printf("Buffer saida = %d\t Buffer Entrada = %d\n",tamanho_buffer_saida,tamanho_buffer_entrada_ordenado);
    printf("arq_ord_count  = %d\n", arq_ordenados_count);

    FILE* arq_saida_principal = NULL;                                           // FILE do arquivo de saida principal(Todos os elementos ordenados)
    BUFF* arq_saida_p = iv_Criar_S(saida, tamanho_buffer_saida, &arq_saida_principal);      // Criação do Buffer de saida principal

    FILE** arq_entrada_ordenados = malloc(sizeof(FILE*)*arq_ordenados_count);   // Vetor de FILES dos arquivos já ordenados
    BUFF** arq_entrada_ord = malloc(sizeof(BUFF*)*arq_ordenados_count);         // Vetor de Buffers dos arquivos já ordenados

    for( i = 0; i < arq_ordenados_count; i++){                                              // Abertura de arquivos ordenados
        arq_entrada_ordenados[i] = NULL;                                                    // ^
        printf("TAMANHO BRABOR: %d\n", tamanho_buffer_entrada_ordenado);
        arq_entrada_ord[i] = iv_Criar_E(arq_ordenados[i], tamanho_buffer_entrada_ordenado, &arq_entrada_ordenados[i]);   // ^
    }

    for(i = 0; i < 200; i++){ // Coloca os itens no arquivo
        int menor;                                          // Guarda o maior id de N Buffer lidos 
        ITEM_VENDA menor_iv;   // ^
        menor_iv.id = qtdeElementos+42;
        for(k = 0; k < arq_ordenados_count; k++){               // ^
            if(iv_Vazio(arq_entrada_ord[k])) continue;
            ITEM_VENDA a = iv_Proximo(arq_entrada_ord[k]);      // ^
            if(a.id < menor_iv.id){                             // ^
                menor = k;                                      // ^
                menor_iv = a;                                   // ^
            }                                                   // ^
        }                                                       // ^
        menor_iv = iv_Consumir(arq_entrada_ord[menor]);
        printf("I: %d K: %d ID: %d\n", i, menor, menor_iv.id);
        iv_Inserir(arq_saida_p, menor_iv);
    }
    iv_Destruir_S(arq_saida_p); // Destruição da Saida

    for(i = 0; i < arq_ordenados_count; i++){    // Destruição dos arquivos de entrada
        iv_Destruir_E(arq_entrada_ord[i]);       // ^      
        // remove(arq_ordenados[i]);                // ^
    }                                            // ^
} 