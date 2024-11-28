# Soletra
1. Bibliotecas e Constantes:
   - Inclui bibliotecas para operações de entrada/saída (stdio.h), alocação de memória (stdlib.h), manipulação de strings (string.h) e tipos booleanos (stdbool.h).
   - Define as constantes MAX_LINE_LENGTH (100) para o tamanho máximo de uma linha e REALLOC (50) para o incremento de realocação de memória.
2. Declaração de Funções: Múltiplas funções são pré-declaradas para facilitar a lógica do jogo:
   - contemLetras: Verifica se uma linha contém letras inválidas.
   - validWord: Cria uma matriz de palavras válidas a partir de um conjunto de letras.
   - busca_binaria: Executa busca binária em uma lista de palavras para verificar se uma palavra tentativa está presente.
   - free_matriz_resposta: Libera a memória associada à matriz de palavras.
3. Função main: Gerencia a execução principal do jogo, incluindo:
   - Inicialização de variáveis para armazenar comandos, tentativas, e listas de palavras.
   - Loop contínuo que processa comandos como "inicio", "palavra", "progresso" e "solucao":
     - "inicio": Lê um conjunto de letras, constroi a matriz de palavras válidas com base nessas letras, e inicializa um vetor de palavras encontradas.
     - "palavra": Lê a tentativa do usuário e executa uma busca binária para verificar se a palavra está na lista. Incrementa o total de palavras acertadas se a palavra for encontrada.
     - "progresso": Exibe o progresso atual do jogo, mostrando quantas palavras foram encontradas e quantas ainda faltam.
     - "solucao": Imprime as palavras que ainda faltam encontrar, encerrando o jogo.
4. Função contemLetras: Verifica se uma linha contém alguma das letras inválidas usando strchr para rapidamente localizar caracteres proibidos.
5. Função validWord:
   - Cria uma matriz dinâmica (char***) para armazenar palavras válidas do arquivo valid_words.txt.
   - Filtra palavras que contêm apenas as letras válidas e monta a matriz por comprimento de palavra.
6. Função busca_binaria: Realiza uma busca binária em sub-arrays de palavras derivadas de validWord, marcando palavras como encontradas.
7. Função free_matriz_resposta: Libera a memória alocada para a matriz de palavras para evitar vazamentos de memória.
Essencialmente, o programa cria um jogo onde o usuário deve encontrar todas as palavras válidas que podem ser formadas a partir de um conjunto de letras dado, interagindo via comandos. Ele utiliza estruturas dinâmicas de dados como matrizes de strings tridimensionais para gerenciar listas de palavras e seu estado de descoberta.
