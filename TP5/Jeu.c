#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct position
{
  int posX;
  int posY;
};

typedef struct position position;

struct coup
{
  int numJoueur;
  position positionDepart;
  position positionArrivee;
};

typedef struct coup coup;

struct plateauJeu
{
  coup * tab;
  int capacite;
  int prochaineCase;
};

typedef struct plateauJeu plateauJeu;

void initPlateauJeu(plateauJeu * pJ, int tailleDebut);
void AfficherPlateauJeu(plateauJeu * pJ);
void AjouteCoup(coup * c, plateauJeu * pJ);
void augmenteTaille(plateauJeu * pJ);





int main()
{ coup c1 = { 1,{0,0},{2,2}};
  coup c2 = { 2,{0,0},{2,2}};
  coup c3 = { 3,{0,0},{2,2}};
  coup c4 = { 4,{0,0},{2,2}};
  coup c5 = { 5,{0,0},{2,2}};
  coup c6 = { 6,{0,0},{2,2}};
  plateauJeu pJ;
 
  initPlateauJeu(&pJ,5);
  AjouteCoup(&c1,&pJ);
  AjouteCoup(&c2,&pJ);
  AjouteCoup(&c3,&pJ);
  AjouteCoup(&c4,&pJ);
  AjouteCoup(&c5,&pJ);
  AjouteCoup(&c6,&pJ);

  AfficherPlateauJeu(&pJ);
   
  

  return 0;
}



void initPlateauJeu(plateauJeu * pJ, int tailleDebut)
{
  pJ->capacite = tailleDebut;
  pJ->tab = (coup*) malloc(tailleDebut*sizeof(coup));
  pJ->prochaineCase = 0;

}

void AfficherPlateauJeu(plateauJeu * pJ)
{
  for(int i = 0; i< pJ->prochaineCase; i++)
    {
      printf (" le coup n°%d est celui du joueur n°%d, qui est parti de la position (%d,%d) pour arriver à la position (%d,%d) \n",i,pJ->tab[i].numJoueur,pJ->tab[i].positionDepart.posX,pJ->tab[i].positionDepart.posY,pJ->tab[i].positionArrivee.posX,pJ->tab[i].positionArrivee.posY);

    }


  printf ("\n =========================================== \n\n");
  printf("Il reste %d case libre \n",pJ->capacite - pJ->prochaineCase);
  
}


void AjouteCoup(coup* c, plateauJeu * pJ)
{
  if (pJ->capacite > pJ->prochaineCase)
    {
      pJ->tab[pJ->prochaineCase] = *c;
      ( pJ->prochaineCase)++;
    }
  else
    {
      augmenteTaille(pJ);
       pJ->tab[pJ->prochaineCase] = *c;
      ( pJ->prochaineCase)++;
      
    }


}

void augmenteTaille(plateauJeu * pJ)
{
  coup * tempo ;
  pJ->capacite *= 2;
  tempo = (coup*) malloc(pJ->capacite*sizeof(coup));
  
  
  memcpy (tempo,pJ->tab,pJ->capacite*sizeof(coup)/2);
free(pJ->tab);
pJ->tab = tempo;

}
