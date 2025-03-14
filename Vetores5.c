#include <stdio.h>

int main() {
    int vetorInteiros[10];

    for(int x = 0; x < 10; x++){
        printf("digite um Inteiro: \n");
        scanf("%d", &vetorInteiros[x]);
        if(x == 9){
            printf("-- Valores Digitados -- \n");
            for(int y=0; y < 10; y++){
                printf("Indice: %d -> Valor: %d \n", y, vetorInteiros[y]);
            }
        }
    }

    getchar();
    return 0;

}
