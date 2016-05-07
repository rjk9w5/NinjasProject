//////////////////////////////////////////////////////////////////////
/// @file   ALinSysSolver.h
/// @author Ryan Krattiger
/// @brief  Abstract Linear system solver class
//////////////////////////////////////////////////////////////////////

#ifndef ABSTRACT_LINEAR_SYSTEMS_SOLVER_H
#define ABSTRACT_LINEAR_SYSTEMS_SOLVER_H


//////////////////////////////////////////////////////////////////////
/// @fn ALinSysSolver<T, Matrix>::operator()(const Matrix&, const Vector<T>&) const;
/// @brief Abstract solver for linear systems of equations
/// @pre See derived solvers.
/// @param aMatrix The A in Ax = b
/// @param bVector The b in Ax = b
/// @return The solution of the solver, aka, x in Ax = b
//////////////////////////////////////////////////////////////////////

#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @class ALinSysSolver
/// @brief Abstract Functor for calculating the solution to Ax = b
//////////////////////////////////////////////////////////////////////
template<class T, class Matrix>
class ALinSysSolver
{
public:
  virtual Vector<T> operator()(const Matrix& aMatrix, const Vector<T>& bVector) const = 0;
};

namespace iterative
{
  constexpr long double TOLERANCE = 0.00000001; // Tolerance to converge on
}

#endif
