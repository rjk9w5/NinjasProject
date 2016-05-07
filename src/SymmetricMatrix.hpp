//////////////////////////////////////////////////////////////////////
/// @file SymmetricMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of Symmetric Matrix
//////////////////////////////////////////////////////////////////////

#include <cassert>

template<class T>
SymmetricMatrix<T>::SymmetricMatrix(const SizeType size):
  AMatrix<T>(size, size), m_data( size * (size+1) / 2 );
{
  assert(this->rows()*(this->rows()+1)/2 == m_data.size() );
  assert(this->cols()*(this->cols()+1)/2 == m_data.size() );
}

SymmetricMatrix(const SymmetricMatrix<T>& other);
SymmetricMatrix(SymmetricMatrix<T>&& other);
virtual ~SymmetricMatrix(){}

virtual MatrixType type() const { return MatrixType::SYMMETRIC; }

SymmetricMatrix<T>& operator=(const SymmetricMatrix<T>& other);
SymmetricMatrix<T>& operator=(SymmetricMatrix<T>&& other);

virtual ValueType get(const SizeType row, const SizeType col) const;
virtual void set(const SizeType row, const SizeType col, ConstReferenceType value);

Symmetric<T>& copy(const Symmetric<T>& other);
Symmetric<T>& swap(Symmetric<T>& other);
Symmetric<T>& move(Symmetric<T>&& other);
