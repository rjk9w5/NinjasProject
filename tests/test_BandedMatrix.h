//////////////////////////////////////////////////////////////////////
/// @file   test_Vector.h
/// @author Russley Shaw
/// @brief  Unit tests for Vector<T>
//////////////////////////////////////////////////////////////////////

#include "Utils.h"

#ifndef TEST_BANDEDMATRIX_H
#define TEST_BANDEDMATRIX_H

#include "BandedMatrix.h"

void test_BandedMatrix()
{
  BEGIN_TESTS("BandedMatrix");

  BEGIN_TEST("BandedMatrix::BandedMatrix(int, int)");
    BandedMatrix<int> m(10, 2);
  END_TEST;

  END_TESTS;
}


#endif
