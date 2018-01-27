#ifndef INIT_HPP
#define INIT_HPP

#define Antenne 6
#define BBU     2
#include <array>
#include <algorithm>
#include <iostream>
#include "rand.hpp"

extern Random randomize;
extern std::array<int, Antenne> nb_user;
extern std::array< std::array<int, Antenne>, Antenne > G;
extern std::array< std::array<int, Antenne>, BBU > Y;
extern float Cost;

int init_all();
int pop_nbu(int, int);
int pop_G();
int pop_Y();

#endif //INIT_HPP
