//////////////////////////////////////////////////////////////////////
/// @file   test_Vector.h
/// @author Russley Shaw
/// @brief  Unit tests for Vector<T>
//////////////////////////////////////////////////////////////////////

#ifndef TEST_POISSON_H
#define TEST_POISSON_H

#include <iostream>

#include "Poisson.h"
#include "BoundaryCondition.h"
#include "Functor.h"
#include "DenseMatrix.h"

// Information Provided for the Boundary Conditions were Y is constant and X
//   is constant respectively...

class Forcing: AFucntorxy<double>
{
public:
  double operator()(const double& x, const double& y)
  {
    return -2*(x*x + y*y);
  }
};

class ConstY: ABoundaryCondition<double>
{
  double upper(const double x)
  {
    return 1 - x*x;
  }

  double lower(const double x)
  {
    return 2*(1 - x*x);
  }

  double upper_bound()
  {
    return 1;
  }

  double lower_bound()
  {
    return 0;
  }
};

class ConstX: ABoundaryCondition<double>
{
  double upper(const double y)
  {
    return 0;
  }

  double lower(const double y)
  {
    return 1 + y*y;
  }

  double upper_bound()
  {
    return 1;
  }

  double lower_bound()
  {
    return 0;
  }
};

void test_Poisson()
{
  int N = 10;
  Poisson<double> P(Forcing& F, ConstX& bc1, ConstY& bc2);
  DenseMatrix<double> exact(N,N), numeric;

  numeric = P.solve(ALinSysSolver<double, BandedMatrix<double>>& blank, N);

  // std::cout << numeric << '\n';

  return;
}