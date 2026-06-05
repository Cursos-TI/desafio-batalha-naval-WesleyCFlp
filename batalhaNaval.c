 #include <stdio.h>
#include <stdbool.h>

#define LINHAS 11
#define COLUNAS 11


// Funções para aproveitamento de código
void regrasDoJogo() {
    printf("\n==================================== Regras do jogo! ====================================\n");
    printf("\nBatalha Naval é um jogo clássico de estratégia e raciocínio lógico onde dois participantes disputam entre si. O objetivo é afundar a frota inimiga em um tabuleiro de coordenadas. Cada jogador posiciona secretamente seus navios e, por turnos, atira informando letras e números. Vence quem destruir todos os navios do oponente primeiro\n");
    printf("Legenda do tabuleiro: \n0 - Água\n1 - Área de ataque\n3 - Navio");
}

void batalhaNavalC() {
    printf("\n==================================== Jogo iniciado! ====================================\n");

    char * tabuleiroNavios[LINHAS][COLUNAS] = {
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

    char * tabuleiroAtaques[LINHAS][COLUNAS] = {
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

    // Definindo alcance de cada ataque através de matrizes - Ataque em forma de cone com o ponto incial no centro
    char * ataqueCone[3][5] = {
        {" 0 ", " 0 ", " 1 ", " 0 ", " 0 "},
        {" 0 ", " 1 ", " 1 ", " 1 ", " 0 "},
        {" 1 ", " 1 ", " 1 ", " 1 ", " 1 "}
    };

    // Ponto de inserção do ataque em forma de cone
    int ataqueConeLinhas = 1;
    int ataqueConeColunas = 1;

    // Loop para definir o alcance do ataque em forma de cone no tabuleiro de ataques
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < LINHAS; k++) {
                for (int l = 0; l < COLUNAS; l++) {
                    if (k == ataqueConeLinhas + i && l == ataqueConeColunas + j) {
                        tabuleiroAtaques[k][l] = ataqueCone[i][j];
                    }
                }
            }
        }
    }

    // Ataque em forma de cruz com o ponto inicial no centro
    char *  ataqueCruz[3][5] = {
        {" 0 ", " 0 ", " 1 ", " 0 ", " 0 "},
        {" 0 ", " 1 ", " 1 ", " 1 ", " 0 "},
        {" 0 ", " 0 ", " 1 ", " 0 ", " 0 "}
    };

    // Ponto de inserção do ataque em forma de cruz
    int ataqueCruzLinhas = 1;
    int ataqueCruzColunas = 1;

    // Loop para definir o alcance do ataque em forma de cruz no tabuleiro de ataques
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < LINHAS; k++) {
                for (int l = 0; l < COLUNAS; l++) {
                    if (k == ataqueCruzLinhas + i && l == ataqueCruzColunas + j) {
                        tabuleiroAtaques[k + 5][l + 5] = ataqueCruz[i][j];
                    }
                }
            }
        }
    }

    // Ataque em forma de octaedro com o ponto inicial no centro
    char *  ataqueOctaedro[5][5] = {
        {" 0 ", " 0 ", " 1 ", " 0 ", " 0 "},
        {" 0 ", " 1 ", " 1 ", " 1 ", " 0 "},
        {" 1 ", " 1 ", " 1 ", " 1 ", " 1 "},
        {" 0 ", " 1 ", " 1 ", " 1 ", " 0 "},
        {" 0 ", " 0 ", " 1 ", " 0 ", " 0 "}
    };

    // Ponto de inserção do ataque em forma de octaedro(losangolo)
    int ataqueOctaedroLinhas = 1;
    int ataqueOctaedroColunas = 1;

    // Loop para definir o alcance do ataque em forma de octaedro no tabuleiro de ataques
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < LINHAS; k++) {
                for (int l = 0; l < COLUNAS; l++) {
                    if (k == ataqueOctaedroLinhas + i && l == ataqueOctaedroColunas + j) {
                        tabuleiroAtaques[k + 5][l] = ataqueOctaedro[i][j];
                    }
                }
            }
        }
    }

    // Primeiro Navio
    // Variáveis para definir a posição do navio 
    int linha1, coluna1, pontaDireita1, pontaEsquerda1;
    linha1 = 5;
    coluna1 = 5;
    pontaDireita1 = 6; // A posição da ponta direita é a linha + 1
    pontaEsquerda1 = 4; // A posição da ponta esquerda é a linha - 1

    // Loop para definir a posição do navio
    for (int i = 0; i <= linha1 + 1; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == linha1 && (j == coluna1 || j == pontaDireita1 || j == pontaEsquerda1)) {
                tabuleiroNavios[i][j] = " 3 ";
            }
        }
    }


    // Segundo Navio
    // Variáveis para definir a posição do navio
    int linha2, coluna2, pontaDireita2, pontaEsquerda2;
    linha2 = 6;
    coluna2 = 7;
    pontaDireita2 = 5; // A posição da ponta direita é a linha - 1
    pontaEsquerda2 = 7; // A posição da ponta esquerda é a linha + 1

    // Loop para definir a posição do navio
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j <= coluna2 + 1; j++) {
            if (j == coluna2 && (i == linha2 || i == pontaDireita2 || i == pontaEsquerda2)) {
                tabuleiroNavios[i][j] = " 3 ";
            }
        }
    }

    // Terceiro Navio - Diagonal Principal
    // Variáveis para definir a posição do navio
    int linha3, coluna3, pontaDireita3, pontaEsquerda3;
    linha3 = 2;
    coluna3 = 2;
    pontaDireita3 = 3; // A posição da ponta direita é a linha + 1 e coluna + 1
    pontaEsquerda3 = 1; // A posição da ponta esquerda é a linha - 1 e coluna - 1

    // Loop para definir a posição do navio
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if ((i == linha3 && j == coluna3) || (i == pontaDireita3 && j == pontaDireita3) || (i == pontaEsquerda3 && j == pontaEsquerda3)) {
                tabuleiroNavios[i][j] = " 3 ";
            }
        }
    }

    // Quarto Navio - Diagonal Secundária
    // Variáveis para definir a posição do navio
    int linha4, coluna4, pontaDireita4, pontaEsquerda4;
    linha4 = 8;
    coluna4 = 3;
    pontaDireita4 = 7; // A posição da ponta direita é a linha - 1 e coluna + 1
    pontaEsquerda4 = 9; // A posição da ponta esquerda é a linha + 1 e coluna - 1

    // Loop para definir a posição do navio
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++){
            if ((i == linha4 && j == coluna4) || (i == pontaDireita4 && j == (coluna4 + 1)) || (i == pontaEsquerda4 && j == (coluna4 - 1))) {
                tabuleiroNavios[i][j] = " 3 ";
            }
        }
    }


    // Loop para imprimir o tabuleiro informando a posição dos navios
    printf("\nTabuleiro dos navios:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%s ", tabuleiroNavios[i][j]);
        }
        printf("\n");
    }

    // Loop para imprimir o tabuleiro informando as áreas de ataque
    printf("\nTabuleiro dos ataques:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%s ", tabuleiroAtaques[i][j]);
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