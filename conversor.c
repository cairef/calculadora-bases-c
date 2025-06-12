#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_HEX 100
#define MAX_BIN 65

short suporte_cores = 1; // Variável para verificar suporte a cores ANSI

// Função para converter caractere hexadecimal para decimal
int caractereHexParaDecimal(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    else if (c >= 'a' && c <= 'f')
        return 10 + (c - 'a');
    else
        return -1;
}

// Função para validar string hexadecimal
int validarHexadecimal(const char *hex)
{
    int i;
    for (i = 0; hex[i] != '\0'; i++)
    {
        if (!isxdigit(hex[i]))
            return 0;
    }
    return 1;
}

// Função para converter hexadecimal para decimal
unsigned long hexadecimalParaDecimal(const char *hex)
{
    return strtoul(hex, NULL, 16);
}

// Função para converter hexadecimal para binário
void hexadecimalParaBinario(const char *hex)
{
    printf("Resultado em binário: ");
    int i;
    for (i = 0; hex[i] != '\0'; i++)
    {
        int decimal = caractereHexParaDecimal(hex[i]);
        if (decimal == -1)
        {
            printf("\nCaractere inválido: %c\n", hex[i]);
            return;
        }
        int j;
        for (j = 3; j >= 0; j--)
        {
            printf("%d", (decimal >> j) & 1);
        }
    }
    printf("\n");
}

// Função para converter decimal para binário
void decimalParaBinario()
{
    int numdec;
    int restoBin[64];
    int i = 0;

    printf("Digite um número decimal: ");
    scanf("%d", &numdec);

    if (numdec == 0)
    {
        printf("O número binário equivalente é: 0\n");
        return;
    }

    while (numdec > 0)
    {
        restoBin[i++] = numdec % 2;
        numdec /= 2;
    }

    printf("O número binário equivalente é: ");
    int j;
    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", restoBin[j]);
    }
    printf("\n");
}

// Função para converter binário para decimal
void binarioParaDecimal()
{
    char binario[MAX_BIN];
    int decimal = 0;

    printf("Digite um número binário: ");
    scanf("%64s", binario);

    int comprimento = strlen(binario);

    int i;
    for (i = 0; i < comprimento; i++)
    {
        char c = binario[comprimento - i - 1];
        if (c == '1')
        {
            decimal += (1 << i);
        }
        else if (c != '0')
        {
            printf("Caractere inválido na entrada!\n");
            return;
        }
    }

    printf("O número decimal correspondente é: %d\n", decimal);
}

// Função para converter hexadecimal para octal
void hexadecimalParaOctal(const char *hex)
{
    unsigned long decimal = hexadecimalParaDecimal(hex);
    printf("Resultado em octal: %lo\n", decimal);
}

// Função para converter decimal para hexadecimal
void decimalParaHexadecimal()
{
    int numdec;
    printf("Digite um número decimal: ");
    scanf("%d", &numdec);
    printf("O número hexadecimal equivalente é: %X\n", numdec);
}

// Função para converter decimal para octal
void decimalParaOctal()
{
    int numdec;
    printf("Digite um número decimal: ");
    scanf("%d", &numdec);
    printf("O número octal equivalente é: %o\n", numdec);
}

// Função para converter binário para hexadecimal
void binarioParaHexadecimal()
{
    char binario[MAX_BIN];
    printf("Digite um número binário: ");
    scanf("%64s", binario);

    int comprimento = strlen(binario);
    unsigned long decimal = 0;
    int i;
    for (i = 0; i < comprimento; i++)
    {
        char c = binario[comprimento - i - 1];
        if (c == '1')
            decimal += (1UL << i);
        else if (c != '0')
        {
            printf("Caractere inválido na entrada!\n");
            return;
        }
    }
    printf("O número hexadecimal correspondente é: %lX\n", decimal);
}

