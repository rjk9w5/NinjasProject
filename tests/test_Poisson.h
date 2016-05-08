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
#include "ProjectParameters.h"
#include "DenseMatrix.h"

void test_Poisson()
{
  BEGIN_TESTS("Poisson");


  //////////////////////////////////////////////////////////////////////////////
  ///                     Test 1: Steepest Descent
  //////////////////////////////////////////////////////////////////////////////

  BEGIN_TEST("Solver: SteepestDescent");

    auto solxy = [](const long double x, const long double y)
    {
      return (1 - x*x)*(1 + y*y);
    };

  int N = 15;
  DenseMatrix<long double> exact_solution(N,N);
  Poisson<long double, ConstX<long double>, ConstY<long double>, Forcing<long double> > P;
  long double h = (1.0l)/(N-1);
  long double exact_average = 0, numeric_average=0;

    for(std::size_t i = 0; i < N; ++i)
    {
      for(std::size_t j = 0; j < N; ++j)
      {
        exact_solution.set(i,j,solxy(h*i, h*j));
        exact_average += exact_solution.get(i,j);
      }
    }

    SteepestDescent<long double> SD_solver;
    DenseMatrix<long double> numeric_solution = P.solve(SD_solver, N);

    for(std::size_t i = 0; i < N; ++i)
    {
      for(std::size_t j = 0; j < N; ++j)
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

  //////////////////////////////////////////////////////////////////////////////
  ///                     Test 2: Gauss Seidel
  //////////////////////////////////////////////////////////////////////////////
  BEGIN_TEST("Solver: GaussSeidel");
  auto solxy = [](const long double x, const long double y)
  {
    return (1 - x*x)*(1 + y*y);
  };

  int N = 15;
  DenseMatrix<long double> exact_solution(N,N);
  Poisson<long double, ConstX<long double>, ConstY<long double>, Forcing<long double> > P;
  long double h = (1.0l)/(N-1);
  long double exact_average = 0, numeric_average = 0;

    for(std::size_t i = 0; i < N; ++i)
    {
      for(std::size_t j = 0; j < N; ++j)
      {
        exact_solution.set(i,j,solxy(h*i, h*j));
        exact_average += exact_solution.get(i,j);
      }
    }

    GaussSeidel<long double> GS_solver;
    DenseMatrix<long double> numeric_solution = P.solve(GS_solver, N);

    for(std::size_t i = 0; i < N; ++i)
    {
      for(std::size_t j = 0; j < N; ++j)
      {
        numeric_average += numeric_solution.get(i,j);
      }
    }

    std::ofstream fout;
    fout.open("poisson_Ugs.m");
    numeric_solution.outputOctave(fout, "Ugs");
    fout.close();

    VERIFY_NEAREQ(exact_average, numeric_average, .001);
  END_TEST;

  END_TESTS;

  return;
}

#endif
