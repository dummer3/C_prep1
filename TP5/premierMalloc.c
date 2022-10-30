#include <stdio.h>
#include <stdlib.h>


void initialiseDeuxEnDeux(int * t, int n,int debut);
void afficheTab(int * tab,int n);
  int main()
{
  int n, debut;
  int * t ;
  printf ("N vaut ?");
  scanf("%d",&n);
  printf ("Debut vaut ?");
  scanf("%d",&debut);

  t = (int*) malloc(n*sizeof (int));
  initialiseDeuxEnDeux(t,n,debut);
  afficheTab(t,n);
  
  return 0;
}

void initialiseDeuxEnDeux(int * t, int n,int debut)
{
  t[0] = debut;
  for (int i = 1; i < n; i++)
    {
      t[i] = t[i-1]+2;

	}

}

void afficheTab(int * tab,int n)
{
  for (int i =0; i<n ; i++)
    {
      printf("|%d|",tab[i]);


    }


}
