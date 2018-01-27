#include "simulate.hpp"


//simule le cas où le 1er BBU a BBU1 antenne et le deuxième 6-BBU1
//cout
int simulate_cout(int BBU1)
{
	//on remplit la matrice Y selon le cas
	pop_Y(BBU1); 
	// calcul le cout moyen pour ce cas et le stock dans le vecteur resultat
	Resultat_C.push_back(cout_moyen());  
}
//debit
int simulate_debit(int BBU1)
{
	//on remplit la matrice Y selon le cas
	pop_Y(BBU1); 
	// calcul le debit moyen pour ce cas et le stock dans le vecteur resultat
	Resultat_D.push_back(debit_moyen());  
}
//Simule tous les cas et stock le resultat dans le vecteur approprie
//cout
int full_sim_cout()
{
	for(int i=1;i<4;i++)
		simulate_cout(i);
}
//debit
int full_sim_debit()
{
	for(int i=1;i<4;i++)
		simulate_debit(i);
}
//affichage resultat

//cout
int disp_res_cout()
{
	for(int i=0;i<3;i++)
		std::cout <<"Cout moyen de " << i+1 << " et " << 5-i << " est de " << Resultat_C[i] << std::endl;
	int best=(int)(std::min_element(Resultat_C.begin(),Resultat_C.end()) - Resultat_C.begin());
	std::cout << "Le meilleur cout est " << best+1 << " et " << 5-best << " est de " << Resultat_C[best] << std::endl;
}
//debit
int disp_res_debit()
{
	for(int i=0;i<3;i++)
		std::cout <<"Debit moyen de " << i+1 << " et " << 5-i << " est de " << Resultat_D[i] << std::endl;
	int best=(int)(std::max_element(Resultat_D.begin(),Resultat_D.end()) - Resultat_D.begin());
	std::cout << "Le meilleur debit est " << best+1 << " et " << 5-best << " est de " << Resultat_D[best] << std::endl;
}
