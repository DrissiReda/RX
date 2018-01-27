#include "simulate.hpp"

int start()
{
	int c;
	std::cout << "Pour simuler le cout entrez un nombre pair"           <<std::endl;
	std::cout << "Pour simuler le debit entrez un nombre impair"        <<std::endl;
	std::cout << "Pour abandonner entrez un nombre strictement negatif" <<std::endl;
	std::cin >> c;
	if(c<0)
		return 0;
	init();
	if(c%2)
	{
		full_sim_debit();
  		disp_res_debit();
	}
	else
	{
		full_sim_cout();
  		disp_res_cout();
	}
	return 1;
}

int main()
{
  while(start());
  return 0;
}
