#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char premio[10] = "1234"; // Prêmio sorteado
    char sorteio[10]; // Número sorteado pelo usuário

    // Gera um número aleatório entre 1000 e 9999
    srand(time(NULL));
    int num_sorteado = rand() % 9000 + 1000;

    // Converte o número sorteado para uma string
    sprintf(sorteio, "%d", num_sorteado);

    // Exibe o número sorteado
    printf("O número sorteado foi: %s\n", sorteio);

    // Compara o número sorteado com o prêmio
    if (strcmp(sorteio, premio) == 0) {
        printf("Ganhou!\n");
    } else {
        printf("Não ganhou!\n");
    }

    return 0;
}
