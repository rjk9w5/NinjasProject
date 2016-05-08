//////////////////////////////////////////////////////////////////////
/// @file GaussSeidel.h
/// @author Russley Shaw & Ryan Krattiger
/// @brief Functor solver implementing GaussSeidel
//////////////////////////////////////////////////////////////////////

#ifndef GAUSS_SEIDEL_SOLVER_H
#define GAUSS_SEIDEL_SOLVER_H

#include "ALinSysSolver.h"
#include "BandedMatrix.h"
#include "LpNorm.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn operator()(const BandedMatrix<T>&, const Vector,T>&) const;
/// @brief Performs linear sys solver operations
/// @pre Given matrix must be linearly independent
/// @param aMatrix The A in Ax=b
/// @param bVector The b in Ax=b
/// @return Vector<T>, the x in Ax=b
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class GaussSeidel
/// @brief Functor solver implementing GaussSeidel
//////////////////////////////////////////////////////////////////////
template<class T>
class GaussSeidel: public ALinSysSolver<T, BandedMatrix<T> >
{
public:
  Vector<T> operator()(const BandedMatrix<T>& aMatrix, const Vector<T>& bVector) const;
};


#include "src/GaussSeidel.hpp"
#endif
