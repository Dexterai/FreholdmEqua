#pragma once
#include "Array.h"

namespace LA
{

	class LASolver
	{
	public:
		
		virtual ~LASolver() {}

		virtual array_1d Solver() = 0;

	};

	class FGDSolver :public LASolver
	{
	public:
		array_1d Solver() {}
	};

	


}