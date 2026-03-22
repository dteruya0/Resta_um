# Link do Youtube

# Resta Um Solver Em C
Este projeto implementa um solucionador para o jogo Resta Um utilizando a linguagem C. A solução é baseada em um algoritmo de backtracking recursivo, capaz de explorar sistematicamente todas as sequências possíveis de movimentos até encontrar uma configuração válida em que resta apenas uma peça no centro do tabuleiro. Além disso, o programa retorna a sequência de passos que levam à resolução do problema.

# Algoritimo
A solução verifica todos os movimentos válidos para cada peça do tabuleiro. Caso exista mais de um movimento possível e a primeira opção não leve a uma solução, o algoritmo retorna à chamada anterior, desfaz o movimento realizado e prossegue para o próximo movimento válido.

## Representação das posições na matiz
`1` → Posição com uma peça

`0` → Posição vazia

`#` → Posição fora do tabuleiro

### Estado inicial do tabuleiro:

```txt
# # # # # # # # #
# # # 1 1 1 # # #
# # # 1 1 1 # # #
# 1 1 1 1 1 1 1 #
# 1 1 1 0 1 1 1 #
# 1 1 1 1 1 1 1 #
# # # 1 1 1 # # #
# # # 1 1 1 # # #
# # # # # # # # #
```
Durante a execução, os passos são armazenados em um vetor, que registra a sequência de movimentos realizados. Quando esse vetor atinge tamanho 31 e a última peça está no centro do tabuleiro, o algoritmo considera que a solução foi encontrada e exibe a sequência completa de movimentos que levou ao resultado final, além de exibir os estados do tabuleiro após cada jogada.

## Complexidade de Tempo

O algoritmo possui complexidade exponencial, característica de soluções baseadas em backtracking. A cada estado do tabuleiro, até 4 movimentos válidos podem ser explorados (Cima, Baixo, Esquerda e Direita), o que resulta em um crescimento exponencial do número de estados possiveis do tabuleiro uma vez que uma chamada da função `resolveRestaUm` pode gerar até 4 novas chamadas. Por exemplo

Passo 0 → 1 estado inicial  
Passo 1 → até 4 estados  
Passo 2 → até 16 estados  
Passo 3 → até 64 estados

Portanto, a complexidade pode ser representada como O(a^b), onde `a` corresponde a ramificação (número de movimentos por estado ) e `b` à profundidade da busca (quantidade de movimentos realizados).

No caso clássico do tabuleiro 9 x 9, a profundidade máxima é de 31 movimentos, o que torna o espaço de busca potencialmente muito grande. Apesar disso, nem todas as ramificações são válidas, o que reduz parcialmente o número de estados explorados na prática. Sendo assim `a = 4` e `b = 31` o que nos da uma complexidade mais especifica de `O(4^31)` no pior caso.

Devido a essa característica, o algoritmo apresenta tempo de execução elevado. Portanto foi adicionado um indicador de status (“Resolvendo...”) com o objetivo de evitar longos períodos sem resposta.

## ⚠️ Limitações

- Apesar do algoritmo receber uma matriz de dimensão n x n, a solução é projetada especificamente para um tabuleiro 9 x 9, pois essa configuração garante exatamente 31 movimentos até a solução. O caso base do algoritmo depende da verificação desse número fixo de movimentos e da permanência de uma única peça no centro do tabuleiro.
  
- Não há otimização para evitar explorar caminhos já visitados.
- A solução encontrada não necessariamente a melhor em termos de otimização, apenas uma solução válida.
