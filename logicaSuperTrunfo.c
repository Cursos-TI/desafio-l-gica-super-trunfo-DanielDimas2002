#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];             // Sigla do estado (ex: SP, RJ)
    char codigo[10];            // Código identificador da carta
    char nomeCidade[50];        // Nome da cidade
    int populacao;              // População da cidade
    float area;                 // Área da cidade
    float pib;                  // Produto Interno Bruto da cidade
    int pontosTuristicos;       // Número de pontos turísticos
    float densidadePopulacional;// População / Área
    float pibPerCapita;         // PIB / População
};

int main() {
    // Declaração das duas cartas
    struct Carta carta1, carta2;

    // ================= CADASTRO DA CARTA 1 =================
    printf("===== Cadastro da Carta 1 =====\n");

    printf("Estado: ");
    scanf("%s", carta1.estado);

    printf("Código: ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);  // lê string com espaços

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Calculando os indicadores da carta 1
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // ================= CADASTRO DA CARTA 2 =================
    printf("\n===== Cadastro da Carta 2 =====\n");

    printf("Estado: ");
    scanf("%s", carta2.estado);

    printf("Código: ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Calculando os indicadores da carta 2
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // =============== ESCOLHA DOS ATRIBUTOS ===============
    int atributo1, atributo2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;

    printf("\n===== Selecione os atributos para comparação =====\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");

    // Leitura do primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo (1 a 6): ");
    scanf("%d", &atributo1);

    // Menu dinâmico (exclui o primeiro atributo da lista)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1) {
            switch(i) {
                case 1: printf("%d - População\n", i); break;
                case 2: printf("%d - Área\n", i); break;
                case 3: printf("%d - PIB\n", i); break;
                case 4: printf("%d - Pontos Turísticos\n", i); break;
                case 5: printf("%d - Densidade Populacional\n", i); break;
                case 6: printf("%d - PIB per Capita\n", i); break;
            }
        }
    }

    printf("Escolha o SEGUNDO atributo: ");
    scanf("%d", &atributo2);

    // =============== OBTENDO VALORES DOS ATRIBUTOS ===============
    // Primeiro atributo
    switch (atributo1) {
        case 1: valor1_c1 = carta1.populacao; valor1_c2 = carta2.populacao; break;
        case 2: valor1_c1 = carta1.area; valor1_c2 = carta2.area; break;
        case 3: valor1_c1 = carta1.pib; valor1_c2 = carta2.pib; break;
        case 4: valor1_c1 = carta1.pontosTuristicos; valor1_c2 = carta2.pontosTuristicos; break;
        case 5: valor1_c1 = carta1.densidadePopulacional; valor1_c2 = carta2.densidadePopulacional; break;
        case 6: valor1_c1 = carta1.pibPerCapita; valor1_c2 = carta2.pibPerCapita; break;
        default: printf("Atributo inválido!\n"); return 1;
    }

    // Segundo atributo
    switch (atributo2) {
        case 1: valor2_c1 = carta1.populacao; valor2_c2 = carta2.populacao; break;
        case 2: valor2_c1 = carta1.area; valor2_c2 = carta2.area; break;
        case 3: valor2_c1 = carta1.pib; valor2_c2 = carta2.pib; break;
        case 4: valor2_c1 = carta1.pontosTuristicos; valor2_c2 = carta2.pontosTuristicos; break;
        case 5: valor2_c1 = carta1.densidadePopulacional; valor2_c2 = carta2.densidadePopulacional; break;
        case 6: valor2_c1 = carta1.pibPerCapita; valor2_c2 = carta2.pibPerCapita; break;
        default: printf("Atributo inválido!\n"); return 1;
    }

    // =============== COMPARAÇÃO DOS ATRIBUTOS ===============
    printf("\n===== Resultado da Comparação =====\n");
    printf("Carta 1 - %s (%s)\n", carta1.nomeCidade, carta1.estado);
    printf("Carta 2 - %s (%s)\n\n", carta2.nomeCidade, carta2.estado);

    // Mostrar os valores
    printf("Atributo 1 (ID %d): %.2f (Carta 1) x %.2f (Carta 2)\n", atributo1, valor1_c1, valor1_c2);
    printf("Atributo 2 (ID %d): %.2f (Carta 1) x %.2f (Carta 2)\n", atributo2, valor2_c1, valor2_c2);

    // Inversão da lógica apenas para densidade (atributo 5)
    float soma1 = ((atributo1 == 5) ? -valor1_c1 : valor1_c1) + ((atributo2 == 5) ? -valor2_c1 : valor2_c1);
    float soma2 = ((atributo1 == 5) ? -valor1_c2 : valor1_c2) + ((atributo2 == 5) ? -valor2_c2 : valor2_c2);

    printf("\nSoma dos atributos:\n");
    printf("Carta 1: %.2f\n", soma1);
    printf("Carta 2: %.2f\n", soma2);

    // Resultado final com ternário
    printf("\nResultado: ");
    (soma1 > soma2) ? printf("Carta 1 (%s) venceu!\n", carta1.nomeCidade) :
    (soma2 > soma1) ? printf("Carta 2 (%s) venceu!\n", carta2.nomeCidade) :
    printf("Empate!\n");

    return 0;
}
