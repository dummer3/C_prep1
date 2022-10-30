# include <stdio.h>
struct score;
typedef  struct score score;
void afficheScore (score sco);
void ajouteBut(score * pSurScore,char equipe);

struct score {
  int butEquDom;
  int butEquExt;

};

int main ()
{
  
  score s = {3,5};
  s.butEquDom = 10;
  ajouteBut(&s,'e');
  afficheScore(s);

  return 0 ;
}

void afficheScore (score sco)
{
  printf("Le score est de : %d pour l'équipe à domicile et : %d pour l'équipe extérieur \n", sco.butEquDom,sco.butEquExt);

}


void ajouteBut(score * pSurScore,char equipe)
{
  if (equipe == 'd')
    {
      pSurScore->butEquDom++;
    }
  else
    {
        pSurScore->butEquExt++;
    }
}
