#include <stdlib.h>
#include <stdio.h>
//Função para criar nó para ligar a fila
typedef struct no
{
    int dados;
    struct no *anterior;
} No;

// Função da estrutura fila
typedef struct fila
{
    No *inicio;
    No *final;
}Fila;

// Função para criar fila
Fila *criar_fila()
{
    Fila *fil = (Fila*) malloc (sizeof(Fila));
    if(fil != NULL)
    {
        fil->inicio = NULL;
        fil->final = NULL;
    }
    return fil;
}

// Função enfileirar para receber os dados e ligar um a o outro
void infileirar(Fila *fil, int dado)
{
    No *novoNo = (No*) malloc (sizeof(No));
    novoNo->dados = dado;
    novoNo->anterior = NULL;
    if(fil->inicio == NULL)
    {
        fil->inicio = novoNo;
        fil->final = novoNo;
    }else
    {
        fil->final->anterior = novoNo;
        fil->final = novoNo;
    }
}

// Função para imprimir sem perder os dados da fila
void imprimir(Fila *fil)
{
    if(fil->inicio == NULL)
        printf("\nFila Vazia!");
    else
    {
        No *aux = fil->inicio;
        printf("\nPrimeiro ->");
        while(aux != NULL)
        {
            printf(" %d->", aux->dados);
            aux = aux->anterior;
        }
        printf("Fim");
    }
}

//Função desenfileirar para tirar o primeiro da fila
int desenfileirar(Fila *fil)
{
    if(fil->inicio == NULL)
    {
        printf("\nFila vazia!");
        return -1;
    }
    else
    {
        No *aux = fil->inicio;
        int retirar = aux->dados;
        fil->inicio = fil->inicio->anterior;
        printf("\nNúmero removido: %d", retirar);
        free(aux);
        
        return retirar;
    }
}

// Função para esvaziar a fila por completo
void esvaziar(Fila *fil)
{
    if(fil->inicio == NULL)
        printf("\nFila vazia!");
    else
    {
        No *aux = fil->inicio;
        do
        {
            fil->inicio = fil->inicio->anterior;
            free(aux);
            aux = fil->inicio;
        } while (aux != NULL);
        printf("\nFila esvaziada!");   
    }
}
// Função para fazer uma cópia da função original
void copiarfila(Fila *fil,Fila *x)
{
    No *auxc = fil->inicio;
    while(auxc != NULL)
    {
        infileirar(x,auxc->dados);
        auxc = auxc->anterior;
    }
}