//////////////////////////////////////////////////////////////////////
/// @file   test_Vector.h
/// @author Russley Shaw
/// @brief  Unit tests for Vector<T>
//////////////////////////////////////////////////////////////////////

#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include "Vector.h"

void test_Vector()
{
  BEGIN_TESTS("Vector");

  BEGIN_TEST("Vector()");
    Vector<int> v;
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 0);
  END_TEST;


  BEGIN_TEST("Vector(const int)");
    Vector<int> v(0);
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 0);

    Vector<int> v1(5);
    VERIFY_EQ(v1.size(), 5);
    VERIFY_EQ(v1.capacity(), 5);

    for(Vector<int>::SizeType i = 0; i < v1.size(); i++)
    {
        VERIFY_EQ(v1[i], 0);
    }

  END_TEST;

  BEGIN_TEST("Vector::operator[](const int)");
    Vector<int> v(20);

    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[5] = 4;
    v[15] = 5;

    VERIFY_EQ(v[15], 5);
    VERIFY_EQ(v[5], 4);
    VERIFY_EQ(v[2], 3);
    VERIFY_EQ(v[1], 2);
    VERIFY_EQ(v[0], 1);
  END_TEST;

  BEGIN_TEST("Vector::at(const int)");
    Vector<int> v(20);

    v.at(0) = 1;
    v.at(1) = 2;
    v.at(2) = 3;
    v.at(5) = 4;
    v.at(15) = 5;

    VERIFY_EQ(v.at(15), 5);
    VERIFY_EQ(v.at(5), 4);
    VERIFY_EQ(v.at(2), 3);
    VERIFY_EQ(v.at(1), 2);
    VERIFY_EQ(v.at(0), 1);
  END_TEST;

  BEGIN_TEST("Vector::Vector(const Vector<T>&)");
    Vector<int> src(5);
    src[1] = 6;

    VERIFY_EQ(src.size(), 5)
    VERIFY_EQ(src.capacity(), 5)
    VERIFY_EQ(src[1], 6);

    Vector<int> dst( src );

    VERIFY_EQ(dst.size(), 5)
    VERIFY_EQ(dst.capacity(), 5)
    VERIFY_EQ(dst[1], 6);
  END_TEST;

  BEGIN_TEST("Vector::Vector(Vector<T>&&)");
    Vector<int> src(5);
    src[1] = 6;

    VERIFY_EQ(src.size(), 5)
    VERIFY_EQ(src.capacity(), 5)
    VERIFY_EQ(src[1], 6);

    Vector<int> dst( std::move(src) );

    VERIFY_EQ(dst.size(), 5)
    VERIFY_EQ(dst.capacity(), 5)
    VERIFY_EQ(dst[1], 6);
  END_TEST;

  BEGIN_TEST("Vector::Vector(const std::initializer_list&)");
    Vector<int> v = {5, 10, 15, 20, 25};

    VERIFY_EQ(v.size(), 5)
    VERIFY_EQ(v.capacity(), 5)
    VERIFY_EQ(v[1], 10);
  END_TEST;

  BEGIN_TEST("Vector::operator=(const Vector<T>&)");
    Vector<int> src(5);
    Vector<int> dst;
    src[1] = 6;

    VERIFY_EQ(src.size(), 5)
    VERIFY_EQ(src.capacity(), 5)
    VERIFY_EQ(src[1], 6);

    dst = src;

    VERIFY_EQ(dst.size(), 5)
    VERIFY_EQ(dst.capacity(), 5)
    VERIFY_EQ(dst[1], 6);
  END_TEST;

  BEGIN_TEST("Vector::operator=(Vector<T>&&)");
    Vector<int> src(5);
    Vector<int> dst;
    src[1] = 6;

    VERIFY_EQ(src.size(), 5)
    VERIFY_EQ(src.capacity(), 5)
    VERIFY_EQ(src[1], 6);

    dst = std::move(src);

    VERIFY_EQ(dst.size(), 5)
    VERIFY_EQ(dst.capacity(), 5)
    VERIFY_EQ(dst[1], 6);
  END_TEST;

  BEGIN_TEST("operator==(const Vector&, const Vector&)");
    Vector<int> v = {1, 2, 3, 4, 5};
    Vector<int> w = {1, 2, 3, 4, 5};
    Vector<int> x = {2, 4, 6, 8, 10};
    VERIFY_EQ(v == w, true);
    VERIFY_EQ(v == x, false);
    VERIFY_EQ(w == x, false);
  END_TEST;

  BEGIN_TEST("Vector::front()");
    Vector<int> v = {5, 10, 15, 20};
    VERIFY_EQ(v.front(), 5);
  END_TEST;

  BEGIN_TEST("Vector::back()");
    Vector<int> v = {5, 10, 15, 20};
    VERIFY_EQ(v.back(), 20);
  END_TEST;

  BEGIN_TEST("Vector::begin()");
    Vector<int> v = {5, 10, 15, 20};
    VERIFY_EQ(v.begin()[0], 5);
    VERIFY_EQ(v.begin()[2], 15);
  END_TEST;

  BEGIN_TEST("Vector::end()");
    Vector<int> v = {5, 10, 15, 20};
    VERIFY_EQ(v.end()[-1], 20);
    VERIFY_EQ(v.end()[-4], 5);
  END_TEST;

  BEGIN_TEST("Range based for loop");
    Vector<int> v = {0, 2, 4, 6, 8, 10};

    int i = -1;
    for(auto& item: v) {
      i++;
      VERIFY_EQ(item, v[i]);
    }
    VERIFY_EQ(i+1, v.size());
  END_TEST;

  BEGIN_TEST("Vector::empty()");
    Vector<int> v1;
    Vector<int> v2 = {5, 10, 15, 20};

    VERIFY_EQ(v1.empty(), true);
    VERIFY_EQ(v2.empty(), false);
  END_TEST;

  BEGIN_TEST("Vector::reserve(const int)");
    Vector<int> v;
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 0);

    v.reserve(1000);
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 1000);

    v.reserve(1);
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 1);

    v.reserve(10);
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 10);

    for(Vector<int>::SizeType i = 0; i < v.capacity(); i++) {
      v.pushBack(1337);
    }
    VERIFY_EQ(v[9], 1337);
    VERIFY_EQ(v.size(), 10);
    VERIFY_EQ(v.capacity(), 10);
  END_TEST;


  BEGIN_TEST("Vector::insert(const int, const T&)");
    Vector<int> v;
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 0);

    v.insert(0, 1);
    VERIFY_EQ(v.size(), 1);
    VERIFY_EQ(v.capacity(), 8);
    VERIFY_EQ(v[0], 1);

    v.insert(0, 2);
    VERIFY_EQ(v.size(), 2);
    VERIFY_EQ(v.capacity(), 8);
    VERIFY_EQ(v[0], 2);
    VERIFY_EQ(v[1], 1);
  END_TEST;

  BEGIN_TEST("Vector::erase(const int)");
    Vector<int> v = {0, 1, 2, 3, 4, 5};

    VERIFY_EQ(v.size(), 6);
    VERIFY_EQ(v.capacity(), 6);

    v.erase(0);
    VERIFY_EQ(v.size(), 5);
    VERIFY_EQ(v.capacity(), 6);
    VERIFY_EQ(v[0], 1);
    VERIFY_EQ(v[1], 2);
    VERIFY_EQ(v[4], 5);

    v.erase(4);
    VERIFY_EQ(v.size(), 4);
    VERIFY_EQ(v.capacity(), 6);
    VERIFY_EQ(v[0], 1);
    VERIFY_EQ(v[1], 2);
    VERIFY_EQ(v[3], 4);
  END_TEST;

  BEGIN_TEST("Vector::pushBack(const T&)");
    Vector<int> v;
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 0);

    v.pushBack(1);
    VERIFY_EQ(v.size(), 1);
    VERIFY_EQ(v.capacity(), 8);

    v.pushBack(2);
    v.pushBack(3);
    v.pushBack(4);
    v.pushBack(5);
    v.pushBack(6);
    v.pushBack(7);
    v.pushBack(8);
    VERIFY_EQ(v.size(), 8);
    VERIFY_EQ(v.capacity(), 8);

    v.pushBack(9);
    VERIFY_EQ(v.size(), 9);
    VERIFY_EQ(v.capacity(), 16);
  END_TEST;

  BEGIN_TEST("Vector::popBack()");
    Vector<int> v = {1, 2, 3, 4, 5};
    VERIFY_EQ(v.size(), 5);
    VERIFY_EQ(v.capacity(), 5);

    v.popBack();
    VERIFY_EQ(v.size(), 4);
    VERIFY_EQ(v.capacity(), 5);

    v.popBack();
    v.popBack();
    VERIFY_EQ(v.size(), 2);
    VERIFY_EQ(v.capacity(), 5);

    v.popBack();
    VERIFY_EQ(v.size(), 1);
    VERIFY_EQ(v.capacity(), 5);

    v.popBack();
    VERIFY_EQ(v.size(), 0);
    VERIFY_EQ(v.capacity(), 5);

  END_TEST;

  BEGIN_TEST("Vector::resize()");
    Vector<int> v1 = {1, 2, 3, 4, 5};
    Vector<int> v2 = {1, 2, 3, 4};
    VERIFY_EQ(v1.size(), 5);
    VERIFY_EQ(v1.capacity(), 5);

    v1.resize(4);
    VERIFY_EQ(v1.size(), v2.size());
    VERIFY_EQ(v1, v2)
    VERIFY_EQ(v1[3], 4);
    VERIFY_EQ(v1[3], v2[3]);
  END_TEST;


  BEGIN_TEST("Vector::swap(Vector&)");
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {4, 5, 6};

    v1.swap(v2);

    VERIFY_EQ(v1, Vector<int>({4, 5, 6}));
    VERIFY_EQ(v2, Vector<int>({1, 2, 3}));
  END_TEST;

  BEGIN_TEST("Vector::shrink()");
    Vector<int> v1 = {1, 2, 3};
    v1.reserve(100);

    VERIFY_EQ(v1.size(), 3);
    VERIFY_EQ(v1.capacity(), 100);

    v1.shrink();

    VERIFY_EQ(v1.size(), 3);
    VERIFY_EQ(v1.capacity(), 3);
  END_TEST;

  BEGIN_TEST("Vector::operator+=(Vector)");
  BEGIN_TEST("operator+(Vector, Vector)");
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {5, 6, 7};

    VERIFY_EQ(v1 + v2, Vector<int>({6, 8, 10}));
    VERIFY_EQ(v2 + v1, Vector<int>({6, 8, 10}));
    VERIFY_EQ(v1, Vector<int>({1, 2, 3}));
    VERIFY_EQ(v2, Vector<int>({5, 6, 7}));

    VERIFY_EQ(v1 += v2, Vector<int>({6, 8, 10}));
    VERIFY_EQ(v1, Vector<int>({6, 8, 10}));
    VERIFY_EQ(v2, Vector<int>({5, 6, 7}));
  END_TEST;
  END_TEST;

  BEGIN_TEST("Vector::operator*=(T)");
  BEGIN_TEST("operator*(T, Vector)");
  BEGIN_TEST("operator*(Vector, T)");
    Vector<int> v = {1, 2, 3};

    VERIFY_EQ(v *= 3, Vector<int>({3, 6, 9}));
    VERIFY_EQ(v, Vector<int>({3, 6, 9}));

    VERIFY_EQ(v *= -1, Vector<int>({-3, -6, -9}));
    VERIFY_EQ(v, Vector<int>({-3, -6, -9}));

    VERIFY_EQ(v * -1, Vector<int>({3, 6, 9}));
    VERIFY_EQ(v, Vector<int>({-3, -6, -9}));

    VERIFY_EQ(-1 * v, Vector<int>({3, 6, 9}));
    VERIFY_EQ(v, Vector<int>({-3, -6, -9}));
  END_TEST;
  END_TEST;
  END_TEST;

  END_TESTS;
}


#endif
