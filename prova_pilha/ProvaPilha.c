#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char dado[30];
    struct no *anterior;
} No;

typedef struct pilha
{
    int contador;
    No *top;
} Pilha;

Pilha *create ()
{
    Pilha *p = (Pilha*) malloc (sizeof(Pilha));
    p->top = NULL;
    p->contador = 0;
    return p;
}

int null (Pilha *x)
{
    if(x->contador == 0)
        return 1;
    else{
        return 0;
    }
}

void push (Pilha *p, char *elemento)
{
    No *Novono = (No*) malloc (sizeof(No));
    strcpy(Novono->dado, elemento);

    if(!null(p))
        Novono->anterior = p->top;
    
    p->top = Novono;
    p->contador++;
}

char *peek (Pilha *p)
{
    if(null(p))
    {
        printf("A pilha está vazia. Não existe nenhum elemento no topo\n");
        return "-1";
    }
    else
    {
      printf("%s\n\n", p->top->dado);
      return "1";
    }
}

void liberar(Pilha *p)
{
    No *q = p->top;
    while(q != NULL)
    {
        No *t = q->anterior;
        free(q);
        q = t;
    }
    free(p);
}

void desempilhar(Pilha *p,int elemento)
{
  if(p->contador < elemento)
    printf("Não é possível desempilhar %d vezes pois há apenas %d elementos!\n\n", elemento,p->contador);
  else
  {
    
    printf("topo");
    int c = 0;
    while(c<elemento)
    {
      No *aux = p->top;
      printf(" -> %s", aux->dado);
      p->top = aux->anterior;
      p->contador--;
      c++;
      printf("\n");
    }
    
    
  }
}

int main()
{
  Pilha *x = create();;
  int opcao, desempilha;
  char site[30];

  do
  {
    printf("Digite:\n1- Para adicionar elemento na pilha.\n2- Para verificar o topo da pilha.\n3- Para desempilhar.\n4-sair\n\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
      case 1:
        printf("Digite o site: ");
        scanf("%s", site);
        push(x, site);
        printf("Site adicionado com sucesso!\n\n");
        break;
      case 2:
        peek(x);
        break;
      case 3:
        printf("Digite quantas vezes você quer desempilhar: ");
        scanf("%d",&desempilha);
        desempilhar(x, desempilha);
        break;
      case 4:
        liberar(x);
        opcao = -1;
        break;
      default:
        printf("Opção inválida, digite novamente!\n");
        opcao = 0;
        break;
        }
    }while(opcao !=-1);
    return 0;
}