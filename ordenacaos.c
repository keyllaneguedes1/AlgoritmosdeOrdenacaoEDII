#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

int comparacoes = 0;
int trocas = 0;

void imprimirPessoas(Pessoa *pessoas, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %d anos\n", pessoas[i].nome, pessoas[i].idade);
    }
    printf("\n");
}

void copiarArray(Pessoa *dest, Pessoa *orig, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = orig[i];
    }
}

void bubbleSort(Pessoa *pessoas, int n) {
    comparacoes = trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                Pessoa temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
                trocas++;
            }
        }
    }
}

void insertionSort(Pessoa *pessoas, int n) {
    comparacoes = trocas = 0;
    for (int i = 1; i < n; i++) {
        Pessoa chave = pessoas[i];
        int j = i - 1;
        while (j >= 0 && strcmp(pessoas[j].nome, chave.nome) > 0) {
            comparacoes++;
            pessoas[j + 1] = pessoas[j];
            j--;
            trocas++;
        }
        comparacoes++;
        pessoas[j + 1] = chave;
    }
}

void merge(Pessoa *pessoas, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Pessoa *L = malloc(n1 * sizeof(Pessoa));
    Pessoa *R = malloc(n2 * sizeof(Pessoa));

    for (int i = 0; i < n1; i++)
        L[i] = pessoas[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = pessoas[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        comparacoes++;
        if (strcmp(L[i].nome, R[j].nome) <= 0) {
            pessoas[k++] = L[i++];
        } else {
            pessoas[k++] = R[j++];
            trocas++;
        }
    }

    while (i < n1) pessoas[k++] = L[i++];
    while (j < n2) pessoas[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(Pessoa *pessoas, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(pessoas, l, m);
        mergeSort(pessoas, m + 1, r);
        merge(pessoas, l, m, r);
    }
}

void mergeSortWrapper(Pessoa *pessoas, int n) {
    comparacoes = trocas = 0;
    mergeSort(pessoas, 0, n - 1);
}

void testarOrdenacao(void (*sort)(Pessoa*, int), Pessoa *original, int n, const char *nomeAlgoritmo) {
    Pessoa copia[100];
    long long tempoTotal = 0;
    int totalComparacoes = 0;
    int totalTrocas = 0;

    for (int i = 0; i < 5; i++) {
        copiarArray(copia, original, n);
        clock_t inicio = clock();

        comparacoes = trocas = 0;
        sort(copia, n);

        clock_t fim = clock();
        tempoTotal += (fim - inicio);
        totalComparacoes += comparacoes;
        totalTrocas += trocas;
    }

    printf("=== %s ===\n", nomeAlgoritmo);
    printf("Comparações médias: %d\n", totalComparacoes / 5);
    printf("Trocas médias: %d\n", totalTrocas / 5);
    printf("Tempo médio: %.4f ms\n", (tempoTotal / 5.0) * 1000 / CLOCKS_PER_SEC);

    copiarArray(copia, original, n);
    sort(copia, n);
    printf("Lista ordenada por %s:\n", nomeAlgoritmo);
    imprimirPessoas(copia, n);
}

int main() {
    Pessoa pessoas[20] = {
        {"Joao", 25}, {"Ana", 22}, {"Carlos", 30}, {"Beatriz", 19}, {"Fernando", 40},
        {"Lucas", 27}, {"Mariana", 23}, {"Daniel", 33}, {"Patricia", 29}, {"Vinicius", 26},
        {"Juliana", 21}, {"Rafael", 35}, {"Camila", 24}, {"Bruno", 28}, {"Larissa", 20},
        {"Thiago", 31}, {"Tatiane", 32}, {"Igor", 18}, {"Eduarda", 34}, {"Fábio", 36}
    };

    int n = 20;

    printf("--- Lista Original ---\n");
    imprimirPessoas(pessoas, n);

    testarOrdenacao(bubbleSort, pessoas, n, "Bubble Sort");
    testarOrdenacao(insertionSort, pessoas, n, "Insertion Sort");
    testarOrdenacao(mergeSortWrapper, pessoas, n, "Merge Sort");

    return 0;
}
