#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sequencia.h"
#include "../include/solucao_dinamica.h"
#include "../include/solucao_alternativa.h"

Sequencia *cria_sequencia(unsigned tamanho){
    Sequencia *S = (Sequencia*) malloc(sizeof(Sequencia));
    S->pontuacao = 0;
    S->tamanho = tamanho;
    S->V = (Valores*) malloc(tamanho * sizeof(struct Valor));

    return S;
}

void apaga_sequencia(Sequencia *S){
    if(S == NULL){
        return;
    }
    if(S->V != NULL)
        free(S->V);

    free(S);
}

long int max(long int a, long int b) {
    return (a > b) ? a : b;
}