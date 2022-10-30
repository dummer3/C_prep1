#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
  int somme = 0;
  for (int i = 0; i <argc; i++)
    {
         somme +=  atoi(argv[i]);
    }

  printf("Somme : %d \n",somme);
  return 0;
}
