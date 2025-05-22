
Aluno: João Arthur Medeiros da Silva.

#include <stdio.h>   // Inclui a biblioteca padrão de entrada e saída (para printf, scanf)
#include <stdlib.h>  // Inclui a biblioteca padrão (para rand, srand)
#include <time.h>    // Inclui a biblioteca de tempo (necessário para a função time(), usada em srand)

#define MAX_TAM 50 // Define uma constante para o tamanho máximo dos arrays (número máximo de cheques)

// Função para gerar um número aleatório entre 0 e n-1
int random_num(int n) { // Renomeado de 'random' para 'random_num' para evitar conflito com funções de biblioteca existentes
    return rand() % n; // Usa a função rand() para gerar um número e o operador módulo para limitá-lo ao intervalo [0, n-1]
}

// Função para verificar se um valor 'k' já existe em um array 'v' de tamanho 'n'
int existe(int n, int v[], int k) {
    int i;
    for (i = 0; i < n; i++) { // Percorre o array do início ao fim
        if (v[i] == k) {      // Se o elemento atual do array for igual ao valor 'k'
            return 1;         // Retorna 1 (verdadeiro), indicando que o valor foi encontrado
        }
    }
    return 0; // Retorna 0 (falso), indicando que o valor não foi encontrado após verificar todo o array
}

// Função para ordenar um array 'arr' de tamanho 'n' usando o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Laço externo: controla o número de passes necessários.
    // Em cada passe, o maior elemento restante "flutua" para sua posição correta no final do sub-array não ordenado.
    for (i = 0; i < n - 1; i++) {
        // Laço interno: compara elementos adjacentes e os troca se estiverem na ordem errada.
        // O '-i' no limite garante que não se compare elementos que já estão na posição correta (no final do array).
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) { // Se o elemento atual for maior que o próximo elemento
                // Troca os elementos de posição
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Função principal do programa
int main(int args, char *arg[]) {
    int i, n, r; // Declaração de variáveis: i (para laços), n (quantidade de cheques), r (número aleatório gerado)
    int vet[MAX_TAM]; // Declara um array 'vet' para armazenar os números dos cheques, com tamanho máximo definido por MAX_TAM

    // Inicializar gerador de números aleatórios
    // srand() semeia o gerador de números aleatórios. Usar time(NULL) como semente garante que os números gerados
    // serão diferentes a cada execução do programa, pois time(NULL) retorna o tempo atual em segundos.
    srand((unsigned)time(NULL));

    // Solicita ao usuário a quantidade de cheques a serem gerados
    printf("Digite a quantidade de cheques que deseja a serem gerados (max %d): ", MAX_TAM);
    scanf("%d", &n); // Lê o valor digitado pelo usuário e armazena em 'n'

    // Verifica se a quantidade digitada é válida
    if (n > MAX_TAM || n <= 0) {
        printf("Quantidade invalida. Usando %d cheques como padrao.\n", MAX_TAM);
        n = MAX_TAM; // Se inválida, define 'n' para o valor máximo padrão
    }

    printf("\nGerando %d numeros de cheques aleatorios e unicos (entre 1 e 100):\n", n);
    i = 0; // Inicializa o contador para o número de cheques gerados
    do {
        r = random_num(100) + 1; // Gera um número aleatório entre 0 e 99 (usando random_num(100)) e soma 1,
                                 // resultando em um número entre 1 e 100 (conforme o problema)
        if (!existe(i, vet, r)) { // Verifica se o número 'r' já existe no array 'vet' (até a posição 'i')
            vet[i] = r;           // Se não existe, adiciona o número ao array
            i++;                  // Incrementa o contador de cheques gerados com sucesso
        }
    } while (i < n); // Continua gerando números até que 'n' cheques únicos tenham sido preenchidos

    // Imprime os cheques gerados na ordem em que foram inseridos (não ordenados)
    printf("Vetor inicial (sem ordenacao):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]); // Imprime cada número de cheque seguido de um espaço
    }
    printf("\n"); // Quebra de linha para melhor formatação

    // Ordenar os cheques em ordem crescente usando a função bubbleSort
    bubbleSort(vet, n);

    // Imprime os cheques após a ordenação
    printf("\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]); // Imprime cada número de cheque ordenado
    }
    printf("\n"); // Quebra de linha

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
// O bubbleSort é um algoritmo de ordenação, que percorre repetidamente a lista, comparar elementos adjacentes e trocá-los de lugar se estiverem na ordem errada.
// Esse processo continua até que nenhuma troca seja necessária em uma passagem ordenada, oque significa que a lista está ordenada.
