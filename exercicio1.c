#include <stdio.h>
#include <locale.h>

#define TAM 10
int main(){
    setlocale(LC_ALL, "Portuguese");
    int numeros[TAM], i;

    for (i = 0; i < TAM; i++) {
        printf("Posição %d do vetor: ", i);
        scanf("%d", &numeros[i]);
    }
        printf("\n\n");

        for (i = 0; i < TAM; i++) {
            printf("%d\t", numeros[i]);
        }
    return 0;
}
