#include <iostream>
#include <cmath>
//#include <math.h> 
//#include "Spline2D.h"
#include "FE2Dsolver.h"

#define PI 3.14159265358979323846 //pi

double ker(double x1,double x2, double s1, double s2)
{
	return (sin(s1) * cos(4.0 * x1) * (2.0 - sin(4.0 * s2))) / (2.0 - sin(4.0 * x2));
}

double f(double x1, double x2)
{
	return 2.0 / (2.0 - sin(4.0 * x2));
}

int main()
{
	FE2D::EqData data;
	FE2D::SCSolver::SplineOpts sopts;

	//��������Χ
	double xr[2] = { 0.0, PI };
	double yr[2] = { 0.0, PI };

	//��ʼ��data����
	data.k = ker;
	data.f = f;
	data.a1 = xr[0];
	data.a2 = xr[1];
	data.b1 = yr[0];
	data.b2 = yr[1];

	//��ʼ�� sopts����
	sopts.xnum = 16;
	sopts.ynum = 16;
	sopts.gtype = G8;





	


	return 0;
}