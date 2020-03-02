#include <stdio.h>
#include <stdlib.h>

int main() {
    int anoAtual, anoNascimento;
    char* nome;

    nome = (char*) malloc(sizeof(char) * 100);
    scanf("%d %s %d", &anoAtual, nome, &anoNascimento);

    printf("%s, voce completa %d anos de idade neste ano.\n", nome, (anoAtual - anoNascimento));

    return 0;
}