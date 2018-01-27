#ifndef INC_2048PP_INC_RANDOM_HPP
#define INC_2048PP_INC_RANDOM_HPP

#include <random>

class Random {
public:
	int operator()(int min, int max);
	
	bool operator()(double p);

private:
	std::mt19937 engine{std::random_device{}()};
};

#endif //INC_2048PP_INC_RANDOM_HPP
