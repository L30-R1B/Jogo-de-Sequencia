#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "../include/sequencia.h"
#include "../include/solucao_dinamica.h"
#include "../include/solucao_alternativa.h"

float retorna_tempo_usuario(struct rusage *start, struct rusage *end) {
  return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) + 1e-6 * (end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}
float retorna_tempo_sistema(struct rusage *start, struct rusage *end) {
  return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) + 1e-6 * (end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}
int main(int argNum, char *args[]){
    
    if(argNum != 3){
        printf("NÚMERO DE ARGUMENTOS INVÁLIDOS ! ! !\n");
        return 1;
    }else if(args[1][0] != 'A' && args[1][0] != 'D'){
        printf("OPERAÇÂO INVÁLIDA ! ! !\n");
        return 1;
    }

    struct timeval start_time, end_time;
    struct rusage start, end;
    double tempo_execucao;

    Sequencia *S;
    unsigned tamanho;

    FILE *F = fopen(args[2], "r");
    if(F == NULL)
        return 1;
    
    fscanf(F, "%u", &tamanho);
    S = cria_sequencia(tamanho);
    for(unsigned vAtual = 0; vAtual < S->tamanho; vAtual ++)
        fscanf(F, "%d", &S->V[vAtual].num);
    
    fclose(F);

    getrusage(RUSAGE_SELF, &start);
    gettimeofday(&start_time, NULL);

    if(!strcmp(args[1], "A"))
        solucao_alternativa(S);
    else if(!strcmp(args[1], "D"))
        solucao_dinamica(S);

    gettimeofday(&end_time, NULL);
    getrusage(RUSAGE_SELF, &end);

    tempo_execucao = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    printf("\n%lu\n", S->pontuacao);

    printf("\n-----------------------------------------------\n");
    printf("Tempo de CPU usado (usuário): %f segundos\n", retorna_tempo_usuario(&start, &end));
    printf("Tempo de CPU usado (sistema): %f segundos\n", retorna_tempo_sistema(&start, &end));
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);
    printf("-----------------------------------------------\n");
    apaga_sequencia(S);

    return 0;
}