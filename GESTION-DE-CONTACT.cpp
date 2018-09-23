#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 1000

struct contact
{
	char nom[30];
	char numero[20];
};
FILE*fich=NULL;
FILE*FX=NULL;
contact personne[N];
int i;

//creer
void creer(contact p[])
{
	int n;
	
	fich=fopen("Repertoire.txt","w");
	if(fich!=NULL)
	{
		printf("entez le nombre de contact a saisir\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("entrez le nom\n");
			scanf("%s",&p[i].nom);
			printf("entrez le numero\n");
			scanf("%s",&p[i].numero);
			fprintf(fich,"%s\t%s\n",p[i].nom,p[i].numero);
		}
		fclose(fich);
	}
	
}


//ajouter
void ajouter(contact p[])
{
	int n;
	fich=fopen("Repertoire.txt","a");
		printf("Combien de contact voulez vous ajouter\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		   printf("entrez le nom\n");
		   scanf("%s",&p[i].nom);
		   printf("entrez le numero\n");
		   scanf("%s",&p[i].numero);
		   fprintf(fich,"%s\t%s\n",p[i].nom,p[i].numero);
		   
	    }
	fclose(fich);
}

//lister
void lister(contact p[])
{
	int k;
	fich=fopen("Repertoire.txt","r");	
	if(fich!=NULL)
	{
		i=0;
		k=0;
	   while(fscanf(fich,"%s%s",p[i].nom,p[i].numero)!=EOF)
	   {
	   	i++;
	   	k++;
	   }
	   for(i=0;i<k;i++)
	   	  {
		     printf("Nom: %s\n",p[i].nom);
		     printf("Numero: %s\n",p[i].numero);
	      }
	   fclose(fich);
    }
}

//rechercher
void rechercher(contact p[])
{
	char numrech[30];
	printf("entrez le nom du contact a rechercher\n");
	scanf("%s",&numrech);
	fich=fopen("Repertoire.txt","r");
	for(i=0;i<N;i++)
	{
		fscanf(fich,"%s",p[i].nom);
		fscanf(fich,"%s",p[i].numero);
		if(strcmp(p[i].nom,numrech)==0)
		{
			printf("Contact trouve\n");
			printf("Nom %s\n",p[i].nom);
			printf("Numero %s",p[i].numero);
		}
	}
	fclose(fich);
}

//modifier
 void modifier(contact p[])
{
    contact nouvo;
    char nomamodif[30];
    int trouve=0;
    i=0;
    fich=fopen("Repertoire.txt","r");
    if(fich==NULL){
    	printf("creer dabord un liste de contact\n");
	}    
    else
    {
       FX=fopen("autrerepertoire.txt","w+");    
       printf("Donner le nom du contact a modifier:\n");
       scanf("%s",nomamodif);    
       printf("Donner le nouveau nom:\n");
       scanf("%s",nouvo.nom);       
       printf("Donner son numero:\n");
       scanf("%s",nouvo.numero);

       while(!feof(fich))
       {
          fscanf(fich,"%s%s",p[i].nom,p[i].numero);
          if(strcmp(nomamodif,p[i].nom)==0)
          {
             fprintf(FX,"%s\t%s\n",nouvo.nom,nouvo.numero);
             trouve=1;
          }

          else
          fprintf(FX,"%s\t%s\n",p[i].nom,p[i].numero);
          i++;
       }
       fclose(fich);
       fclose(FX);
       remove("Repertoire.txt");
        rename("autrerepertoire.txt","Repertoire.txt");
    }
    if(trouve==1)
        printf("Modification reussi\n");
    else
        printf("Ce contact n existe pas \n");
  fclose(fich);
}


//supprimer
void supprimer(contact p[])
{
    char nomasup[30];
    int trouve=0;
    fich=fopen("Repertoire.txt","r");
    if(fich==NULL){
    	printf("creer dabord un liste de contact\n");
	}    
    else
    {
       FX=fopen("suprepertoire.txt","w+");    
       printf("Donner le nom du contact a supprimer:\n");
       scanf("%s",nomasup);    
       while(!feof(fich))
       {
          fscanf(fich,"%s%s",p[i].nom,p[i].numero);
          if(strcmp(nomasup,p[i].nom)==0)
          {
             i++;
             trouve=1;
          }

          else
          fprintf(FX,"%s\t%s\n",p[i].nom,p[i].numero);
          i++;
       }
       fclose(fich);
       fclose(FX);
       remove("Repertoire.txt");
       rename("suprepertoire.txt","Repertoire.txt");
    }
    if(trouve==1)
        printf("Suppression reussi\n");
    else
        printf("Ce contact n existe pas \n");
  fclose(fich);
}




//programme principale
main()
{
	int choix;
	int choix2;
	
	do
	{
		printf("MANIPULATION DE FICHIER\n");
	    printf("MENU\n");
	    printf("1.CREER\n");
	    printf("2.INSERER\n");
	    printf("3.RECHERCHER\n");
	    printf("4.MODIFIER\n");
	    printf("5.SUPPRIMER\n");
	    printf("6.LISTER\n");
	    printf("Quel est votre choix?\n");
	    scanf("%d",&choix);
	    switch(choix)
	    {
		   case 1: creer(personne);
		   break;
           case 2: ajouter(personne);
		   break;
		   case 3: rechercher(personne);
		   break;
		   case 4: modifier(personne);
	       break;
		   case 5: supprimer(personne);
		   break;
		   case 6: lister(personne);
		   break;
		   default: printf("choix impossible\n");
		   break;
	    }
	    printf("\nvoulez vous revenir au menu?\n");
	    printf("1.NON\n");
	    printf("2.OUI\n");
	    scanf("%d",&choix2);
    }
    while(choix2==2);
}
