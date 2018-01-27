#include "debit.hpp"

//Calcul du debit d'un BBU
float debit(int nBBU){
  float sum=0.0;
  int yib;
  for(int i=0;i<Antenne;i++){
    yib=in(i+1,nBBU);
    if(yib)
    	sum += yib * ( (log(1+sub_sumF(nBBU,i+1))/log(2)) / sub_sumG(nBBU) );
  }
  return W*sum;
}

//Somme Gji (1 - yjb) , j!=i
float sub_sumF(int nBBU,int nRRH){
  float sum=0.0;
  for(int i=0;i<Antenne;i++){
    if(i != nRRH)
      sum += G[nRRH][i] * in(i+1,nBBU);
  }
  return sum;
}

//Somme yjb * nj
float sub_sumG(int nBBU){
  float sum=0.0;
  for(int i=0;i<Antenne;i++){
    sum += in(i+1,nBBU) * nb_user[i];
  }
  return sum;
}
//calcul du debit total
float debit_total()
{
	float res=0.0;
	for(int i=0;i<Antenne;i++)
		res+=debit(i);
	return res;
}

//calcul du cost moyen pour un certain RRH 
float debit_moyen()
{
	
	float res=0.0;
	for(int i=0;i<NBSIM;i++)
	{
		//on génère une nouvelle matrice G à chaque fois 
		pop_G();
		res+=debit_total();
	}
	return res/20;
}
