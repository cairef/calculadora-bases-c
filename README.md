<object>
  <a href="https://www.markdownguide.org/">
    <img src="https://img.shields.io/badge/Markdown-000000?style=flat&logo=markdown&logoColor=white" alt="Markdown"/>
  </a>
</object>
<object>
  <a href="https://en.wikipedia.org/wiki/C_(programming_language)">
    <img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=black" alt="C"/>
  </a>
</object>
&ensp;
<object>
  <a href="https://github.com/cairef/calculadora-bases-c">
    <img src="https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white" alt="GitHub"/>
  </a>
</object>
&ensp;
<object>
  <a href="https://github.com/cairef/calculadora-bases-c/releases/latest">
    <img src="https://img.shields.io/github/v/release/cairef/calculadora-bases-c" alt="GitHub release"/>
  </a>
</object>
<object>
  <a href="https://github.com/cairef/calculadora-bases-c">
    <img src="https://img.shields.io/github/stars/cairef/calculadora-bases-c" alt="GitHub release"/>
  </a>
</object>
<object>
  <a href="https://github.com/cairef/calculadora-bases-c">
    <img src="https://img.shields.io/github/forks/cairef/calculadora-bases-c" alt="GitHub release"/>
  </a>
</object>

<br/>

# 🔢 Conversor de Números em C

Um conversor de bases numéricas desenvolvido em linguagem C, capaz de converter números entre base

- [🔢 Conversor de Números em C](#-conversor-de-números-em-c)
  - [✨ Funcionalidades](#-funcionalidades)
  - [📷 Demonstrações](#-demonstrações)
  - [🧪 Requisitos](#-requisitos)
  - [🚀 Como Usar](#-como-usar)
    - [1. Preparação](#1-preparação)
    - [2. Execução](#2-execução)
  - [🛠️ Build](#️-build)
  - [📋 Exemplo de Uso](#-exemplo-de-uso)
    - [REPL (Read Evaluate Print Loop)](#repl-read-evaluate-print-loop)
    - [CLI (Command-Line Interface)](#cli-command-line-interface)
  - [🛠️ Estrutura do Projeto](#️-estrutura-do-projeto)
  - [🧠 Aprendizados](#-aprendizados)
  - [👥 Grupo (ordem alfabética)](#-grupo-ordem-alfabética)
  - [🧩 Misc](#-misc)
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

### 1. Preparação

- Você pode baixar os binários em https://github.com/cairef/calculadora-bases-c/releases/tag/release
- Ou siga as instruções em [build](#Build) para compilar com o código-fonte.

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

## 🛠️ Build

1. Certifique-se de ter um compilador C instalado (GCC, MinGW, Clang, etc).

2. Clone o repositório

```bash
git clone https://github.com/cairef/calculadora-bases-c.git
```

3. Compile usando o GCC

- No **Linux/macOS**:

```bash
gcc conversor.c -o conversor
```

- No **Windows** (usando MinGW):

```bash
gcc conversor.c -o conversor.exe
```

4. (Opcional) crie demonstrações

- usando linux, instale o asciinema, termsvg e o agg
- clone o repositório em https://github.com/cairef/term-nema.git
- crie os arquivos .cast usando record.sh [working_directory] e converta usando convert.sh

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

## 👥 Grupo (ordem alfabética)

- Adão
- Cairé (https://github.com/cairef)
- Gustavo Sanches
- Jane
- Lucas (https://github.com/Ramos-jft)

## 🧩 Misc

![](https://imgs.xkcd.com/comics/1_to_10.png)
<br>[https://xkcd.com/953/](https://xkcd.com/953/)

## 📄 Licença

Este projeto é de uso acadêmico e livre para fins educacionais.

