#include <stdio.h>
#include <time.h>


#define N 4
#define M 4

void gauss(float tab[][M],int n);
void affichage(float tab[][M], int n);



int main ()
{
  srand(time(NULL));
  float tab[N][M]= {{2,-3,-5,2},
		    {4,2,1,4},
		    {-3,-1,2,-2},
		    {1,-1,2,-2}} ;

  affichage(tab,N);
  gauss(tab,N);
  affichage(tab,N);

  return 0;
}


void gauss(float tab[][M],int l)
{
  for(int i =0; i< l; i++)
    {
    
      float n = tab[i][i];
      for (int j=i;j<M;j++)
	{
	  tab[i][j] =tab[i][j]/ n;
	}

      for(int k = i+1; k<l; k++)
    
	{
	  float a = - tab[k][i];

	  for(int t=i; t<M;t++)
	    {
	      tab[k][t]  += a*tab[i][t];
	    }

	}


    }


}

void affichage(float tab[][M], int n)
{
  for(int i=0;i< n ;i++)
    {
      for(int j =0 ; j <M; j++)
	{
	  printf(" |%.2f| ",tab[i][j]);

	}

	    printf("\n");
    }

      printf("\n\n");


}


