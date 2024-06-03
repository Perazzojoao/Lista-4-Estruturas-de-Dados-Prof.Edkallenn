/*
** Função: Pilha de números reais.
** Autor: João Victor Barbosa Perazzo
** Data: 02/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_SIZE 100

typedef struct {
    float itens[MAX_SIZE];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void push(Pilha *p, float item);
float pop(Pilha *p);
void exibirPilha(Pilha *p);

int main() {
    setlocale(LC_ALL, "Portugese");
    
    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao;
    float elemento;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir elemento (push)\n:");
        printf("2. Retirar elemento (pop)\n");
        printf("3. Exibir pilha\n");
        printf("4. Verificar se a pilha está vazia\n");
        printf("5. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número real a ser inserido na pilha: ");
                scanf("%f", &elemento);
                push(&pilha, elemento);
                exibirPilha(&pilha);
                break;
            case 2:
                elemento = pop(&pilha);
                if (elemento != -1)
                    printf("Elemento removido: %.2f\n", elemento);
                exibirPilha(&pilha);
                break;
            case 3:
                exibirPilha(&pilha);
                break;
            case 4:
                if (pilhaVazia(&pilha))
                    printf("A pilha está vazia.\n");
                else
                    printf("A pilha n�o está vazia.\n");
                break;
            case 5:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida. Por favor, escolha novamente.\n");
        }
    }

    return 0;
}

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX_SIZE - 1;
}

void push(Pilha *p, float item) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia.\n");
        return;
    }
    p->itens[++(p->topo)] = item;
}

float pop(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia.\n");
        return -1; // Valor arbitr�rio para indicar erro
    }
    return p->itens[(p->topo)--];
}

void exibirPilha(Pilha *p) {
	int i;
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha:");
    for ( i = 0; i <= p->topo; i++) {
        printf(" %.2f", p->itens[i]);
    }
    printf("\n");
}



