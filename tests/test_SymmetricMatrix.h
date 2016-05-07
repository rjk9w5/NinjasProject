//////////////////////////////////////////////////////////////////////
/// @file   test_SymmetricMatrix.h
/// @author Russley Shaw
/// @brief  Unit tests for SymmetricMatrix<T>
//////////////////////////////////////////////////////////////////////

#ifndef TEST_SYMMETRIC_MATRIX_H
#define TEST_SYMMETRIC_MATRIX_H

#include <iostream>

#include "MatrixType.h"
#include "SymmetricMatrix.h"

void test_SymmetricMatrix()
{
  BEGIN_TESTS("SymmetricMatrix");

  BEGIN_TEST("SymmetricMatrix::SymmetricMatrix(size)");
    SymmetricMatrix<int> m1(5);
    VERIFY_EQ(m1.rows(), 5);
    VERIFY_EQ(m1.cols(), 5);
    VERIFY_EQ(m1.type(), MatrixType::SYMMETRIC);
  END_TEST;


  BEGIN_TEST("SymmetricMatrix::rowColToIndex(row, col)");
    SymmetricMatrix<int> m(5);
    VERIFY_EQ(m.rows(), 5);
    VERIFY_EQ(m.cols(), 5);
    VERIFY_EQ(m.type(), MatrixType::SYMMETRIC);

    VERIFY_EQ(m.rowColToIndex(0, 0), 0);
    VERIFY_EQ(m.rowColToIndex(0, 1), 1);
    VERIFY_EQ(m.rowColToIndex(0, 2), 2);
    VERIFY_EQ(m.rowColToIndex(0, 3), 3);
    VERIFY_EQ(m.rowColToIndex(0, 4), 4);

    VERIFY_EQ(m.rowColToIndex(1, 1), 5);
    VERIFY_EQ(m.rowColToIndex(1, 2), 6);
    VERIFY_EQ(m.rowColToIndex(1, 3), 7);
    VERIFY_EQ(m.rowColToIndex(1, 4), 8);

    VERIFY_EQ(m.rowColToIndex(2, 2), 9);
    VERIFY_EQ(m.rowColToIndex(2, 3), 10);
    VERIFY_EQ(m.rowColToIndex(2, 4), 11);

    VERIFY_EQ(m.rowColToIndex(3, 3), 12);
    VERIFY_EQ(m.rowColToIndex(3, 4), 13);

    VERIFY_EQ(m.rowColToIndex(4, 4), 14);
  END_TEST;


  BEGIN_TEST("get(SizeType, SizeType)");
  BEGIN_TEST("set(SizeType, SizeType, ValueType)");
    SymmetricMatrix<int> m(4);
    VERIFY_EQ(m.rows(), 4);
    VERIFY_EQ(m.cols(), 4);

    m.set(0, 0, 1);
    m.set(1, 1, 1);
    m.set(2, 2, 1);
    m.set(3, 3, 1);

    m.set(0, 1, 7);
    m.set(1, 2, 8);
    m.set(2, 3, 9);

    VERIFY_EQ( m.get(1, 0), 7);
    VERIFY_EQ( m.get(2, 1), 8);
    VERIFY_EQ( m.get(3, 2), 9);

    std::cout << m << std::endl;
  END_TEST;
  END_TEST;

  END_TESTS;
}


#endif
