#ifndef SIM_HPP
#define SIM_HPP

#include "cout.hpp"
#include "debit.hpp"

float simulate_cout();
int   full_sim_cout();
int   disp_res_cout();


float simulate_debit();
int   full_sim_debit();
int   disp_res_debit();

int   save_best_Y(std::vector<float> A, char val);
#endif //SIM_HPP
