//////////////////////////////////////////////////////////////////////
/// @file header.h
/// @author Your name and class section here
/// @brief A brief description of the file
////////////////////////////////////////////////////////////////////// 

#ifndef GAUSS_SEIDEL_SOLVER_H
#define GAUSS_SEIDEL_SOLVER_H

#include "ALinSysSolver.h"
#include "BandedMatrix.h"
#include "LpNorm.h"
#include "Vector.h"

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
