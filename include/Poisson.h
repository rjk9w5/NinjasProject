#ifndef POISSON_H
#define POISSON_H

#include "BoundaryCondition.h"
#include "DenseMatrix.h"
#include "Vector.h"
#include "ALinSysSolver.h"

template <class T, class T_ForceFunction>
class Poisson
{
public:
  Poisson(
  const T_ForceFunction func, 
  const ABoundaryCondition<T>& constX, 
  const ABoundaryCondition<T>& constY);
  void solve(const ALinSysSolver<T, BandedMatrix<T>>& solver, const size_t N);
private:
  Vector<ABoundaryCondition<T>&> BC;
  T_ForceFunction f;
};

#include "src/Poisson.hpp"
#endif
