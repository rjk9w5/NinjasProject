//////////////////////////////////////////////////////////////////////
/// @file AMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of base Matrix class
//////////////////////////////////////////////////////////////////////

#include "Utils.h"

template<class T>
AMatrix<T>::AMatrix(const MatrixType& type, const SizeType rows, const SizeType cols): m_type(type), m_rows(rows), m_cols(cols)
{
}

template<class T>
AMatrix<T>::AMatrix(const AMatrix<T>& other):  m_type(other.m_type), m_rows(other.m_rows), m_cols(other.m_cols)
{
}

template<class T>
AMatrix<T>::AMatrix(AMatrix<T>&& other): m_type(other.m_type), m_rows(other.m_rows), m_cols(other.m_cols)
{

}

template<class T>
AMatrix<T>::~AMatrix()
{
}

template<class T>
Vector<typename AMatrix<T>::ValueType> AMatrix<T>::getRow(const SizeType row) const
{
  if(row >= m_rows)
  {
    throw std::out_of_range( GEN_EXCEPT("Given row out of range") );
  }

  Vector<ValueType> tmp(m_cols);
  for(SizeType i = 0; i < m_cols; i++)
  {
    tmp[i] = this->get(row, i);
  }
  return tmp;
}

template<class T>
Vector<typename AMatrix<T>::ValueType> AMatrix<T>::getCol(const SizeType col) const
{
  if(col >= m_cols)
  {
    throw std::out_of_range( GEN_EXCEPT("Given column out of range") );
  }

  Vector<ValueType> tmp(m_rows);
  for(SizeType i = 0; i < m_rows; i++)
  {
    tmp[i] = this->get(i, col);
  }
  return tmp;
}

template<class T>
void AMatrix<T>::setRow(const SizeType row, const Vector< typename AMatrix<T>::ValueType >& values)
{
  if(row >= m_rows)
  {
    throw std::out_of_range( GEN_EXCEPT("Given row out of range") );
  }
  if(values.size() != m_cols)
  {
    throw std::out_of_range( GEN_EXCEPT("Given values length out of range") );
  }

  for(SizeType i = 0; i < m_cols; i++)
  {
    this->set(row, i, values[i]);
  }
}

template<class T>
void AMatrix<T>::setCol(const SizeType col, const Vector<T>& values)
{
  if(col >= m_cols)
  {
    throw std::out_of_range( GEN_EXCEPT("Given column out of range") );
  }
  if(values.size() != m_rows)
  {
    throw std::out_of_range( GEN_EXCEPT("Given values length out of range") );
  }

  for(SizeType i = 0; i < m_rows; i++)
  {
    this->set(i, col, values[i]);
  }
}

template<class T>
std::istream& AMatrix<T>::input(std::istream& stream)
{
  for(SizeType i = 0; i < m_rows; i++)
  {
    for(SizeType j = 0; j < m_cols; j++)
    {
      ValueType tmp;
      stream >> tmp;
      this->set(i, j, tmp);
    }
  }
  return stream;
}

template<class T>
std::ostream& AMatrix<T>::output(std::ostream& stream) const
{
  for(SizeType i = 0; i < m_rows; i++)
  {
    for(SizeType j = 0; j < m_cols; j++)
    {
      stream << std::setw(12) << this->get(i, j) << " ";
    }
    stream << std::endl;
  }
  return stream;
}

template<class T>
bool AMatrix<T>::equalTo(const AMatrix<T>& other) const
{
  if(m_rows != other.m_rows || m_cols != other.m_cols)
  {
    return false;
  }

  for(SizeType i = 0; i < m_rows; i++)
  {
    for(SizeType j = 0; j < m_cols; j++)
    {
      if(this->get(i, j) != other.get(i, j))
      {
        return false;
      }
    }
  }
  return true;
}
