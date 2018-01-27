#include "../include/debit.hpp"

float debit(int nBBU){
  float sum=0.0;
  int yib;
  for(int i=0;i<Antenne;i++){
    yib=in(i+1,nBBU);
    if(yib)
    	sum += yib * ( (log(1+sub_sumA(nBBU,i+1))/log(2)) / sub_sumB(nBBU) );
  }
  std::cout << "Debit: " << sum << std::endl;
  return sum;
}

//Renvoie 1 si l'antenne appartient au BBU, 0 sinon


//Somme Gji (1 - yjb) , j!=i
float sub_sumA(int nBBU,int nRRH){
  float sum=0.0;
  for(int i=0;i<Antenne;i++){
    if(i != nRRH)
      sum += G[nRRH][i] * in(i+1,nBBU);
  }
  return sum;
}

//Somme yjb * nj
float sub_sumB(int nBBU){
  float sum=0.0;
  for(int i=0;i<Antenne;i++){
    sum += in(i+1,nBBU) * nb_user[i];
  }
  return sum;
}
