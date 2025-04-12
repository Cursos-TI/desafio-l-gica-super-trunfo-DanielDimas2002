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
    int escolha;

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

    // =============== MENU INTERATIVO DE COMPARAÇÃO ===============
    printf("\n===== MENU DE COMPARAÇÃO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    // Lógica de comparação com switch e if-else aninhado
    switch (escolha) {
        case 1: // População
            printf("\n===== Comparação de Cartas (População) =====\n");
            printf("%s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
            printf("%s (%s): %d habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("\n===== Comparação de Cartas (Área) =====\n");
            printf("%s (%s): %.2f km²\n", carta1.nomeCidade, carta1.estado, carta1.area);
            printf("%s (%s): %.2f km²\n", carta2.nomeCidade, carta2.estado, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("\n===== Comparação de Cartas (PIB) =====\n");
            printf("%s (%s): R$ %.2f bilhões\n", carta1.nomeCidade, carta1.estado, carta1.pib);
            printf("%s (%s): R$ %.2f bilhões\n", carta2.nomeCidade, carta2.estado, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("\n===== Comparação de Cartas (Pontos Turísticos) =====\n");
            printf("%s (%s): %d pontos turísticos\n", carta1.nomeCidade, carta1.estado, carta1.pontosTuristicos);
            printf("%s (%s): %d pontos turísticos\n", carta2.nomeCidade, carta2.estado, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (regra invertida)
            printf("\n===== Comparação de Cartas (Densidade Demográfica) =====\n");
            printf("%s (%s): %.2f hab/km²\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional);
            printf("%s (%s): %.2f hab/km²\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);
            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default: // Opção inválida
            printf("\nOpção inválida! Por favor, escolha um número de 1 a 5.\n");
            break;
    }

    return 0;
}
