#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
    char nome[30];
    int idade;
    float altura;
} Pessoal;

typedef struct casa
{
    Pessoal *dono;
    int numero_da_casa;
    char rua[30];
    char cidade[30];

}Aluguel;


void imprimir(Aluguel *x)
{
    printf("Seu nome é %s, tem %d anos, mora na cidade de %s, na rua %s, do número %d", x->dono->nome, x->dono->idade, x->cidade, x->rua, x->numero_da_casa);
}

int main()
{
    Aluguel *dados;
    dados = malloc (sizeof(Aluguel));
    printf("Digite seu nome: ");
    scanf("%[^\n]", dados->dono->nome);
    printf("\nDigite sua idade: ");
    scanf("%d", &dados->dono->idade);
    printf("\nDigite o número da casa: ");
    scanf("%d", &dados->numero_da_casa);
    printf("\nDigite o nome da rua da sua casa: ");
    scanf("%[^\n]", dados->rua);
    printf("\nDigite a o nome da cidade de onde é a casa: ");
    scanf("%[^\n]", dados->cidade);
    imprimir(dados);
    return 0;
}
