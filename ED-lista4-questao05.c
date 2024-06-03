/*
** Função: Gerenciador de pilha de processos.
** Autor: João Victor Barbosa Perazzo
** Data: 02/06/2024
** Observações:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_DESCRICAO 100
#define MAX_PROCESSOS 100


typedef struct {
    int identificador;
    char descricao[MAX_DESCRICAO];
} Processo;


typedef struct {
    Processo itens[MAX_PROCESSOS];
    int topo;
} PilhaProcessos;

void inicializarPilha(PilhaProcessos *pilha);
int pilhaVazia(PilhaProcessos *pilha);
int pilhaCheia(PilhaProcessos *pilha);
void inserirProcesso(PilhaProcessos *pilha, Processo processo);
void removerProcesso(PilhaProcessos *pilha);

int main() {
    setlocale(LC_ALL, "Portugese");

    PilhaProcessos pilha;
    inicializarPilha(&pilha);

    int escolha;
    Processo processo;

    printf("Bem-vindo ao gerenciador de pilha de processos.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Incluir processo\n");
        printf("2. Retirar processo\n");
        printf("3. Encerrar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o identificador do processo: ");
                scanf("%d", &processo.identificador);
                printf("Digite a descri��o do processo: ");
                scanf(" %[^\n]s", processo.descricao);
                inserirProcesso(&pilha, processo);
                break;
            case 2:
                removerProcesso(&pilha);
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (escolha != 3);


    printf("Esvaziando a pilha antes de encerrar o programa...\n");
    while (!pilhaVazia(&pilha)) {
        removerProcesso(&pilha);
    }

    return 0;
}


void inicializarPilha(PilhaProcessos *pilha) {
    pilha->topo = -1;
}


int pilhaVazia(PilhaProcessos *pilha) {
    return pilha->topo == -1;
}


int pilhaCheia(PilhaProcessos *pilha) {
    return pilha->topo == MAX_PROCESSOS - 1;
}


void inserirProcesso(PilhaProcessos *pilha, Processo processo) {
    if (pilhaCheia(pilha)) {
        printf("Erro: Pilha cheia.\n");
        return;
    }
    pilha->itens[++(pilha->topo)] = processo;
    printf("Processo #%d - \"%s\" inserido na pilha.\n", processo.identificador, processo.descricao);
}


void removerProcesso(PilhaProcessos *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }
    Processo removido = pilha->itens[(pilha->topo)--];
    printf("Removido o processo #%d - \"%s\" da pilha.\n", removido.identificador, removido.descricao);
}
