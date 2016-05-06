
#include <algorithm>
#include <cassert>
#include <exception>

#include "MatrixType.h"
#include "Utils.h"

template<class T>
BandedMatrix<T>::BandedMatrix(const SizeType rows, const SizeType cols, const SizeType upperBands, const SizeType lowerBands):
  AMatrix<T>(MatrixType::BANDED, rows, cols), m_upperBands(upperBands), m_lowerBands(lowerBands),
  m_data(upperBands + lowerBands + 1, cols)
{
  if(m_upperBands + m_lowerBands + 1 > std::min(this->rows(), this->cols()))
  {
    throw std::length_error( GEN_EXCEPT("The total number of bands must be less than the dimensions of the matrix") );
  }
}

template<class T>
BandedMatrix<T>::BandedMatrix(const BandedMatrix<ValueType>& other):
  AMatrix<T>(other), m_upperBands(other->m_upperBands), m_lowerBands(other->m_lowerBands),
  m_data(other.m_data)
{
  assert(m_upperBands + m_lowerBands + 1 <= std::min(this->rows(), this->cols()));
}

template<class T>
BandedMatrix<T>::BandedMatrix(BandedMatrix<ValueType>&& other):
  AMatrix<T>(other), m_upperBands(other->m_upperBands), m_lowerBands(other->m_lowerBands),
  m_data(std::move(other.m_data))
{
  assert(m_upperBands + m_lowerBands + 1 <= std::min(this->rows(), this->cols()));
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::operator=(const BandedMatrix<T>& other)
{
  assert(other.type() == MatrixType::BANDED);
  assert(other.m_upperBands + other.m_lowerBands + 1 <= std::min(other.rows(), other.cols()));
  if(this != &other)
  {
    this->m_type = MatrixType::BANDED;
    this->m_rows = other.rows();
    this->m_cols = other.cols();
    this->m_upperBands = other.m_upperBands;
    this->m_lowerBands = other.m_lowerBands;
    m_data = other.m_data;
  }
  return *this;
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::operator=(BandedMatrix<T>&& other)
{
  assert(other.type() == MatrixType::BANDED);
  assert(other.m_upperBands + other.m_lowerBands + 1 <= std::min(other.rows(), other.cols()));
  if(this != &other)
  {
    this->m_type = MatrixType::BANDED;
    this->m_rows = other.rows();
    this->m_cols = other.cols();
    this->m_upperBands = other.m_upperBands;
    this->m_lowerBands = other.m_lowerBands;
    m_data = std::move(other.m_data);
  }
  return *this;
}

template<class T>
typename BandedMatrix<T>::ValueType BandedMatrix<T>::get(const SizeType row, const SizeType col) const
{
  if(row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT("Given row, column index must be less than actual row, columns") );
  }
  else if(col + m_lowerBands >= row && col <= row + m_upperBands)
  {
    return m_data.get(m_upperBands + row - col, col);
  }
  else
  {
    return 0;
  }
}

template<class T>
void BandedMatrix<T>::set(const SizeType row, const SizeType col, ConstReferenceType value)
{
  if(row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT("Given row, column index must be less than actual row, columns") );
  }
  else if(col + m_lowerBands >= row && col <= row + m_upperBands )
  {
    return m_data.set(m_upperBands + row - col, col, value);
  }
  else if(value != 0)
  {
    throw std::domain_error( GEN_EXCEPT("Cannot set a non-zero value outside of bands") );
  }
  else
  {
    // Do nothing, setting unbanded value to 0
  }
}
