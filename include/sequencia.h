#ifndef _sequencia_h_
#define _sequencia_h_

#define VMAX 10

typedef struct Valor{
    int num;
}Valores;

typedef struct {
    Valores *V;
    long int pontuacao;
    unsigned tamanho;
}Sequencia;

long int max(long int a, long int b);

Sequencia *cria_sequencia(unsigned tamanho);
void apaga_sequencia(Sequencia *S);

#endif
