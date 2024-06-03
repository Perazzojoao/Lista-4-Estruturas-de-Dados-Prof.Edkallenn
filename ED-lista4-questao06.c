/*
** Função: Gerenciador de lista de compras.
** Autor: João Victor Barbosa Perazzo
** Data: 02/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Item {
    char nome[50];
    int quantidade;
    struct Item *prox;
} Item;

void inserir(Item **lista, char nome[], int quantidade);
void remover(Item **lista, char nome[]);
void consultar(Item *lista, char nome[]);
void mostrarTodos(Item *lista);

int main() {
    setlocale(LC_ALL, "Portugese");

    Item *lista = NULL;
    int opcao, quantidade;
    char nome[50];

    do {
        printf("\n1. Inserir item na lista de compras\n");
        printf("2. Remover item da lista de compras\n");
        printf("3. Consultar item na lista de compras\n");
        printf("4. Mostrar todos os itens da lista de compras\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome do item: ");
                scanf("%s", nome);
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                inserir(&lista, nome, quantidade);
                break;
            case 2:
                printf("Nome do item a ser removido: ");
                scanf("%s", nome);
                remover(&lista, nome);
                break;
            case 3:
                printf("Nome do item a ser consultado: ");
                scanf("%s", nome);
                consultar(lista, nome);
                break;
            case 4:
                mostrarTodos(lista);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    return 0;
}


void inserir(Item **lista, char nome[], int quantidade) {
    Item *novoItem = (Item *)malloc(sizeof(Item));
    strcpy(novoItem->nome, nome);
    novoItem->quantidade = quantidade;
    novoItem->prox = *lista;
    *lista = novoItem;
    printf("%d %s(s) adicionado(s) à lista de compras.\n", quantidade, nome);
}


void remover(Item **lista, char nome[]) {
    Item *atual = *lista;
    Item *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                *lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("%s removido da lista de compras.\n", nome);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("%s não encontrado na lista de compras.\n", nome);
}


void consultar(Item *lista, char nome[]) {
    while (lista != NULL) {
        if (strcmp(lista->nome, nome) == 0) {
            printf("%s: %d\n", lista->nome, lista->quantidade);
            return;
        }
        lista = lista->prox;
    }

    printf("%s não encontrado na lista de compras.\n", nome);
}


void mostrarTodos(Item *lista) {
    if (lista == NULL) {
        printf("Lista de compras vazia.\n");
        return;
    }

    printf("Itens na lista de compras:\n");
    while (lista != NULL) {
        printf("%s: %d\n", lista->nome, lista->quantidade);
        lista = lista->prox;
    }
}
