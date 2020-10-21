#pragma once
#include <stdint.h>
#include <stdio.h>

typedef struct ITEM_VENDA {
    uint32_t id;
    uint32_t id_venda;
    uint32_t data;
    float desconto;
    char obs[1008];
} ITEM_VENDA;

typedef struct BUFF{
    ITEM_VENDA* iv;
    int tam;
    int pos;
    FILE** arq;
}BUFF;