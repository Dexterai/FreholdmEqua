#include "Spline2D.h"
#include "GaussNodes.h"


double LarangePoly2D::fundPoly(const array_1d& g, double x, size_t k) const
{
    double tmp = 1.0;
    for (size_t i = 0; i < g.size(); ++i)
    {
        if (i == k) continue;
        tmp *= (x - g[i]) / (g[k] - g[i]);
    }
    return tmp;
}

const Spline2D& Spline2D::operator=(const Spline2D& spl)
{
    if (this == &spl) return *this;
    _copy(spl);
    return *this;
}

double Spline2D::operator()(double x, double y) const
{
    return 0.0;
}

Spline2D::~Spline2D()
{
    for (size_t i = 0; i < polys.row(); i++)
    {
        for (size_t j = 0; j < polys.col(); j++)
        {
            delete polys[i][j];
        }
    }
}

void Spline2D::_copy(const Spline2D& spl)
{
    xgrid = spl.xgrid;
    ygrid = spl.ygrid;

    const array_2p& tmpPolys = spl.polys;
    polys = array_2p(tmpPolys.row(), tmpPolys.col());

    for (size_t i = 0; i < tmpPolys.row(); i++)
    {
        for (size_t j = 0; j < tmpPolys.col(); j++)
        {
            polys[i][j] = new LarangePoly2D(*tmpPolys[i][j]);
        }
    }
}

void setupGaussGrid(LarangePoly2D &poly, const double xval[2], const double yval[2], GaussGdType gtype)
{
    size_t gsize = (size_t)gtype;
    array_1d xnodes(gsize);
    array_1d ynodes(gsize);

    GaussNodes gNodes(gtype);
    const double* gnodes = gNodes.getGnode();
    for (size_t i = 0; i < gsize; ++i)
    {
        xnodes[i] = (xval[0] + xval[1]) / 2 + (xval[1] - xval[0]) / 2 * gnodes[i];
        ynodes[i] = (yval[0] + yval[1]) / 2 + (yval[1] - yval[0]) / 2 * gnodes[i];
    }

    poly.setxNodes(xnodes);
    poly.setyNodes(ynodes);
}

Spline2D createGaussSpline2D(const double xval[2],const double yval[2], size_t xnum, size_t ynum, GaussGdType gtype)
{
    array_1d xnodes(xnum);
    array_1d ynodes(ynum);

    double xstep = (xval[1] - xval[0]) / (xnum - 1);
    double ystep = (yval[1] - yval[0]) / (ynum - 1);

    for (size_t i = 0; i < xnum; ++i)
    {
        xnodes[i] = xval[0] + i * xstep;
    }

    for (size_t j = 0; j < ynum; ++j)
    {
        ynodes[j] = yval[0] + j * ystep;
    }

    Spline2D::array_2p arrayPoly(xnum - 1, ynum - 1);

    for (size_t i = 0; i < xnum - 1; ++i)
    {
        const double xr[2] = { xnodes[i], xnodes[i + 1] };
        for (size_t j = 0; j < ynum - 1; ++j)
        {
            const double yr[2] = { ynodes[j], ynodes[j + 1] };

            LarangePoly2D* coply = new LarangePoly2D();
            setupGaussGrid(*coply, xr, yr, gtype);

            arrayPoly[i][j] = coply;
        }
    }

    return Spline2D(xnodes, ynodes, arrayPoly);
}