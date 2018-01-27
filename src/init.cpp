#include "../include/init.hpp"

Random randomize;
std::array<int, Antenne> nb_user;
std::array< std::array<int, Antenne>, BBU > G;
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
    for(int a=0;a<BBU;a++)
        for(int b=0;b<Antenne;b++)
        {
            if(a==b) 
            {
                G[a][b]=0;
            }
            else
            {
                G[a][b]=randomize(1,5);
                G[b][a]=G[a][b];
            }
        }
   return 0;
}
int sim(int RRH)
{
	return 0;
}
