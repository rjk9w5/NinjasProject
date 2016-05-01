//////////////////////////////////////////////////////////////////////
/// @file DiagonalMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of DiagonalMatrix
//////////////////////////////////////////////////////////////////////

template<class T>
DiagonalMatrix<T>::DiagonalMatrix(const int m): TridiagMatrix<T>(m, m)
{
  this->m_type = MatrixType::DIAGONAL;
}

template<class T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& other): TridiagMatrix<T>(other)
{
  this->m_type = MatrixType::DIAGONAL;
}

template<class T>
DiagonalMatrix<T>::DiagonalMatrix(DiagonalMatrix<T>&& other): TridiagMatrix<T>(other)
{
  this->m_type = MatrixType::DIAGONAL;
}

template<class T>
DiagonalMatrix<T>::~DiagonalMatrix()
{
}

template<class T>
DiagonalMatrix<T>& DiagonalMatrix<T>::operator=(const DiagonalMatrix<T>& rhs)
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
DiagonalMatrix<T>& DiagonalMatrix<T>::operator=(DiagonalMatrix<T>&& rhs)
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
T DiagonalMatrix<T>::get(const int m, const int n) const
{
  if(m == n)
  {
    return TridiagMatrix<T>::get(m, m);
  }
  else
  {
    return 0;
  }
}

template<class T>
void DiagonalMatrix<T>::set(const int m, const int n, const T& value)
{
  if(m == n)
  {
    TridiagMatrix<T>::set(m, m, value);
  }
  else
  {
    throw std::domain_error("void DiagonalMatrix<T>::set(const int, const int, const T&) - cannot set outside the diagonal");
  }
}

template<class T>
DiagonalMatrix<T> operator*(const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs)
{
  if(lhs.cols() != rhs.rows())
  {
    throw std::length_error("DiagonalMatrix<T> operator*(const DiagonalMatrix<T>&, const DiagonalMatrix<T>&) - lhs must have same number columns as rhs has rows");
  }
  DiagonalMatrix<T> product(lhs.rows());
  for(int i = 0; i < lhs.rows(); i++)
  {
     product.set(i, i, lhs.get(i, i) * rhs.get(i, i));
  }
  return product;
}
