#ifndef INIT_HPP
#define INIT_HPP

#define Antenne 6
#define BBU     2
#define Alpha   0.5
#define NBSIM   20
#define W	    10


#include <array>
#include <algorithm>
#include <iostream>
#include "rand.hpp"
//////////////variables globales
extern Random randomize;
extern std::array<int, Antenne> nb_user;
extern std::array< std::array<int, Antenne>, Antenne > G;
extern std::array< std::array<int, Antenne>, BBU > Y;
extern float Cost;
extern std::vector<float> Resultat_C;
extern std::vector<float> Resultat_D;
////////////fonctions/////////////////////////////
int init();
int pop_nbu(int, int);
int pop_G();
int pop_Y(int);
int in(int nRRH,int nBBU);

#endif //INIT_HPP
