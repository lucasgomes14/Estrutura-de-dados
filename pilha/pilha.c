#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no anterior;
} No;

typedef struct pilha
{
    No *top;
    int contador;
} Pilha;

Pilha *create ()
{
    Pilha *p = (Pilha*) malloc (sizeof(Pilha));
    p-> top = NULL;
    p->contador = 0;
    return p;
}

void push(Pilha *p, int elemento)
{
    No *Novono = (No*) malloc (sizeof(No));
    Novono->dado = elemento;

    if(p->contador == NULL)
        Novono->anterior = p->top;

    p->top = Novono;
    p->contador++;
}