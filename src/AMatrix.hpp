//////////////////////////////////////////////////////////////////////
/// @file AMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of base Matrix class
//////////////////////////////////////////////////////////////////////

template<class T>
AMatrix<T>::AMatrix(const MatrixType& type, const int m, const int n): m_type(type), m_rows(m), m_cols(n)
{
  if(m < 0)
  {
    throw std::length_error("AMatrix::AMatrix(const int, const int) - Param m cannot be less than 0");
  }
  if(n < 0)
  {
    throw std::length_error("AMatrix::AMatrix(const int, const int) - Param n cannot be less than 0");
  }
}

template<class T>
AMatrix<T>::AMatrix(const AMatrix& other):  m_type(other.m_type), m_rows(other.m_rows), m_cols(other.m_cols)
{
}

template<class T>
AMatrix<T>::AMatrix(AMatrix&& other): m_type(other.m_type), m_rows(other.m_rows), m_cols(other.m_cols)
{

}

template<class T>
AMatrix<T>::~AMatrix()
{
}
