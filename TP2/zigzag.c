# include <stdio.h>


void zigzag (int a, int b, int c)
{
  for(int i = a; i <= b; i++)
    {
      if (i%2 == 0)
	{
	  printf("%d ",i);
	}
      for(int j = 0; j < c ; j++)
	{
	  printf("z");
      
	}
      printf("igzag ");
   
      
      if (i%2 == 1)
	{
	  printf("%d",i);
	}
	   printf("\n");
    }
}

int main ()
{
  int a,b,c;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  
  zigzag(a,b,c);
  return 0;
    }

