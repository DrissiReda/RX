#include "simulate.hpp"


//simule le cas où le 1er BBU a BBU1 antenne et le deuxième 6-BBU1
//cout
float simulate_cout()
{
	//on remplit la matrice Y selon le cas
	pop_Y();
	// calcul le cout moyen pour ce cas et le stock dans le vecteur resultat
	Resultat_C.push_back(cout_moyen());
	save_best_Y(Resultat_C,'C');
	return Resultat_C.back();
}
//debit
float simulate_debit()
{
	//on remplit la matrice Y selon le cas
	pop_Y();
	// calcul le debit moyen pour ce cas et le stock dans le vecteur resultat
	Resultat_D.push_back(debit_moyen());
	save_best_Y(Resultat_D,'D');
	return Resultat_D.back();
}
int save_best_Y(std::vector<float> A, char val)
{
	if(A.size()<2)
	{
		std::next_permutation(Y[0].begin(), Y[0].begin()+Antenne);
		pop_Y_2();
		best_Y=Y;
		std::prev_permutation(Y[0].begin(), Y[0].begin()+Antenne);
		pop_Y_2();
		best_R=A[0];
	}
	else
		switch(val)
		{
			case 'C' :
				if(A.back() < best_R)
					{
						std::next_permutation(Y[0].begin(), Y[0].begin()+Antenne);
						pop_Y_2();
						best_Y=Y;
						std::prev_permutation(Y[0].begin(), Y[0].begin()+Antenne);
						pop_Y_2();
						best_R=A.back(); 
						
					}
				break;
			case 'D' :
				if(A.back() > best_R)
					{
						std::next_permutation(Y[0].begin(), Y[0].begin()+Antenne);
						pop_Y_2();
						best_Y=Y;
						std::prev_permutation(Y[0].begin(), Y[0].begin()+Antenne);
						pop_Y_2();
						best_R=A.back(); 
					}
				break;
		}
}
//Simule tous les cas et stock le resultat dans le vecteur approprie
//cout
int full_sim_cout()
{
	while(BBU1<4)
	{
		std::cout <<"Cout moyen : config ";
		std::cout <<"BBU1 [ ";
		for(int j=0;j<Antenne;j++)
			std::cout << Y[0][j] << " ";
		std::cout <<"] BBU2 [ ";
		for(int j=0;j<Antenne;j++)
			std::cout << Y[1][j] << " ";
		std::cout << " ] est de " << simulate_cout() << std::endl;
	}
}
//debit
int full_sim_debit()
{
	while(BBU1<4)
	{
		std::cout <<"Cout moyen : config ";
		std::cout <<"BBU1 [ ";
		for(int j=0;j<Antenne;j++)
			std::cout << Y[0][j] << " ";
		std::cout <<"] BBU2 [ ";
		for(int j=0;j<Antenne;j++)
			std::cout << Y[1][j] << " ";
		std::cout << " ] est de " << simulate_debit() << std::endl;
	}
}
//affichage resultat

//affichage de la meilleure config
int disp_best_Y()
{
	std::cout << "La meilleure config est " << std::endl;
	std::cout << "RRH  1 2 3 4 5 6" << std::endl;
	std::cout << "================" << std::endl;
	for(int i=0;i<BBU;i++)
	{
		std::cout << "BBU" << i+1 << " ";
		for(int j=0;j<Antenne;j++)
			std::cout << best_Y[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
//cout
int disp_res_cout()
{
	int best=(int)(std::min_element(Resultat_C.begin(),Resultat_C.end()) - Resultat_C.begin());
	std::cout << "Le meilleur cout est de " << Resultat_C[best] << std::endl;
	std::cout << std::endl;
	disp_best_Y();
}
//debit
int disp_res_debit()
{
	int best=(int)(std::max_element(Resultat_D.begin(),Resultat_D.end()) - Resultat_D.begin());
	std::cout << "Le meilleur debit est de " << Resultat_D[best] << std::endl;
	std::cout << std::endl;
	disp_best_Y();
}
