# ALgoritmos_LABAED

Projeto da cadeira **Laboratório de Algoritmos e Estruturas de Dados (LABAED)**, desenvolvido em linguagem C.

## 📋 Sobre o Projeto

O sistema implementa dois algoritmos clássicos de ordenação e os compara com versões aprimoradas pelo **ChatGPT**, medindo e exibindo métricas de desempenho como número de comparações, trocas e tempo de execução.

## 🔀 Algoritmos Implementados

| Algoritmo | Versão Original | Versão Melhorada (ChatGPT) |
|---|---|---|
| Insertion Sort | `insertionSort` | `insertionSort_GPT` |
| Quick Sort | `quickSort` | `quickSort_GPT` (com mediana de três) |

### Destaques das melhorias
- **Insertion Sort GPT**: usa índice direto em vez de variável auxiliar de deslocamento, evitando comparações redundantes.
- **Quick Sort GPT**: utiliza a estratégia da **mediana de três** (`medianaDeTres`) para a escolha do pivô, reduzindo o pior caso e melhorando o desempenho médio.

## 📊 Métricas Coletadas

Para cada uma das **10 execuções** realizadas, o programa coleta:
- ⏱️ Tempo de execução (em microssegundos)
- 🔁 Número de trocas (*swaps*)
- 🔍 Número de comparações

Ao final, são exibidos:
- Média dos tempos de execução
- Diferença entre o maior e o menor tempo

## 🚀 Como Compilar e Executar

### Pré-requisitos
- Compilador GCC instalado
- Sistema operacional Linux, macOS ou Windows (com MinGW)

### Compilação

```bash
gcc algorimtos.c -o algoritmos -lm
```

### Execução

```bash
./algoritmos
```

### Selecionar o algoritmo

Dentro do arquivo `algorimtos.c`, no bloco `main()`, descomente a linha correspondente ao algoritmo que deseja testar:

```c
// Descomente apenas UMA das linhas abaixo:
// insertionSort(vet, a);
// insertionSort_GPT(vet, a);
// quickSort(vet, 0, a-1, &comp[w], &trocas[w]);
// quickSort_GPT(vet, 0, a-1, &comp[w], &trocas[w]);
```

O tamanho do vetor pode ser ajustado alterando o valor da variável `a` (padrão: `10000`):

```c
int a = 10000;
```

## 📁 Estrutura do Projeto

```
ALgoritmos_LABAED/
├── algorimtos.c   # Código-fonte principal com todos os algoritmos
└── README.md      # Documentação do projeto
```

## 📝 Relatório

O relatório completo com a análise comparativa dos algoritmos está disponível no link abaixo:

🔗 [Relatório no Google Docs](https://docs.google.com/document/d/1Gow5sR-P6z-TNItUYVTAyramQg-nbkLA/edit?usp=drivesdk&ouid=105524381943492740473&rtpof=true&sd=true)

## 🛠️ Tecnologias Utilizadas

- Linguagem **C**
- Bibliotecas padrão: `stdio.h`, `stdlib.h`, `math.h`, `time.h`
