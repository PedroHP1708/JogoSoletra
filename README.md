# Soletra
O programa é uma implementação de um jogo de soletração nos moldes dos disponíveis em https://www.nytimes.com/puzzles/spelling-bee para o inglês e https://g1.globo.com/jogos/soletra/ para o português.

1. Programa principal:
   - Inicialização de variáveis para armazenar comandos, tentativas, e listas de palavras.
   - Loop contínuo que processa comandos como "inicio", "palavra", "progresso" e "solucao":
     - "inicio": Lê um conjunto de letras, constroi a matriz de palavras válidas com base nessas letras, e inicializa um vetor de palavras encontradas.
     - "palavra": Lê a tentativa do usuário e executa a função de busca binária para verificar se a palavra está na lista. Incrementa o total de palavras acertadas se a palavra for encontrada. Se o total de palavras encontradas for igual ao total de palavras válidas, o jogo é encerrado.
     - "progresso": Exibe o progresso atual do jogo, mostrando quantas palavras foram encontradas e quantas ainda faltam. Para o cálculo das palavras encontradas, percorre-se vetor 'encontradas' (base da busca binária), verificando quais ainda estão marcadas como 'false'.
     - "solucao": Imprime todas as palavras válidas (por especificação do trabalho).
2. Função contemLetras: Verifica se uma linha do arquivo de valid_words.txt contém alguma das letras inválidas usando strchr para localizar caracteres.
3. Função validWord:
   - Cria uma matriz dinâmica de strings (char***) para armazenar as palavras válidas do arquivo valid_words.txt.
   - Filtra palavras que contêm apenas as letras válidas e monta a matriz por comprimento de palavra.
4. Função busca_binaria: Realiza uma busca binária em sub-arrays de palavras derivadas de validWord, marcando palavras como encontradas.
5. Função free_matriz_resposta: Libera a memória alocada para a matriz de palavras para evitar vazamentos de memória.
