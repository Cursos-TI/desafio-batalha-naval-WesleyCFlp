#include <stdio.h>
#include <stdbool.h>

// Funções para aproveitamento de código
void regrasDoJogo() {
    printf("\n==================================== Regras do jogo! ====================================\n");
    printf("\nBatalha Naval é um jogo clássico de estratégia e raciocínio lógico onde dois participantes disputam entre si. O objetivo é afundar a frota inimiga em um tabuleiro de coordenadas. Cada jogador posiciona secretamente seus navios e, por turnos, atira informando letras e números. Vence quem destruir todos os navios do oponente primeiro\n");
}

void batalhaNavalC() {
    printf("\n==================================== Jogo iniciado! ====================================\n");

    char * tabuleiro[11][11] = {
        {" - ",  " A ", " B ", " C ", " D ", " E ", " F ", " G ", " H ", " I ", " J "},
        {" 1 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {" 2 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {" 3 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {" 4 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {" 5 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {" 6 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {" 7 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {" 8 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {" 9 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "},
        {"10 ",  " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 ", " 0 "}
    };

    // Variáveis para definir a posição do navio 1
    int linha1, coluna1, pontaDireita1, pontaEsquerda1;
    linha1 = 5;
    coluna1 = 5;
    pontaDireita1 = 6; // A posição da ponta direita é a linha + 1
    pontaEsquerda1 = 4; // A posição da ponta esquerda é a linha - 1

    // Loop para definir a posição do primeiro navio
    for (int i = 0; i <= linha1 + 1; i++) {
        for (int j = 0; j < 11; j++) {
            if (i == linha1 && (j == coluna1 || j == pontaDireita1 || j == pontaEsquerda1)) {
                tabuleiro[i][j] = " 3 ";
            }
        }
    }

    // Variáveis para definir a posição do navio 2
    int linha2, coluna2, pontaCima2, pontaBaixo2;
    linha2 = 6;
    coluna2 = 7;
    pontaCima2 = 5; // A posição da ponta direita é a linha - 1
    pontaBaixo2 = 7; // A posição da ponta esquerda é a linha + 1

    // Loop para definir a posição do segundo navio
    for (int k = 0; k < 11; k++) {
        for (int l = 0; l <= coluna2 + 1; l++) {
            if (l == coluna2 && (k == linha2 || k == pontaCima2 || k == pontaBaixo2)) {
                tabuleiro[k][l] = " 3 ";
            }
        }
    }

    // Loop para imprimir o tabuleiro
    for (int m = 0; m < 11; m++) {
        for (int n = 0; n < 11; n++) {
            printf("%s ", tabuleiro[m][n]);
        }
        printf("\n");
    }





    printf("\n");
    printf("\nJogo finalizado!\n");
    printf("\n");
}

void creditosCriacao() {
    printf("\n==================================== Créditos ====================================\n");
    printf("\nBem-vindo à aba dos créditos!\nO intuito dessa aba é dar créditos ao criador desse sistema, Wesley Amaral de Carvalho. Esse sistema foi feito durante sua primeira graduação, bacharelado em Ciências da Computação, na instituição Newton Paiva Wyden, Alípio de Melo polo EAD.\n");
}



int main() {                                   // Jogo de batalha naval em C
    // While para manter o sistema funcionando até que o usuário escolha finalizar o jogo
    bool play = true;
    int opcaoMenu;

    printf("\n==================================== Bem-vindo(a) ao jogo de xadrez online! ====================================\n");

    while (play == true) {
        
        // Menu do jogo
        printf("\n1. Regras do jogo\n2. Jogar\n3. Créditos\n4. Sair do jogo\nPara começar, digite o que deseja fazer: ");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
        case 1:
            // Como jogar xadrez
            regrasDoJogo();
            break;

        case 2: 
            // Jogo 
            batalhaNavalC();
            break;

        case 3: 
            // Créditos
            creditosCriacao();
            break;

        case 4: 
            // Encerrar o jogo
            printf("\nSaindo...");
            printf("\nJogo encerrado!\n");
            play = false;
            break;

        default:
            printf("\n==================================== Opção inválida! Digite um número de 1 a 4 para continuar! ====================================\n");
            break;
        }
    }

    return 0;

}