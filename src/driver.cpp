////////////////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Russley Shaw and Ryan Krattiger
/// @brief Driver file for homework 6
////////////////////////////////////////////////////////////////////////////////

#include <chrono> // std::chrono::system_clock::now()
#include <iostream>
#include <fstream>

#include "Poisson.h"
#include "ProjectParameters.h"
#include "DenseMatrix.h"

int main(int argc, char ** argv)
{
  // Timer
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::chrono::duration<double> elapsed_seconds; // = end-start;

  // Matrix Solvers
  SteepestDescent<long double> SD_solver;
  GaussSeidel<long double> GS_solver;
  // Solution Matrices
  DenseMatrix<long double> numeric_solutionSD(0,0), numeric_solutionGS(0,0);
  // Poisson equation definition
  Poisson<long double, ConstX<long double>, ConstY<long double>, Forcing<long double> > P;
  // Metric Variables
  long double h;
  long double exact_average, numeric_averageSD, numeric_averageGS;
  // Iteration variables for soltion comparisons
  Vector<int> N({5, 10, 15, 20, 25, 30, 40, 45, 50});
  Vector<std::string> N_strings({"5", "10", "15", "20", "25", "30", "40", "45", "50"});

  std::ofstream fout;

  // Lambda with exact soltion
  auto solxy = [](const long double x, const long double y)
  {
    return (1 - x*x)*(1 + y*y);
  };

  // Loop over range of N to make comparison data
  for(std::size_t k=0; k<N.size(); ++k)
  {
    DenseMatrix<long double> exact_solution(N[k],N[k]);
    // initialize metrics for iteration
    h = (1.0l)/(N[k]-1);
    exact_average = 0;
    numeric_averageSD=0;
    numeric_averageGS=0;

    // Calculate Exact soltion matrics
    for(std::size_t i=0; i<N[k]; ++i)
    {
      for(std::size_t j=0; j<N[k]; ++j)
      {
        exact_solution.set(i,j,solxy(h*i, h*j));
        exact_average += exact_solution.get(i,j)/N[k];
      }
    }

    // Solve Poisson using two methods
    std::cout << "Steepest Descent: N = " + N_strings[k] + "\n";
    start = std::chrono::system_clock::now();
    numeric_solutionSD = P.solve(SD_solver, N[k]);
    end = std::chrono::system_clock::now();
    // Calculate a comparison metric for the solutions
    for(std::size_t i=0; i<N[k]; ++i)
    {
      for(std::size_t j=0; j<N[k]; ++j)
      {
        numeric_averageSD += numeric_solutionSD.get(i,j)/N[k];
      }
    }
    std::cout << "Total Relative Error: " << fabs(exact_average - numeric_averageSD)/exact_average << '\n';
    elapsed_seconds = end-start;
    std::cout << "Time elapsed: " << elapsed_seconds.count() << "s.\n\n";

    std::cout << "Gauss-Seidel: N = " + N_strings[k] + "\n";
    start = std::chrono::system_clock::now();
    numeric_solutionGS = P.solve(GS_solver, N[k]);
    end = std::chrono::system_clock::now();
    // Calculate a comparison metric for the solutions
    for(std::size_t i=0; i<N[k]; ++i)
    {
      for(std::size_t j=0; j<N[k]; ++j)
      {
        numeric_averageGS += numeric_solutionGS.get(i,j)/N[k];
      }
    }
    std::cout << "Total Relative Error: " << fabs(exact_average - numeric_averageGS)/exact_average << '\n';
    elapsed_seconds = end-start;
    std::cout << "Time elapsed: " << elapsed_seconds.count() << "s.\n\n";

    // Write results to Octave files for ease of plotting
    fout.open("poisson_Usd" + N_strings[k] + ".m");
    numeric_solutionSD.outputOctave(fout, "Usd" + N_strings[k]);
    fout.close();

    fout.open("poisson_Ugs" + N_strings[k] + ".m");
    numeric_solutionGS.outputOctave(fout, "Ugs" + N_strings[k]);
    fout.close();

    fout.open("poisson_exact" + N_strings[k] + ".m");
    exact_solution.outputOctave(fout, "U" + N_strings[k]);
    fout.close();
  }

  return 0;
}
