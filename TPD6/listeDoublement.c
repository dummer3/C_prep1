#include <stdio.h>
#include <stdlib.h>

/* ============== Correction liste doublement chainee circulaire =========== */
/* == Fiche 06, exo 10 du TD et exo 3 du TP ====*/

struct maillonDoublementChaine
{
    int valeur;
    struct maillonDoublementChaine * suivant;
    struct maillonDoublementChaine * prec;
};

typedef struct maillonDoublementChaine maillonDC;

struct listeDouble{ // liste doublement chainee circulaire
    maillonDC * debut;
    maillonDC * fin;
};

typedef struct listeDouble listeD;

listeD * creeListeVide()
{
    listeD * l=(listeD *) malloc(sizeof(listeD));
    l->debut=NULL;
    l->fin=NULL;
    return l;
}

void ajouteMaillonTete(listeD * l, int valeur)
{
    maillonDC * e=(maillonDC *) malloc(sizeof(maillonDC));
    e->valeur=valeur;
    if (l->debut==NULL)
    {
        l->fin=e;
        e->suivant=e;
        e->prec=e;
    }
    else
    {
        e->suivant=l->debut;
        e->prec=l->fin;
        l->fin->suivant=e;
        e->suivant->prec=e;
    }
    l->debut=e;
}

void afficheListe(listeD * l)
{
    maillonDC * e=l->debut;
    printf("debut ");

    if (e!=NULL)
    {
        do
        {
            printf("%d <-> ", e->valeur);
            e=e->suivant;
        } while(e!=(l->debut));
    }
    printf("fin \n");
}

void afficheListeInverse(listeD * l)
{
    maillonDC * e=l->fin;
    printf("fin ");
    if (e!=NULL)
    {
        do
        {
            printf("%d <-> ", e->valeur);
            e=e->prec;
        } while(e!=(l->fin));
    }
    printf("debut \n");
}

void ajouteMaillonFin(listeD * l, int valeur)
{
    maillonDC * e=(maillonDC *) malloc(sizeof(maillonDC));
    e->valeur=valeur;
    if (l->fin==NULL)
    {
        l->fin=e;
        e->suivant=e;
        e->prec=e;
    }
    else
    {
        e->suivant=l->debut;
        e->prec=l->fin;
        l->fin->suivant=e;
        e->suivant->prec=e;
    }
    l->fin=e;
}

void supprimeMaillonTete(listeD * l)
{
    
    if (l->debut!=NULL)
    {
        if (l->debut!=l->fin)
        {
            maillonDC * nvDebut=l->debut->suivant;
            free(l->debut);
            nvDebut->prec=l->fin;
            l->fin->suivant=nvDebut;
            l->debut=nvDebut;
            
        }
        else
        {
            free(l->debut);
            l->debut=NULL;
            l->fin=NULL;
        }
    }
}

void destruction(listeD * l)
{
    maillonDC * premierElem=l->debut;
    if (premierElem!=NULL)
    {
        maillonDC * e=premierElem->suivant;
        maillonDC * e2;
        while (e!=premierElem)
        {
            e2=e->suivant;
            free(e);
            e=e2;
        }
        free(premierElem);
    }
    free(l);
}



int main()
{
    listeD * l=creeListeVide();
    ajouteMaillonTete(l, 3);
    ajouteMaillonTete(l, 5);
    
    afficheListe(l);
    afficheListeInverse(l);
    /*
    supprimeElementTete(l);
    afficheListe(l);
    afficheListeInverse(l);
    
    supprimeElementTete(l);
    afficheListe(l);
    afficheListeInverse(l);
    */
    
    
    ajouteMaillonFin(l, 12);
    ajouteMaillonFin(l, 200);
    ajouteMaillonTete(l, 102);
    afficheListe(l);
    afficheListeInverse(l);
    
    supprimeMaillonTete(l);
    afficheListe(l);
    afficheListeInverse(l);
    
    
    destruction(l);
    return 0;
}
