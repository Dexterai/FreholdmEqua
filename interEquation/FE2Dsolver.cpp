#include "FE2Dsolver.h"

Spline2D FE2D::SCSolver::solver(const EqData& data)
{
    size_t nx = opts.xnum;
    size_t ny = opts.ynum;
    //GaussGdType 

    double xr[2] = { data.a1, data.a2 };
    double yr[2] = { data.b1, data.b2 };

    Spline2D spline = createGaussSpline2D(xr, yr, nx, ny, opts.gtype);
    Spline2D::array_2p& polynoms = spline.getPolys();
    array_1d& splYGrid = spline.getYGrid();
    array_1d& splXGrid = spline.getXGrid();

    size_t r = polynoms[0][0]->getxNodes().size();
    size_t sys_sz = nx * ny * r * r;

    array_1d sys_fvector(sys_sz);
    array_2d sys_matrix(sys_sz, sys_sz);

    //初始化右边向量
    for (size_t i = 0; i < nx; ++i)
    {
        for (size_t j = 0; j < ny; ++j)
        {
             LarangePoly2D* coply = polynoms[i][j];
             const array_1d& xgrid = coply->getxNodes();
             const array_1d& ygrid = coply->getyNodes();

             for (size_t k = 0; k < r; ++k)
             {
                 for (size_t p = 0; p < r; ++p)
                 {
                     size_t index = i * ny * r * r + j * r * r + k * r + p;
                     sys_fvector[index] = data.f(xgrid[k], ygrid[p]);
                 }
             }

        }
    }

    //填写系统矩阵M_ij
    


    return spline;
}
