// Russley...comment this
// TODO: Comments!

#ifndef GAUSS_SEIDEL_SOLVER_H
#define GAUSS_SEIDEL_SOLVER_H

#include "ALinSysSolver.h"
#include "BandedMatrix.h"
#include "LpNorm.h"
#include "Vector.h"

template<class T>
class GaussSeidel: public ALinSysSolver<T, BandedMatrix<T> >
{
public:
  Vector<T> operator()(const BandedMatrix<T>& aMatrix, const Vector<T>& bVector);
};


#include "src/GaussSeidel.hpp"
#endif
