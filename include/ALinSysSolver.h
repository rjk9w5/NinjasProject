//////////////////////////////////////////////////////////////////////
/// @file   ALinSysSolver.h
/// @author Ryan Krattiger
/// @brief  Abstract Linear system solver class
//////////////////////////////////////////////////////////////////////

#ifndef ABSTRACT_LINEAR_SYSTEMS_SOLVER_H
#define ABSTRACT_LINEAR_SYSTEMS_SOLVER_H

#include "Vector.h"

template<class T, class Matrix>
class ALinSysSolver 
{
public:
  virtual Vector<T> operator()(const Matrix& aMatrix, const Vector<T>& bVector) const = 0;
};

namespace iterative
{
  constexpr long double TOLERANCE = 0.00000001; 
}

#endif