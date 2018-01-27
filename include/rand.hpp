#ifndef RAND_HPP
#define RAND_HPP

#include <random>

class Random {
public:
	int operator()(int min, int max);
	
	bool operator()(double p);

private:
	std::mt19937 engine{std::random_device{}()};
};

#endif //RAND_HPP
