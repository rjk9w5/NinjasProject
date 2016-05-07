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
#include "SteepestDescent.h"
#include "GaussSeidel.h"
#include "Functor.h"
#include <cmath>

template <class T, class T_XBound, class T_YBound, class T_ForcingFunction>
class Poisson
{
public:
  typedef T ValueType;
  typedef size_t SizeType;

  DenseMatrix<T> solve(const ALinSysSolver<T, BandedMatrix<T>>& solver, const size_t N);
  // DenseMatrix<T> solve(const size_t N);
private:
  T_XBound m_xBound;
  T_YBound m_yBound;
  T_ForcingFunction m_forcingFunc;
};

#include "src/Poisson.hpp"
#endif
