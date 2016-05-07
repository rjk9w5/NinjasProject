
#include <algorithm>
#include <cassert>
#include <exception>

#include "MatrixType.h"
#include "Utils.h"

template<class T>
BandedMatrix<T>::BandedMatrix(const SizeType rows, const SizeType cols, const SizeType upperBands, const SizeType lowerBands):
  AMatrix<T>(rows, cols), m_upperBands(upperBands), m_lowerBands(lowerBands),
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
  assert(other.m_upperBands + other.m_lowerBands + 1 <= std::min(other.rows(), other.cols()));
  if(this != &other)
  {
    copy(other);
  }
  return *this;
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::operator=(BandedMatrix<T>&& other)
{
  assert(other.m_upperBands + other.m_lowerBands + 1 <= std::min(other.rows(), other.cols()));
  if(this != &other)
  {
    move(other);
  }
  return *this;
}

template<class T>
typename BandedMatrix<T>::ValueType BandedMatrix<T>::get(const SizeType row, const SizeType col) const
{
   if(col + m_lowerBands >= row && col <= row + m_upperBands)
  {
    return m_data.get(m_upperBands + row - col, col);
  }
  else
  {
    return 0;
  }
}

template<class T>
typename BandedMatrix<T>::ConstPointerType BandedMatrix<T>::getPtr(const SizeType row, const SizeType col) const
{
  if(col + m_lowerBands >= row && col <= row + m_upperBands)
 {
   return m_data.getPtr(m_upperBands + row - col, col);
 }
 else
 {
   return nullptr;
 }
}

template<class T>
Vector< typename BandedMatrix<T>::ValueType > BandedMatrix<T>::getRow(const SizeType row) const
{
  Vector<ValueType> ret(this->cols());

  int start = std::max({0, static_cast<int>(row) - static_cast<int>(m_lowerBands) });
  int size = std::min({this->cols(), static_cast<int>(row) + m_upperBands + 1});
  for(int j = start; j < size; j++)
  {
    ret[j] = this->get(row, j);
  }
  return ret;
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

template<class T>
std::ostream& BandedMatrix<T>::output(std::ostream& stream) const
{
  for(SizeType i = 0; i < this->rows(); i++)
  {
    for(SizeType j = 0; j < this->cols(); j++)
    {
      stream << std::setw(8);
      if(j + m_lowerBands >= i && j <= i + m_upperBands)
      {
        stream << m_data.get(m_upperBands + i - j, j);
      }
      else
      {
        stream << '-';
      }
      stream << " ";
    }
    stream << std::endl;
  }
  return stream;
}

template<class T>
std::ostream& BandedMatrix<T>::altOutput(std::ostream& stream) const
{
  for(SizeType i = 0; i < m_data.rows(); i++)
  {
    for(SizeType j = 0; j < m_data.cols(); j++)
    {
      stream << std::setw(8);
      if(true)
      {
        stream << m_data.get(i, j);
      }
      else
      {
        stream << '-';
      }
      stream << " ";
    }
    stream << std::endl;
  }
  return stream;
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::copy(const BandedMatrix<T>& other)
{
  m_upperBands = other.m_upperBands;
  m_lowerBands = other.m_lowerBands;
  m_data = other.m_data;
  AMatrix<T>::copy(other);
  return *this;
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::swap(BandedMatrix<T>& other)
{
  using std::swap;
  swap(m_upperBands, other.m_upperBands);
  swap(m_lowerBands, other.m_lowerBands);
  swap(m_data, other.m_data);
  AMatrix<T>::swap(other);
  return *this;
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::move(BandedMatrix<T>&& other)
{
  using std::move;
  move(m_upperBands, other.m_upperBands);
  move(m_lowerBands, other.m_lowerBands);
  move(m_data, other.m_data);
  AMatrix<T>::move(other);
  return *this;
}
