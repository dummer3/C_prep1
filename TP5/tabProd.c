#include <stdio.h>
#include <stdlib.h>

struct produitInventaire{
  int quantite;
  int reference;

};

typedef struct produitInventaire produit;

void AfficheProd(produit prod);
void ajoute(produit *p, int q);
void initialise (produit * tab,int n);
void afficheTabProd ( produit * tab,int n);
void ajouteProd(produit * tab,int n, produit p);

int main()
{
  int n;
  produit * tab;
  produit p ;
  
  printf("Combien de produit ?");
  scanf("%d",&n);
  tab = (produit*)malloc( n*sizeof (produit));
  initialise(tab,n);

  p = tab[1];
  
  ajouteProd(tab,n,p);
  afficheTabProd(tab,n);
    


  free (tab);
  return 0;
}



void AfficheProd(produit prod)
{
  printf("Reference : %d \nquantite : %d\n",prod.reference,prod.quantite);
    
}

void ajoute(produit *p, int q)
{
  p->quantite += q;

}

void initialise (produit * tab,int n)
{
  for (int i =0 ; i<n ; i++)
    {
      printf("le produit n°%d à comme reference : ",i);
	scanf("%d",&tab[i].reference);
	 printf("le produit n°%d à comme quantite : ",i);
	scanf("%d",&tab[i].quantite);

    }
  printf("\n \n");
}

void afficheTabProd ( produit * tab,int n)
{
  for(int i =0; i<n; i++)
    {
      AfficheProd(tab[i]);

    }

}

void ajouteProd(produit * tab,int n, produit p)
{
  for(int i=0; i<n;i++)
    {
      if (p.reference == tab[i].reference)
	{
	  tab[i].quantite += p.quantite;
	}

    }

}

