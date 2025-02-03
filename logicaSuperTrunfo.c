#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas

void get_string(char *prompt, char *output);
void get_int(char *prompt, int *output);
void get_float(char *prompt, float *output);
void get_double(char *prompt, double *output);
void get_entrada_cidade(
    int ordinal,
    char *nome,
    char *cod_cidade,
    int *populacao,
    int *num_pontos_turisticos,
    float *area,
    float *densidade,
    double *pib,
    double *pib_per_capita,
    double *super_poder);
void exibir_dados_cidade(
    int ordinal,
    char *nome,
    char *cod_cidade,
    int populacao,
    int num_pontos_turisticos,
    float area,
    float densidade,
    double pib,
    double pib_per_capita,
    double super_poder);
void exibir_resultado_int(char *propriedade, char *nome_a, char *nome_b, int valor_a, int valor_b);
void exibir_resultado_float(char *propriedade, char *nome_a, char *nome_b, float valor_a, float valor_b, int invertido);
void exibir_resultado_double(char *propriedade, char *nome_a, char *nome_b, double valor_a, double valor_b);
void comparar_populacao(char *nome_a, char *nome_b, int valor_a, int valor_b);
void comparar_area(char *nome_a, char *nome_b, float valor_a, float valor_b);
void comparar_densidade(char *nome_a, char *nome_b, float valor_a, float valor_b);
void comparar_pib(char *nome_a, char *nome_b, double valor_a, double valor_b);
void comparar_pib_per_capita(char *nome_a, char *nome_b, double valor_a, double valor_b);

int main()
{
    // Declaração dos tributos das cartas
    char nome_a[50];
    char cod_cidade_a[4];
    int populacao_a, num_pontos_turisticos_a;
    float area_a, densidade_a;
    double pib_a, pib_per_capita_a, super_poder_a;

    char nome_b[50];
    char cod_cidade_b[4];
    int populacao_b, num_pontos_turisticos_b;
    float area_b, densidade_b;
    double pib_b, pib_per_capita_b, super_poder_b;

    // Cadastro dos atributos cartas
    printf("\nInserir dados:\n");
    printf("Primeira cidade:\n");

    get_entrada_cidade(
        1,
        nome_a,
        cod_cidade_a,
        &populacao_a,
        &num_pontos_turisticos_a,
        &area_a,
        &densidade_a,
        &pib_a,
        &pib_per_capita_a,
        &super_poder_a);

    printf("\nSegunda cidade:\n");

    get_entrada_cidade(
        2,
        nome_b,
        cod_cidade_b,
        &populacao_b,
        &num_pontos_turisticos_b,
        &area_b,
        &densidade_b,
        &pib_b,
        &pib_per_capita_b,
        &super_poder_b);

    // Exibição dos atributos das cartas
    printf("\nDados:\n");

    exibir_dados_cidade(
        1,
        nome_a,
        cod_cidade_a,
        populacao_a,
        num_pontos_turisticos_a,
        area_a,
        densidade_a,
        pib_a,
        pib_per_capita_a,
        super_poder_a);

    printf("\n");

    exibir_dados_cidade(
        2,
        nome_b,
        cod_cidade_b,
        populacao_b,
        num_pontos_turisticos_b,
        area_b,
        densidade_b,
        pib_b,
        pib_per_capita_b,
        super_poder_b);

    // comparação das cartas
    printf("\nComparação:\n");

    int escolha = 0;

    do
    {
        printf("\nEscolha a propriedade a ser comparada:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Densidade populacional\n");
        printf("5 - PIB per capita\n");
        get_int("Escolha", &escolha);
    } while (!(escolha >= 1 && escolha <= 5));

    printf("\n");

    switch (escolha)
    {
    case 1:
        comparar_populacao(nome_a, nome_b, populacao_a, populacao_b);
        break;
    case 2:
        comparar_area(nome_a, nome_b, area_a, area_b);
        break;
    case 3:
        comparar_pib(nome_a, nome_b, pib_a, pib_b);
        break;
    case 4:
        comparar_densidade(nome_a, nome_b, densidade_a, densidade_b);
        break;
    case 5:
        comparar_pib_per_capita(nome_a, nome_b, pib_per_capita_a, pib_per_capita_b);
        break;
    }

    return 0;
}

