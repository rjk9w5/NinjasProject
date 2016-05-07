//////////////////////////////////////////////////////////////////////
/// @file   test_TridiagMatrix.h
/// @author Russley Shaw
/// @brief  Unit tests for TridiagMatrix<T>
//////////////////////////////////////////////////////////////////////

#ifndef TEST_TRIDIAG_MATRIX_H
#define TEST_TRIDIAG_MATRIX_H

#include <iostream>

#include "MatrixType.h"
#include "TridiagMatrix.h"

void test_TridiagMatrix()
{
  BEGIN_TESTS("TridiagMatrix");

  BEGIN_TEST("TridiagMatrix(size)");
    TridiagMatrix<int> m1(5);
    VERIFY_EQ(m1.rows(), 5);
    VERIFY_EQ(m1.cols(), 5);
    VERIFY_EQ(m1.upperBands(), 1);
    VERIFY_EQ(m1.lowerBands(), 1);
    VERIFY_EQ(m1.type(), MatrixType::TRIDIAGONAL);
  END_TEST;

  BEGIN_TEST("get(SizeType, SizeType)");
  BEGIN_TEST("set(SizeType, SizeType, ValueType)");
    TridiagMatrix<int> m(7); //7x7, (2+2+1) 5 bands
    VERIFY_EQ(m.rows(), 7);
    VERIFY_EQ(m.cols(), 7);
    VERIFY_EQ(m.upperBands(), 1);
    VERIFY_EQ(m.lowerBands(), 1);

    std::cout << m << std::endl;
  END_TEST;
  END_TEST;

  END_TESTS;
}


#endif
