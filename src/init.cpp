#include "init.hpp"

Random randomize;
std::array<int, Antenne> nb_user; // nombre d'utilisateur par antenne
std::array< std::array<int, Antenne>, Antenne > G;// la matrice G
std::array< std::array<int, Antenne>, BBU > Y; // la matrice qui informe quel RRH est dans quel BBU
std::array< std::array<int, Antenne>, BBU > best_Y; // la matrice qui stock la meilleure config
float best_R=0.0;
std::vector<float> Resultat_C; //stock les resultats des simulations cout
std::vector<float> Resultat_D; //stock les resultats des simulations debit
int BBU1; //nombre d'antenne dans le 1er BBU
int init()
{
	empty_Y();
	init_Y();
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
//initialise la matrice Y a 0
int init_Y()
{
	//initialise la generation de combination a chaque 
	//changement de BBU1
	new_comb(BBU1);
  	pop_Y_2();
}
//@param : BBU1 nombre d'antennes dans le premier BBU (le reste dans le deux)
int pop_Y()
{
  //s'il ne reste aucune combination possible avec BBU1 d'antennes dans le 1er BBU
  //il faut l'incrementer de 1 (la premiere execution renvoie toujours faux 
  // car toutes les valeurs de Y sont a 0
  if(!std::prev_permutation(Y[0].begin(), Y[0].begin()+Antenne))
  {
  	//il faut creer une autre suite de combination quand BBU1 change
  	init_Y();
  	BBU1++;
  	if(BBU1<4)
  		new_comb(BBU1);
  }
  //s'il reste des combinations, changer la deuxieme ligne de Y
  else
  	pop_Y_2();
  return 0;
}
int pop_Y_2()
{
	for(int i=0;i<Antenne;i++)
		Y[1][i]=(Y[0][i]==0)?1:0;
	return 0;
}
int new_comb(int r)
{
  std::fill(Y[0].begin(),Y[0].begin()+r, true);
  pop_Y_2();
  return 0;
}
//Renvoie 1 si l'antenne appartient au BBU, 0 sinon
int in(int nRRH,int nBBU){
  return Y[nBBU-1][nRRH-1]==1;
}

int empty_Y()
{
	BBU1=0;
	std::fill(Y[0].begin(),Y[0].begin()+Antenne, false);
	std::fill(Y[1].begin(),Y[1].begin()+Antenne, true);
}
