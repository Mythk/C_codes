#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 5

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    int mat[LINHAS][COLUNAS], i, j;

    for( i = 0; i < LINHAS; i++) {
        for( j = 0; j < COLUNAS; j++) {
            mat[i][j] = rand()%(LINHAS * COLUNAS) + 1;
        }
    }
        for( i = 0; i < LINHAS; i++) {
            for( j = 0; j < COLUNAS; j++) {
                printf("%d\t", mat[i][j]);
            }
            printf("\n");
        }


    return 0;
}
