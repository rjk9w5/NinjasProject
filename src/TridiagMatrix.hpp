////////////////////////////////////////////////////////////////////////////////
/// @file TridiagMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation for Tridiagonal Matrix
////////////////////////////////////////////////////////////////////////////////

#include <utility>

#include "MatrixType.h"


template<class T>
TridiagMatrix<T>::TridiagMatrix(const int m, const int n): AMatrix<T>(MatrixType::TRIDIAGONAL, m, n), m_data(3, m)
{
}

template<class T>
TridiagMatrix<T>::TridiagMatrix(const TridiagMatrix<T>& other): AMatrix<T>(other), m_data(other.m_data)
{
}

template<class T>
TridiagMatrix<T>::TridiagMatrix(TridiagMatrix<T>&& other): AMatrix<T>(other), m_data( std::move(other.m_data) )
{
}

template<class T>
TridiagMatrix<T>::~TridiagMatrix()
{
}

template<class T>
T TridiagMatrix<T>::get(const int row, const int col) const
{
  if(row < 0 || col < 0 || row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range("Given row & col must be within bounds of matrix");
  }
  else if(row == col)
  {
    return m_data.get(1, row);
  }
  else if(row+1 == col)
  {
    return m_data.get(0, row);
  }
  else if(col+1 == row)
  {
    return m_data.get(2, col);
  }

  return 0;
}

template<class T>
void TridiagMatrix<T>::set(const int row, const int col, const T& value)
{
  if(row < 0 || col < 0 || row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range("Given row & col must be within bounds of matrix");
  }
  else if(row == col)
  {
    return m_data.set(1, row, value);
  }
  else if(row+1 == col)
  {
    return m_data.set(0, row, value);
  }
  else if(col+1 == row)
  {
    return m_data.set(2, col, value);
  }
  else
  {
    throw std::domain_error("void TridiagMatrix<T>::set(const int, const int, const T&) - Cannot set outside triple band");
  }
}

template<class T>
void TridiagMatrix<T>::setRow(const int row, const Vector<T>& values)
{
  if(row-1 >= 0)
  {
    this->set(row, row-1, values[row-1]);
  }

  this->set(row, row, values[row]);

  if(row+1 < this->rows())
  {
    this->set(row, row+1, values[row+1]);
  }
}

template<class T>
void TridiagMatrix<T>::setCol(const int col, const Vector<T>& values)
{
  if(col-1 >= 0)
  {
    this->set(col-1, col, values[col-1]);
  }

  this->set(col, col, values[col]);

  if(col+1 < this->cols())
  {
    this->set(col+1, col, values[col+1]);
  }
}

template<class T>
std::istream& TridiagMatrix<T>::input(std::istream& stream)
{
  T elem;
  for(int i = 0; i < this->rows(); i++)
  {
    for(int j = 0; j < this->cols(); j++)
    {
      stream >> elem;
      this->set(i, j, elem);
    }
  }
  return stream;
}

template<class T>
Vector<T> TridiagMatrix<T>::getRow(const int row) const
{
  Vector<T> tmp(this->cols());

  for(int i = 0; i < this->cols(); i++)
  {
    tmp[i] = this->get(row, i);
  }
  return tmp;
}

template<class T>
Vector<T> TridiagMatrix<T>::getCol(const int col) const
{
  Vector<T> tmp(this->rows());

  for(int i = 0; i < this->rows(); i++)
  {
    tmp[i] = this->get(i, col);
  }
  return tmp;
}

template<class T>
std::ostream& TridiagMatrix<T>::output(std::ostream& stream) const
{
  for(int i = 0; i < this->rows(); i++)
  {
    for(int j = 0; j < this->cols(); j++)
    {
      stream << std::setw(16) << std::setprecision(10) << std::fixed << this->get(i, j) << " ";
    }
    stream << std::endl;
  }
  return stream;
}

template<class T>
bool TridiagMatrix<T>::equalTo(const AMatrix<T>& other) const
{
  for(int i = 0; i < this->rows(); i++)
  {
    for(int j = 0; j < this->cols(); j++)
    {
      if(this->get(i, j) != other.get(i, j))
      {
        return false;
      }
    }
  }
  return true;
}
