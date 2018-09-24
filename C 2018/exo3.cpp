#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 1000


//Farticleier

//Structure pour representer les articles
struct articles{
    char code[2];
    char prix[20];
}

//pointeurs vers le Farticleier

FILE*Farticle=NULL;


//2 Ajouter un article au Farticleier

articles article[N];

//ajouter
void ajouter(articles p[])
{
	int n;
	Farticle=fopen("Farticle.txt","a");
		printf("Combien d'article voulez vous ajouter\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		   printf("entrez le code\n");
		   scanf("%s",&p[i].code);
		   printf("entrez le prix\n");
		   scanf("%s",&p[i].prix);
		   fprintf(Farticle,"%s\t%s\n",p[i].code,p[i].prix);
		   
	    }
	fclose(Farticle);
}


//3 Prix d'un article a partir de son code

void rechercher(articles p[])
{
	char codeRechercher[2];
	printf("entrez le code de l'article a rechercher\n");
	scanf("%s",&codeRechercher);
	Farticle=fopen("Farticle.txt","r");
	for(i=0;i<N;i++)
	{
		fscanf(Farticle,"%s",p[i].code);
		fscanf(Farticle,"%s",p[i].prix);
		if(strcmp(p[i].code,codeRechercher)==0)
		{
			printf("article trouve\n");
			printf("code %s\n",p[i].code);
			printf("prix %s",p[i].prix);
		}
	}
	fclose(Farticle);
}



//4 programme principale
//charger les donnees


//lister
void charger(articles p[])
{
	int k;
	Farticle=fopen("Farticle.txt","r");	
	if(Farticle!=NULL)
	{
		i=0;
		k=0;
	   while(fscanf(Farticle,"%s%s",p[i].code,p[i].prix)!=EOF)
	   {
	   	i++;
	   	k++;
	   }
	   for(i=0;i<k;i++)
	   	  {
		     printf("code: %s\n",p[i].code);
		     printf("prix: %s\n",p[i].prix);
	      }
	   fclose(Farticle);
    }
}


main(){
    int choix;
    int quitter;
    do{
        printf("Les Articles\n");
	    printf("MENU\n");
	    printf("1.AJOUTER\n");
	    printf("2.CONSULTER PRIX PAR ARTICLE\n");
	    printf("Quel est votre choix?\n");
	    scanf("%d",&choix);
        switch(choix){
		   case 1: ajouter(article);
		   break;
           case 2: rechercher(article);
		   break;
		   default: printf("choix impossible\n");
		   break;
	    }
        printf("\nvoulez vous quitter\n");
	    printf("1.NON\n");
	    printf("2.OUI\n");
	    scanf("%d",&quitter);
    }while(quitter==1)
}


