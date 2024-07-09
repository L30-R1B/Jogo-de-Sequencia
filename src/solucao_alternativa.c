#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sequencia.h"
#include "../include/solucao_bonus.h"

void backtracking(Valores *nums, int tamanho, int index, int last_included, long int current_sum, long int *max_sum) {
    long int upper_bound = current_sum;
    for (int i = index; i < tamanho; i++) {
        upper_bound += nums[i].num;
    }
    if (upper_bound <= *max_sum) {
        return;
    }

    if (index >= tamanho) {
        if (current_sum > *max_sum) {
            *max_sum = current_sum;
        }
        return;
    }

    backtracking(nums, tamanho, index + 1, last_included, current_sum, max_sum);

    if (index == 0 || index > last_included + 1) {
        backtracking(nums, tamanho, index + 1, index, current_sum + nums[index].num, max_sum);
    }
}

void solucao_alternativa(Sequencia *S) {
    backtracking(S->V, S->tamanho, 0, -1, 0, &S->pontuacao);
}