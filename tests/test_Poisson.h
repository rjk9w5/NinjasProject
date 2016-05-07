//////////////////////////////////////////////////////////////////////
/// @file   test_Poisson.h
/// @author Ryan Krattiger
/// @brief  Unit tests for Poisson<T>
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

class Forcing: public AFunctorxy<double>
{
public:
  virtual double operator()(const double& x, const double& y)
  {
    return -2*(x*x + y*y);
  }
};

class ConstY: public ABoundaryCondition<double>
{
public:
  virtual double upper(const double &x)
  {
    return 1 - x*x;
  }

  virtual double lower(const double &x)
  {
    return 2*(1 - x*x);
  }

  virtual double upper_bound()
  {
    return 1;
  }

  virtual double lower_bound()
  {
    return 0;
  }
};

class ConstX: public ABoundaryCondition<double>
{
public:
  virtual double upper(const double &y)
  {
    return 0;
  }

  virtual double lower(const double &y)
  {
    return 1 + y*y;
  }

  virtual double upper_bound()
  {
    return 1;
  }

  virtual double lower_bound()
  {
    return 0;
  }
};

void test_Poisson()
{
  int N = 10;
  Poisson<double, ConstX, ConstY, Forcing> P;
  DenseMatrix<double> exact(N,N), numeric(0,0);

  // numeric = P.solve(ALinSysSolver<double, BandedMatrix<double>>& blank, N);
  numeric = P.solve(N);

  // std::cout << numeric << '\n';

  return;
}

#endif
