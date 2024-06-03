/*
** Função: Perfil de Saúde.
** Autor: João Victor Barbosa Perazzo
** Data: 02/06/2024
** Observações:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_STRING_LENGTH 81 
#define EXPECTANCY_MALE 75 
#define EXPECTANCY_FEMALE 80 

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nomeCompleto[MAX_STRING_LENGTH];
    char sexo;
    Data dataNascimento;
    float altura;
    float peso;
} PerfilSaude;

int calcularIdade(PerfilSaude *perfil);
float calcularIMC(PerfilSaude *perfil);
int calcularFreqCardiacaMaxima(PerfilSaude *perfil);
int calcularFreqCardiacaIdeal(PerfilSaude *perfil);
int calcularExpectativaAnos(PerfilSaude *perfil);
void preencherPerfil(PerfilSaude *perfil);
void exibirPerfil(PerfilSaude *perfil);
void exibirTabelaIMC();

int main() {
    setlocale(LC_ALL, "Portugese");

    int n,i;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);

    PerfilSaude *perfis = malloc(n * sizeof(PerfilSaude));
    if (perfis == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    for ( i = 0; i < n; i++) {
        printf("\nDados da Pessoa %d:\n", i + 1);
        preencherPerfil(&perfis[i]);
    }

    printf("\n\nResultados:\n");
    for ( i = 0; i < n; i++) {
        exibirPerfil(&perfis[i]);
        printf("Idade: %d anos\n", calcularIdade(&perfis[i]));
        printf("IMC: %.2f\n", calcularIMC(&perfis[i]));
        printf("Frequência Cardíaca Máxima: %d bpm\n", calcularFreqCardiacaMaxima(&perfis[i]));
        printf("Frequência Cardíaca Ideal: %d bpm\n", calcularFreqCardiacaIdeal(&perfis[i]));
        printf("Expectativa de Anos: %d anos\n", calcularExpectativaAnos(&perfis[i]));
    }

    exibirTabelaIMC();
    free(perfis);

    return 0;
}

int calcularIdade(PerfilSaude *perfil) {
    int idade = 2024 - perfil->dataNascimento.ano;
    if (perfil->dataNascimento.mes > 5 ||
        (perfil->dataNascimento.mes == 5 && perfil->dataNascimento.dia > 21)) {
        idade--; 
    }
    return idade;
}

float calcularIMC(PerfilSaude *perfil) {
    return perfil->peso / (perfil->altura * perfil->altura);
}

int calcularFreqCardiacaMaxima(PerfilSaude *perfil) {
    int idade = calcularIdade(perfil);
    if (perfil->sexo == 'M') {
        return 220 - idade;
    } else {
        return 226 - idade;
    }
}

int calcularFreqCardiacaIdeal(PerfilSaude *perfil) {
    return calcularFreqCardiacaMaxima(perfil) * 0.7; 
}

int calcularExpectativaAnos(PerfilSaude *perfil) {
    if (perfil->sexo == 'M') {
        return EXPECTANCY_MALE - calcularIdade(perfil);
    } else {
        return EXPECTANCY_FEMALE - calcularIdade(perfil);
    }
}

void preencherPerfil(PerfilSaude *perfil) {
    printf("Nome Completo: ");
    fgets(perfil->nomeCompleto, MAX_STRING_LENGTH, stdin);
    printf("Sexo (M/F): ");
    scanf(" %c", &perfil->sexo);
    printf("Data de Nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &perfil->dataNascimento.dia, &perfil->dataNascimento.mes, &perfil->dataNascimento.ano);
    printf("Altura (m): ");
    scanf("%f", &perfil->altura);
    printf("Peso (kg): ");
    scanf("%f", &perfil->peso);
}

void exibirPerfil(PerfilSaude *perfil) {
    printf("\nPerfil de Sa�de:\n");
    printf("Nome Completo: %s", perfil->nomeCompleto);
    printf("Sexo: %c\n", perfil->sexo);
    printf("Data de Nascimento: %02d/%02d/%04d\n", perfil->dataNascimento.dia, perfil->dataNascimento.mes, perfil->dataNascimento.ano);
    printf("Altura: %.2f m\n", perfil->altura);
    printf("Peso: %.2f kg\n", perfil->peso);
}

void exibirTabelaIMC() {
    printf("\nTabela de IMC:\n");
    printf("Abaixo do Peso:\t< 18.5\n");
    printf("Peso Normal:\t18.5 - 24.9\n");
    printf("Sobrepeso:\t25.0 - 29.9\n");
    printf("Obesidade:\t>= 30.0\n");
}


