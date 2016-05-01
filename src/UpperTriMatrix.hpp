//////////////////////////////////////////////////////////////////////
/// @file UpperTriMatrix.hpp
/// @author Russley Shaw
/// @brief An implementation of Upper Triangular Matricies
//////////////////////////////////////////////////////////////////////

template<class T>
UpperTriMatrix<T>::UpperTriMatrix(const int m): SymDenseMatrix<T>(m)
{
  this->m_type = MatrixType::UPPERTRI;
}

template<class T>
UpperTriMatrix<T>::UpperTriMatrix(const UpperTriMatrix<T>& other): SymDenseMatrix<T>(other)
{
  this->m_type = MatrixType::UPPERTRI;
}

template<class T>
UpperTriMatrix<T>::UpperTriMatrix(UpperTriMatrix<T>&& other): SymDenseMatrix<T>(other)
{
  this->m_type = MatrixType::UPPERTRI;
}

template<class T>
UpperTriMatrix<T>::~UpperTriMatrix()
{
}

template<class T>
UpperTriMatrix<T>& UpperTriMatrix<T>::operator=(const UpperTriMatrix<T>& rhs)
{
  if(this != &rhs)
  {
    this->m_type = rhs.m_type;
    this->m_rows = rhs.m_rows;
    this->m_cols = rhs.m_cols;
    this->m_data = rhs.m_data;
  }
  return *this;
}

template<class T>
UpperTriMatrix<T>& UpperTriMatrix<T>::operator=(UpperTriMatrix<T>&& rhs)
{
  if(this != &rhs)
  {
    this->m_type = rhs.m_type;
    this->m_rows = rhs.m_rows;
    this->m_cols = rhs.m_cols;
    this->m_data = std::move(rhs.m_data);
  }
  return *this;
}

template<class T>
void UpperTriMatrix<T>::set(const int m, const int n, const T& value)
{
  if(m > n)
  {
    throw std::domain_error("void UpperTriMatrix<T>::set(const int, const int, const T&) - Cannot set in lower triangle");
  }
  else
  {
    SymDenseMatrix<T>::set(m, n, value);
  }
}

template<class T>
T UpperTriMatrix<T>::get(const int m, const int n) const
{
  if(m > n) {
    return 0;
  }
  else
  {
    return SymDenseMatrix<T>::get(m, n);
  }
}
