//////////////////////////////////////////////////////////////////////
/// @file SymmetricMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of Symmetric Matrix
//////////////////////////////////////////////////////////////////////

#include <cassert>

template<class T>
SymmetricMatrix<T>::SymmetricMatrix(const SizeType size):
  AMatrix<T>(size, size), m_data( size * (size+1) / 2 )
{
  assert(this->rows()*(this->rows()+1)/2 == m_data.size() );
  assert(this->cols()*(this->cols()+1)/2 == m_data.size() );
}

template<class T>
SymmetricMatrix<T>::SymmetricMatrix(const SymmetricMatrix<T>& other):
  AMatrix<T>(other), m_data( other.m_data )
{
}

template<class T>
SymmetricMatrix<T>::SymmetricMatrix(SymmetricMatrix<T>&& other):
  AMatrix<T>(other), m_data( std::move(other.m_data) )
{
}

template<class T>
SymmetricMatrix<T>& SymmetricMatrix<T>::operator=(const SymmetricMatrix<T>& other)
{
  if(this != &other)
  {
    copy(other);
  }
  return *this;
}

template<class T>
SymmetricMatrix<T>& SymmetricMatrix<T>::operator=(SymmetricMatrix<T>&& other)
{
  if(this != &other)
  {
    move(std::move(other));
  }
  return *this;
}


template<class T>
typename SymmetricMatrix<T>::ValueType SymmetricMatrix<T>::get(const SizeType row, const SizeType col) const
{
  if(row >= this->rows() || col >= this->cols() )
  {
    throw std::out_of_range( GEN_EXCEPT("Given row,col should not be outside range of matrix row, col") );
  }
  return m_data[ rowColToIndex(row, col) ];
}

template<class T>
void SymmetricMatrix<T>::set(const SizeType row, const SizeType col, ConstReferenceType value)
{
  if(row >= this->rows() || col >= this->cols() )
  {
    throw std::out_of_range( GEN_EXCEPT("Given row,col should not be outside range of matrix row, col") );
  }
  m_data[ rowColToIndex(row, col) ] = value;
}


template<class T>
SymmetricMatrix<T>& SymmetricMatrix<T>::copy(const SymmetricMatrix<T>& other)
{
  m_data = other.m_data;
  AMatrix<T>::copy(other);
  return *this;
}

template<class T>
SymmetricMatrix<T>& SymmetricMatrix<T>::swap(SymmetricMatrix<T>& other)
{
  using std::swap;
  swap(m_data, other.m_data);
  AMatrix<T>::swap(other);
  return *this;
}

template<class T>
SymmetricMatrix<T>& SymmetricMatrix<T>::move(SymmetricMatrix<T>&& other)
{
  using std::move;
  m_data = std::move(other.m_data);
  AMatrix<T>::move(std::move(other));
  return *this;
}

template<class T>
typename SymmetricMatrix<T>::SizeType SymmetricMatrix<T>::rowColToIndex(const SizeType row, const SizeType col) const
{
  if (row <= col)
  {
    return row * this->rows() - (row - 1) * row / 2 + col - row;
  }
  else
  {
    return col * this->rows() - (col - 1) * col / 2 + row - col;
  }
}
