
#include "MatrixType.h"

template<class T>
BandedMatrix<T>::BandedMatrix(const SizeType rowcols, const SizeType bands):
  AMatrix<T>(MatrixType::BANDED, rowcols, rowcols), m_data(bands, rowcols)
{
}

template<class T>
BandedMatrix<T>::BandedMatrix(const BandedMatrix<ValueType>& other):
  AMatrix<T>(other), m_data(other.m_data)
{
}

template<class T>
BandedMatrix<T>::BandedMatrix(BandedMatrix<ValueType>&& other)
  :AMatrix<T>(other), m_data( std::move(other.m_data) )
{
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::operator=(const BandedMatrix<T>& other)
{
  return *this;
}

template<class T>
BandedMatrix<T>& BandedMatrix<T>::operator=(BandedMatrix<T>&& other)
{
  return *this;
}

template<class T>
T BandedMatrix<T>::get(const SizeType row, const SizeType col) const
{
  return T
}

template<class T>
void BandedMatrix<T>::set(const SizeType row, const SizeType col, ConstReferenceType value)
{
}
