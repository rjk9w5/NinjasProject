//////////////////////////////////////////////////////////////////////
/// @file DenseMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of Dense Matrix
//////////////////////////////////////////////////////////////////////

#include <iomanip>

#include "Utils.h"

template<class T>
DenseMatrix<T>::DenseMatrix(const SizeType m, const SizeType n): AMatrix<T>(m, n), m_data(m*n)
{
}

template<class T>
DenseMatrix<T>::DenseMatrix(const SizeType rows, const SizeType cols , const std::initializer_list< ValueType >& l)
  :AMatrix<T>(rows, cols), m_data(rows * cols)
{
  if(l.size() != m_data.size())
  {
    throw std::length_error( GEN_EXCEPT("Initializer list must be same size as row*cols") );
  }
  std::copy(l.begin(), l.end(), m_data.begin());
}

template<class T>
DenseMatrix<T>::DenseMatrix(const DenseMatrix<T>& other): AMatrix<T>(other), m_data(other.m_data)
{
  assert(&m_data != &other.m_data);
}

template<class T>
DenseMatrix<T>::DenseMatrix(DenseMatrix<T>&& other): AMatrix<T>(other), m_data(std::move(other.m_data) )
{
}

template<class T>
DenseMatrix<T>& DenseMatrix<T>::operator=(const DenseMatrix<T>& other)
{
  if(this != &other)
  {
    copy(other);
  }
  return *this;
}

template<class T>
DenseMatrix<T>& DenseMatrix<T>::operator=(DenseMatrix<T>&& other)
{
  if(this != &other)
  {
    move(std::move(other));
  }
  return *this;
}

template<class T>
typename DenseMatrix<T>::ValueType DenseMatrix<T>::get(const SizeType row, const SizeType col) const
{
  if(row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range("Given row, col must be in interval [0, rows), [0, cols)");
  }

  return m_data[row * this->cols() + col];
}

template<class T>
void DenseMatrix<T>::set(const SizeType row, const SizeType col, ConstReferenceType value)
{
  if(row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range("Given row, col must be in interval [0, rows), [0, cols)");
  }

  m_data[row * this->cols() + col] = value;
}


template<class T>
DenseMatrix<T> operator*(const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs)
{
  if(lhs.cols() != rhs.rows())
  {
    throw std::length_error("DenseMatrix<T> operator*(const DenseMatrix<T>&, const DenseMatrix<T>&) - lhs must have same number columns as rhs has rows");
  }
  int n = lhs.rows();
  int m = lhs.cols();
  int p = rhs.cols();
  DenseMatrix<T> product(lhs.rows(), rhs.cols());
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < p; j++)
    {
      product.set(i, j, 0);
      for(int k = 0; k < m; k++)
      {
        product.set(i, j, product.get(i, j) + lhs.get(i, k)*rhs.get(k, j));
      }

    }
  }
  return product;
}


template<class T>
DenseMatrix<T>& DenseMatrix<T>::copy(const DenseMatrix<T>& other)
{
  m_data = other.m_data;

  AMatrix<T>::copy(other);
  return *this;
}

template<class T>
DenseMatrix<T>& DenseMatrix<T>::swap(DenseMatrix<T>& other)
{
  using std::swap;
  swap(m_data, other.m_data);

  AMatrix<T>::swap(other);
  return *this;
}

template<class T>
DenseMatrix<T>& DenseMatrix<T>::move(DenseMatrix<T>&& other)
{
  m_data = std::move(other.m_data);

  AMatrix<T>::move(std::move(other));
  return *this;
}
