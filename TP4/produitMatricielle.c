#include <stdio.h>
#include <time.h>
#define N 2
#define M 4
#define U 4
#define V 2


void produit(int m1[][N],int m2[][M],int t1,int t2);
void assignation1 (int m[][N], int t);
void assignation2 (int  m[][M], int t);

int main ()
{
 srand(time(NULL));
  int t1[U][N];
  int t2[V][M];
  assignation1(t1,U);
  assignation2(t2,V);
  produit(t1,t2,U,V);
  return 0;


}


void produit(int m1[][N],int m2[][M],int t1,int t2)
{
  int somme;
  int m3[t1][M];
  if(N == t2)
    {
      for (int i =0 ; i< t1 ; i++)
	{
	  for (int j= 0; j  < M; j++)
	    {
	      somme = 0;
	      for (int k = 0; k < N; k++)
	      {
		somme += m1[i][k] * m2 [k][j];


	      }
	      m3 [i][j] = somme;
	      printf(" |%3d| ",m3[i][j]);
	      
	    }
	  printf("\n"); 
	}

    }

  else
    {
      printf("produit matricielle impossible ! \n ");
    }

}

void assignation1 (int  m[][N], int t)
{
  for (int i = 0 ; i < t; i++)
    {
      for (int j = 0; j < N; j++)
	{
	  m[i][j] = rand() % 10;
	  	    printf(" |%2d| ",m[i][j]);
	}
	  printf("\n"); 
    }
	  printf("\n\n"); 

}

void assignation2 (int  m[][M], int t)
{
  for (int i = 0 ; i < t; i++)
    {
      for (int j = 0; j < M; j++)
	{
	  m[i][j] = rand() % 10;
	    printf(" |%2d| ",m[i][j]);
	}
      	  printf("\n"); 

    }

	  printf("\n\n"); 
}
