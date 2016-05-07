//////////////////////////////////////////////////////////////////////
/// @file   test_Vector.h
/// @author Russley Shaw
/// @brief  Unit tests for Vector<T>
//////////////////////////////////////////////////////////////////////

#ifndef TEST_DENSEMATRIX_H
#define TEST_DENSEMATRIX_H

#include "DenseMatrix.h"
#include "MatrixType.h"

void test_DenseMatrix()
{
  BEGIN_TESTS("DenseMatrix");

  BEGIN_TEST("DenseMatrix::DenseMatrix(int, int)");
    DenseMatrix<int> m(3, 4);
    VERIFY_EQ(m.rows(), 3);
    VERIFY_EQ(m.cols(), 4);
    VERIFY_EQ(m.type(), MatrixType::DENSE);
  END_TEST;

  BEGIN_TEST("DenseMatrix::operator=(DenseMatrix)");
  DenseMatrix<int> m1(3, 3, {
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
  });

  DenseMatrix<int> m2(3, 5, {
    1, 2, 3, 1, 2,
    4, 5, 6, 3, 4,
    7, 8, 9, 5, 6
  });

  m2 = m1;

  VERIFY_EQ(m2, m1);
  END_TEST;

  BEGIN_TEST("DenseMatrix::get(SizeType, SizeType)");
  BEGIN_TEST("DenseMatrix::set(SizeType, SizeType, ValueType)");
    DenseMatrix<int> m(3, 4);
    VERIFY_EQ(m.rows(), 3);
    VERIFY_EQ(m.cols(), 4);

    for(int i = 0; i < m.rows(); i++)
    {
      for(int j = 0; j < m.cols(); j++)
      {
        VERIFY_EQ(m.get(i, j), 0);
      }
    }

    m.set(0, 0, 1); m.set(0, 1, 2); m.set(0, 2, 3); m.set(0, 3, 4);
    m.set(1, 0, 5); m.set(1, 1, 6); m.set(1, 2, 7); m.set(1, 3, 8);
    m.set(2, 0, 9); m.set(2, 1, 10); m.set(2, 2, 11); m.set(2, 3, 12);

    VERIFY_EQ(m.get(0, 0), 1); VERIFY_EQ(m.get(0, 1), 2); VERIFY_EQ(m.get(0, 2), 3); VERIFY_EQ(m.get(0, 3), 4);
    VERIFY_EQ(m.get(1, 0), 5); VERIFY_EQ(m.get(1, 1), 6); VERIFY_EQ(m.get(1, 2), 7); VERIFY_EQ(m.get(1, 3), 8);
    VERIFY_EQ(m.get(2, 0), 9); VERIFY_EQ(m.get(2, 1), 10); VERIFY_EQ(m.get(2, 2), 11); VERIFY_EQ(m.get(2, 3), 12);
  END_TEST;
  END_TEST;

  BEGIN_TEST("DenseMatrix::DenseMatrix(int, int, const std::initializer_list& l)");
    DenseMatrix<int> m1(3, 3, {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9
    });

    DenseMatrix<int> m2(3, 5, {
      1, 2, 3, 1, 2,
      4, 5, 6, 3, 4,
      7, 8, 9, 5, 6
    });

    DenseMatrix<int> m3(5, 3, {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9,
      1, 2, 3,
      4, 5, 6
    });

    VERIFY_EQ(m1.rows(), 3);
    VERIFY_EQ(m1.cols(), 3);
    VERIFY_EQ(m1.get(1, 1), 5);
    VERIFY_EQ(m1.get(1, 2), 6);
    VERIFY_EQ(m1.get(0, 0), 1);
    VERIFY_EQ(m1.get(2, 2), 9);

    VERIFY_EQ(m2.rows(), 3);
    VERIFY_EQ(m2.cols(), 5);
    VERIFY_EQ(m2.get(1, 1), 5);
    VERIFY_EQ(m2.get(1, 2), 6);
    VERIFY_EQ(m2.get(2, 3), 5);
    VERIFY_EQ(m2.get(2, 4), 6);


    VERIFY_EQ(m3.rows(), 5);
    VERIFY_EQ(m3.cols(), 3);
    VERIFY_EQ(m3.get(1, 1), 5);
    VERIFY_EQ(m3.get(1, 2), 6);
    VERIFY_EQ(m3.get(3, 2), 3);
    VERIFY_EQ(m3.get(4, 2), 6);

  END_TEST;

  BEGIN_TEST("DenseMatrix::DenseMatrix(int, int)");
    DenseMatrix<int> m(3, 4);
    VERIFY_EQ(m.rows(), 3);
    VERIFY_EQ(m.cols(), 4);
  END_TEST;

  BEGIN_TEST("DenseMatrix::getRow(int");
    DenseMatrix<int> m(3, 5, {
      1, 2, 3, 4, 5,
      4, 5, 6, 3, 4,
      7, 8, 9, 5, 6
    });

    auto row0 = m.getRow(0);
    VERIFY_EQ(m.get(0, 0), row0[0]);
    VERIFY_EQ(m.get(0, 1), row0[1]);
    VERIFY_EQ(m.get(0, 2), row0[2]);
    VERIFY_EQ(m.get(0, 3), row0[3]);
    VERIFY_EQ(m.get(0, 4), row0[4]);
  END_TEST;

  BEGIN_TEST("DenseMatrix::getCol(SizeType)");
    DenseMatrix<int> m(3, 5, {
      1, 2, 3, 4, 5,
      4, 5, 6, 3, 4,
      7, 8, 9, 5, 6
    });

    auto v = m.getCol(1);
    VERIFY_EQ(m.get(0, 1), v[0]);
    VERIFY_EQ(m.get(1, 1), v[1]);
    VERIFY_EQ(m.get(2, 1), v[2]);
  END_TEST;

  BEGIN_TEST("DenseMatrix::setRow(SizeType, Vector)");
    DenseMatrix<int> m(3, 5, {
      1, 2, 3, 4, 5,
      4, 5, 6, 3, 4,
      7, 8, 9, 5, 6
    });
    Vector<int> v({100, 200, 300, 400, 500});

    m.setRow(1, v);
    VERIFY_EQ(m.get(1, 0), v[0]);
    VERIFY_EQ(m.get(1, 1), v[1]);
    VERIFY_EQ(m.get(1, 2), v[2]);
    VERIFY_EQ(m.get(1, 3), v[3]);
    VERIFY_EQ(m.get(1, 4), v[4]);
  END_TESTS;

  BEGIN_TEST("DenseMatrix::setCol(SizeType, Vector)");
    DenseMatrix<int> m(3, 5, {
      1, 2, 3, 4, 5,
      4, 5, 6, 3, 4,
      7, 8, 9, 5, 6
    });
    Vector<int> v({100, 200, 300});

    m.setCol(1, v);
    VERIFY_EQ(m.get(0, 1), v[0]);
    VERIFY_EQ(m.get(1, 1), v[1]);
    VERIFY_EQ(m.get(2, 1), v[2]);
  END_TESTS;

  END_TESTS;
}


#endif
