# Soletra
O programa é uma implementação de um jogo de soletração nos moldes dos disponíveis em https://www.nytimes.com/puzzles/spelling-bee para o inglês e https://g1.globo.com/jogos/soletra/ para o português.

1. Programa principal:
   - Inicialização de variáveis para armazenar comandos, tentativas, e listas de palavras.
   - Loop contínuo que processa comandos como "inicio", "palavra", "progresso" e "solucao":
     - "inicio": Lê um conjunto de letras, constrói a matriz de palavras válidas com base nessas letras, e inicializa um vetor de palavras encontradas.
     - "palavra": Lê a tentativa do usuário e executa a função de busca binária para verificar se a palavra está na lista. Incrementa o total de palavras acertadas se a palavra for encontrada. Se o total de palavras encontradas for igual ao total de palavras válidas, o jogo é encerrado.
     - "progresso": Exibe o progresso atual do jogo, mostrando quantas palavras foram encontradas e quantas ainda faltam. Para o cálculo das palavras encontradas, percorre-se a matriz 'encontradas' (base da busca binária), verificando quais ainda estão marcadas como 'false'.
     - "solucao": Imprime todas as palavras válidas (por especificação do trabalho) e encerra o jogo.
2. Função contemLetras: Verifica se uma linha do arquivo de valid_words.txt contém alguma das letras inválidas usando strchr para localizar caracteres.
3. Função palavrasValidas:
   - Cria uma matriz dinâmica de strings (char***) para armazenar as palavras válidas do arquivo valid_words.txt.
   - Filtra palavras que contêm apenas as letras válidas e monta a matriz por tamanho da palavra.
   - Foi escolhida a matriz como estrutura de dados principal devido ao fato de ser uma maneira mais visual de de guardar os elementos do que em um vetor: no caso da matriz linhas e colunas têm significado, ao invés de estarem apenas ordenadas como nos vetores. Além disso, a complexidade do trabalho não exigia a implementação de estruturas como pilhas e filas e listas ligadas, por não permitirem indexação, não possibilitariam o uso da busca binária. 
4. Função busca_binaria:
   - Realiza uma busca binária nos subvetores de palavras válidas, geradas pela função palavrasValidas. Essa função retorna 0 caso a palavra procurada não seja encontrada na lista, 1 caso seja encontrada (nesse caso, marcando 'true' na posição especificada na matriz 'encontradas') e 2 caso a palavra seja digitada novamente (por especificação do trabalho, esse caso não é implementado no programa principal porém a função funciona de maneira mais completa assim).
   - Foi escolhido o algoritmo de busca binária pelo fato de se tratar de uma matriz ordenada de palavras, que possibilita uma busca otimizada através desse algoritmo, que é de fácil implementação.
6. Função free_matriz_palavras:
   - Libera a memória alocada para a matriz de palavras para evitar vazamentos de memória.
