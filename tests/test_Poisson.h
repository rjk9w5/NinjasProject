//////////////////////////////////////////////////////////////////////
/// @file   test_Poisson.h
/// @author Ryan Krattiger
/// @brief  Unit tests for Poisson<T>
//////////////////////////////////////////////////////////////////////

#ifndef TEST_POISSON_H
#define TEST_POISSON_H

#include <iostream>
#include <fstream>

#include "Poisson.h"
#include "BoundaryCondition.h"
#include "Functor.h"
#include "DenseMatrix.h"

// Information Provided for the Boundary Conditions were Y is constant and X
//   is constant respectively...

template <class T>
class Forcing: public AFunctorxy<T>
{
public:
  virtual T operator()(const T& x, const T& y)
  {
    return -2*(x*x + y*y);
  }
};

template <class T>
class ConstY: public ABoundaryCondition<T>
{
public:
  virtual T upper(const T &x)
  {
    return 2*(1 - x*x);
  }

  virtual T lower(const T &x)
  {
    return (1 - x*x);
  }

  virtual T upper_bound()
  {
    return 1;
  }

  virtual T lower_bound()
  {
    return 0;
  }
};

template <class T>
class ConstX: public ABoundaryCondition<T>
{
public:
  virtual T upper(const T &y)
  {
    return 0;
  }

  virtual T lower(const T &y)
  {
    return 1 + y*y;
  }

  virtual T upper_bound()
  {
    return 1;
  }

  virtual T lower_bound()
  {
    return 0;
  }
};

void test_Poisson()
{
  int N = 17;
  Poisson<long double, ConstX<long double>, ConstY<long double>, Forcing<long double> > P;
  DenseMatrix<long double> exact(N,N);

  // numeric = P.solve(ALinSysSolver<double, BandedMatrix<double>>& blank, N);
  DenseMatrix<long double> numeric = P.solve(N);

  std::ofstream fout;
  fout.open("pois_res_U.m");
  fout << "U = [" << numeric << "];\n";
  fout.close();

  // std::cout << numeric << '\n';

  return;
}

#endif

// -3.000 -1.011 -1.042 -1.093 -1.165 -1.257 -1.370 -2.463
