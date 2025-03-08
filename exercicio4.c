#include <stdio.h>
#include <locale.h>

#define 20

int main(){
    setlocale(LC_ALL, "Portuguese");
    int numeros[20], i;

    for (i = 0; i < 20; i++) {
        printf("Posição %d do vetor: ", i);
        scanf("%d", &numeros[i]);
    }
        printf("\n\n");

        for(i = 0; i < 20; i++) {
            if(numeros[i] % 2 == 0) {
                printf("\nElemento %d na posição %d\n", numeros[i]);

            }
        }
            return 0;
}
