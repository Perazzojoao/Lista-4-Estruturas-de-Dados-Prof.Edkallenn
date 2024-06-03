/*
** Função: Gerenciador de fila de atendimento.
** Autor: João Victor Barbosa Perazzo
** Data: 02/06/2024
** Observações:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char paciente[50];
    struct Node *prox;
} Node;


typedef struct Atendimento {
    Node *inicio;
    Node *fim;
} Atendimento;

void inicializar(Atendimento *fila);
void adicionarPaciente(Atendimento *fila, char paciente[]);
char *proximoPaciente(Atendimento *fila);
int quantidadePacientes(Atendimento *fila);

int main() {
    Atendimento fila;
    inicializar(&fila);

    adicionarPaciente(&fila, "Pedro");
    adicionarPaciente(&fila, "Daniel");
    adicionarPaciente(&fila, "Edkallen");

    printf("Quantidade de pacientes na fila: %d\n", quantidadePacientes(&fila));

    printf("Próximo paciente a ser atendido: %s\n", proximoPaciente(&fila));
    printf("Quantidade de pacientes na fila: %d\n", quantidadePacientes(&fila));

    printf("Próximo paciente a ser atendido: %s\n", proximoPaciente(&fila));
    printf("Quantidade de pacientes na fila: %d\n", quantidadePacientes(&fila));

    printf("Próximo paciente a ser atendido: %s\n", proximoPaciente(&fila));
    printf("Quantidade de pacientes na fila: %d\n", quantidadePacientes(&fila));

    printf("Próximo paciente a ser atendido: %s\n", proximoPaciente(&fila));

    return 0;
}


void inicializar(Atendimento *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}


void adicionarPaciente(Atendimento *fila, char paciente[]) {
    Node *novoNo = (Node *)malloc(sizeof(Node));
    strcpy(novoNo->paciente, paciente);
    novoNo->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }

    printf("Paciente %s adicionado à fila de atendimento.\n", paciente);
}


char *proximoPaciente(Atendimento *fila) {
    if (fila->inicio == NULL) {
        return "Não há pacientes na fila.";
    } else {
        char *proximo = fila->inicio->paciente;
        Node *temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
        return proximo;
    }
}


int quantidadePacientes(Atendimento *fila) {
    int count = 0;
    Node *atual = fila->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}
