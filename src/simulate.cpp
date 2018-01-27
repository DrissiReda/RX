#include "simulate.hpp"


//simule le cas où le 1er BBU a BBU1 antenne et le deuxième 6-BBU1
int simulate(int BBU1)
{
	//on remplit la matrice Y selon le cas
	pop_Y(BBU1); 
	// calcul le cout moyen pour ce cas et le stock dans le vecteur resultat
	Resultat.push_back(cout_moyen());  
}
int full_sim()
{
	for(int i=1;i<4;i++)
		simulate(i);
}
int disp_res()
{
	for(int i=0;i<3;i++)
		std::cout <<"Cout moyen de " << i+1 << " et " << 5-i << " est de " << Resultat[i] << std::endl;
	int best=(int)(std::min_element(Resultat.begin(),Resultat.end()) - Resultat.begin());
	std::cout << "Le meilleur cout est " << best+1 << " et " << 5-best << " est de " << Resultat[best] << std::endl;
}
