#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nome[20];
    float notas[4];

} TAluno;

typedef TAluno TListaAlunos[2];

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mediaNotas(TListaAlunos aluno) {

    for(int x=0; x<2; x++) {
        printf("Digite o nome do aluno %d: ", x+1);
        scanf("%[^\n]", aluno[x].nome);
        limpaBuffer();

        for(int y=0; y<4; y++){
            printf("Digite a nota %d, do aluno %d: ", y+1, x+1);
            scanf("%f", &aluno[x].notas[y]);
        }

    }
}


int main() {

    TListaAlunos aluno;

    mediaNotas(aluno);



    return 0;
}
