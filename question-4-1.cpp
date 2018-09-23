#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// les contacts
typedef struct Contact Contact;
struct Contact
{
 int index;
 char *nom;
 char *numero;
 Contact *Precedent;
};
//la pile
typedef struct Pile Pile;
struct Pile
{
 Contact *Debut;
 int Taille;
};

Pile *pile = NULL;

//pile vide
int estvide(Pile *pile)
{
 if(pile->Taille==0) return 1;
 else return 0;
}
//pile pleine
int estpleine(Pile *pile) 
{
 if(pile->Taille==256) return 1;
 else return 0;
}
//total empiler
int totalempile(Pile *pile) 
{
 return pile->Taille;
}
//empiler
void empiler(Pile *pile,Contact *contact)
{
   if(estpleine(pile)) printf("La pile est pleine vous ne pouvez pas mettre un contact");
   else
   {
      contact->Precedent =  pile->Debut;
      contact->index = pile->Taille ;
      pile->Taille++;
      pile->Debut = contact;
   }
}
//depiler
void depiler(Pile *pile)
{
    if(estvide(pile)) printf("La pile est vide");
    else
    {
       Contact *asupprimer = pile->Debut;
       pile->Debut = pile->Debut->Precedent;
       pile->Taille--;
       free(asupprimer);
    }
}


//initialiser
Pile * initialize()
{
   Pile *pile = (Pile*)malloc(sizeof(Pile));
   Contact *contact = (Contact*)malloc(sizeof(Contact));
   contact->Precedent = NULL;
   pile->Debut = contact;
   pile->Taille=0;
   return pile;
}

//remplir la pile
void prendrecontact()
{

   Contact *nouveauContact = (Contact*)malloc(sizeof(Contact));
   char *nom = (char*)malloc(81);
   char *numero = (char*)malloc(9);
   do
   {
      printf("Le nom du contact: ");
      fflush(stdin);
      gets(nom);
   } while(strlen(nom)>80);
   nouveauContact->nom = nom;
   do
   {
     printf("Le numero du contact: ");
     fflush(stdin);
     gets(numero);
   }while(strlen(numero)>8);
    nouveauContact->numero = numero;
    empiler(pile,nouveauContact);
}

//modifier
void modifier(Contact *contact)
{
   int choix=0;
   char *nom = (char*)malloc(81);
   char *numero = (char*)malloc(9);
   printf("1-MODIFIER NOM\n");
   printf("2-MODIFIER NUMERO\n");
   printf("3-TOUT MODIFIER\n");
   fflush(stdin);
   scanf("%d",&choix);
   switch(choix)
   {
      case 1:
      {
      	do
        {
           printf("Le nom du contact: ");
           fflush(stdin);
           gets(nom);
        }while(strlen(nom)>80);
        contact->nom = nom;
      }
      break;
      case 2:
      {
      	 do
         {
           printf("Le numero du contact: ");
           fflush(stdin);
           gets(numero);
        }while(strlen(numero)>8);
        contact->numero = numero;
      }
      break;
      case 3:
      {
      	do
        {
           printf("Le nom du contact: ");
           fflush(stdin);
           gets(nom);
        }while(strlen(nom)>80);
        contact->nom = nom;
        do
        {
           printf("Le numero du contact: ");
		   fflush(stdin);
           gets(numero);
        }while(strlen(numero)>8);
        contact->numero = numero;
      }
      break;
   }
}



//afficher
void afficherPile(Pile *pile)
{
   if(estvide(pile)) printf("Pile Vide");
   else
   {
      Contact *courant =  pile->Debut;
      while(courant->Precedent!=NULL)
      {
        printf("Nom: ");
        fflush(stdin);
        puts(courant->nom);
        printf("%d",courant->index);
        printf("Numero: ");
        fflush(stdin);
        puts(courant->numero);
        courant = courant->Precedent;
      }
   }
   getch();
}


//rechercher
void rechercher(Pile *pile)
{
   char *achercher = (char*)malloc(81);
   int trouve=0;
   printf("donner le nom du contact: ");
   fflush(stdin);
   gets(achercher);
   if(estvide(pile)) printf("La pile est vide");
   else
   {
      Contact *courant = pile->Debut;
      while(!trouve && courant->Precedent!=NULL)
      {
         if(strcmp(achercher,courant->nom)==0) trouve=1;
         else courant = courant->Precedent;
      }
      if(trouve)
      {
         printf("Nom: ");
         fflush(stdin);
         puts(courant->nom);
         printf("%d",courant->index);
         printf("Numero: ");
         fflush(stdin);
         puts(courant->numero);
         printf("Pour continuer taper 1 ou 0 sinon: ");
         scanf("%d",&trouve);
         if(trouve==1)
         {
            modifier(courant);
         }
      }
      if(!trouve)
      {
         printf("Aucun contact trouve");
      }
   }  
}



// Programme Principal
int c=0,t1=0,t2=0;
main()
{
   pile = initialize();
   do
   {
      printf("\n1-EMPILER\n");
      printf("2-LISTER\n");
      printf("3-DEPILER\n");
      printf("4-RECHERCHER\n");
      printf("5-VERIFICATION DE PILE PLEINE\n");
      printf("6-VERIFICATION DE PILE VIDE\n");
      printf("7-QUITER");
      printf("Que voulez vous faire\n");
      scanf("%d",&c);
      printf("\n\n");
      switch(c)
      {
         case 1: prendrecontact();
         break;
         case 2: afficherPile(pile);
         break;
         case 3: depiler(pile);
         break;
         case 4: rechercher(pile);
         break;
         case 5: 
		 {
		    t1 = estpleine(pile);
            if(t1==1) printf("La pile est pleine\n");
            else printf("La pile n'est pas pleine\n");
            getch();
         }
         break;
         case 6: 
		 {
		 	 t1 = estvide(pile);
             if(t1==1) printf("La pile est vide\n");
             else printf("La pile n'est pas vide\n");
             getch();
		 }
         break;
      }
   }while(c!=7);
   free(pile);
   return 0;
}
