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

	printf("PROGRAMME DE RECHERCHE \n");
	printf("Entrez le nombre d'entier a entre dans le tableau: \n");
	scanf("%d",&n);
    sequentielle(TAB,n);
}

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
//tri bulle
void tribulle(int T[5])
{
	int j=0;
	int aux=0;
	int echange=1;
	while (echange)
	{
		echange=FALSE;
		for (j=0;j<n-1;j++)
		{
			if (T[j]>T[j+1])
			{
				aux=T[j+1];
				T[j+1]=T[j];
				T[j]=aux;
				echange=TRUE;
			}
		}
	}
}







