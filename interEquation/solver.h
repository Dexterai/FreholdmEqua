#pragma once

#include <cmath>



struct Par
{
	
};


//y(x) = exp(x) - x - integrate_{0}^{1}x*(exp(x*t) - 1) * y(t)dt
class baseSolver
{
public:
	void function(const Par);
private:
	Par par;
};