void get_string(char *prompt, char *output)
{
    printf("%s: ", prompt);
    scanf("%s", output);
}

void get_int(char *prompt, int *output)
{
    printf("%s: ", prompt);
    scanf("%i", output);
}

void get_float(char *prompt, float *output)
{
    printf("%s: ", prompt);
    scanf("%f", output);
}

void get_double(char *prompt, double *output)
{
    printf("%s: ", prompt);
    scanf("%lf", output);
}

void get_entrada_cidade(
    int ordinal,
    char *nome,
    char *cod_cidade,
    int *populacao,
    int *num_pontos_turisticos,
    float *area,
    float *densidade,
    double *pib,
    double *pib_per_capita,
    double *super_poder)
{
    if (ordinal == 1)
    {
        get_string("Digite o nome da primeira cidade", nome);
        get_string("Digite o código da primeira cidade", cod_cidade);
        get_int("Digite a população da primeira cidade", populacao);
        get_float("Digite a área da primeira cidade (em km²)", area);
        get_double("Digite o PIB da primeira cidade", pib);
        get_int("Digite o número de pontos turísticos da primeira cidade", num_pontos_turisticos);
    }
    else if (ordinal == 2)
    {
        get_string("Digite o nome da segunda cidade", nome);
        get_string("Digite o código da segunda cidade", cod_cidade);
        get_int("Digite a população da segunda cidade", populacao);
        get_float("Digite a área da segunda cidade (em km²)", area);
        get_double("Digite o PIB da segunda cidade", pib);
        get_int("Digite o número de pontos turísticos da segunda cidade", num_pontos_turisticos);
    }

    *densidade = (*area > 0) ? *populacao / *area : 0;
    *pib_per_capita = (*populacao > 0) ? *pib / *populacao : 0;
    *super_poder = *populacao + *num_pontos_turisticos + *area + *pib + *densidade + *pib_per_capita;
}

