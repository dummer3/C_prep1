#include <stdio.h>
#include <stdlib.h>

/* ============== Correction liste chainee sur les entiers =========== */
/* == Fiche TD06, exos 2 à 8 ====*/

struct maillonPrListe
{
    int valeur;
    struct maillonPrListe * suivant;
};

typedef struct maillonPrListe maillon;

struct listeChainee
{
    maillon * debut;
};

typedef struct listeChainee liste;

liste * pointeurSurNouvelleListeVide()
{
    liste * pointeurSurListe;
    pointeurSurListe=(liste *) malloc (1*sizeof(liste));
    pointeurSurListe->debut=NULL;
    return pointeurSurListe;
}

void afficheListe(liste * pSurListe)
{
    maillon * pSurMaillon;
    pSurMaillon=pSurListe->debut;
    while (pSurMaillon!=NULL)
    {
        printf("%d ->", pSurMaillon->valeur);
        pSurMaillon=pSurMaillon->suivant;
    }
    printf("NULL\n");
}

void insereDebutListe(liste * pointeurSurListe, int valeurAAjouter)
{
    maillon * pSurMaillon;
    pSurMaillon=(maillon *) malloc(1*sizeof(maillon));
    pSurMaillon->valeur=valeurAAjouter;
    pSurMaillon->suivant=pointeurSurListe->debut;
    pointeurSurListe->debut=pSurMaillon;
}

void supprimeMaillonTete(liste * pSurListe)
{
	if (pSurListe->debut!=NULL)
	{
		maillon * pSurDeuxieme;
		pSurDeuxieme=pSurListe->debut->suivant;
		free(pSurListe->debut);
		pSurListe->debut=pSurDeuxieme;
    }
}

int taille(liste * pSurListe)
{
    int i=0;
    maillon * pSurMaillon=pSurListe->debut;
    while(pSurMaillon!=NULL)
    {
        i=i+1;
        pSurMaillon=pSurMaillon->suivant;
    }
    return i;
}

int lireValeurMaillon(liste * pSurListe, int index)
{
    int i=0;
    maillon * pSurMaillon=pSurListe->debut;
    while((pSurMaillon!=NULL) && (i<index))
    {
        i=i+1;
        pSurMaillon=pSurMaillon->suivant;
    }
    if (pSurMaillon!=NULL)
    {
        return pSurMaillon->valeur;
    }
    else
    {
        printf("Liste pas assez longue, fin à l'indice %d, indice demandé: %d\n", i-1, index);
        return 0;
    }
}

void modifValeur(liste * pSurListe, int index, int nvValeur)
{
    int i=0;
    maillon * pSurMaillon=pSurListe->debut;
    while((pSurMaillon!=NULL) && (i<index))
    {
        i=i+1;
        pSurMaillon=pSurMaillon->suivant;
    }
    if (pSurMaillon!=NULL)
    {
        pSurMaillon->valeur=nvValeur;
    }
    else
    {
        printf("Liste pas assez longue, fin à l'indice %d, indice demandé: %d\n", i-1, index);
    }
}

void renverseListe(liste * pSurListe)
{
    if ((pSurListe->debut !=NULL) && ((pSurListe->debut->suivant)!=NULL))
    {
        
    
       
        maillon * pSurMaillonABouger;
        maillon * pSurMaillonSuivant=NULL;
        maillon * premierListeAux=NULL;
       
        while (pSurListe->debut!=NULL)
        {
            pSurMaillonABouger=pSurListe->debut;
            pSurListe->debut=pSurMaillonABouger->suivant;
            pSurMaillonABouger->suivant=premierListeAux;
            premierListeAux=pSurMaillonABouger;
        }
        pSurListe->debut=premierListeAux;
    }
    
}

void libererListe(liste * pointeurSurListe)
{
    maillon * pSurMaillon;
    maillon * pSurPrecedent;
    pSurMaillon=pointeurSurListe->debut;
    while (pSurMaillon!=NULL)
    {
        pSurPrecedent=pSurMaillon;
        pSurMaillon=pSurMaillon->suivant;
        free(pSurPrecedent);
    }
    free(pointeurSurListe);
}

liste * copierListe(liste * pSurListe)
{
    
    if (pSurListe->debut==NULL)
    {
        return pointeurSurNouvelleListeVide();
    }
    else
    {
        liste * pSurCopie;
        pSurCopie=(liste *) malloc(1*sizeof(liste));
        maillon * pSurMaillon=pSurListe->debut;
        maillon * pSurMaillonCopie=(maillon *) malloc(1*sizeof(maillon));
        
        pSurCopie->debut=pSurMaillonCopie;
        maillon * pSuivantCopie;
        while (pSurMaillon->suivant!=NULL)
        {
            
            pSurMaillonCopie->valeur=pSurMaillon->valeur;
            pSuivantCopie=(maillon *) malloc(1*sizeof(maillon));
            pSurMaillonCopie->suivant=pSuivantCopie;
            pSurMaillon=pSurMaillon->suivant;
            pSurMaillonCopie=pSuivantCopie;
            
        }
        pSurMaillonCopie->suivant=NULL;
        return pSurCopie;
    }
}



void ajouterReelFin(liste * pointeur,float r)
{
  maillon * nvMaillon;
    maillon * fin = pointeur->debut;
  nvMaillon = (maillon * ) malloc(sizeof(maillon));
  nvMaillon -> valeur = r;
  nvMaillon -> suivant = NULL;
  while(fin->suivant != NULL)
    {
      fin = fin -> suivant;

    }
  fin->suivant = nvMaillon;
  

}

int main()
{
   liste * pSurLi;
    pSurLi=pointeurSurNouvelleListeVide();
      insereDebutListe(pSurLi, 13);
    insereDebutListe(pSurLi, -5);
    insereDebutListe(pSurLi, 6);
    printf("Liste Li: ");
    afficheListe(pSurLi);
    
    supprimeMaillonTete(pSurLi);
    printf("Liste Li: ");
    afficheListe(pSurLi);
    
    liste * pSurLi2=copierListe(pSurLi);
    
    insereDebutListe(pSurLi2, 60);
    insereDebutListe(pSurLi2, 288);
    
    printf("Liste Li2: ");
    afficheListe(pSurLi2);
    modifValeur(pSurLi2, 1, 56);
    ajouterReelFin(pSurLi2,10);
     printf("Liste Li2: ");
    afficheListe(pSurLi2);
    printf("Element numero 2 de Li2: %d\n", lireValeurMaillon(pSurLi2, 2));
    
    printf("Liste Li: ");
    afficheListe(pSurLi);
    
    printf("Tailles: %d pour Li, et %d pour Li2\n", taille(pSurLi), taille(pSurLi2));
    
 
    libererListe(pSurLi);
    libererListe(pSurLi2);
    
    printf("Fin du programme\n");
    return 0;
}
