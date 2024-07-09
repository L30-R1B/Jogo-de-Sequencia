#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sequencia.h"
#include "../include/solucao_bonus.h"

long unsigned max_pontucao_recursiva(Valores vetor[], int indice, int tamanho, long unsigned *memoria) {
    if (indice >= tamanho)
        return 0;

    if (memoria[indice] != 0)
        return memoria[indice];

    long unsigned incluir = vetor[indice].num + max_pontucao_recursiva(vetor, indice + 2, tamanho, memoria);

    long unsigned excluir = max_pontucao_recursiva(vetor, indice + 1, tamanho, memoria);

    memoria[indice] = max(incluir, excluir);

    return memoria[indice];
}

void solucao_bonus(Sequencia *S) {
    long unsigned memo[S->tamanho];
    for (unsigned i = 0; i < S->tamanho; i++) {
        memo[i] = 0; 
    }

    S->pontuacao = max_pontucao_recursiva(S->V, 0, S->tamanho, memo);
    
    return;
}
