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
  BEGIN_TESTS("Poisson");

  int N = 5;
  DenseMatrix<long double> exact_solution(N,N);
  Poisson<long double, ConstX<long double>, ConstY<long double>, Forcing<long double> > P;
  long double h = (1.0l)/(N-1);
  long double exact_average = 0, numeric_average = 0;

  auto solxy = [](const long double x, const long double y)
  {
    return (1 - x*x)*(1 + y*y);
  };

  for(std::size_t i=0; i<N; ++i)
  {
    for(std::size_t j=0; j<N; ++j)
    {
      exact_solution.set(i,j,solxy(h*i, h*j));
      exact_average += exact_solution.get(i,j);
    }
  }

  std::cout << exact_solution << '\n';
  std::cout << exact_average << '\n';

/* ------------------------------------------------------------- *\
 *                    Test 1: Steepest Descent                   *
\* ------------------------------------------------------------- */

  BEGIN_TEST("Solver: SteepestDescent");

  int N = 5;
  DenseMatrix<long double> exact_solution(N,N);
  Poisson<long double, ConstX<long double>, ConstY<long double>, Forcing<long double> > P;
  long double h = (1.0l)/(N-1);
  long double exact_average = 0, numeric_average=0;

  auto solxy = [](const long double x, const long double y)
  {
    return (1 - x*x)*(1 + y*y);
  };

  for(std::size_t i=0; i<N; ++i)
  {
    for(std::size_t j=0; j<N; ++j)
    {
      exact_solution.set(i,j,solxy(h*i, h*j));
      exact_average += exact_solution.get(i,j);
    }
  }  
  
  SteepestDescent<long double> SD_solver;

  DenseMatrix<long double> numeric_solution = P.solve(SD_solver, N);

  for(std::size_t i=0; i<N; ++i)
  {
    for(std::size_t j=0; j<N; ++j)
    {
      numeric_average += numeric_solution.get(i,j);
    }
  }

  std::ofstream fout;
  fout.open("poisson_Usd.m");
  numeric_solution.outputOctave(fout, "Usd");
  fout.close();

  VERIFY_NEAREQ(exact_average, numeric_average, .001)

  END_TEST;

/* ------------------------------------------------------------- *\
 *                      Test 2: Gauss Seidel                     *
\* ------------------------------------------------------------- */
  BEGIN_TEST("Solver: GaussSeidel");

  int N = 5;
  DenseMatrix<long double> exact_solution(N,N);
  Poisson<long double, ConstX<long double>, ConstY<long double>, Forcing<long double> > P;
  long double h = (1.0l)/(N-1);
  long double exact_average = 0, numeric_average = 0;

  auto solxy = [](const long double x, const long double y)
  {
    return (1 - x*x)*(1 + y*y);
  };

  for(std::size_t i=0; i<N; ++i)
  {
    for(std::size_t j=0; j<N; ++j)
    {
      exact_solution.set(i,j,solxy(h*i, h*j));
      exact_average += exact_solution.get(i,j);
    }
  }  
  
  GaussSeidel<long double> GS_solver;

  DenseMatrix<long double> numeric_solution = P.solve(GS_solver, N);

  for(std::size_t i=0; i<N; ++i)
  {
    for(std::size_t j=0; j<N; ++j)
    {
      numeric_average += numeric_solution.get(i,j);
    }
  }

  std::ofstream fout;
  fout.open("poisson_Ugs.m");
  numeric_solution.outputOctave(fout, "Ugs");
  fout.close();

  VERIFY_NEAREQ(exact_average, numeric_average, .001)

  END_TEST;

  END_TESTS;

  return;
}

#endif