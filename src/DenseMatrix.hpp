//////////////////////////////////////////////////////////////////////
/// @file DenseMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of Dense Matrix
//////////////////////////////////////////////////////////////////////

#include <iomanip>

template<class T>
DenseMatrix<T>::DenseMatrix(const SizeType m, const SizeType n): AMatrix<T>(MatrixType::DENSE, m, n), m_data(m*n)
{
}

template<class T>
DenseMatrix<T>::DenseMatrix(const SizeType rows, const SizeType cols , const std::initializer_list< ValueType >& l)
  :AMatrix<T>(MatrixType::DENSE, rows, cols), m_data(rows * cols)
{
  if(l.size() != m_data.size())
  {
    //throw std::length_error(__FILE__":"LINE_STRING": Bad juju");
  }
}

template<class T>
DenseMatrix<T>::DenseMatrix(const DenseMatrix<T>& other): AMatrix<T>(other), m_data(other.m_data)
{
}

template<class T>
DenseMatrix<T>::DenseMatrix(DenseMatrix<T>&& other): AMatrix<T>(other), m_data(other.m_data)
{
}

template<class T>
DenseMatrix<T>::~DenseMatrix()
{
}

template<class T>
DenseMatrix<T>& DenseMatrix<T>::operator=(const DenseMatrix<T>& other)
{
  if(this != &other)
  {
    this->m_rows = other.m_rows;
    this->m_cols = other.m_cols;
    this->m_data = other.m_data;
  }
  return *this;
}

template<class T>
DenseMatrix<T>& DenseMatrix<T>::operator=(DenseMatrix<T>&& other)
{
  if(this != &other)
  {
    this->m_rows = other.m_rows;
    this->m_cols = other.m_cols;
    m_data = std::move(other.m_data);

    other.m_rows = 0;
    other.m_cols = 0;
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
