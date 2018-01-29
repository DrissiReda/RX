#include "simulate.hpp"


//simule le cas où le 1er BBU a BBU1 antenne et le deuxième 6-BBU1
//cout
int simulate_cout()
{
	//on remplit la matrice Y selon le cas
	pop_Y(); 
	// calcul le cout moyen pour ce cas et le stock dans le vecteur resultat
	Resultat_C.push_back(cout_moyen());  
	save_best_Y(Resultat_C,'C');
}
//debit
int simulate_debit()
{
	//on remplit la matrice Y selon le cas
	pop_Y(); 
	// calcul le debit moyen pour ce cas et le stock dans le vecteur resultat
	Resultat_D.push_back(debit_moyen());
	save_best_Y(Resultat_D,'D');  
}
int save_best_Y(std::vector<float> A, char val)
{
	if(A.size()<2)
	{
		best_Y=Y;
	}
	switch(val)
	{
		case 'C' : 	
			if(A.back() < *(A.end()-2))
				best_Y=Y;
			break;
		case 'D' :
			if(A.back() > *(A.end()-2))
				best_Y=Y;
			break;
	}
}
//Simule tous les cas et stock le resultat dans le vecteur approprie
//cout
int full_sim_cout()
{
	while(BBU1<4)
		simulate_cout();
}
//debit
int full_sim_debit()
{
	while(BBU1<4)
		simulate_debit();
}
//affichage resultat

//affichage de la meilleure config
int disp_best_Y()
{
	std::cout << "La meilleure config est de " << std::endl;
	for(int i=0;i<BBU;i++)
	{
		for(int j=0;j<Antenne;j++)
			std::cout << best_Y[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}
//cout
int disp_res_cout()
{
	for(int i=0;i<Resultat_C.size();i++)
		std::cout <<"Cout moyen de " << i << "est de " << Resultat_C[i] << std::endl;
	int best=(int)(std::min_element(Resultat_C.begin(),Resultat_C.end()) - Resultat_C.begin());
	std::cout << "Le meilleur cout est de " << Resultat_C[best] << std::endl;
	disp_best_Y();
}
//debit
int disp_res_debit()
{
	for(int i=0;i<3;i++)
		std::cout <<"Debit moyen est de " << Resultat_D[i] << std::endl;
	int best=(int)(std::max_element(Resultat_D.begin(),Resultat_D.end()) - Resultat_D.begin());
	std::cout << "Le meilleur debit est de " << Resultat_D[best] << std::endl;
	disp_best_Y();
}
