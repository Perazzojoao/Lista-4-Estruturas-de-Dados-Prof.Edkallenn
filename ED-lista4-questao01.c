/*
** Função: Gerenciar uma biblioteca
** Autor: João Victor Barbosa Perazzo
** Data: 02/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Livro {
    char autor[100];
    char titulo[100];
    char editora[100];
    int ano_edicao;
    struct Livro *proximo;
} Livro;

typedef struct Biblioteca {
    Livro *primeiro;
} Biblioteca;

Biblioteca *criarBiblioteca();
Livro *criarLivro(char autor[], char titulo[], char editora[], int ano_edicao);
Livro *buscar_por_titulo(Biblioteca *biblioteca, char titulo[]);
void inserirOrdenado(Biblioteca *biblioteca, char autor[], char titulo[], char editora[], int ano_edicao);
void remover(Biblioteca *biblioteca, char titulo[]);
void alterar(Biblioteca *biblioteca, char titulo[], char novo_autor[], char nova_editora[], int novo_ano);
void buscarPorAutor(Biblioteca *biblioteca, char autor[]);
void menu();

int main() {
    setlocale(LC_ALL, "Portugese");

    Biblioteca *biblioteca = criarBiblioteca();
    int opcao;
    char autor[100], titulo[100], editora[100];
    int ano_edicao;

    while (1) {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Autor: ");
                scanf("%s", autor);
                printf("Título: ");
                scanf("%s", titulo);
                printf("Editora: ");
                scanf("%s", editora);
                printf("Ano de Edição: ");
                scanf("%d", &ano_edicao);
                inserirOrdenado(biblioteca, autor, titulo, editora, ano_edicao);
                printf("Livro inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite o título do livro a ser removido: ");
                scanf("%s", titulo);
                remover(biblioteca, titulo);
                printf("Livro removido com sucesso!\n");
                break;
            case 3:
                printf("Digite o título do livro a ser alterado: ");
                scanf("%s", titulo);
                printf("Novo autor: ");
                scanf("%s", autor);
                printf("Nova editora: ");
                scanf("%s", editora);
                printf("Novo ano de Edição: ");
                scanf("%d", &ano_edicao);
                alterar(biblioteca, titulo, autor, editora, ano_edicao);
                printf("Informa��es do livro alteradas com sucesso!\n");
                break;
            case 4:
                printf("Digite o título do livro a ser buscado: ");
                scanf("%s", titulo);
                Livro *livro = buscar_por_titulo(biblioteca, titulo);
                if (livro != NULL) {
                    printf("Autor: %s\n", livro->autor);
                    printf("Editora: %s\n", livro->editora);
                    printf("Ano de Edição: %d\n", livro->ano_edicao);
                } else {
                    printf("Livro n�o encontrado na biblioteca.\n");
                }
                break;
            case 5:
                printf("Digite o nome do autor a ser buscado: ");
                scanf("%s", autor);
                buscarPorAutor(biblioteca, autor);
                break;
            case 6:
                printf("Encerrando o programa...\n");
                return 0;
            default:
                printf("Opção inv�lida. Por favor, escolha uma opção v�lida.\n");
        }
    }

    return 0;
}

Livro *criarLivro(char autor[], char titulo[], char editora[], int ano_edicao) {
    Livro *novo_livro = (Livro *)malloc(sizeof(Livro));
    strcpy(novo_livro->autor, autor);
    strcpy(novo_livro->titulo, titulo);
    strcpy(novo_livro->editora, editora);
    novo_livro->ano_edicao = ano_edicao;
    novo_livro->proximo = NULL;
    return novo_livro;
}

Biblioteca *criarBiblioteca() {
    Biblioteca *biblioteca = (Biblioteca *)malloc(sizeof(Biblioteca));
    biblioteca->primeiro = NULL;
    return biblioteca;
}

void inserirOrdenado(Biblioteca *biblioteca, char autor[], char titulo[], char editora[], int ano_edicao) {
    Livro *novo_livro = criarLivro(autor, titulo, editora, ano_edicao);

    if (biblioteca->primeiro == NULL || strcmp(biblioteca->primeiro->titulo, titulo) > 0) {
        novo_livro->proximo = biblioteca->primeiro;
        biblioteca->primeiro = novo_livro;
    } else {
        Livro *atual = biblioteca->primeiro;
        while (atual->proximo != NULL && strcmp(atual->proximo->titulo, titulo) < 0) {
            atual = atual->proximo;
        }
        novo_livro->proximo = atual->proximo;
        atual->proximo = novo_livro;
    }
}

void remover(Biblioteca *biblioteca, char titulo[]) {
    Livro *atual = biblioteca->primeiro;
    Livro *anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            if (anterior == NULL) {
                biblioteca->primeiro = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void alterar(Biblioteca *biblioteca, char titulo[], char novo_autor[], char nova_editora[], int novo_ano) {
    Livro *atual = biblioteca->primeiro;
    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            strcpy(atual->autor, novo_autor);
            strcpy(atual->editora, nova_editora);
            atual->ano_edicao = novo_ano;
            return;
        }
        atual = atual->proximo;
    }
}

Livro *buscar_por_titulo(Biblioteca *biblioteca, char titulo[]) {
    Livro *atual = biblioteca->primeiro;
    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void buscarPorAutor(Biblioteca *biblioteca, char autor[]) {
    Livro *atual = biblioteca->primeiro;
    int encontrado = 0;
    while (atual != NULL) {
        if (strcmp(atual->autor, autor) == 0) {
            printf("Título: %s\n", atual->titulo);
            printf("Editora: %s\n", atual->editora);
            printf("Ano de Edição: %d\n", atual->ano_edicao);
            encontrado = 1;
        }
        atual = atual->proximo;
    }
    if (!encontrado) {
        printf("Nenhum livro encontrado para esse autor.\n");
    }
}

void menu() {
    printf("\n=== Menu ===\n");
    printf("1. Inserir livro\n");
    printf("2. Remover livro\n");
    printf("3. Alterar livro\n");
    printf("4. Buscar por título\n");
    printf("5. Buscar por autor\n");
    printf("6. Sair\n");
}


