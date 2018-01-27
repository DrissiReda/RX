#include "../include/init.hpp"

Random randomize;
std::array<int, Antenne> nb_user;
std::array< std::array<int, Antenne>, Antenne > G;
std::array< std::array<int, Antenne>, BBU > Y;
float Cost=0.0;


int init_all()
{
   	pop_nbu(1,5);
    pop_G();
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
int pop_Y()
{
  for(int i=0;i<BUU;i++){
    for(int j=0;j<Antenne;j++){
      Y[i][j]=0;
    }
  }
  for(int i=0;i<Antenne;i++){
    int b = randomize(1,BBU);
    Y[b-1][i]=1;
  }
  for(int i=0;i<BUU;i++){
    for(int j=0;j<Antenne;j++){
      std::cout << Y[i][j] << " ";
      //printf("%d ",);
    }
    std::endl;
  }
}
int sim(int RRH)
{

	return 0;
}
