
Aluno: Jo�o Arthur Medeiros da Silva.

#include <stdio.h>   // Inclui a biblioteca padr�o de entrada e sa�da (para printf, scanf)
#include <stdlib.h>  // Inclui a biblioteca padr�o (para rand, srand)
#include <time.h>    // Inclui a biblioteca de tempo (necess�rio para a fun��o time(), usada em srand)

#define MAX_TAM 50 // Define uma constante para o tamanho m�ximo dos arrays (n�mero m�ximo de cheques)

// Fun��o para gerar um n�mero aleat�rio entre 0 e n-1
int random_num(int n) { // Renomeado de 'random' para 'random_num' para evitar conflito com fun��es de biblioteca existentes
    return rand() % n; // Usa a fun��o rand() para gerar um n�mero e o operador m�dulo para limit�-lo ao intervalo [0, n-1]
}

// Fun��o para verificar se um valor 'k' j� existe em um array 'v' de tamanho 'n'
int existe(int n, int v[], int k) {
    int i;
    for (i = 0; i < n; i++) { // Percorre o array do in�cio ao fim
        if (v[i] == k) {      // Se o elemento atual do array for igual ao valor 'k'
            return 1;         // Retorna 1 (verdadeiro), indicando que o valor foi encontrado
        }
    }
    return 0; // Retorna 0 (falso), indicando que o valor n�o foi encontrado ap�s verificar todo o array
}

// Fun��o para ordenar um array 'arr' de tamanho 'n' usando o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // La�o externo: controla o n�mero de passes necess�rios.
    // Em cada passe, o maior elemento restante "flutua" para sua posi��o correta no final do sub-array n�o ordenado.
    for (i = 0; i < n - 1; i++) {
        // La�o interno: compara elementos adjacentes e os troca se estiverem na ordem errada.
        // O '-i' no limite garante que n�o se compare elementos que j� est�o na posi��o correta (no final do array).
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) { // Se o elemento atual for maior que o pr�ximo elemento
                // Troca os elementos de posi��o
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Fun��o principal do programa
int main(int args, char *arg[]) {
    int i, n, r; // Declara��o de vari�veis: i (para la�os), n (quantidade de cheques), r (n�mero aleat�rio gerado)
    int vet[MAX_TAM]; // Declara um array 'vet' para armazenar os n�meros dos cheques, com tamanho m�ximo definido por MAX_TAM

    // Inicializar gerador de n�meros aleat�rios
    // srand() semeia o gerador de n�meros aleat�rios. Usar time(NULL) como semente garante que os n�meros gerados
    // ser�o diferentes a cada execu��o do programa, pois time(NULL) retorna o tempo atual em segundos.
    srand((unsigned)time(NULL));

    // Solicita ao usu�rio a quantidade de cheques a serem gerados
    printf("Digite a quantidade de cheques que deseja a serem gerados (max %d): ", MAX_TAM);
    scanf("%d", &n); // L� o valor digitado pelo usu�rio e armazena em 'n'

    // Verifica se a quantidade digitada � v�lida
    if (n > MAX_TAM || n <= 0) {
        printf("Quantidade invalida. Usando %d cheques como padrao.\n", MAX_TAM);
        n = MAX_TAM; // Se inv�lida, define 'n' para o valor m�ximo padr�o
    }

    printf("\nGerando %d numeros de cheques aleatorios e unicos (entre 1 e 100):\n", n);
    i = 0; // Inicializa o contador para o n�mero de cheques gerados
    do {
        r = random_num(100) + 1; // Gera um n�mero aleat�rio entre 0 e 99 (usando random_num(100)) e soma 1,
                                 // resultando em um n�mero entre 1 e 100 (conforme o problema)
        if (!existe(i, vet, r)) { // Verifica se o n�mero 'r' j� existe no array 'vet' (at� a posi��o 'i')
            vet[i] = r;           // Se n�o existe, adiciona o n�mero ao array
            i++;                  // Incrementa o contador de cheques gerados com sucesso
        }
    } while (i < n); // Continua gerando n�meros at� que 'n' cheques �nicos tenham sido preenchidos

    // Imprime os cheques gerados na ordem em que foram inseridos (n�o ordenados)
    printf("Vetor inicial (sem ordenacao):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]); // Imprime cada n�mero de cheque seguido de um espa�o
    }
    printf("\n"); // Quebra de linha para melhor formata��o

    // Ordenar os cheques em ordem crescente usando a fun��o bubbleSort
    bubbleSort(vet, n);

    // Imprime os cheques ap�s a ordena��o
    printf("\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]); // Imprime cada n�mero de cheque ordenado
    }
    printf("\n"); // Quebra de linha

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
// O bubbleSort � um algoritmo de ordena��o, que percorre repetidamente a lista, comparar elementos adjacentes e troc�-los de lugar se estiverem na ordem errada.
// Esse processo continua at� que nenhuma troca seja necess�ria em uma passagem ordenada, oque significa que a lista est� ordenada.
