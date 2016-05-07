//////////////////////////////////////////////////////////////////////
/// @file   Poisson.h
/// @author Ryan Krattiger
/// @brief  A class object for solving the infamous Poisson PDE
//////////////////////////////////////////////////////////////////////

#ifndef POISSON_H
#define POISSON_H

#include "BoundaryCondition.h"
#include "DenseMatrix.h"
#include "Vector.h"
#include "ALinSysSolver.h"
#include "Functor.h"
#include <cmath>

template <class T>
class Poisson
{
public:
  typedef T ValueType;
  typedef size_t SizeType; 
  Poisson(
  const AFunctorxy<T>& func, 
  const ABoundaryCondition<T>& constX, 
  const ABoundaryCondition<T>& constY);

  // DenseMatrix<T> solve(const ALinSysSolver<T, BandedMatrix<T>>& solver, const size_t N);
  DenseMatrix<T> solve(const size_t N);
private:
  Vector<ABoundaryCondition<T>*> BC;
  AFunctorxy<T>& f;
};

#include "src/Poisson.hpp"
#endif
