//////////////////////////////////////////////////////////////////////
/// @file SteepestDescent.h
/// @author Russley Shaw & Ryan Krattiger
/// @brief Linear Systems Solver using Steepest Descent approach
//////////////////////////////////////////////////////////////////////

#ifndef STEEPEST_DESCENT_SOLVER_H
#define STEEPEST_DESCENT_SOLVER_H

#include "ALinSysSolver.h"
#include "BandedMatrix.h"
#include "LpNorm.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn operator()(const BandedMatrix<T>&, const Vector<T>&) const;
/// @brief Operate & perform Steepest Descent solver
/// @pre
/// @param aMatrix The A in Ax=b
/// @param bVector The b in Ax=b
/// @return Vector<T> The x in Ax = b
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class SteepestDescent
/// @brief Linear Systems Solver functor using Steepest Descent approach
//////////////////////////////////////////////////////////////////////
template<class T>
class SteepestDescent: public ALinSysSolver<T, BandedMatrix<T> >
{
public:
  Vector<T> operator()(const BandedMatrix<T>& aMatrix, const Vector<T>& bVector) const;
};


#include "src/SteepestDescent.hpp"
#endif
