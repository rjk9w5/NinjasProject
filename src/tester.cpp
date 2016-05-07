//////////////////////////////////////////////////////////////////////
/// @file tester.cpp
/// @author Russley Shaw
/// @brief Unit tester top level
//////////////////////////////////////////////////////////////////////

#include "RLib/include/Test.h"

#include "tests/test_Vector.h"
#include "tests/test_DenseMatrix.h"
#include "tests/test_BandedMatrix.h"
#include "tests/test_TridiagMatrix.h"
#include "tests/test_SymmetricMatrix.h"
#include "tests/test_Poisson.h"

#include <iostream>

int main(int argc, char** argv)
{
  START_GLOBAL_TESTS;

  // Put functions containing tests here
  test_Vector();
  test_DenseMatrix();
  test_BandedMatrix();
  test_TridiagMatrix();

  test_SymmetricMatrix();

  test_Poisson();

  END_GLOBAL_TESTS;

  return 0;
}
