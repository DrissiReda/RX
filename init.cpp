#include "init.h"
using namespace std;

int init_G(array A, int i, int j)
{
    array<int> nb_user[Antenne];
    fill_n(nb_user, 0, Antenne, rand()%5+1);
int pop_G(array A
    for(int a=0;a<i;a++)
        for(int b=a;b<j;b++)
        {
            if(a==b) 
            {
                G[a][b]=0;
            }
            else
            {
                G[a][b]=rand()%4+1;
                G[b][a]=G[a][b];
            }
        }
}

int sim(int RRH)
