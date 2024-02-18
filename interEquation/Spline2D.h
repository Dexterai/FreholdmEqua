#pragma once

#include "Array.h"

//used to receive solver's output 
class LarangePoly2D
{
public:
	LarangePoly2D();
	LarangePoly2D(
		const array_1d& _xnode,
		const array_1d& _ynode)
		:xnodes(_xnode), ynodes(_ynode) {}
	~LarangePoly2D() {};

private:
	array_1d xnodes;
	array_1d ynodes;
};


class Spline2D
{
public:
	

private:
	array_1d xgrid;
	array_1d ygrid;

};

