# README - Trabalho Prático 2: Jogo de Sequência

## Visão Geral
Este projeto é parte do curso de Projeto e Análise de Algoritmos do Bacharelado em Ciência da Computação na Universidade Federal de São João Del Rei, no 1º semestre de 2024, sob a orientação do Professor Leonardo Chaves Dutra da Rocha. O objetivo deste trabalho é implementar duas estratégias para resolver um jogo inventado por João, que consiste em obter a pontuação máxima possível ao excluir elementos de uma sequência de números inteiros.

## Descrição do Problema
Dada uma sequência de inteiros `a` de tamanho `n`, o jogador pode realizar várias jogadas. Em cada jogada, ele pode escolher um elemento `a_k` da sequência e excluí-lo, juntamente com os elementos adjacentes `a_{k+1}` e `a_{k-1}`. Cada exclusão de `a_k` adiciona `a_k` pontos ao total do jogador. O objetivo é maximizar a pontuação total.

## Estratégias Implementadas
Foram implementadas duas estratégias para solucionar o problema:
1. **Programação Dinâmica (D)**
2. **Estratégia Alternativa (A)**

### Estratégia 1: Programação Dinâmica (D)
A solução baseada em programação dinâmica envolve a construção de uma tabela para armazenar os resultados das subproblemas, evitando recalcular os resultados de forma redundante.

### Estratégia 2: Alternativa (A)
A estratégia alternativa foi desenvolvida para garantir a resolução do problema de forma eficiente.

## Entrada e Saída
### Entrada
- A primeira linha contém o inteiro `N` (0 ≤ N ≤ 10^5), indicando a quantidade de números na sequência.
- A segunda linha contém `N` inteiros `a1, a2, ..., aN`.

### Saída
- A pontuação máxima possível.

### Exemplo de Entrada
```
9
1 2 1 3 2 2 2 2 3
```

### Exemplo de Saída
```
10
```
