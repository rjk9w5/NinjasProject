//////////////////////////////////////////////////////////////////////
/// @file UpperTriMatrix.hpp
/// @author Russley Shaw
/// @brief An implementation of Upper Triangular Matricies
//////////////////////////////////////////////////////////////////////

template<class T>
UpperTriMatrix<T>::UpperTriMatrix(const SizeType size):
  SymmetricMatrix<T>(size)
{
}

template<class T>
UpperTriMatrix<T>::UpperTriMatrix(const UpperTriMatrix<T>& other):
  SymmetricMatrix<T>(other)
{
}

template<class T>
UpperTriMatrix<T>::UpperTriMatrix(UpperTriMatrix<T>&& other):
  SymmetricMatrix<T>(other)
{
}

template<class T>
UpperTriMatrix<T>& UpperTriMatrix<T>::operator=(const UpperTriMatrix<T>& other)
{
  if(this != &other)
  {
    copy(other);
  }
  return *this;
}

template<class T>
UpperTriMatrix<T>& UpperTriMatrix<T>::operator=(UpperTriMatrix<T>&& other)
{
  if(this != &other)
  {
    move(std::move(other));
  }
  return *this;
}

template<class T>
typename UpperTriMatrix<T>::ValueType UpperTriMatrix<T>::get(const SizeType row, const SizeType col) const
{
  if(row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT( "Given row,col should be within matrix's row,col" ) );
  }
  else if(col >= row)
  {
    return SymmetricMatrix<T>::get(row, col);
  }
  else
  {
    return 0;
  }
}

template<class T>
void UpperTriMatrix<T>::set(const SizeType row, const SizeType col, ConstReferenceType value)
{
  if(row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT( "Given row,col should be within matrix's row,col" ) );
  }
  else if(col >= row)
  {
    return SymmetricMatrix<T>::set(row, col, value);
  }
  else if(value == 0)
  {
    //Do nothing
  }
  else
  {
    throw std::domain_error( GEN_EXCEPT("Cannot edit values in lower half of upper triangular") );
  }
}