// Função para converter binário para octal
void binarioParaOctal()
{
    char binario[MAX_BIN];
    printf("Digite um número binário: ");
    scanf("%64s", binario);

    int comprimento = strlen(binario);
    unsigned long decimal = 0;
    int i;
    for (i = 0; i < comprimento; i++)
    {
        char c = binario[comprimento - i - 1];
        if (c == '1')
            decimal += (1UL << i);
        else if (c != '0')
        {
            printf("Caractere inválido na entrada!\n");
            return;
        }
    }
    printf("O número octal correspondente é: %lo\n", decimal);
}

// Função para converter octal para decimal
void octalParaDecimal()
{
    char octal[32];
    printf("Digite um número octal: ");
    scanf("%31s", octal);

    char *endptr;
    unsigned long decimal = strtoul(octal, &endptr, 8);
    if (*endptr != '\0')
    {
        printf("Caractere inválido na entrada!\n");
        return;
    }
    printf("O número decimal correspondente é: %lu\n", decimal);
}

// Função para converter octal para binário
void octalParaBinario()
{
    char octal[32];
    printf("Digite um número octal: ");
    scanf("%31s", octal);

    char *endptr;
    unsigned long decimal = strtoul(octal, &endptr, 8);
    if (*endptr != '\0')
    {
        printf("Caractere inválido na entrada!\n");
        return;
    }
    printf("O número binário correspondente é: ");
    if (decimal == 0)
        printf("0");
    else
    {
        int bits[64], i = 0, j;
        while (decimal > 0)
        {
            bits[i++] = decimal % 2;
            decimal /= 2;
        }
        for (j = i - 1; j >= 0; j--)
            printf("%d", bits[j]);
    }
    printf("\n");
}

// Função para converter octal para hexadecimal
void octalParaHexadecimal()
{
    char octal[32];
    printf("Digite um número octal: ");
    scanf("%31s", octal);

    char *endptr;
    unsigned long decimal = strtoul(octal, &endptr, 8);
    if (*endptr != '\0')
    {
        printf("Caractere inválido na entrada!\n");
        return;
    }
    printf("O número hexadecimal correspondente é: %lX\n", decimal);
}

// Função para validar string binária
int validarBinario(const char *bin)
{
    int i;
    for (i = 0; bin[i] != '\0'; i++)
    {
        if (bin[i] != '0' && bin[i] != '1')
            return 0;
    }
    return 1;
}

// Função para validar string octal
int validarOctal(const char *oct)
{
    int i;
    for (i = 0; oct[i] != '\0'; i++)
    {
        if (oct[i] < '0' || oct[i] > '7')
            return 0;
    }
    return 1;
}

// Função para validar string decimal
int validarDecimal(const char *dec)
{
    int i;
    for (i = 0; dec[i] != '\0'; i++)
    {
        if (!isdigit(dec[i]))
            return 0;
    }
    return 1;
}

// Função para converter string de qualquer base para decimal
unsigned long stringParaDecimal(const char *entrada, int base)
{
    char *endptr;
    unsigned long decimal = strtoul(entrada, &endptr, base);
    if (*endptr != '\0')
        return (unsigned long)-1;
    return decimal;
}

// Função para imprimir número em qualquer base
void imprimirEmBase(unsigned long decimal, int base)
{
    char buffer[65];
    char *digitos = "0123456789ABCDEF";
    int i = 0;

    if (base < 2 || base > 16)
    {
        printf("Base de saída não suportada.\n");
        return;
    }

    if (decimal == 0)
    {
        printf("\033[0;32m0\033[0m\n");
        return;
    }

    while (decimal > 0)
    {
        buffer[i++] = digitos[decimal % base];
        decimal /= base;
    }
    buffer[i] = '\0';

    // Imprimir reverso
    printf("Resultado: ");
    if (suporte_cores)
    {
        // printf("\n");
        /* FORMATO:
             \033[38;2;<r>;<g>;<b>m     #Select RGB foreground color
             \033[48;2;<r>;<g>;<b>m     #Select RGB background color
           REFERENCIA: https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
        */
        // printf("\033[38;2;0;255;0m"); // texto em verde
        printf("\033[38;2;100;255;100m"); // texto em verde claro
        // printf("\033[38;2;0;255;255m"); // texto em ciano
        // printf("\033[48;2;0;255;255m"); // fundo em ciano
        printf("\033[4m"); // texto sublinhado
        printf("\033[1m"); // texto em negrito
        // printf("hello");
        // printf("\033[0m\n"); // resetar formatação
        // printf("\n");

        // printf("\033[1;92m"); // verde claro (bold green)
    }
    int j;
    for (j = i - 1; j >= 0; j--)
        printf("%c", buffer[j]);
    if (suporte_cores)
    {
        printf("\033[0m"); // resetar formatação
    }
    printf("\n");
}

