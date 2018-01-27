#include "../include/cout.hpp"

//Calcul du cout d'un RRH
int cout(int nRRH){
  int sum=0;
  int yib;
  for(int i=0;i<BBU;i++){
    yib=in(nRRH,i);
    sum += yib * (sum_users(i) + (1-Alpha) * sum_interferences(nRRH,i));
  }
  std::cout << "Cout: " << sum << std::endl;
  return sum;
}

//Renvoie 1 si l'antenne appartient au BBU, 0 sinon
int in(int nRRH,int nBBU){
  if(Y[nBBU][nRRH-1]==1)
    return 1;
  return 0;
}

//Somme yjb * nj
int sum_users(int nBBU){
  int sum=0;
  for(int i=0;i<Antenne;i++){
    sum += in(i+1,nBBU) * nb_user[i];
  }
  return sum;
}

//Somme Gji * (1 - yjb) + N0
int sum_interferences(int nRRH,int nBBU){
  int sum=0;
  for(int i=0;i<Antenne;i++){
    if(i != nRRH-1)
      sum += G[nRRH-1][i] * (1-in(i+1,nBBU)) + 0.01;
  }
  return sum;
}
