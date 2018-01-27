#include "cout.hpp"

//Calcul du cout d'un RRH
int cout(int nRRH){
  float sum=0.0;
  int yib;
  for(int i=0;i<BBU;i++){
    yib=in(nRRH,i);
    if(yib)
    	sum += yib * (sub_sumA(i) + (1-Alpha) * sub_sumB(nRRH,i));
  }
  std::cout << "Cout: " << sum << std::endl;
  return sum;
}

//Renvoie 1 si l'antenne appartient au BBU, 0 sinon
int in(int nRRH,int nBBU){
  return Y[nBBU][nRRH-1]==1;
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
