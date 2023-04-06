#include <stdio.h>

// Função que calcula a cor atual a partir da cor inicial e final
int calc_color_init(int cor_inicial, int cor_final, int passo_atual, int num_passos) {
    int r_inicial = (cor_inicial >> 16) & 0xFF;
    int g_inicial = (cor_inicial >> 8) & 0xFF;
    int b_inicial = cor_inicial & 0xFF;
    
    int r_final = (cor_final >> 16) & 0xFF;
    int g_final = (cor_final >> 8) & 0xFF;
    int b_final = cor_final & 0xFF;
    
    int delta_r = r_final - r_inicial;
    int delta_g = g_final - g_inicial;
    int delta_b = b_final - b_inicial;
    
    int r_atual = r_inicial + (passo_atual * delta_r / num_passos);
    int g_atual = g_inicial + (passo_atual * delta_g / num_passos);
    int b_atual = b_inicial + (passo_atual * delta_b / num_passos);
    
    return (r_atual << 16) | (g_atual << 8) | b_atual;
}

// Função que imprime a cor em formato hexadecimal
void print_color(int cor) {
    printf("#%06X\n", cor);
}

// Função principal
int main() {
    int cor_inicial = 0x00001A;
    int cor_final = 0xFF001A;
    int num_passos = 10;
    
    for (int i = 0; i < num_passos; i++) {
        int cor_atual = calc_color_init(cor_inicial, cor_final, i, num_passos);
        print_color(cor_atual);
    }
    
    return 0;
}
