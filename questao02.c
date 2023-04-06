#include <stdio.h>

int val_romano(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    char num_romano[20];
    int num_decimal = 0, i;

    printf("Digite um número romano: ");
    scanf("%s", num_romano);

    for (i = 0; num_romano[i] != '\0'; i++) {
        if (val_romano(num_romano[i]) < val_romano(num_romano[i+1])) {
            num_decimal -= val_romano(num_romano[i]);
        }
        else {
            num_decimal += val_romano(num_romano[i]);
        }
    }

    printf("O número decimal é: %d\n", num_decimal);

    return 0;
}
