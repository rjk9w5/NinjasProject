//////////////////////////////////////////////////////////////////////
/// @file SymmetricMatrix.h
/// @author Russley Shaw
/// @brief Symmetric Matric implementation
//////////////////////////////////////////////////////////////////////

#include <cassert>

template<class T>
SymmetricMatrix<T>::SymmetricMatrix(const SizeType rowcols)
  :AMatrix<T>(MatrixType::SYMMETRIC, rowcols, rowcols), m_data( (rowcols*(rowcols+1))/2 )
{
}

template<class T>
SymmetricMatrix<T>::SymmetricMatrix(const SymmetricMatrix<T>& other)
  :AMatrix<T>(other), m_data(other.m_data)
{
}

template<class T>
SymmetricMatrix<T>::SymmetricMatrix(SymmetricMatrix<T>&& other)
  :AMatrix<T>(other), m_data(std::move(other.m_data))
{
}

template<class T>
SymmetricMatrix<T>::~SymmetricMatrix()
{
}

template<class T>
SymmetricMatrix<T>& SymmetricMatrix::operator=(const SymmetricMatrix<T>& other)
{
  if(this != &other)
  {
    this->m_rows = other.m_rows;
    this->m_cols = other.m_cols;
    this->m_data = other.m_data;
  }
}

SymmetricMatrix<T>& operator=(SymmetricMatrix<T>&& rhs);

virtual T get(const int m, const int n) const;
virtual void set(const int m, const int n, const T& value);
