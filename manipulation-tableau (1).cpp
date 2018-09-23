#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 1000
#define TRUE 1
#define FALSE 0


//procedure saisie
void saisie(int*T,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Entrez la valeur %d \t",i);
		scanf("%d",&T[i]);
	}
}


//procedure afficher
void afficher(int*T,int n)
{
	int i;
	printf("les element du tableau sont\n");
	for (i=0;i<n;i++)
	{
		printf("%d",T[i]);
		printf("\t");	
	}
}


//tri bulle
void tribulle(int*T,int n)
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


//tri selection
void triselection(int*T,int n)
{
	int i;
	int min;
	int j;
	int aux;
	for (i=0;i<n-1;i++)
	{
		min=i;
		for (j=i+1;j<n;j++)
		   if(T[j]<T[min])
		     min=j;
		   	aux=T[i];
		   	T[i]=T[min];
		   	T[min]=aux;
		   
	}
}

//tri insertion
void tri_insertion(int*T,int n)
{
	int i;
	int j;
	int x;
	for(i=1;i<n;i++)
	{
		x=T[i];
		j=i;
		while((j>0) && (T[j-1]>x))
		{
			T[j]=T[j-1];
			j=j-1;
		}
		T[j]=x;
	}
}



//tri rapide
void echange(int*T,int i, int j)
{
	int aux;
	aux=T[i];
	T[i]=T[j];
	T[j]=aux;
}
int partition(int*T,int deb,int fin)
{
	int cpt=deb;
	int pivot=T[deb];
	int i;
	for (i=deb+1;i<=fin;i++)
	{
		if(T[i]<pivot)
		{
			cpt++;
			echange(T,cpt,i);
		}
	}
	echange(T,cpt,deb);
	return(cpt);
}
void trirapiderapide(int*T,int debut,int fin)
{
	if(debut<fin)
	{
		int pivot=partition(T,debut,fin);
		trirapiderapide(T,debut,pivot-1);
		trirapiderapide(T,pivot+1,fin);
	}
}
void trirapide(int*T,int n)
{
	trirapiderapide(T,0,n-1);
}

//tri fusion
void fusion(int*T,int deb1,int fin1,int fin2)
{
    int *table1;
    int deb2=fin1+1;
    int compt1=deb1;
    int compt2=deb2;
    int i;
        
    table1=(int*)malloc((fin1-deb1+1)*sizeof(int));

    //je recopie les éléments du début du tableau
    for(i=deb1;i<=fin1;i++)
    {
        table1[i-deb1]=T[i];
    }
                        
    for(i=deb1;i<=fin2;i++)
    {    
	    //cas ou tous les éléments du premier tableau ont été utilisés    
        if (compt1==deb2) 
        {
            break; 
        }
        //cas ou tous les éléments du second tableau ont été utilisés
        else if (compt2==(fin2+1)) 
        {
        	//ajoute des éléments restants du premier tableau
            T[i]=table1[compt1-deb1]; 
            compt1++;
        }
        else if (table1[compt1-deb1]<T[compt2])
        {
        	//ajoute d'un élément du premier tableau
            T[i]=table1[compt1-deb1]; 
            compt1++;
        }
        else
        {
        	//ajoute d'un élément du second tableau
            T[i]=T[compt2]; 
            compt2++;
        }
    }
    free(table1);
}
        

void trifusionfusion(int*T,int deb,int fin)
{
    if (deb!=fin)
    {
        int milieu=(fin+deb)/2;
        trifusionfusion(T,deb,milieu);
        trifusionfusion(T,milieu+1,fin);
        fusion(T,deb,milieu,fin);
    }
}

void trifusion(int*T,int n)
{
  if (n>0)
  {
    trifusionfusion(T,0,n-1);
  }
}



//tri par tas

void permutation(int*T,int i, int j)
{
	int temp;
	temp = T[i];
	T[i]=T[j];
	T[j]=temp;
}
 
void tamiser(int*T, int noeud, int n)
{
	int k = noeud;
	int j = 2*k;
	while(j<=n)
	{
		if ((j<n) && (T[j]<T[j+1]))
		{
			j++;		
		}
		if (T[k]<T[j])
		{
			permutation(T,k,j);
			k = j;
			j = 2*k;
		}
		else return;
	}
}
void tritas(int*T, int n)
{
	if (n <= 1) return;
 
	for (int i = n/2; i>=0;i--)
	{
		tamiser(T,i,n);
	}
	for (int i=(n-1); i>0;i-- )
	{
		permutation(T,i,0);
		tamiser(T,0,i-1);
	}
 
}


