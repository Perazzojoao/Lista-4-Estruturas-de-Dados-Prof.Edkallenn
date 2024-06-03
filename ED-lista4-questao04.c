/*
** Função: Selection Sort.
** Autor: João Victor Barbosa Perazzo
** Data: 02/06/2024
** Observações:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void trocar(int *a, int *b);
void classificacaoPorSelecao(int vetor[], int tamanho);
void exibirVetor(int vetor[], int tamanho);

int main() {
    setlocale(LC_ALL, "Portugese");

    srand(time(NULL)); 
    int i;
    int tamanho = 10;
    int vetor[tamanho];

    for ( i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; 
    }

    printf("Vetor original: ");
    exibirVetor(vetor, tamanho);

    classificacaoPorSelecao(vetor, tamanho);

    printf("Vetor classificado: ");
    exibirVetor(vetor, tamanho);

    return 0;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void classificacaoPorSelecao(int vetor[], int tamanho) {
	int i,j;
    for ( i = 0; i < tamanho - 1; i++) {
        int indice_minimo = i;
        for ( j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indice_minimo]) {
                indice_minimo = j;
            }
        }
        if (indice_minimo != i) {
            trocar(&vetor[i], &vetor[indice_minimo]);
        }
    }
}

void exibirVetor(int vetor[], int tamanho) {
		int i;
    printf("[");
    for ( i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
