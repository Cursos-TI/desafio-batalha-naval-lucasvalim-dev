#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se o navio pode ser posicionado sem sair dos limites ou sobrepor outro navio
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        if (coluna + TAM_NAVIO > TAMANHO) return 0; // Fora dos limites
        for (int j = 0; j < TAM_NAVIO; j++) {
            if (tabuleiro[linha][coluna + j] != 0) return 0; // Sobreposição
        }
    } else { // Vertical
        if (linha + TAM_NAVIO > TAMANHO) return 0; // Fora dos limites
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Sobreposição
        }
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (orientacao == 0) // Horizontal
            tabuleiro[linha][coluna + i] = 3;
        else // Vertical
            tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para exibir o tabuleiro com rótulos de linha e coluna
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%2d ", j + 1); // Exibe os números das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%c  ", 'A' + i); // Exibe as letras das linhas
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (convertendo de letras para índices)
    int linha1 = 1, coluna1 = 2, orientacao1 = 0; // Navio horizontal (Linha B, Coluna 3)
    int linha2 = 4, coluna2 = 6, orientacao2 = 1; // Navio vertical (Linha E, Coluna 7)

    // Posiciona os navios validando as posições
    if (podePosicionar(tabuleiro, linha1, coluna1, orientacao1))
        posicionarNavio(tabuleiro, linha1, coluna1, orientacao1);

    if (podePosicionar(tabuleiro, linha2, coluna2, orientacao2))
        posicionarNavio(tabuleiro, linha2, coluna2, orientacao2);

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
