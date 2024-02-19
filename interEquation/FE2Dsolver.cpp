#include "FE2Dsolver.h"

Spline2D FE2D::SCSolver::solver(const EqData& data)
{
    size_t xn = opts.xnum;
    size_t yn = opts.ynum;
    //GaussGdType 

    double xr[2] = { data.a1, data.a2 };
    double yr[2] = { data.b1, data.b2 };

    Spline2D spline = createGaussSpline2D(xr, yr, xn, yn, opts.gtype);

    return spline;
}
