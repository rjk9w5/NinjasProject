//////////////////////////////////////////////////////////////////////
/// @file   test_Vector.h
/// @author Russley Shaw
/// @brief  Unit tests for Vector<T>
//////////////////////////////////////////////////////////////////////

#include "Utils.h"

#ifndef TEST_DENSEMATRIX_H
#define TEST_DENSEMATRIX_H

#include "DenseMatrix.h"

void test_DenseMatrix()
{
  BEGIN_TESTS("DenseMatrix");

  BEGIN_TEST("DenseMatrix::DenseMatrix(int, int)");
    DenseMatrix<int> m(3, 4);
    VERIFY_EQ(m.rows(), 3);
    VERIFY_EQ(m.cols(), 4);
  END_TEST;

  END_TESTS;
}


#endif
