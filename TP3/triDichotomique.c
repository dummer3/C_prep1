#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 25
#define M 8

void afficherTabInt(int tab[], int );
void initClavier(int tab[], int);
void initRandom(int  tab[], int );
int rechercheTab( int tab[], int, int);
int maxTab(int tab[] ,int );
int maxTabPairs(int tab[] ,int );
int maxPosTab1(int tab[],int );
int maxPosTab2(int tab[],int );
void echangeDernierTab (int tab[], int ,int );
void triParSelectionDuMax (int tab[], int );
void triParBubulles(int tab[], int );
int PowDe2(int);
void triFusion(int tab[],int );
void fusion(int tab[], int, int, int);
void trier(int tab[], int, int);


int main()
{
  srand(time(NULL));
   
  int t1[N];
  int t2[M];

  initRandom(t1,N);
  initRandom(t2,M);

  
  triFusion(t1,N);
  triFusion(t2,M);
  

  /*  triParSelectionDuMax(t1,N);
      triParSelectionDuMax(t2,M);
      initClavier(t1,N);
      initClavier(t2,M);
      triParBubulles(t1,N);
      triParBubulles(t2,M);
     
  */
   
  

  afficherTabInt( t1,N);
  afficherTabInt( t2,M);
  
  
}


void afficherTabInt( int tab[], int taille)
{
  for (int i = 0 ; i < taille ; i++)
    {
      printf("Dans la case n* %d il y a %d \n", i , tab[i]);
    }
  printf(" ============================================ \n");
}

void initClavier (int tab[], int n)
{
  int i = 0;
  int s= -1;
  while ( i < n)
    {
      scanf("%d", &s);
      if (s >= 0)
	{
	  tab[i] = s;
	  i++;
	}
	
    }

}

void initRandom(int tab[], int n)
{
  for  (int j = 0; j < n ; j++)
    {
      tab[j]  = 10+rand()%90;
    }
  
}


int rechercheTab( int tab[], int n, int x)
{
  int r = -1;
  for (int i = 0 ; i < n ; i++)
    {
      if (tab[i] == x)
	{
	  r = i;
	    }
    }
  return r;
}

int maxTab(int tab[],int n)
{
  int max = tab[0];
  for (int i = 1 ; i < n ; i++)
    {
      if (tab[i] > max)
	{
	  max = tab[i];
	}
    }
  return max;
}


int maxTabPairs(int tab[],int n)
{
  int max = 0;
  for (int i = 1 ; i < n ; i++)
    {
      if (tab[i]%2 == 0 && tab[i] > max)
	{
	  max = tab[i];
	}
    }
  return max;
}


int maxPosTab1(int tab[],int n)
{
return  rechercheTab(tab , n , maxTab(tab,n));
}

int maxPosTab2(int tab[],int n)
{
  int max = tab[0];
  int r = 0;
  for (int i = 1 ; i < n ; i++)
    {
      if (tab[i] > max)
	{
	  max = tab[i];
	  r = i;
	}
    }
  return r;
}

void echangeDernierTab (int tab[], int n,int p)
{
  if ( p < n && p >= 0)
    {
      int a = tab[p];
      tab[p]= tab[n-1],
	tab[n-1] = a;
    }
  else
    {
      printf("Indice non valide");
    }
}

void triParSelectionDuMax (int tab[], int n)
{
  int pos ;
  while ( n >= 1 )
    {
      pos = maxPosTab1(tab,n);
      echangeDernierTab(tab,n,pos);
      n--;
    }
  
  
}

void triParBubulles(int tab[], int n)
{
  while ( n >= 1 )
    {
      for(int i = 0; i < n-1; i ++)
	{
	  if (tab[i] > tab [i+1])
	    {
	      int t = tab[i];
	      tab[i] = tab[i+1];
	      tab[i+1] = t;
	    }
	}
      n--;
    }


}


void triFusion(int tab[],int n)
{
  trier(tab,0,n);
}

void trier(int tab[], int g, int d)
{

  int m = (g+d+1)/2;
    if (m-g > 1)
    {
      trier(tab, g,m);
      }
  if (d-m > 1)
    {
      trier(tab, m,d);
    }


  fusion(tab,g,m,d);
  
  
}

void fusion(int tab[], int g, int m, int d)
{
  printf ("\n g = %d , m = %d , d = %d \n  \n" , g,m,d);
  int g1 = g;
  int m1 = m;
  int n = 0;         

  int tempo[100];
 
   for (int n = g;n < d; n++)
      {
	tempo[n] = tab[n];
	  printf("| %d | ",tempo[n]) ;
      }
   printf("\n");
  while (n < d-g)
    {
     
       if ((m1 >= d) || (tab[g1] < tab[m1] && g1 <=m1 && g1 < m))
	{

	  tempo[g+n] = tab[g1];
	  g1++;
	    
	}
      else  
	{


	  
	   tempo[g+n] = tab[m1];
	  
	   m1++;
	     
	 
	}
      
      
      n++;
       
	}
   for( int j = g ; j < d ; j++)
	{
	  tab[j] = tempo[j];
	  printf("| %d | ",tab[j]) ;
	  }
   printf("\n \n");
}
