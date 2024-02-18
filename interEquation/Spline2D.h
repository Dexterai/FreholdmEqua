#pragma once

#include "Array.h"
#include "GaussNodes.h"

//used to receive solver's output 
class LarangePoly2D
{
public:
	LarangePoly2D() {}
	LarangePoly2D(
		const array_1d& _xnode,
		const array_1d& _ynode,
		const array_2d& _values)
		:xnodes(_xnode), ynodes(_ynode), values(_values) {}
	~LarangePoly2D() {};

	const array_1d getxNodes()
	{
		return xnodes;
	}

	void setxNodes(const array_1d& xn)
	{
		xnodes = xn;
	}

	const array_1d getyNodes()
	{
		return ynodes;
	}

	void setyNodes(const array_1d& yn)
	{
		ynodes = yn;
	}

	void setValues(const array_2d& v)
	{
		values = v;
	}

	double getxFundPoly(double x, size_t t) const
	{
		fundPoly(xnodes, x, t);
	}

	double getyFundPoly(double y, size_t t) const
	{
		fundPoly(ynodes, y, t);
	}

private:
	//在点x处第k个largange多项式
	double fundPoly(const array_1d& g, double x,size_t k) const;

	array_1d xnodes;
	array_1d ynodes;
	array_2d values;
};


class Spline2D
{
public:

	typedef valarray_2d<LarangePoly2D*> array_2p;
	
	Spline2D(
		const array_1d _xgrid,
		const array_1d _ygrid,
		const array_2p _polys)
		: xgrid(_xgrid), ygrid(_ygrid), polys(_polys) {}

	Spline2D(const Spline2D &spl)
	{
		_copy(spl);
	}
	const Spline2D& operator=(const Spline2D& spl);
	
	~Spline2D();

private:

	void _copy(const Spline2D& spl);

	array_1d xgrid;
	array_1d ygrid;
	//多项式数组
	array_2p polys;
};

