// Russley...comment this
// TODO: Comments!

#ifndef STEEPEST_DESCENT_SOLVER_H
#define STEEPEST_DESCENT_SOLVER_H

#include "ALinSysSolver.h"
#include "BandedMatrix.h"
#include "LpNorm.h"
#include "Vector.h"

template<class T>
class SteepestDescent: public ALinSysSolver<T, BandedMatrix<T> >
{
public:
  Vector<T> operator()(const BandedMatrix<T>& aMatrix, const Vector<T>& bVector);
};


#include "src/SteepestDescent.hpp"
#endif
