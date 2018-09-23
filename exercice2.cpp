#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//exercice 2

//recherche sequentielle
void sequentielle (int*T,int n)
{
	int val;
	int i;
	int posi;
	printf("Entrez l'element a chercher\n");
	scanf("%d",&val);
	//recherche
	posi=-1;
	for(i=0;((i<n) && (posi==-1));i++)
	{
		if (T[i]==val) posi=i;
	}
	//affichage
	if (posi==-1) printf("La valeur entre n''est pas dans le tableau\n");
	else printf("La valeur %d est dans le tableau.\n",val);
}


//programme principale
int main(void)
{
	int n;
	int *TAB;
	int i;

	printf("PROGRAMME DE RECHERCHE \n");
	printf("Entrez le nombre d'entier a entre dans le tableau: \n");
	scanf("%d",&n);
	
	//allouer memoire pour tableau
	
	TAB=(int*) malloc(n*sizeof(int));
	
	//remplire le tableau
    saisie(TAB,n);

    sequentielle(TAB,n);
}