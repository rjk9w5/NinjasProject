#ifndef GAUSSIAN_ELIMINATION_SOLVER_H
#define GAUSSIAN_ELIMINATION_SOLVER_H

#include "ALinSysSolver.h"
#include "PivotMethod.h"

template<class T, class TMatrix, PivotMethod TPivotMethod>
class GaussElimSolver: public ALinSysSolver<T, Matrix>
{
public:
  Vector<T> operator(const Matrix& aMatrix, const Vector<T>& bVector);
};


#include "src/GaussElimSolver.hpp"
#endif
