#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Contact Contact;
struct Contact
{
    int index;
    char nom[20];
    char numero[9];
    Contact *suivant;
};


typedef struct Liste Liste;
struct Liste
{
    Contact *premier;
    int taille_liste;
};
Liste *liste = NULL; 
Contact *contact = NULL; 
Contact nouveau;

//lire dans la chaine
void Lire(char *chaine, int longueur)
{
    char *entrer=NULL;
    if(fgets(chaine, longueur, stdin)!=NULL)
    {
       entrer=strchr(chaine,'\n');
       if(entrer!=NULL)
       {
          *entrer='\0';
       }
    }
}

//menu
void menu()
{
    system("cls");
    printf("MANIPULATION DE LISTE CHAINER");
    printf("\n1-ENREGISTRER");
    printf("\n2-SUPPRIMER");
    printf("\n3-AFFICHER");
    printf("\n4-QUITTER\n");

}

//construction de liste chainé
void Construire_Liste()
{
    liste = (Liste *)malloc(sizeof(Liste));
    contact = (Contact *)malloc(sizeof(Contact));
    contact->suivant = NULL;
    liste->premier = contact;
    liste->taille_liste = 0;
}
//ajouter
void Ajouter(Liste *liste,Contact contact)
{
    Contact *nouveau_contact = (Contact *)malloc(sizeof(Contact));
    if(liste == NULL || nouveau_contact == NULL) exit(1);
    strcpy(nouveau_contact->nom,contact.nom);
    strcpy(nouveau_contact->numero,contact.numero);
    nouveau_contact->index=contact.index;
    nouveau_contact->suivant = liste->premier;
    liste->premier = nouveau_contact;
    liste->taille_liste++;
}

//supprimer
void Supprimer(Liste *liste)
{
    if(liste == NULL) exit(1);
    if(liste->taille_liste ==0)
    {
       printf("\nAUCUN NUMERO");
       Sleep(2000);
    }
    if(liste->premier->suivant != NULL)
    {
       Contact *asupprimer = liste->premier;
       liste->premier = liste->premier->suivant;
       free(asupprimer);
       liste->taille_liste--;
    }
}

//afficher
void Afficher(Liste *liste)
{
    int i=liste->taille_liste;
    if(liste == NULL) exit(1);
    if(liste->taille_liste ==0)
    {
      printf("\nAUCUN NUMERO");
      Sleep(2000);
    }
    else
    {
       Contact *actuel = liste->premier;
       while(actuel->suivant != NULL)
       {
           printf("\n%d Index : %d \n Nom : %s \n  numero : %s \n\n",i,actuel->index,actuel->nom,actuel->numero);
           actuel = actuel->suivant;
           i--;
       }
       getch();
    }
}

//programme principale
main()
{
   int num, sortir=0;
   Construire_Liste();
   nouveau.index=-1;
   while(sortir == 0)
   {
       menu();
       printf("\nQue voulez vus faire: ");
       scanf("%d",&num);
       switch(num)
       {
          case 1:
          system("cls");
          nouveau.index+=1;

          printf("\nEntrez le nom: ");
          fflush(stdin);
          Lire(nouveau.nom,20);
          fflush(stdin);
          printf("\nEntrer le numero: ");
          Lire(nouveau.numero,9);
          fflush(stdin);
          Ajouter(liste,nouveau);
          getch();
          break;
          case 2:
          Supprimer(liste);
          break;
          case 3:
          system("cls");
          Afficher(liste);
          break;
          case 4: 
		  sortir=1;
          break;
          default:
          system("cls");
          printf("\nChoix impossible");
          Sleep(1500);
          break;
        }
   }
   return 0;
}
