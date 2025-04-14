#include <stdio.h>
#include <string.h>

#define MAX 2

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void cadastrarCartas(Carta cartas[]) {
    for (int i = 0; i < MAX; i++) {
        printf("\n--- Cadastro da Carta %d ---\n", i + 1);
        printf("Nome do País: ");
        scanf(" %[^\n]", cartas[i].nomePais);

        printf("População (em milhões): ");
        scanf("%d", &cartas[i].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em trilhões): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }
}

void exibirMenuAtributos() {
    printf("\nEscolha os atributos para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
}

int compararAtributo(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: return (c1.populacao > c2.populacao) ? 1 : (c1.populacao < c2.populacao) ? 2 : 0;
        case 2: return (c1.area > c2.area) ? 1 : (c1.area < c2.area) ? 2 : 0;
        case 3: return (c1.pib > c2.pib) ? 1 : (c1.pib < c2.pib) ? 2 : 0;
        case 4: return (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : (c1.pontosTuristicos < c2.pontosTuristicos) ? 2 : 0;
        default: return -1;
    }
}

void compararCartas(Carta cartas[]) {
    int atributo1, atributo2;

    exibirMenuAtributos();
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    int resultado1 = compararAtributo(cartas[0], cartas[1], atributo1);
    int resultado2 = compararAtributo(cartas[0], cartas[1], atributo2);

    printf("\nResultado da Comparação:\n");
    if (resultado1 == 0 && resultado2 == 0) {
        printf("Empate nos dois atributos!\n");
    } else if ((resultado1 == 1 && resultado2 != 2) || (resultado2 == 1 && resultado1 != 2)) {
        printf("Carta Vencedora: %s\n", cartas[0].nomePais);
    } else if ((resultado1 == 2 && resultado2 != 1) || (resultado2 == 2 && resultado1 != 1)) {
        printf("Carta Vencedora: %s\n", cartas[1].nomePais);
    } else {
        printf("Empate! Uma carta venceu um atributo e perdeu o outro.\n");
    }
}

int main() {
    Carta cartas[MAX];

    printf("=== SUPER TRUNFO - PAÍSES (NÍVEL MESTRE) ===\n");

    cadastrarCartas(cartas);
    compararCartas(cartas);

    return 0;
}
