#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *anterior;
}No;

typedef struct pilha
{
    int contador;
    No *topo;
}Pilha;

Pilha *create()
{
    Pilha *x = (Pilha*) malloc (sizeof(Pilha));
    x->topo = NULL;
    x -> contador = 0;
    return x;
}

int vazio (Pilha *x)
{
    if(x -> topo == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void inserir (Pilha *x, char elemento)
{
    No *Novono = (No*) malloc(sizeof(No));

    /**/

    Novono -> dado = elemento;

    if(vazio(x) == 1)
    {
        Novono -> anterior = x -> topo;
    }
    x -> topo = Novono;
    x -> contador++;
}

int remover(Pilha *x)
{
    if(vazio(x) == 1)
    {
        No *deletarno = x -> topo;
        int dado = deletarno -> dado;
        x -> topo = deletarno -> anterior;
        x -> contador--;
        free(deletarno);
        return dado; 
    }else
    {
        printf("Pilha já está vazia.\n");
        return -1;
    }
}

int ultimohistorico(Pilha *x)
{
    if(vazio(x) == 1)
    {
        printf("O histórico está vazio. Não há elementos anterior\n");
    }else
    {
        return x -> topo -> dado; 
    }
}

void apagarhistorico(Pilha *x)
{
    No *p = x -> topo;
    while (p != NULL)
    {
        No *z = p -> anterior;
        free(p);
        p = z;
    }
    free(x);
}

void historico (Pilha *x)
{
    No *aux = x -> topo;
    if(aux == NULL)
        printf("Seu histórico está vazio!\n");
    else
    {
        while (aux != NULL)
        {
            printf("-> %d\n", aux -> dado);
            aux = aux -> anterior;
        }
    }
}

int main()
{
    char link[30];
    int t;
    Pilha *p = create();
    printf("Caso queira acessar um site digite 1, para remover o último site digite 2, mostrar histórico digite 3, mostrar o último site visitado 4 e para fechar o programa digite 0: ");
    scanf("%d", &t);
    if(t == 1)
    {
        printf("Digite o link do site que você quer acessar: ");
        scanf("%s", link);
        inserir(p, link);
    }
    printf("Caso queira acessar um site digite 1, para remover o último site digite 2, mostrar histórico digite 3, mostrar o último site visitado 4 e para fechar o programa digite 0: \n");
    scanf("%d", &t);
    if (t == 2)
    {
        printf("Removido elemento: %d", remover(p));
    }
    /*else if (t == 3)
    {
        historico(p);
    }
    else if (t == 4)
    {
        printf("Seu último site acessado foi: ");
        ultimohistorico(p);
    }*/
}