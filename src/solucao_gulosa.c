#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/sequencia.h"
#include "../include/solucao_gulosa.h"

typedef struct {
    int valor;
    int indice;
} Elemento;

typedef struct {
    Elemento *elementos;
    int tamanho;
    int capacidade;
} MaxHeap;

MaxHeap* criar_heap(int capacidade) {
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->elementos = (Elemento*)malloc(capacidade * sizeof(Elemento));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void trocar(Elemento *a, Elemento *b) {
    Elemento temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(MaxHeap *heap, int idx) {
    int maior = idx;
    int esquerda = 2 * idx + 1;
    int direita = 2 * idx + 2;

    if (esquerda < heap->tamanho && heap->elementos[esquerda].valor > heap->elementos[maior].valor) {
        maior = esquerda;
    }

    if (direita < heap->tamanho && heap->elementos[direita].valor > heap->elementos[maior].valor) {
        maior = direita;
    }

    if (maior != idx) {
        trocar(&heap->elementos[idx], &heap->elementos[maior]);
        max_heapify(heap, maior);
    }
}

void inserir_heap(MaxHeap *heap, int valor, int indice) {
    if (heap->tamanho == heap->capacidade) {
        return;
    }

    heap->tamanho++;
    int i = heap->tamanho - 1;
    heap->elementos[i].valor = valor;
    heap->elementos[i].indice = indice;

    while (i != 0 && heap->elementos[(i - 1) / 2].valor < heap->elementos[i].valor) {
        trocar(&heap->elementos[i], &heap->elementos[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Elemento extrair_max(MaxHeap *heap) {
    if (heap->tamanho <= 0) {
        return (Elemento){0, -1}; 
    }

    if (heap->tamanho == 1) {
        heap->tamanho--;
        return heap->elementos[0];
    }

    Elemento raiz = heap->elementos[0];
    heap->elementos[0] = heap->elementos[heap->tamanho - 1];
    heap->tamanho--;
    max_heapify(heap, 0);

    return raiz;
}

void solucao_gulosa(Sequencia *S) {
    int tamanho = S->tamanho;
    Valores *nums = S->V;
    bool *removido = (bool*)calloc(tamanho, sizeof(bool));
    MaxHeap *heap = criar_heap(tamanho);

    for (int i = 0; i < tamanho; i++) {
        inserir_heap(heap, nums[i].num, i);
    }

    S->pontuacao = 0;

    while (heap->tamanho > 0) {
        Elemento max_elem = extrair_max(heap);
        int idx = max_elem.indice;

        if (removido[idx]) {
            continue;
        }

        S->pontuacao += nums[idx].num;

        removido[idx] = true;
        if (idx > 0) {
            removido[idx - 1] = true;
        }
        if (idx < tamanho - 1) {
            removido[idx + 1] = true;
        }
    }

    free(removido);
    free(heap->elementos);
    free(heap);
}
