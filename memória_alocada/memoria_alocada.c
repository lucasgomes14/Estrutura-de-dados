#include <stdio.h>
#include <malloc.h>
#define alturamaxima 225

typedef struct
{
	int peso; // peso em Kilograma
	int altura; // altura em centimetros
}Peso_e_altura;

int main() 
{
	Peso_e_altura* pessoa1 = (Peso_e_altura*) malloc(sizeof(Peso_e_altura));
	printf("Digite o seu peso em KG e em seguida sua altura em cm: \n");
	scanf("%d \n %d",&pessoa1->peso, &pessoa1->altura);
	printf("Seu peso é de: %d\nSua altura é de: %d\n",pessoa1->peso, pessoa1->altura);
  if(pessoa1->altura < alturamaxima) printf("Sua altura está abaixo da altura máxima");
  
  else printf("Sua altura ultrapassou o limite de altura!\n");
  
	return(0);
}
