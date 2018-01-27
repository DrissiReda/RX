#include "../include/cout.hpp"

//Calcul du cout d'un RRH
float cout(int nRRH){
  float sum=0.0;
  int yib;
  for(int i=0;i<BBU;i++){
    yib=in(nRRH,i+1);
    if(yib)
    	sum += yib * (sub_sumA(i+1) + (1-Alpha) * sub_sumB(nRRH,i+1));
  }
  return sum;
}

//Somme yjb * nj
float sub_sumA(int nBBU){
  float sum=0.0;
  for(int i=0;i<Antenne;i++){
    sum += in(i+1,nBBU) * nb_user[i];
  }
  return sum;
}

//Somme Gji * (1 - yjb) + N0
float sub_sumB(int nRRH,int nBBU){
  float sum=0.0;
  for(int i=0;i<Antenne;i++){
    if(i != nRRH-1)
      sum += G[nRRH-1][i] * (1-in(i+1,nBBU)) + 0.01;
  }
  return sum;
}
//calcul du cout total
float cout_total()
{
	float res=0.0;
	for(int i=0;i<Antenne;i++)
		res+=cout(i);
	return res;
}

//calcul du cost moyen pour un certain RRH 
float cout_moyen()
{
	
	float res=0.0;
	for(int i=0;i<NBSIM;i++)
	{
		//on génère une nouvelle matrice G à chaque fois 
		pop_G();
		res+=cout_total();
	}
	return res/20;
}