void exibirAjuda() {
    printf("\n");
    printf("./conversor - Conversor de bases numéricas\n");
    printf("\n");
    printf("Uso:\n");
    printf("  ./conversor -h | --help                          # exibe esta mensagem de ajuda\n");
    printf("  ./conversor                                      # inicia o programa em modo de REPL\n");
    printf("  ./conversor <baseEntrada> <baseSaida> <numero>   # converte <numero> da <baseEntrada> para <baseSaida>\n");
    printf("\n");
    printf("Bases possíveis (pode usar número ou letra):\n");
    printf("  1 ou b ou B = Binário\n");
    printf("  2 ou o ou O = Octal\n");
    printf("  3 ou d ou D = Decimal\n");
    printf("  4 ou h ou H = Hexadecimal\n");
    printf("\n");
    printf("Exemplo:\n");
    printf("  conversor 4 2 1A3F   # converte 1A3F de hexadecimal para octal\n");
    printf("  conversor h o 1A3F   # converte 1A3F de hexadecimal para octal\n");
    printf("Se nenhum argumento for passado, o modo interativo será iniciado.\n");
    printf("\n");
}

void exibirMenuBasesEntrada()
{
    printf("\nEscolha o sistema de base de entrada:\n");
    printf("1 - Binário\n");
    printf("2 - Octal\n");
    printf("3 - Decimal\n");
    printf("4 - Hexadecimal\n");
    printf("0 - Sair\n");
    printf("Opção: ");
}

void exibirMenuBasesSaida()
{
    printf("\nEscolha o sistema de base de saída:\n");
    printf("1 - Binário\n");
    printf("2 - Octal\n");
    printf("3 - Decimal\n");
    printf("4 - Hexadecimal\n");
    printf("0 - Sair\n");
    printf("Opção: ");
}

// Função auxiliar para interpretar base a partir de string (número ou letra)
int interpretarBase(const char *arg) {
    if (strlen(arg) == 1) {
        switch (arg[0]) {
            case '1': case 'b': case 'B': return 1;
            case '2': case 'o': case 'O': return 2;
            case '3': case 'd': case 'D': return 3;
            case '4': case 'h': case 'H': return 4;
        }
    }
    // Se não for válido, retorna -1
    return -1;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "pt_br.UTF-8");

    // Verifica se o usuário pediu ajuda
    if ((argc == 2) && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        exibirAjuda();
        return 0;
    }

    // Se houver argumentos mas não for modo help nem modo conversão, mostra erro e ajuda
    if (argc > 1 && argc != 4) {
        exibirAjuda();
        printf("\nERRO: Modo de uso ou argumentos inválido!\n");
        return 1;
    }

    // // Verifica se o terminal suporta cores ANSI
    // if (!isatty(fileno(stdout)))
    // {
    //     printf("Aviso: O terminal não suporta cores ANSI. A saída será sem formatação de cor.\n");
    // }

#ifdef _WIN32
    // No Windows, ANSI escape codes podem não ser suportados por padrão
    // Tenta habilitar suporte a ANSI no Windows 10+
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    if (hOut == INVALID_HANDLE_VALUE || !GetConsoleMode(hOut, &dwMode) ||
        !SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING))
    {
        printf("Aviso: O terminal não suporta cores ANSI. A saída será sem formatação de cor.\n");
        suporte_cores = 0;
    }
#else
    if (!isatty(fileno(stdout)))
    {
        printf("Aviso: O terminal não suporta cores ANSI. A saída será sem formatação de cor.\n");
        suporte_cores = 0;
    }
