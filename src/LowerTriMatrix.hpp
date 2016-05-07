//////////////////////////////////////////////////////////////////////
/// @file LowerTriMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of lower triangular matrix
//////////////////////////////////////////////////////////////////////

template<class T>
LowerTriMatrix<T>::LowerTriMatrix(const SizeType size):
  SymmetricMatrix<T>(size)
{
}

template<class T>
LowerTriMatrix<T>::LowerTriMatrix(const LowerTriMatrix<T>& other):
  SymmetricMatrix<T>(other)
{
}

template<class T>
LowerTriMatrix<T>::LowerTriMatrix(LowerTriMatrix<T>&& other):
  SymmetricMatrix<T>(other)
{
}

template<class T>
LowerTriMatrix<T>& LowerTriMatrix<T>::operator=(const LowerTriMatrix<T>& other)
{
  if(this != &other)
  {
    copy(other);
  }
  return *this;
}

template<class T>
LowerTriMatrix<T>& LowerTriMatrix<T>::operator=(LowerTriMatrix<T>&& other)
{
  if(this != &other)
  {
    move(other);
  }
  return *this;
}

template<class T>
typename LowerTriMatrix<T>::ValueType LowerTriMatrix<T>::get(const SizeType row, const SizeType col) const
{
  if(row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT( "Given row,col should be within matrix's row,col" ) );
  }
  else if(col <= row)
  {
    return SymmetricMatrix<T>::get(row, col);
  }
  else
  {
    return 0;
  }
}

template<class T>
void LowerTriMatrix<T>::set(const SizeType row, const SizeType col, ConstReferenceType value)
{
  if(row >= this->rows() || col >= this->cols())
  {
    throw std::out_of_range( GEN_EXCEPT( "Given row,col should be within matrix's row,col" ) );
  }
  else if(col <= row)
  {
    return SymmetricMatrix<T>::set(row, col, value);
  }
  else if(value == 0)
  {
    //Do nothing
  }
  else
  {
    throw std::domain_error( GEN_EXCEPT("Cannot edit values in upper half of lower triangular") );
  }
}
