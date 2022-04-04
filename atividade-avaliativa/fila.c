#include <stdio.h>
#include "fila.h"

int main()
{
    int opcao, num;
    Fila *fil = criar_fila();
    Fila *copia = criar_fila();
    do
    {
        printf("\n\nDigite:\n1- Para adicionar um número na fila.\n2- Para imprimir a fila original.\n3- Para tirar o primeiro número da fila original.\n4- Para esvaziar a fila e liberar a memória.\n5- Fazer uma cópia da fila.\n6- Mostrar cópia da fila.\n7- Sair.\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("\nDigite um número para infileirar: ");
                scanf("%d", &num);
                infileirar(fil,num);
                break;
            case 2:
                imprimir(fil);
                break;
            case 3:
                desenfileirar(fil);
                break;
            case 4:
                esvaziar(fil);
                break;
            case 5:
                copiarfila(fil,copia);
                printf("Cópiado com sucesso!");
                break;
            case 6:
                imprimir(copia);
                break;
            case 7:
                opcao = -1;
                printf("Saindo do programa...");
                break;
            default:
                printf("\nOpção inválida, digite novamente!\n");
                opcao = 0;
                break;
        }
    } while (opcao != -1);
    return 0;
}