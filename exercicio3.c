#include <stdio.h>
#include <locale.h>

#define TAM 15

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int vet[TAM], posicao;

    for (posicao = 0; psicao < TAM; posicao++) {
        printf("Posição %d do vetor: ", posicao);
        scanf("%d", &vet[posicao]);
    }

    print("\n\n");

    for (posicao = TAM - 1; posicao >= 0; posicao=-) {
        printf("%d\t", &vet[posicao]);
    }

    return 0;



}
