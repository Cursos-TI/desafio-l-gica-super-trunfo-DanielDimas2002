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

    // =============== COMPARAÇÃO DAS CARTAS ===============
    // Atributo escolhido para comparação: POPULAÇÃO

    printf("\n===== Comparação de Cartas (Atributo: População) =====\n");

    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate! Ambas as cidades têm a mesma população.\n");
    }

    return 0;
}
