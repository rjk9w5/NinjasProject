//////////////////////////////////////////////////////////////////////
/// @file   test_Vector.h
/// @author Russley Shaw
/// @brief  Unit tests for Vector<T>
//////////////////////////////////////////////////////////////////////

#ifndef TEST_BANDEDMATRIX_H
#define TEST_BANDEDMATRIX_H

#include <iostream>

#include "BandedMatrix.h"

void test_BandedMatrix()
{
  BEGIN_TESTS("BandedMatrix");

  BEGIN_TEST("BandedMatrix(rows, cols, upperBands, lowerBands)");
    BandedMatrix<int> m1(5, 5, 1, 1);
    VERIFY_EQ(m1.rows(), 5);
    VERIFY_EQ(m1.cols(), 5);
    VERIFY_EQ(m1.upperBands(), 1);
    VERIFY_EQ(m1.lowerBands(), 1);

    BandedMatrix<int> m2(7, 7, 1, 5);
    VERIFY_EQ(m2.rows(), 7);
    VERIFY_EQ(m2.cols(), 7);
    VERIFY_EQ(m2.upperBands(), 1);
    VERIFY_EQ(m2.lowerBands(), 5);

    BandedMatrix<int> m3(5, 4, 2, 1);
    VERIFY_EQ(m3.rows(), 5);
    VERIFY_EQ(m3.cols(), 4);
    VERIFY_EQ(m3.upperBands(), 2);
    VERIFY_EQ(m3.lowerBands(), 1);

    BandedMatrix<int> m4(3, 4, 1, 1);
    VERIFY_EQ(m4.rows(), 3);
    VERIFY_EQ(m4.cols(), 4);
    VERIFY_EQ(m4.upperBands(), 1);
    VERIFY_EQ(m4.lowerBands(), 1);
  END_TEST;

  BEGIN_TEST("get(SizeType, SizeType)");
  BEGIN_TEST("set(SizeType, SizeType, ValueType)");
    BandedMatrix<int> m(7, 7, 2, 2); //7x7, (2+2+1) 5 bands
    VERIFY_EQ(m.rows(), 7);
    VERIFY_EQ(m.cols(), 7);
    VERIFY_EQ(m.upperBands(), 2);
    VERIFY_EQ(m.lowerBands(), 2);

    m.set(0, 0, 1);
    m.set(1, 1, 1);
    m.set(2, 2, 1);
    m.set(3, 3, 1);
    m.set(4, 4, 1);
    m.set(5, 5, 1);
    m.set(6, 6, 1);

    m.set(0, 1, 2);
    m.set(1, 2, 2);
    m.set(2, 3, 2);
    m.set(3, 4, 2);
    m.set(4, 5, 2);
    m.set(5, 6, 2);

    m.set(0, 2, 4);
    m.set(1, 3, 4);
    m.set(2, 4, 4);
    m.set(3, 5, 4);
    m.set(4, 6, 4);

    m.set(1,0, 3);
    m.set(2,1, 3);
    m.set(3,2, 3);
    m.set(4,3, 3);
    m.set(5,4, 3);
    m.set(6,5, 3);

    VERIFY_EQ(m.get(0, 0), 1 );
    VERIFY_EQ(m.get(1, 1), 1 );
    VERIFY_EQ(m.get(2, 2), 1 );
    VERIFY_EQ(m.get(3, 3), 1 );
    VERIFY_EQ(m.get(4, 4), 1 );
    VERIFY_EQ(m.get(5, 5), 1 );
    VERIFY_EQ(m.get(6, 6), 1 );

    VERIFY_EQ(m.get(0, 1), 2 );
    VERIFY_EQ(m.get(1, 2), 2 );
    VERIFY_EQ(m.get(2, 3), 2 );
    VERIFY_EQ(m.get(3, 4), 2 );
    VERIFY_EQ(m.get(4, 5), 2 );
    VERIFY_EQ(m.get(5, 6), 2 );

    VERIFY_EQ(m.get(0, 2), 4 );
    VERIFY_EQ(m.get(1, 3), 4 );
    VERIFY_EQ(m.get(2, 4), 4 );
    VERIFY_EQ(m.get(3, 5), 4 );
    VERIFY_EQ(m.get(4, 6), 4 );

    VERIFY_EQ(m.get(1,0), 3 );
    VERIFY_EQ(m.get(2,1), 3 );
    VERIFY_EQ(m.get(3,2), 3 );
    VERIFY_EQ(m.get(4,3), 3 );
    VERIFY_EQ(m.get(5,4), 3 );
    VERIFY_EQ(m.get(6,5), 3 );

    std::cout << m << std::endl;
  END_TEST;
  END_TEST;

  END_TESTS;
}


#endif
