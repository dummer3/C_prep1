# include <stdio.h>

void espace(int);
void espaceXespace(int);
void espaceXespaceXespace(int,int);
int main (){
  
  int n;
  scanf("%d", &n);
  
  
  for (int l = n+1; l>0 ; l--)
    {
      for (int p = 0 ; p < n;p++)
	{
	  if (l > p+2 )
	    {
	      int largeur = 2+p*2;
	      espace(largeur);
	    }
	 else if (l == p+2 )
	    {
	      int espace = (2+p*2)/2;
	      espaceXespace (espace);
	    }
	
      else
	{
	  int millieu =2+(p+1-l)*2;
	  int a = l-1;
	  espaceXespaceXespace(a,millieu);
	}
    }
      printf("\n");
    }
  
  return 0;
}

void espace(int l)
{
  for(int i = 0 ; i < l; i++)
    {
      printf(" ");
    }

}

void espaceXespace (int e)
{
  for (int i = 0 ; i < e ; i++)
	    {
	      printf(" ");
		}
  printf("*");
  for (int i = 0 ; i < e ; i++)
	    {
	      printf(" ");
		}
  
}


void espaceXespaceXespace (int a, int millieu)
{
  for (int i = 0 ; i < a ; i++)
    {
      printf("-");
    }
  
  printf("*");
    
  for (int m = 1 ; m < millieu ; m++)
    {
      printf("+");
    }
  printf("*");
  for (int i = 1 ; i < a ; i++)
    {
      printf("-");
    }
  
}
