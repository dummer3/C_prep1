#include <stdio.h>
#include <stdlib.h>
#define N 7



void afficheTab(int tab[N][N])
{
  for(int i = 0 ; i< N ; i++)
    {
      for(int j = 0 ; j<N; j++)
	{
	  printf("| %d |  ", tab[i][j]);

	}
      printf("\n");

    }



}
void afficheMenu(char * prenom)
{
    printf("%s, appuyez sur n'importe quelle touche pour lancer le menu\n\n", prenom);
    
    /* Les deux lignes ci-dessous permettent d'attendre avant de relancer le menu.
     Les enlever si le fonctionnement est défaillant (cela dépend de la machine)*/
    char inutile;
    scanf("%c", &inutile);

    printf("1. Afficher le tableau des resultats\n");
    printf("2. Modifier un resultat\n");
    printf("3. Calculer le nombre de points d'une equipe\n");
    printf("4. Afficher les scores\n");
    printf("5. Savoir quelle équipe a le plus de points\n");
    printf("6. Savoir quelle équipe a le plus de victoires à domicile\n");
    printf("7. Savoir quelle équipe a le plus de victoires à l'extérieur\n");
    printf("0. Quitter\n");
}

void modifCase(int tab[N][N])
{
  int dom,ext,res;

    
    printf("Quel est le numéro de l'équipe jouant à domicile? ");
    scanf("%d",&dom);
    printf("Quel est le numéro de l'équipe jouant à l'extérieur? ");
    scanf("%d",&ext);
    printf("Quel est le nouveau resultat? \n (0: match nul, 1: equipe domicile gagnante, 2: equipe exterieur gagnante)\n");
       scanf("%d",&res);

       tab[dom][ext] = res;
       
  
  
}

int  nbPoints(int tab[N][N],int nbrEquipe)
{
  int somme = 0;
  for (int j = 0; j < N; j++)
    {
      if (j != nbrEquipe)
	{
	  if (tab[nbrEquipe][j] == 0)
	    {
	      somme += 1;
		}
	  else if (tab[nbrEquipe][j] == 1)
	    {
	      somme += 3;
		}

	}
    }
  for(int i = 0; i<N; i++)
    {
      if(i != nbrEquipe)
	{
	  
	  if (tab[i][nbrEquipe] == 0)
	    {
	      somme += 1;
		}
	  else if (tab[i][nbrEquipe] == 2)
	    {
	      somme += 3;
		}

	    

	}
     
    }
  return somme;
}


void afficheScores(int tab[N][N])
{
  for (int i = 0; i< N ; i++)
    {
      printf(" l'équipe %d à obtenu : %d points \n",i,nbPoints(tab,i)) ;

    }
  printf("\n");
}

void equipeLeader(int tab[N][N])
{
  int leader = 0;
  for (int i = 0; i< N;i++)
    {

      if (nbPoints(tab,leader) < nbPoints(tab,i))
	{
	  leader = i;
	}

    }
	printf("le leader est : %d \n\n", leader);

}

int nbVictoires (int tab[N][N],int numEquipe,char domOuExt)
{
  int somme = 0;
  if (domOuExt == 'e')
    {
      for(int i = 0; i<N ; i++)
	{
	  if(tab[i][numEquipe] == 2)
	    {
	      somme++;
	    }


	}


    }
  else if (domOuExt == 'd')
    {
      for(int j = 0; j<N ; j++)
	{
	  if(tab[numEquipe][j] == 1)
	    {
	      somme++;
	    }
	  

	}

    
    }

  else
    {
      printf("Error");
    }
   return somme;
}

int meilleurEquipeDomicile(int tab[N][N])
{
 int  leader=0;
 for(int i =1; i <N;i++)
   {
     if(nbVictoires(tab,leader,'d')<nbVictoires(tab,i,'d'))
       {
	 leader = i;
       }

   }
 
 printf("le leader à domicile est : %d \n\n ", leader);
}



int meilleurEquipeExterieur(int tab[N][N])
{
 int  leader=0;
 for(int i =1; i <N;i++)
   {
     if(nbVictoires(tab,leader,'e')<nbVictoires(tab,i,'e'))
       {
	 leader = i;
       }

   }
 
 printf("le leader à l'exterieur est : %d \n\n", leader);
}



int main()
{
  int choix = -1;
  int resultat[N][N]={{0, 1, 1, 2, 0, 1, 1},
		      {2, 0, 1, 1 ,1 ,0 ,2},
		      {1, 1, 0, 2, 2, 2, 0},
		      {2, 1, 1, 0, 0, 0, 0},
		      {0, 0, 1, 2, 0, 2, 2},
		      {0, 1, 2, 2, 2, 1, 1},
		      {2, 1, 1, 1, 1, 1, 1}};
    
    
    printf("Bienvenue, quel est votre nom ? ");
    char nom[20];
    scanf("%20s",nom);
    do
      {
	afficheMenu(nom);
	printf("Votre choix:");
	scanf("%d", &choix); 
	switch (choix)
	  {
	  case 0:
	    break;
	  case 1 :
	    afficheTab(resultat);
	    break;

	  case 2 :
	    modifCase(resultat);
	    break;
	    
	  case 3 :
	    printf("Quel est l'équipe ? \n");
	    int e;
	    scanf("%d",&e);
	    nbPoints(resultat ,e);
	    break;
	  case 4:
	    afficheScores(resultat);
	    break;
	     case 5:
	    equipeLeader(resultat);
	    break;
	      case 6:
	        meilleurEquipeDomicile(resultat);
	    break;
	      case 7:
		meilleurEquipeExterieur(resultat);
	    break;

	  default:
	     printf("commande non trouvable, recommencer \n");
	  }
      }while(choix != 0);
    /*
      printf("Choisissez un numero d'équipe: ");
    
    printf("L'équipe ayant le plus de points est l'équipe %d avec %d points\n", A COMPLETER);
    
    printf("L'équipe %d avec %d victoires à domicile est la meilleure dans ces conditions\n", A COMPLETER);
    
    printf("L'équipe %d avec %d victoires à l'exterieur est la meilleure dans ces conditions\n", A COMPLETER );
    */
    printf("Au revoir\n");
    
    return 0;
}
