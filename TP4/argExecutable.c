#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i;
    printf("Valeur de argc: %d\n", argc);
    for (i=0; i<argc; i++)
    {
      int taille = strlen(argv[i]);
      printf("Argu. n° %d: %s de taille %d\n", i, argv[i],taille);
	
    }
    return 0;
}
