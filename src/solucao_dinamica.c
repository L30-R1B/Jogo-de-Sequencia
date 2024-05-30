#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sequencia.h"
#include "../include/solucao_dinamica.h"

void solucao_dinamica(Sequencia *S){
    if(!S->tamanho)
        return;
    long int incluido = 0, excluido = 0;
    long int temp;

    for(unsigned vAtual = 0; vAtual < S->tamanho; vAtual ++){
        temp = incluido;
        incluido = excluido + S->V[vAtual].num;
        excluido = max(temp, excluido);
    }
    S->pontuacao = max(incluido, excluido);
    return;
}

