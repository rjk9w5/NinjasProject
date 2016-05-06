#ifndef GAUSS_SEIDEL_SOLVER_H
#define GAUSS_SEIDEL_SOLVER_H

#include "ALinSysSolver.h"

template<class T, class TMatrix>
class GaussSeidelSolver: public ALinSysSolver<T, Matrix>
{
public:
  Vector<T> operator(const Matrix& aMatrix, const Vector<T>& bVector);
};


#include "src/GaussSeidelSolver.hpp"
#endif
