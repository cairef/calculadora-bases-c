![](https://img.shields.io/badge/Markdown-000000?style=flat&logo=markdown&logoColor=white) ![](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=black) &ensp; ![](https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white&link=https%3A%2F%2Fgithub.com%2Fcairef%2Fcalculadora-bases-c) &ensp; ![](https://img.shields.io/github/v/release/cairef/calculadora-bases-c?link=https%3A%2F%2Fgithub.com%2Fcairef%2Fcalculadora-bases-c%2Freleases%2Flatest)

# 🔢 Conversor de Números em C

Um conversor de bases numéricas desenvolvido em linguagem C, capaz de converter números entre base

- [🔢 Conversor de Números em C](#-conversor-de-números-em-c)
  - [✨ Funcionalidades](#-funcionalidades)
  - [📷 Demonstrações](#-demonstrações)
  - [🧪 Requisitos](#-requisitos)
  - [🚀 Como Usar](#-como-usar)
    - [1. A. Download](#1-a-download)
    - [1. B. Compilação](#1-b-compilação)
    - [2. Execução](#2-execução)
  - [📋 Exemplo de Uso](#-exemplo-de-uso)
    - [REPL (Read Evaluate Print Loop)](#repl-read-evaluate-print-loop)
    - [CLI (Command-Line Interface)](#cli-command-line-interface)
  - [🛠️ Estrutura do Projeto](#️-estrutura-do-projeto)
  - [🧠 Aprendizados](#-aprendizados)
  - [👥 Equipe (ordem alfabética)](#-equipe-ordem-alfabética)
  - [📄 Licença](#-licença)

## ✨ Funcionalidades

- Conversão entre bases:
  - **binário**: representação do sistema númerico de máquinas
  - **octal**: representação de 1 byte
  - **decimal**: sistema padrão humano
  - **hexadecimal**: representação de 2 bytes, ou a maior base númerica múltipla de 8 (octal), menor do que 36 (10 + 26, ou o sistema decimal + o sistema alfabético insensível a maiúsulos e minúsculos)
- Validação automática da entrada conforme a base escolhida
- Interface interativa por menus no terminal (REPL) e comandos por argumentos (CLI)
- Resultado destacado em verde (se o terminal suportar ANSI colors)
- Suporte a UTF-8 para acentuação e caracteres especiais nas mensagens. (locale = pt_br.UTF-8)

## 📷 Demonstrações

### demo &ensp; <sub>|&ensp;[ demo4 em imagem ](demo/demo4.jpg)&ensp;|&ensp;[demo4 no terminal virtual](demo/demo4.gif)&ensp;|&ensp;[mais demos](demo/)&ensp;|</sub>
  ![](demo/demo-b2.gif)

## 🧪 Requisitos

- Terminal com suporte a UTF-8
- (Opcional) Compilador C (GCC, MinGW, Clang, etc.)
- (Opcional) Suporte a cores ANSI para destaque do resultado

## 🚀 Como Usar

### 1. A. Download

- Você pode baixar os binários em https://github.com/cairef/calculadora-bases-c/releases/tag/release

### 1. B. Compilação

Certifique-se de ter um compilador C instalado (GCC, MinGW, Clang, etc).

No **Linux/macOS**:

```bash
gcc conversor.c -o conversor
```

No **Windows** (usando MinGW):

```bash
gcc conversor.c -o conversor.exe
```

### 2. Execução

No **Linux/macOS**:

```bash
./conversor
./conversor --help
./conversor <baseDeEntrada> <baseDeSaida> <entrada>
```

No **Windows**:

```bash
conversor.exe
conversor.exe --help
conversor.exe <baseDeEntrada> <baseDeSaida> <entrada>
```

## 📋 Exemplo de Uso

### REPL (Read Evaluate Print Loop)

```
Escolha o sistema de base de entrada:

1 - Binário
2 - Octal
3 - Decimal
4 - Hexadecimal
0 - Sair
Opção: 4

Escolha o sistema de base de saída:

1 - Binário
2 - Octal
3 - Decimal
4 - Hexadecimal
0 - Sair
Opção: 1

Digite o número na base de entrada: 1A3F
Resultado: 1101000111111
```
> O resultado será exibido em verde, se o terminal suportar cores ANSI.

### CLI (Command-Line Interface)

```bash
./conversor -h
./conversor --help
./conversor 1 3 101
./conversor b d 101
./conversor d b 6
```

## 🛠️ Estrutura do Projeto

- `demo/*` — arquivos de demonstração
- `conversor` — binário para Linux (ELF x86-64)
- `conversor.exe` — binário para Windows (Portable x86-64)
- `conversor.c` — Código-fonte principal do conversor
- `README.md` — Este arquivo de documentação

## 🧠 Aprendizados

Durante o desenvolvimento, a equipe praticou:

- Leitura e validação de strings em C
- Conversão entre diferentes bases numéricas
- Manipulação de arrays e laços
- Uso de `<locale.h>` para suporte a caracteres especiais
- Boas práticas de programação estruturada em C
- Detecção e uso de cores ANSI no terminal

## 👥 Equipe (ordem alfabética)

- Adão
- Cairé (https://github.com/cairef)
- Gustavo Sanches
- Jane
- Lucas (https://github.com/Ramos-jft)

## 📄 Licença

Este projeto é de uso acadêmico e livre para fins educacionais.

