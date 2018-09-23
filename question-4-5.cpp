#include <stdio.h>
#include <conio.h>
#include <myconio.h>
#include <string.h>


typedef struct Personne Personne;
struct Personne
{
   char *NomPrenom;
   long Montan;
   Personne *Precedent;
};

typedef struct Liste Liste;
struct Liste
{
   Personne *Debut;
   Personne *Fin;
   int Taille;
};

Liste *CreerListe()
{
   Liste *liste = (Liste*)malloc(sizeof(Liste));
   Personne *personne = (Personne*)malloc(sizeof(Personne));
   personne->Precedent = NULL;
   liste->Debut = personne;
   liste->Taille = -1;
   return liste;
}

void Inserer(Liste *liste,Personne *personne)
{
   if(liste==NULL) printf("AUCUNE LISTE");
   else
   {
      Personne *momo = liste->Debut;
      if(liste->Taille==-1)
      {
         momo->Precedent = personne;
         liste->Taille += 2;
         liste->Debut = personne;
         personne->Precedent = NULL;
      }
      else
      {
         while(momo->Precedent != NULL) momo = momo->Precedent;
         personne->Precedent = NULL;
         momo->Precedent = personne;
         liste->Taille++;
      }
   }
}

void Retirer(Liste *liste)
{
   if(liste==NULL) printf("AUCUNE LISTE");
   if(liste->Taille == 0 || liste->Taille == -1);
   else
   {
      Personne *asupprimer = liste->Debut;
      liste->Debut = liste->Debut->Precedent;
      liste->Taille--;
      free(asupprimer);
      Personne *momo = liste->Debut;
      while(momo->Precedent != NULL)
      {
         momo = momo->Precedent;
      }
   }
}

void Coller(Liste *liste1,Liste *liste2)
{
  if(liste1==NULL && liste2==NULL) printf("AUCUNE LISTE");
  else
  {
     Personne *momo = liste1->Debut;
     liste2->Taille++;
     while(momo->Precedent != NULL)
     {
         momo = momo->Precedent;
     }
     momo = liste2->Debut;
     while(momo->Precedent != NULL) momo = momo->Precedent;
     momo->Precedent = liste1->Debut;
  }
}

void Afficher(Liste *liste)
{
     Personne *reafficher = liste->Debut;
     if(liste == NULL) printf("AUCUNE LISTE");
     if(liste->Taille == -1) printf("LISTE VIDE");
     else
     {
        for (int i=0;i<liste->Taille+1;i++)
        {
           printf("\nNOM: ");
           puts(reafficher->NomPrenom);
           gotoxy(2,wherey()+1);
           printf("%d",i);
           printf("\tFACTURE A PAYER: %d",reafficher->Montan);
           reafficher = reafficher->Precedent;
        }
     }
}


Liste *liste1,*liste2;
int choix = 0,choix2 = 0;
main()
{
   liste1 = CreerListe();
   liste2 = CreerListe();
   do
   {
      textbackground(6);
      clrscr();
      gotoxy(15,6);printf("1-LISTE 1\n\n");
      gotoxy(15,8);printf("2-LISTE 2\n\n");
      gotoxy(15,10);printf("3-FUSIONNER LES 2 LISTES\n\n");
      gotoxy(15,12);printf("4-QUITTER\n\n");
      gotoxy(15,14);printf("QUE VOULEZ VOUS FAIRE: ");
      gotoxy(15,16);scanf("%d",&choix);
      switch(choix)
      {
         case 1:
         textbackground(3);
         clrscr();
         do
         {
            char *nom = (char*)malloc(81);
            Personne *personne = (Personne*)malloc(sizeof(Personne));
            long montant =0;
            clrscr();
            gotoxy(15,6); printf("1-INSERER\n\n");
            gotoxy(15,8);printf("2-RETIRER\n\n");
            gotoxy(15,10);printf("3-AFFICHER\n\n");
            gotoxy(15,12);printf("4-RETOUR AU MENU\n\n");
            gotoxy(15,14);printf("QUE VOULEZ VOUS FAIRE: ");
            fflush(stdin);
            scanf("%d",&choix2);
            switch(choix2)
            {
               case 1:
               clrscr();
               printf("Donner le nom et prenom: ");
               fflush(stdin);
               gets(nom); personne->NomPrenom = nom;
               printf("\n\nDonner le montant de la facture a payer: ");
               fflush(stdin);
               scanf("%d",&montant); personne->Montan = montant;
               Inserer(liste1,personne);
               break;
               case 2:
               Retirer(liste1);
               break;
               case 3:
               Afficher(liste1);
               getch();
               break;
            }
         }while(choix2!=4);
         break;
         case 2:
         textbackground(4);
         clrscr();
         do
         {
             char *nom = (char*)malloc(81);
             Personne *personne = (Personne*)malloc(sizeof(Personne));
             long montant =0;
             clrscr();
             gotoxy(15,6);printf("1-INSERER\n\n");
             gotoxy(15,8);printf("2-RETIRER\n\n");
             gotoxy(15,10);printf("3-AFFICHER\n\n");
             gotoxy(15,12);printf("4-RETOUR AU MENU\n\n");
             gotoxy(15,14);printf("QUE VOULEZ-VOUS FAIRE: ");
             fflush(stdin);
             scanf("%d",&choix2);
             switch(choix2)
             {
                case 1:
                clrscr();
                printf("Donner le nom et prenom: ");
                fflush(stdin);
                gets(nom); personne->NomPrenom = nom;
                printf("\n\nDonner le montant de la facture a payer: ");
                fflush(stdin);
                scanf("%d",&montant); personne->Montan = montant;
                Inserer(liste2,personne);
                break;
                case 2:
                Retirer(liste2);
                break;
                case 3:
                Afficher(liste2);
                getch();
                break;
             }
         }while(choix2!=4);
         break;
         case 3:
         Coller(liste2,liste1);
         Afficher(liste1);
         getch();
         break;
        break;
      }
   }while(choix !=4);
    getch();
    return 0;
}


