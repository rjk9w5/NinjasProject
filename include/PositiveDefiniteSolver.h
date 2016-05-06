#ifndef POSITIVE_DEFINITE_SOLVER_H
#define POSITIVE_DEFINITE_SOLVER_H

#include "ALinSysSolver.h"
#include "BandedMatrix.h"

template<class T>
class PositiveDefiniteSolver: public ALinSysSolver<T, BandedMatrix<T> >
{
public:
  Vector<T> operator(const BandedMatrix<T>& aMatrix, const Vector<T>& bVector);
};


#include "src/PositiveDefiniteSolver.hpp"
#endif