#endif

    int baseEntrada, baseSaida;
    char entrada[100];

    // --- CLI MODE ---
    if (argc == 4) {
        int baseEntrada = interpretarBase(argv[1]);
        int baseSaida = interpretarBase(argv[2]);
        strncpy(entrada, argv[3], sizeof(entrada)-1);
        entrada[sizeof(entrada)-1] = '\0';

        if (baseEntrada < 1 || baseEntrada > 4 || baseSaida < 1 || baseSaida > 4) {
            printf("Base de entrada/saída inválida! Use 1/b=Binário, 2/o=Octal, 3/d=Decimal, 4/h=Hexadecimal\n");
            return 1;
        }

        // Validação da entrada
        int valido = 0;
        switch (baseEntrada)
        {
        case 1:
            valido = validarBinario(entrada);
            break;
        case 2:
            valido = validarOctal(entrada);
            break;
        case 3:
            valido = validarDecimal(entrada);
            break;
        case 4:
            valido = validarHexadecimal(entrada);
            break;
        }
        if (!valido)
        {
            printf("Número inválido para a base escolhida!\n");
            return 1;
        }

        // Conversão para decimal
        int baseConv[] = {2, 8, 10, 16};
        unsigned long decimal = stringParaDecimal(entrada, baseConv[baseEntrada - 1]);
        if (decimal == (unsigned long)-1)
        {
            printf("Erro ao converter o número!\n");
            return 1;
        }

        // Imprimir apenas o número do resultado em verde
        imprimirEmBase(decimal, baseConv[baseSaida - 1]);
        return 0;
    }

    // --- MODO INTERATIVO ---
    while (1)
    {
        exibirMenuBasesEntrada();
        char baseEntradaStr[10];
        if (scanf("%9s", baseEntradaStr) == EOF) {
            printf("\nEncerrando o programa (EOF).\n");
            break;
        }
        baseEntrada = interpretarBase(baseEntradaStr);

        if (baseEntradaStr[0] == '0' && baseEntradaStr[1] == '\0') {
            printf("Encerrando o programa.\n");
            break;
        }

        if (baseEntrada < 1 || baseEntrada > 4) {
            printf("Base de entrada inválida! Use 1/b=Binário, 2/o=Octal, 3/d=Decimal, 4/h=Hexadecimal ou 0 para sair.\n");
            continue;
        }

        exibirMenuBasesSaida();
        char baseSaidaStr[10];
        if (scanf("%9s", baseSaidaStr) == EOF) {
            printf("\nEncerrando o programa (EOF).\n");
            break;
        }
        baseSaida = interpretarBase(baseSaidaStr);

        if (baseSaidaStr[0] == '0' && baseSaidaStr[1] == '\0') {
            printf("Encerrando o programa.\n");
            break;
        }

        if (baseSaida < 1 || baseSaida > 4) {
            printf("Base de saída inválida! Use 1/b=Binário, 2/o=Octal, 3/d=Decimal, 4/h=Hexadecimal ou 0 para sair.\n");
            continue;
        }

        printf("\nDigite o número na base de entrada: ");
        if (scanf("%s", entrada) == EOF) {
            printf("\nEncerrando o programa (EOF).\n");
            break;
        }

        // Validação da entrada
        int valido = 0;
        switch (baseEntrada)
        {
        case 1:
            valido = validarBinario(entrada);
            break;
        case 2:
            valido = validarOctal(entrada);
            break;
        case 3:
            valido = validarDecimal(entrada);
            break;
        case 4:
            valido = validarHexadecimal(entrada);
            break;
        }
        if (!valido)
        {
            printf("Número inválido para a base escolhida!\n");
            continue;
        }

        // Conversão para decimal
        int baseConv[] = {2, 8, 10, 16};
        unsigned long decimal = stringParaDecimal(entrada, baseConv[baseEntrada - 1]);
        if (decimal == (unsigned long)-1)
        {
            printf("Erro ao converter o número!\n");
            continue;
        }

        // Imprimir apenas o número do resultado em verde
        imprimirEmBase(decimal, baseConv[baseSaida - 1]);
    }

    return 0;
}
