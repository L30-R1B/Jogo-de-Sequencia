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

## Execução do Programa
O executável deve ser chamado `tp2` e deve ser executado com a seguinte sintaxe:
```
./tp2 <estrategia> entrada.txt
```
- `<estrategia>`: Pode ser `D` para a solução baseada em programação dinâmica ou `A` para a estratégia alternativa.
- `entrada.txt`: Arquivo contendo a sequência de entrada.

O programa deve gerar um arquivo `saida.txt` com a resposta e imprimir os tempos de usuário e de sistema no console para fins de comparação. Utilize as funções `getrusage` e `gettimeofday` para a avaliação do tempo.

## Estrutura do Código
- **Módulos**: O código está modularizado em arquivos `.c` e `.h` para facilitar a manutenção e leitura.
- **Alocação Dinâmica**: As estruturas de dados são alocadas dinamicamente para gerenciar a memória de forma eficiente.

## Compilação
Utilize o utilitário Make para compilar o programa. Um exemplo de `Makefile` é fornecido no projeto para auxiliar na compilação.

## Documentação
A documentação detalha as soluções adotadas, justificando as escolhas realizadas. Inclui também:
- Descrição das soluções e estruturas de dados utilizadas.
- Análise de complexidade detalhada das rotinas.
- Análise dos resultados obtidos com diversas configurações e tempos de execução.

## Avaliação
### Critérios de Avaliação
- **Execução (E)**
  - Execução correta: 80%
- **Estilo de Programação**
  - Código bem estruturado: 10%
  - Código legível: 10%
- **Documentação (D)**
  - Comentários explicativos: 40%
  - Análise de complexidade: 30%
  - Análise de resultados: 30%

### Cálculo da Nota Final
A nota final é calculada como a média harmônica entre execução (E) e documentação (D):
```
Nota Final = 2 * (D * E) / (D + E)
```

## Observações Finais
- O código deve ser submetido para compilação e execução em ambiente Linux, conforme os padrões dos laboratórios do DCOMP.
- O código deve ser escrito em C. Outras linguagens não serão aceitas.
- A saída deve seguir estritamente o formato especificado, caso contrário, o resultado será considerado errado.
- O arquivo executável deve ser chamado `tp2` e deve receber apenas o nome do arquivo de entrada e a estratégia escolhida.

Para mais detalhes, consulte a documentação fornecida no projeto.