//tri shell
void trishell(int*T,int n)
     {
     int o, i, j, valeur;

     o=0;
        
     while(o<n)
         {
         o=3*o+1;
         }
        
     while(o!=0)
         {
         o=o/3;
         for (i=o;i<n;i++)
             {
             valeur=T[i];
             j=i;

             while((j>(o-1)) && (T[j-o]>valeur))
                 {
                 T[j]=T[j-o];
                 j=j-o;
                 }
             T[j]=valeur;
             }
         }
     }


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


//recherche dichotomique
void dichotomique (int*T, int n)
{
	int posi;
	int val;
	int inf;
	int mili;
	int sup;
	printf("Element a rechercher\n");
	scanf("%d",&val);
	//initialisation des limites du domaine de recherche
	inf=0;
	sup=n-1;
	//recherche de position et valeur
	posi=-1;
	while((inf<=sup) && (posi==-1))
	{
		mili=(sup+inf)/2;
		if (val<T[mili]) sup=mili-1;
		else if (val>T[mili]) inf=mili+1;
		else posi=mili;
	}
	//affichage du resultat
	if (posi==-1) printf("La valeur rechercher n'est pas dans le tableau\n");
	else printf("La valeur %d est dans le tableau.\n",val);
}


//recherche du maximum
int maximum(int*T,int n)
{
	int i;
	int max;
	max=T[1];
	for(i=0;i<n;i++)
	{
		if(T[i]>max) max=T[i];
	}
	printf("Le maximum est %d.",max);
}

//programme principale
int main(void)
{
	int n;
	int *TAB;
	int i;
	int num;
	int choix;
	int choix1;
	
	printf("PROGRAMME DE MANIPULATION DE TABLEAU \n");
	printf("Entrez le nombre d'entier a entre dans le tableau: \n");
	scanf("%d",&n);
	
	//allouer memoire pour tableau
	
	TAB=(int*) malloc(n*sizeof(int));
	
	//remplire le tableau
    saisie(TAB,n);
	
	//faire le choix
	printf("MENU DES TRIS\n");
	printf("1.TRI BULLE \n");
	printf("2.TRI SELECTION \n");
	printf("3.TRI INSERTION \n");
	printf("4.TRI RAPIDE \n");
	printf("5.TRI FUSION \n");
	printf("6.TRI TAS\n");
	printf("7.TRI SHELL\n");
	
	printf("Entrez votre choix \n");
	scanf("%d",&choix);
	switch (choix)
	{
		case 1: 
		{
			tribulle(TAB,n);
			afficher(TAB,n);
		}
		break; 
		case 2: 
		{
		    triselection(TAB,n);
		    afficher(TAB,n);
	    }
		break; 
		case 3: 
		{
			tri_insertion(TAB,n);
		    afficher(TAB,n);
		}
		break; 
		case 4: 
		{
			trirapide(TAB,n);
		    afficher(TAB,n);
		}
		break; 
		case 5: 
		{
			trifusion(TAB,n);
		    afficher(TAB,n);
		}
		break; 
		case 6: 
		{
			tritas(TAB,n);
			afficher(TAB,n);
		}
		break;
		case 7:
		{
			trishell(TAB,n);
			afficher(TAB,n);
		}
		break;
		default: printf("CHOIX IMPOSSIBLE ");
		break;
	}
	
    printf("\n");
    printf("MENU DES RECHERCHES\n");
    printf("1.RECHERCHE SEQUENTIELLE\n");
    printf("2.RECHERCHE DICHOTOMIQUE\n");
    printf("3.RECHERCHE DU MAXIMUM\n");
    printf("Quelle recherche voulez vous effectuer ?\n");
    scanf("%d",&choix1);
    switch (choix1)
    {
    case 1: sequentielle(TAB,n);
    break;
    case 2: dichotomique(TAB,n);
    break;
    case 3: maximum(TAB,n);
    break;
    default: printf("Choix imposible");
    break;
    }
	return 0;
	
}
