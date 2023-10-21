#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertionSort(int *vet, int n){
    int i, j, aux;
    int comparisons = 0;
    int swaps = 0;
    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i;
        while(j > 0 && aux < vet[j-1]){
            vet[j] = vet[j-1];
            j--;
            comparisons++;
        }
        vet[j] = aux;
        swaps++;
    }
   printf("Comparisons: %d\n", comparisons);
   printf("Swaps: %d\n", swaps);
}



int particiona(int *vet, int inicio, int fim, int *comparisons, int *swaps){
    int esq, dir, pivo;
    esq = inicio;
    dir = fim;
    pivo = vet[inicio];
    while(esq < dir){
        while(esq <= fim && vet[esq] <= pivo){
            esq++;
            (*comparisons)++;
        }
        while(dir >= inicio && vet[dir] > pivo){
            dir--;
            (*comparisons)++;
        }
        if(esq < dir){
            swap(&vet[esq], &vet[dir]);
            (*swaps)++;
        }
    }
    swap(&vet[inicio], &vet[dir]);
    (*swaps)++;
    return dir;
}

void quickSort(int *vet, int inicio, int fim, int *comparisons, int *swaps){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vet, inicio, fim, comparisons, swaps);
        quickSort(vet, inicio, pivo-1, comparisons, swaps);
        quickSort(vet, pivo+1, fim, comparisons, swaps);
    }
}

float media(int *vet)
{
    int soma=0, i;
    for(i = 0; i < 10; i++)
        soma += vet[i];
    return (float)soma/10;
}

//diferenca entre o maior e menor tempo
int difere(int *vet)
{
  int maior, menor, resultado;
    maior= vet[0];
    menor= vet[0];
    for(int i=1; i<10; i++){
        if(vet[i]>maior){
            maior = vet[i];
        }
    }
     for(int i=1; i<10; i++){
        if(vet[i]<menor){
            menor = vet[i];
        }
    }
    resultado = maior - menor;
    return resultado;
}



void insertionSort_GPT(int *vet, int n) {
    int i, j;
    int comparisons = 0;
    int swaps = 0;

    for (i = 1; i < n; i++) {
        int current = vet[i];
        for (j = i - 1; j >= 0 && current < vet[j]; j--) {
            vet[j + 1] = vet[j];
            comparisons++;
        }
        if (j != i - 1) {
            vet[j + 1] = current;
            swaps++;
        }
    }

    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);
}


int medianaDeTres(int *vet, int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    if (vet[inicio] > vet[meio])
        swap(&vet[inicio], &vet[meio]);
    if (vet[inicio] > vet[fim])
        swap(&vet[inicio], &vet[fim]);
    if (vet[meio] > vet[fim])
        swap(&vet[meio], &vet[fim]);
    swap(&vet[meio], &vet[fim - 1]);
    return vet[fim - 1];
}

int particiona_GPT(int *vet, int inicio, int fim, int *comparisons, int *swaps){
    int esq, dir, pivo;
    esq = inicio;
    dir = fim - 1;
    pivo = medianaDeTres(vet, inicio, fim);
    while(esq < dir){
        while(vet[++esq] < pivo){
            (*comparisons)++;
        }
        while(vet[--dir] > pivo){
            (*comparisons)++;
        }
        if(esq < dir){
            swap(&vet[esq], &vet[dir]);
            (*swaps)++;
        }
    }
    swap(&vet[esq], &vet[fim - 1]);
    (*swaps)++;
    return esq;
}

void quickSort_GPT(int *vet, int inicio, int fim, int *comparisons, int *swaps){
    if(fim - inicio + 1 >= 3){
        int pivo = particiona_GPT(vet, inicio, fim, comparisons, swaps);
        quickSort(vet, inicio, pivo-1, comparisons, swaps);
        quickSort(vet, pivo+1, fim, comparisons, swaps);
    } else {
        // inserção direta quando a partição tem tamanho 2
        if (vet[inicio] > vet[fim]) {
            swap(&vet[inicio], &vet[fim]);
            (*swaps)++;
        }
        (*comparisons)++;
    }
}



int main()
{
 
    int trocas[10], comp[10];
    clock_t inicio, fim;
    unsigned int duracao;
    // tamanho do seu algoritmo
    int a=10000;
    int *vet = (int *)malloc(sizeof(int) * a);
    int tempos[10];
    srand(time(NULL));

    for(int w = 0; w < 10; w++) {
        trocas[w] = 0; comp[w] = 0;
        inicio = clock();
         for(int i=0; i<a; i++){
             vet[i]= rand()%a;
        }
        //algoritmos ordenacao:
      //  insertionSort(vet,a);
       // insertionSort_GPT(vet,a);
       // quickSort(vet, 0, a-1, &comp[w],&trocas[w]);
       // quickSort_GPT(vet, 0, a-1, &comp[w],&trocas[w]);
        fim = clock();

        //caso deseje printar o vetor ordenado
        /*for(int i = 0; i < a; i++){
          printf("%d ", vet[i]);
        }
        printf("\n===============================================\n");
        */
        duracao = (fim - inicio)*1000000/CLOCKS_PER_SEC;
        tempos[w] = duracao;
    }
    for(int i = 0; i < 10; i++){
        printf("\nExecutado  em %d  microsegundos.", tempos[i]);
        printf("\nTrocas: %d (%i)\nComparacoes: %d  (%i)", trocas[i], i+1, comp[i], i+1);
    }

    printf("\n\nMedia dos tempos: %.2f microsegundos\n", media(tempos));
    printf("\nA diferenca entre os tempos e: %d\n\n", difere(tempos));

    return 0;
}



