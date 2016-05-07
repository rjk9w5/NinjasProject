//////////////////////////////////////////////////////////////////////
/// @file AMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of base Matrix class
//////////////////////////////////////////////////////////////////////

#include "Utils.h"

template<class T>
AMatrix<T>::AMatrix(const SizeType rows, const SizeType cols): m_rows(rows), m_cols(cols)
{
}

template<class T>
AMatrix<T>::AMatrix(const AMatrix<T>& other): m_rows(other.m_rows), m_cols(other.m_cols)
{
}

template<class T>
AMatrix<T>::AMatrix(AMatrix<T>&& other): m_rows(other.m_rows), m_cols(other.m_cols)
{

}

template<class T>
AMatrix<T>& AMatrix<T>::copy(const AMatrix<T>& other)
{
  m_rows = other.m_rows;
  m_cols = other.m_cols;
  return *this;
}

template<class T>
AMatrix<T>& AMatrix<T>::swap(AMatrix<T>& other)
{
  using std::swap;
  swap(m_rows, other.m_rows);
  swap(m_cols, other.m_cols);
  return *this;
}

template<class T>
AMatrix<T>& AMatrix<T>::move(AMatrix<T>&& other)
{
  m_rows = other.m_rows;
  m_cols = other.m_cols;
  return *this;
}


template<class T>
Vector<typename AMatrix<T>::ValueType> AMatrix<T>::getRow(const SizeType row) const
{
  if(row >= this->rows())
  {
    throw std::out_of_range( GEN_EXCEPT("Given row out of range") );
  }

  Vector<ValueType> tmp(this->cols());
  for(SizeType i = 0; i < this->cols(); i++)
  {
    tmp[i] = this->get(row, i);
  }
  return tmp;
}

template<class T>
Vector<typename AMatrix<T>::ValueType> AMatrix<T>::getCol(const SizeType col) const
{
  if(col >= this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT("Given column out of range") );
  }

  Vector<ValueType> tmp(this->rows());
  for(SizeType i = 0; i < this->rows(); i++)
  {
    tmp[i] = this->get(i, col);
  }
  return tmp;
}

template<class T>
void AMatrix<T>::setRow(const SizeType row, const Vector< typename AMatrix<T>::ValueType >& values)
{
  if(row >= this->rows())
  {
    throw std::out_of_range( GEN_EXCEPT("Given row out of range") );
  }
  if(values.size() != this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT("Given values length out of range") );
  }

  for(SizeType i = 0; i < this->cols(); i++)
  {
    this->set(row, i, values[i]);
  }
}

template<class T>
void AMatrix<T>::setCol(const SizeType col, const Vector<T>& values)
{
  if(col >= this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT("Given column out of range") );
  }
  if(values.size() != this->rows())
  {
    throw std::out_of_range( GEN_EXCEPT("Given values length out of range") );
  }

  for(SizeType i = 0; i < this->rows(); i++)
  {
    this->set(i, col, values[i]);
  }
}

template<class T>
std::istream& AMatrix<T>::input(std::istream& stream)
{
  for(SizeType i = 0; i < this->rows(); i++)
  {
    for(SizeType j = 0; j < this->cols(); j++)
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
  for(SizeType i = 0; i < this->rows(); i++)
  {
    for(SizeType j = 0; j < this->cols(); j++)
    {
      stream << std::setw(6) << this->get(i, j) << " ";
    }
    stream << std::endl;
  }
  return stream;
}

template<class T>
bool AMatrix<T>::isEqual(const AMatrix<T>& other) const
{
  if(this->rows() != other.rows() || this->cols() != other.cols())
  {
    return false;
  }

  for(SizeType i = 0; i < this->rows(); i++)
  {
    for(SizeType j = 0; j < this->cols(); j++)
    {
      if(this->get(i, j) != other.get(i, j))
      {
        return false;
      }
    }
  }
  return true;
}
