/*  Grupo:
        Frederico Scheffel Oliveira   15452718
        Leonardo Massuhiro Sato       15469108
        Nicolas Amaral dos Santos     16304033
        Pedro Henrique Perez Dias     15484075
        Pedro Lunkes Villela          15484287
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declaração das constantes
#define MAX_LINE_LENGTH 100
#define REALLOC 50

// Declaração das funções
bool contemLetras(char *linhas, char* invalidas);
char*** palavrasValidas(char *letras, int** tams);
int busca_binaria(char*** lista, int tam_vet, int tam_pal, char* procura, bool** encontradas);
void free_matriz_palavras(char **** matriz, int* tams);

int main(){
    char *comando = (char *) malloc(20 * sizeof(char));
    char *tentativa = (char *) malloc(25 * sizeof(char));
    char *entrada = (char *) malloc(7 * sizeof(char));
    bool **encontradas = (bool **) malloc(sizeof(bool *) * 25); // Máximo tamanho possível de uma palavra
    char*** palavras;
    int* tams;
    int totalPalavras = 0;
    int totalAcertadas = 0;
    while(true) 
    {
        // Seleção do comando a ser executado
        scanf(" %s", comando);
        if(strcmp(comando, "inicio") == 0)
        {
            // Leitura das letras digitadas 
            for(int i = 0; i < 7; i++) {
                scanf(" %c", &entrada[i]);
            }

            // Montagem da matriz de palavras válidas, a partir das letras dadas
            palavras = palavrasValidas(entrada, &tams);

            // Cálculo do total de palavras
            for(int i = 0; i < 25; i++) {
                totalPalavras += tams[i];
            }

            for(int i = 0;i < 25;i++){
                encontradas[i] = (bool *) calloc(sizeof(bool), tams[i]);
            }
        }
        else if(strcmp(comando, "palavra") == 0)
        {
            scanf(" %s", tentativa);

            // Uso de busca binária para encontrar a palavra digitada dentro do vetor de palavras
            int busca = busca_binaria(palavras, tams[strlen(tentativa)], strlen(tentativa), tentativa, encontradas);
            if(busca == 1)
            {
                printf("sucesso + 1\n");
                totalAcertadas++;
                
                // Acertou todas as palavras, portanto o jogo deve ser encerrado 
                if(totalAcertadas == totalPalavras)
                {
                    printf("parabens! voce encontrou todas as palavras\n");
                    break;
                }
            }

            // Palavra não encontrada pela busca
            else if(busca == 0)
                printf("palavra invalida\n");
        }
        else if(strcmp(comando, "progresso") == 0)
        {
            printf("progresso atual:\n");
            
            for(int x = 0; x < 25; x++) 
            {
                // Contagem de palavras encontradas, agrupadas por letras
                int contEncontradas = 0;
                for(int i = 0;i < tams[x];i++)
                {
                    if(encontradas[x][i] == true)
                        contEncontradas++;
                }
                if(tams[x] != 0)
                    printf("(%d letras) %d palavra(s) encontrada(s) / %d palavra(s) faltando\n", x, contEncontradas, tams[x] - contEncontradas);
            }
        }
        else if(strcmp(comando, "solucao") == 0)
        {
            printf("para encerrar o jogo estavam faltando as palavras:");
            for(int x = 0; x < 25; x++) 
            {
                if(tams[x] != 0)
                {
                    printf("\n(%d letras) ", x);
                    for(int i = 0;i < tams[x];i++)
                    {
                        if (i == tams[x] - 1) 
                        {
                            // Última palavra, sem vírgula
                            printf("%s", palavras[x][i]);
                        } else {
                            // Outras palavras, com vírgula
                            printf("%s, ", palavras[x][i]);
                        }
                    }
                }
            }
            printf("\nfim!");
            // Quebra o loop e encerra o jogo
            break;  
        }
    }

    // Liberação da memória utilizada
    free_matriz_palavras(&palavras, tams);
    free(tams);
    free(entrada);
    free(comando);
}

// Função que procura na linha alguma das letras inválidas
bool contemLetras(char *linha, char* invalidas){
    for(int j = 0;j < 19;j++){
        if(strchr(linha, invalidas[j]) != NULL){
            return false;
        }
    }

    return true;
}

// Função responsável por montar a matriz de palavras válidas
char*** palavrasValidas(char *letras, int** tams){
    *tams = (int *) calloc(sizeof(int), 25);
    int* capacidade = (int *) malloc(sizeof(int) * 25);

    // Leitura do arquivo de palavras
    FILE *dicionario = fopen("valid_words.txt", "r");
    if (dicionario == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Tamanho do vetor é 19, pois é o total do alfabeto (26) menos as digitadas (7)
    char* invalidas = (char *) malloc(19 * sizeof(char));
    int indice = 0;

    char line[MAX_LINE_LENGTH];
    char abc[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 
                    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
                    'Y', 'Z'};
    
    // Marca no vetor as letras que não estão contidas na letras passadas na digitação
    for(int i = 0;i < 26;i++){
        bool valid = true;

        for(int j = 0;j < 7;j++){
            if(letras[j] == abc[i]){ 
                valid = false;
                break;
            }
        }

        if(valid) 
            invalidas[indice++] = abc[i];
    }

    char*** matriz_resposta = (char ***) malloc(sizeof(char **) * 25);
    for(int i = 0;i< 25;i++){
        matriz_resposta[i] = (char **) malloc(sizeof(char *) * REALLOC);
    }

    for(int j = 0;j < 25;j++){
        capacidade[j] = REALLOC;
    }

    while (fgets(line, sizeof(line), dicionario)) {
        line[strcspn(line, "\n")] = '\0';
        
        // Procura pela letra principal na linha do arquivo. Além disso, verifica se a palavra é válida (tem as letras dadas)
        if(strchr(line, letras[0]) != NULL && contemLetras(line, invalidas)){
            int t = strlen(line);

            if((*tams)[t] > capacidade[t]){
                capacidade[t] += REALLOC;
                matriz_resposta[t] = (char **) realloc(matriz_resposta[t], sizeof(char *) * capacidade[t]);
                
                if (matriz_resposta[t] == NULL) {
                    perror("Error reallocating memory");
                    exit(1);
                }
            }

            matriz_resposta[t][(*tams)[t]] = (char *) malloc(sizeof(char) * t);
            strcpy(matriz_resposta[t][(*tams)[t]], line);

            (*tams)[t]++;
        }
    } 

    // Liberação de memória
    free(capacidade);
    free(invalidas);
    fclose(dicionario);
    return matriz_resposta;
}

// Função responsável por procurar uma palavra na matriz de palavras e marcá-la como encontrada na respectiva matriz
int busca_binaria(char*** lista, int tam_vet, int tam_pal, char* procura, bool** encontradas){
    int left = 0, right = tam_vet - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int res = strcmp(lista[tam_pal][mid], procura);
        if (res == 0) {
            if(!encontradas[tam_pal][mid]){
                encontradas[tam_pal][mid] = true;
                return 1; // Palavra encontrada 1 vez
            }
            return 2;     // Palavra encontrada + de 1 vez
        }

        if (res < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0; // Não encontrada
}

// Liberação da memória da matriz utilizada
void free_matriz_palavras(char **** matriz, int* tams){
    for(int i = 0;i < 25;i++){
        for(int j = 0; j < tams[i]; j++){
            free((*matriz)[i][j]);
        }
        free((*matriz)[i]);
    }
    free(*matriz);
}
