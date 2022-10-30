#include <stdio.h>

#define N 10

void maxTab2D(int t[][N] ,int );
  
int main ()
{
  int tab[10][N] = {{5,30,100,-20}};
    maxTab2D(tab,10);

  return 0;
}



void maxTab2D(int tab[][N],int l)
{
  int max = tab[0][0];
  for(int i = 0 ; i < l ;i++)
    {
     for(int j = 0 ; j < N; j++)
       {
	if (tab[i][j] > max)
	  {
	   max = tab[i][j];
	  }
       }
     
    }
 printf("max : %d \n",max);

}
