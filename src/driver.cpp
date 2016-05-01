////////////////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Russley Shaw
/// @brief Driver file for homework 6
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <fstream>
#include <iostream>

#include "AMatrix.h"
#include "DenseMatrix.h"
#include "TridiagMatrix.h"
#include "UpperTriMatrix.h"
#include "DiagonalMatrix.h"
#include "SymDenseMatrix.h"
#include "QrDecomp.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn doTest()
/// @brief Performs basic matrix multiplication testing
/// @post Outputs to user some test cases
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn findEigenValues
/// @brief Finds & prints eigen values from user specified matricies
/// @post The matricies will be read in from stream and info outputted to user
/// @param inFile input stream
/// @param num nth matrix to read in (for formatting purposes)
//////////////////////////////////////////////////////////////////////

void doTest();
void findEigenValues(std::istream& inFile, const int num);

int main(int argc, char ** argv)
{
  try
  {
    if(argc != 2)
    {
      throw std::invalid_argument("main(): Must be supplied 1 argument");
    }

    std::ifstream inFile;
    inFile.open(argv[1]);
    if( !inFile.is_open() )
    {
      throw std::ios_base::failure("main(): Unable to open file");
    }

    doTest();
    findEigenValues(inFile, 1);
    findEigenValues(inFile, 2);

  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

void doTest()
{
  std::cout << "UpperTriMatrix Multiplication" << std::endl;
  std::cout << "A = " << std::endl;
  UpperTriMatrix<long double> ut1(5);
  ut1.set(0, 0, 1); ut1.set(0, 1, 2); ut1.set(0, 2, 3); ut1.set(0, 3, 4); ut1.set(0, 4, 5);
  ut1.set(1, 1, 2); ut1.set(1, 2, 3); ut1.set(1, 3, 4); ut1.set(1, 4, 5);
  ut1.set(2, 2, 3); ut1.set(2, 3, 4); ut1.set(2, 4, 5);
  ut1.set(3, 3, 4); ut1.set(3, 4, 5);
  ut1.set(4, 4, 5);
  std::cout << ut1 << std::endl;

  std::cout << "B = " << std::endl;
  UpperTriMatrix<long double> ut2(5);
  ut2.set(0, 0, 59); ut2.set(0, 1, 2); ut2.set(0, 2, 3); ut2.set(0, 3, 9); ut2.set(0, 4, 12);
  ut2.set(1, 1, 2); ut2.set(1, 2, 3); ut2.set(1, 3, 12); ut2.set(1, 4, 0);
  ut2.set(2, 2, 3); ut2.set(2, 3, 4); ut2.set(2, 4, 5);
  ut2.set(3, 3, 33); ut2.set(3, 4, 7);
  ut2.set(4, 4, 5);
  std::cout << ut2 << std::endl;

  std::cout << "A * B = " << std::endl << ut1 * ut2 << std::endl;

  std::cout << "Diagonal Matrix Multiplication" << std::endl;
  std::cout << "A = " << std::endl;
  DiagonalMatrix<long double> d1(5);
  d1.set(0, 0, 600);
  d1.set(1, 1, -800);
  d1.set(2, 2, 3200);
  d1.set(3, 3, 100);
  d1.set(4, 4, 100);
  std::cout << d1 << std::endl;

  std::cout << "B = " << std::endl;
  DiagonalMatrix<long double> d2(5);
  d2.set(0, 0, 10);
  d2.set(1, 1, -10);
  d2.set(2, 2, 10);
  d2.set(3, 3, -10);
  d2.set(4, 4, 10);
  std::cout << d2 << std::endl;

  std::cout << "A * B = " << std::endl << d1 * d2 << std::endl;
}

void findEigenValues(std::istream& inFile, const int num)
{
  QrDecomp<long double> qrDecomp;
  int size;

  //Get matrix
  inFile >> size;
  DenseMatrix<long double> A(size, size);
  DenseMatrix<long double> Q(size, size);
  DenseMatrix<long double> R(size, size);

  //Get matrix
  inFile >> A;
  int i;
  for(i = 0; i < 300; i++)
  {
    qrDecomp(A, Q, R);

    if(i % 2 == 0)
    {
    A = R * Q;
    }
    else
    {
    A = Q * R;
    }


    if(i == 5)
    {
      std::cout << "=== Iteration 5 - Matrix " << num <<" ===" << std::endl;
      std::cout << A << std::endl;
    }
    if(i == 10)
    {
      std::cout << "=== Iteration 10 - Matrix " << num <<" ===" << std::endl;
      std::cout << A << std::endl;
    }
  }
  std::cout << "=== Final Iteration - Matrix " << num <<" ===" << std::endl;
  std::cout << A << std::endl;

  std::cout << "=== Reason - Matrix " << num << " ===" << std::endl;
  std::cout << "Completed " << i << " iterations" << std::endl;

  std::cout << "=== Eigenvalues - Matrix " << num <<" ===" << std::endl;
  Vector<long double> eigen(size);
  for(int j = 0; j < size; j++)
  {
    eigen[j] = A.get(j, j);
  }
  std::cout << eigen << std::endl;
}
