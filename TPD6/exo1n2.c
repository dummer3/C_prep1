#include <stdio.h>
#include <stdlib.h>




struct maillonPrListe
{
    float valeur;
    struct maillonPrListe * suivant;
};

typedef struct maillonPrListe maillon;

struct listeReels
{
    maillon * debut;
    int taille;
};

typedef struct listeReels liste;

liste * creerListeReelsVide()
{
    liste * pointeurSurListe;
    pointeurSurListe=(liste *) malloc (1*sizeof(liste));
    pointeurSurListe->debut=NULL;
    pointeurSurListe->taille=0;
    return pointeurSurListe;
}



int retournerTaille(liste * pSurListe)
{
    return pSurListe->taille;
}



void ajoutReelDebut(liste * pointeurSurListe, float valeurAAjouter)
{
    maillon * pSurMaillon;
    pSurMaillon=(maillon *) malloc(1*sizeof(maillon));
    pSurMaillon->valeur=valeurAAjouter;
    pSurMaillon->suivant=pointeurSurListe->debut;
    pointeurSurListe->debut=pSurMaillon;
    pointeurSurListe->taille+=1;
}

void afficherListeReels(liste * pSurListe)
{
    maillon * pSurMaillon;
    pSurMaillon=pSurListe->debut;
    while (pSurMaillon!=NULL)
    {
        printf("%f ->", pSurMaillon->valeur);
        pSurMaillon=pSurMaillon->suivant;
    }
    printf("NULL\n");
}


float valeurPremierReel(liste * pSurListe)
{
    return pSurListe->debut->valeur;
}

void supprimerPremierReel(liste * pSurListe)
{
    if (pSurListe->debut!=NULL)
    {
        maillon * pSurDeuxieme;
        pSurDeuxieme=pSurListe->debut->suivant;
        free(pSurListe->debut);
        pSurListe->debut=pSurDeuxieme;
        pSurListe->taille--;
    }
}

void ajouterReelFin(liste * pSurListe, float reel)
{
    maillon * pSurMaillon;
    maillon * prec;
    pSurMaillon=pSurListe->debut;
    while (pSurMaillon!=NULL)
    {
        prec=pSurMaillon;
        pSurMaillon=pSurMaillon->suivant;
    }
    maillon * new_maillon=(maillon *) malloc(1*sizeof(maillon));
    new_maillon->valeur=reel;
    new_maillon->suivant=NULL;
    prec->suivant=new_maillon;
    pSurListe->taille++;
    
}





void destruction(liste * pointeurSurListe)
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


int main()
{
    liste * pSurLi;
    pSurLi=creerListeReelsVide();
    ajoutReelDebut(pSurLi, 13.5);
    ajoutReelDebut(pSurLi, -5.4);
    ajoutReelDebut(pSurLi, 6);
    printf("Liste Li: ");
    afficherListeReels(pSurLi);
    
    supprimerPremierReel(pSurLi);
    printf("Liste Li: ");
    afficherListeReels(pSurLi);
    
    
    ajoutReelDebut(pSurLi, 60);
    ajoutReelDebut(pSurLi, 288);
    
    printf("Liste Li: ");
    afficherListeReels(pSurLi);
    printf("Valeur premier: %f\n", valeurPremierReel(pSurLi));
    supprimerPremierReel(pSurLi);
    printf("Liste Li: ");
    afficherListeReels(pSurLi);
    ajouterReelFin(pSurLi, 444.44);
    printf("Liste Li: ");
    afficherListeReels(pSurLi);
    
    
   
    
    printf("Tailles: %d pour Li\n", retournerTaille(pSurLi));
    

    
    
    destruction(pSurLi);
   
    printf("Fin du programme\n");
    return 0;
}
