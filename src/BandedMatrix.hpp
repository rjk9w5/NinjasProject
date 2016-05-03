
#include <cassert>
#include "MatrixType.h"

template<class T>
BandedMatrix<T>::BandedMatrix(const SizeType rowcols, const SizeType bands):
  AMatrix<T>(MatrixType::BANDED, rowcols, rowcols), m_data(bands, rowcols)
{
  if(bands > rowcols)
  {
    throw std::length_error( GEN_EXCEPT("Given number of bands must be less than or equal to number of rows & columns") );
  }
}

template<class T>
BandedMatrix<T>::BandedMatrix(const BandedMatrix<ValueType>& other):
  AMatrix<T>(other), m_data(other.m_data)
{
  assert( this->bands() <= this->m_rows );
}

template<class T>
BandedMatrix<T>::BandedMatrix(BandedMatrix<ValueType>&& other)
  :AMatrix<T>(other), m_data( std::move(other.m_data) )
{
  assert( this->bands() <= this->m_rows );
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::operator=(const BandedMatrix<T>& other)
{
  assert(other.m_rows == other.m_cols);
  assert(other.m_type == MatrixType::BANDED);
  assert( other.bands() <= other.m_rows );
  if(this != &other)
  {
    this->m_type = MatrixType::BANDED;
    this->m_rows = other.m_rows;
    this->m_cols = other.m_cols;
    m_data = other.m_data;
  }
  return *this;
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::operator=(BandedMatrix<T>&& other)
{
  assert(other.m_rows == other.m_cols);
  assert(other.m_type == MatrixType::BANDED);
  assert( other.bands() <= other.m_rows );
  if(this != &other)
  {
    this->m_type = MatrixType::BANDED;
    this->m_rows = other.m_rows;
    this->m_cols = other.m_cols;
    m_data = std::move(other.m_data);
  }
  return *this;
}

template<class T>
typename BandedMatrix<T>::ValueType BandedMatrix<T>::get(const SizeType row, const SizeType col) const
{
  //TODO: BandedMatrix<T>::get logic
  return ValueType(0);
}

template<class T>
void BandedMatrix<T>::set(const SizeType row, const SizeType col, ConstReferenceType value)
{
  //TODO: BandedMatrix<T>::get logic
}
