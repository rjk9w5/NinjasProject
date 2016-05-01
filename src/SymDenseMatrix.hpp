//////////////////////////////////////////////////////////////////////
/// @file SymDenseMatrix.h
/// @author Russley Shaw
/// @brief Symmetric Dense Matric implementation 
//////////////////////////////////////////////////////////////////////

template<class T>
SymDenseMatrix<T>::SymDenseMatrix(const int m): DenseMatrix<T>(m, m)
{
  this->m_type = MatrixType::SYMMETRIC_DENSE;
}

template<class T>
SymDenseMatrix<T>::SymDenseMatrix(const SymDenseMatrix<T>& other): DenseMatrix<T>(other)
{
  this->m_type = MatrixType::SYMMETRIC_DENSE;
}

template<class T>
SymDenseMatrix<T>::SymDenseMatrix(SymDenseMatrix<T>&& other): DenseMatrix<T>(other)
{
  this->m_type = MatrixType::SYMMETRIC_DENSE;
}

template<class T>
SymDenseMatrix<T>& SymDenseMatrix<T>::operator=(const SymDenseMatrix<T>& rhs)
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
SymDenseMatrix<T>& SymDenseMatrix<T>::operator=(SymDenseMatrix<T>&& rhs)
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
SymDenseMatrix<T>::~SymDenseMatrix()
{
}

template<class T>
void SymDenseMatrix<T>::set(const int m, const int n, const T& value)
{
  DenseMatrix<T>::set(m, n, value);
  DenseMatrix<T>::set(n, m, value);
}
