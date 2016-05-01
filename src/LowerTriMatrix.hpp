//////////////////////////////////////////////////////////////////////
/// @file LowerTriMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of lower triangular matrix
//////////////////////////////////////////////////////////////////////

template<class T>
LowerTriMatrix<T>::LowerTriMatrix(const int m): SymDenseMatrix<T>(m)
{
  this->m_type = MatrixType::LOWERTRI;
}

template<class T>
LowerTriMatrix<T>::LowerTriMatrix(const LowerTriMatrix<T>& other): SymDenseMatrix<T>(other)
{
  this->m_type = MatrixType::LOWERTRI;
}

template<class T>
LowerTriMatrix<T>::LowerTriMatrix(LowerTriMatrix<T>&& other): SymDenseMatrix<T>(other)
{
  this->m_type = MatrixType::LOWERTRI;
}

template<class T>
LowerTriMatrix<T>::~LowerTriMatrix()
{
}

template<class T>
LowerTriMatrix<T>& LowerTriMatrix<T>::operator=(const LowerTriMatrix<T>& rhs)
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
LowerTriMatrix<T>& LowerTriMatrix<T>::operator=(LowerTriMatrix<T>&& rhs)
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
void LowerTriMatrix<T>::set(const int m, const int n, const T& value)
{
  if(m < n)
  {
    throw std::domain_error("void LowerTriMatrix<T>::set(const int, const int, const T&) - Cannot set in upper triangle");
  }
  else
  {
    SymDenseMatrix<T>::set(m, n, value);
  }
}

template<class T>
T LowerTriMatrix<T>::get(const int m, const int n) const
{
  if(m > n) {
    return 0;
  }
  else
  {
    return SymDenseMatrix<T>::get(m, n);
  }
}
