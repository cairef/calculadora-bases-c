#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>

#define MAX_HEX 100
#define MAX_BIN 65

// Função para converter caractere hexadecimal para decimal
int caractereHexParaDecimal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    else if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    else return -1;
}

// Função para validar string hexadecimal
int validarHexadecimal(const char *hex) {
    int i;
    for (i = 0; hex[i] != '\0'; i++) {
        if (!isxdigit(hex[i])) return 0;
    }
    return 1;
}

// Função para converter hexadecimal para decimal
unsigned long hexadecimalParaDecimal(const char *hex) {
    return strtoul(hex, NULL, 16);
}

// Função para converter hexadecimal para binário
void hexadecimalParaBinario(const char *hex) {
    printf("Resultado em binário: ");
    int i;
    for (i = 0; hex[i] != '\0'; i++) {
        int decimal = caractereHexParaDecimal(hex[i]);
        if (decimal == -1) {
            printf("\nCaractere inválido: %c\n", hex[i]);
            return;
        }
        int j;
        for (j = 3; j >= 0; j--) {
            printf("%d", (decimal >> j) & 1);
        }
    }
    printf("\n");
}

// Função para converter decimal para binário
void decimalParaBinario() {
    int numdec;
    int restoBin[64];
    int i = 0;

    printf("Digite um número decimal: ");
    scanf("%d", &numdec);

    if (numdec == 0) {
        printf("O número binário equivalente é: 0\n");
        return;
    }

    while (numdec > 0) {
        restoBin[i++] = numdec % 2;
        numdec /= 2;
    }

    printf("O número binário equivalente é: ");
    int j;
    for (j = i - 1; j >= 0; j--) {
        printf("%d", restoBin[j]);
    }
    printf("\n");
}

// Função para converter binário para decimal
void binarioParaDecimal() {
    char binario[MAX_BIN];
    int decimal = 0;

    printf("Digite um número binário: ");
    scanf("%64s", binario);

    int comprimento = strlen(binario);

    int i;
    for (i = 0; i < comprimento; i++) {
        char c = binario[comprimento - i - 1];
        if (c == '1') {
            decimal += (1 << i);
        } else if (c != '0') {
            printf("Caractere inválido na entrada!\n");
            return;
        }
    }

    printf("O número decimal correspondente é: %d\n", decimal);
}

// Função para exibir o menu principal
void exibirMenu() {
    printf("\n--- Conversor de Números ---\n");
    printf("1 - Hexadecimal para Binário\n");
    printf("2 - Hexadecimal para Decimal\n");
    printf("3 - Decimal para Binário\n");
    printf("4 - Binário para Decimal\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    setlocale(LC_ALL, "");
    char opcao;
    char hexInput[MAX_HEX];

    do {
        exibirMenu();
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
            case '2':
                printf("Digite o número hexadecimal: ");
                scanf("%s", hexInput);

                if (!validarHexadecimal(hexInput)) {
                    printf("Entrada inválida! Use apenas dígitos hexadecimais (0-9, A-F).\n");
                    break;
                }

                if (opcao == '1') {
                    hexadecimalParaBinario(hexInput);
                } else {
                    unsigned long decimal = hexadecimalParaDecimal(hexInput);
                    printf("Resultado em decimal: %lu\n", decimal);
                }
                break;

            case '3':
                decimalParaBinario();
                break;

            case '4':
                binarioParaDecimal();
                break;

            case '0':
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != '0');

    return 0;
}