void exibir_dados_cidade(
    int ordinal,
    char *nome,
    char *cod_cidade,
    int populacao,
    int num_pontos_turisticos,
    float area,
    float densidade,
    double pib,
    double pib_per_capita,
    double super_poder)
{
    char *ord = "primeira";
    if (ordinal == 2)
    {
        ord = "segunda";
    }

    printf("Dados da %s cidade:\n", ord);
    printf("Nome: %s\n", nome);
    printf("Código: %s\n", cod_cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("Pib: r$ %.2f\n", pib);
    printf("Pontos turísticos: %d\n", num_pontos_turisticos);
    printf("Densidade populacional: %.2f pessoas / km²\n", densidade);
    printf("Pib per capita: R$ %.2f por pessoa\n", pib_per_capita);
    printf("Super poder: %.2f\n", super_poder);
}

int comparar_int(int a, int b)
{
    if (a == b)
    {
        return -1;
    }
    return (a > b) ? 1 : 0;
}

float comparar_float(float a, float b)
{
    if (a == b)
    {
        return -1;
    }
    return (a > b) ? 1 : 0;
}

double comparar_double(double a, double b)
{
    if (a == b)
    {
        return -1;
    }
    return (a > b) ? 1 : 0;
}

void exibir_resultado_int(char *propriedade, char *nome_a, char *nome_b, int valor_a, int valor_b)
{
    printf("%s: %s: %i\n", nome_a, propriedade, valor_a);
    printf("%s: %s: %i\n", nome_b, propriedade, valor_b);

    int resultado = comparar_int(valor_a, valor_b);
    if (resultado == -1)
    {
        printf("%s: Empate! (%i = %i)\n", propriedade, valor_a, valor_b);
    }
    else
    {
        char *vencedor;
        int valor_maior;
        int valor_menor;

        if (resultado == 1)
        {
            vencedor = nome_a;
            valor_maior = valor_a;
            valor_menor = valor_b;
        }
        else
        {

            vencedor = nome_b;
            valor_maior = valor_b;
            valor_menor = valor_a;
        }
        printf("%s: %s venceu! (%i > %i)\n", propriedade, vencedor, valor_maior, valor_menor);
    }
}

void exibir_resultado_float(char *propriedade, char *nome_a, char *nome_b, float valor_a, float valor_b, int invertido)
{
    printf("%s: %s: %.2f\n", nome_a, propriedade, valor_a);
    printf("%s: %s: %.2f\n", nome_b, propriedade, valor_b);

    int resultado = comparar_float(valor_a, valor_b);
    if (resultado != -1 && invertido != 0)
    {
        resultado = (resultado == 1) ? 0 : 1;
    }
    if (resultado == -1)
    {
        printf("%s: Empate! (%.2f = %.2f)\n", propriedade, valor_a, valor_b);
    }
    else
    {
        char *vencedor;
        float valor_maior;
        float valor_menor;

        if (resultado == 1)
        {
            vencedor = nome_a;
            valor_maior = valor_a;
            valor_menor = valor_b;
        }
        else
        {

            vencedor = nome_b;
            valor_maior = valor_b;
            valor_menor = valor_a;
        }
        printf("%s: %s venceu! (%.2f > %.2f)\n", propriedade, vencedor, valor_maior, valor_menor);
    }
}

void exibir_resultado_double(char *propriedade, char *nome_a, char *nome_b, double valor_a, double valor_b)
{
    printf("%s: %s: %.2lf\n", nome_a, propriedade, valor_a);
    printf("%s: %s: %.2lf\n", nome_b, propriedade, valor_b);

    int resultado = comparar_double(valor_a, valor_b);
    if (resultado == -1)
    {
        printf("%s: Empate! (%.2lf = %.2lf)\n", propriedade, valor_a, valor_b);
    }
    else
    {
        char *vencedor;
        double valor_maior;
        double valor_menor;

        if (resultado == 1)
        {
            vencedor = nome_a;
            valor_maior = valor_a;
            valor_menor = valor_b;
        }
        else
        {

            vencedor = nome_b;
            valor_maior = valor_b;
            valor_menor = valor_a;
        }
        printf("%s: %s venceu! (%.2lf > %.2lf)\n", propriedade, vencedor, valor_maior, valor_menor);
    }
}

void comparar_populacao(char *nome_a, char *nome_b, int valor_a, int valor_b)
{
    exibir_resultado_int("População", nome_a, nome_b, valor_a, valor_b);
}

void comparar_num_pontos_turisticos(char *nome_a, char *nome_b, int valor_a, int valor_b)
{
    exibir_resultado_int("Pontos turísticos", nome_a, nome_b, valor_a, valor_b);
}

void comparar_area(char *nome_a, char *nome_b, float valor_a, float valor_b)
{
    exibir_resultado_float("Área", nome_a, nome_b, valor_a, valor_b, 0);
}

void comparar_densidade(char *nome_a, char *nome_b, float valor_a, float valor_b)
{
    exibir_resultado_float("Densidade", nome_a, nome_b, valor_a, valor_b, 1);
}

void comparar_pib(char *nome_a, char *nome_b, double valor_a, double valor_b)
{
    exibir_resultado_double("PIB", nome_a, nome_b, valor_a, valor_b);
}

void comparar_pib_per_capita(char *nome_a, char *nome_b, double valor_a, double valor_b)
{
    exibir_resultado_double("PIB per capita", nome_a, nome_b, valor_a, valor_b);
}

void comparar_super_poder(char *nome_a, char *nome_b, double valor_a, double valor_b)
{
    exibir_resultado_double("Super poder:", nome_a, nome_b, valor_a, valor_b);
}
