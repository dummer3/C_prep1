#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void majuscule(char* source, char* destination);

int main(int argc , char* argv[])
{
  char phrase[100];
 
  if (argc == 7)
    {
      majuscule(argv[2],argv[2]);
      majuscule(argv[5],argv[5]);
      
      if (atoi(argv[3]) <= atoi(argv[6]))
	{
	  sprintf(phrase,"le plus agé est : %s %s (%s ans) \n",argv[4],argv[5],argv[6]);

	}
      else
	{
	  sprintf(phrase,"le plus agé est : %s %s (%s ans) \n",argv[1],argv[2],argv[3]);
	}

      printf("%s", phrase);


      if (strcmp(argv[2], argv[5]) <= 0)
	{
	  printf("%s \n",argv[2]);
	}
    
	else
	  {
	    printf("%s \n",argv[2]);
	  }
	    
         
    }
  else
    {
      printf("Nombre invalide de parametres \n ");


    }

  return 0;
}

void majuscule(char* source, char* destination)
{
  int t = strlen(source);
  for(int i = 0 ; i < t; i++)
    {
      if(source[i] >= 'a' && source[i] <= 'z')
	{
	  destination[i] = source[i] + 'A' - 'a';
	}
      else
	{
	  destination[i] = source[i];
	}
    }


}
