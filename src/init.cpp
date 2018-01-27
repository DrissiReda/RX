#include "init.hpp"

Random randomize;
std::array<int, Antenne> nb_user; // nombre d'utilisateur par antenne
std::array< std::array<int, Antenne>, Antenne > G;// la matrice G
std::array< std::array<int, Antenne>, BBU > Y; // la matrice qui informe quel RRH est dans quel BBU
float Cost=0.0;
std::vector<float> Resultat_C; //stock les resultats des simulations cout
std::vector<float> Resultat_D; //stock les resultats des simulations debit
int init()
{
	Resultat_C.clear();
	Resultat_D.clear();
   	pop_nbu(1,5);
	return 0;
}
int pop_nbu (int min, int max)
{
	for (int i=0;i<Antenne;i++)
		nb_user[i]=randomize(min, max);
	return 0;
}
int pop_G()
{
    for(int a=0;a<Antenne;a++)
        for(int b=a;b<Antenne;b++)
        {
            if(a==b)
            {
                G[a][b]=0;
            }
            else
            {
                G[a][b]=randomize(1,4);
                G[b][a]=G[a][b];
            }
        }
   return 0;
}
//@param : BBU1 nombre d'antennes dans le premier BBU (le reste dans le deux)
int pop_Y(int BBU1)
{
  for(int i=0;i<BBU;i++){ //initialisation de la matrice à 0
    for(int j=0;j<Antenne;j++){
      Y[i][j]=0;
    }
  }

  for(int i=0;i<Antenne;i++){ //attribue les antennes aux BBU selon le paramètre
    if(i<BBU1)
      Y[0][i]=1;
    else
      Y[1][i]=1;
  }
  return 0;
}

//Renvoie 1 si l'antenne appartient au BBU, 0 sinon
int in(int nRRH,int nBBU){
  return Y[nBBU-1][nRRH-1]==1;
}

int sim(int RRH)
{

	return 0;
}
