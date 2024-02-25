#pragma once
#include <cmath>
#include "Array.h"
#include "LASolver.h"
#include "Spline2D.h" 

typedef double (*function_1d)(double);
typedef double (*function_2d)(double, double);
typedef double (*function_4d)(double, double, double, double);

namespace FE2D
{
	struct EqData
	{
		function_4d k;   // kernal
		function_2d f;
		double lm;   //lambda
		double a1;   //grid x left
		double a2;   //grid x right
		double b1;	 //grid y left
		double b2;	 //grid y right
	};


	//y(x) = exp(x) - x - integrate_{0}^{1}x*(exp(x*t) - 1) * y(t)dt
	class baseSolver
	{
	public:
		baseSolver(LA::LASolver* _laSolver)
			:laSolver(_laSolver) {}
		virtual ~baseSolver() {}
		//每新增一个解法都需要重写该solver
		virtual Spline2D solver(const EqData& data) = 0;

	protected:
		LA::LASolver* laSolver;
	};

	class SCSolver : public baseSolver
	{
	public:

		struct SplineOpts
		{
			size_t xnum;
			size_t ynum;
			GaussGdType gtype;
		};

		SCSolver(LA::LASolver* _laSolver, const SplineOpts& _opts)
			: baseSolver(_laSolver), opts(_opts){}

		Spline2D solver(const EqData& data);
	private:
		SplineOpts opts;
	};

	class FSSolver : public baseSolver
	{

	};

}
