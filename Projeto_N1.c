#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Define o tamanho máximo da mensagem.

int main() {
    char mensagem[MAX_LENGTH]; // Array para armazenar a mensagem original.
    char msgCodificada[MAX_LENGTH]; // Array para armazenar a mensagem codificada.
    int i;

    // Solicita para o usuário que insira a mensagem.
    printf("Digite a mensagem a ser codificada: ");
    fgets(mensagem, MAX_LENGTH, stdin); // Lê a mensagem do usuário.

    // Percorre cada caractere da mensagem
    for (i = 0; i < strlen(mensagem); i++) 
    {
        // Aplica a fórmula de codificação
        msgCodificada[i] = (5 * mensagem[i] + 100) % 256;
    }
    // Adiciona o caractere nulo ao final da mensagem codificada
    msgCodificada[i] = '\0';

    // Exibe a mensagem codificada
    printf("Mensagem codificada: ");
    for (int j = 0; j < strlen(mensagem); j++)
    { 
    // Exibe cada caractere codificado como um número inteiro.
        printf("%d ", msgCodificada[j]);
    }
    printf("\n");

    return 0; // Indica que o programa terminou.
}