//////////////////////////////////////////////////////////////////////
/// @file SymmetricMatrix
/// @author Your name and class section here
/// @brief A brief description of the file
//////////////////////////////////////////////////////////////////////

#ifndef SYMMETRIC_MATRIX_H
#define SYMMETRIC_MATRIX_H

#include "AMatrix.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix(const int);
/// @brief M x M constructor
/// @pre See SymmetricMatrix<T>(const int)
/// @post Constructs Upper triangular matrix with M x M size
/// @param m Size to allocate for Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix(const SymmetricMatrix<T>&);
/// @brief Copy constructor
/// @pre See SymmetricMatrix<T>(const SymmetricMatrix<T>&)
/// @post Constructs copied object
/// @param other Object to be copied
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix(SymmetricMatrix<T>&&);
/// @brief Move constructor
/// @pre See SymmetricMatrix<T>(SymmetricMatrix<T>&&)
/// @post Moves to copied object
/// @param other Object to be moved
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>& operator=(const SymmetricMatrix<T>& rhs);
/// @brief Copy assignment
/// @pre See SymmetricMatrix::operator=(const SymmetricMatrix<T>&);
/// @post Copies data from rhs to calling object
/// @param rhs Right hand side object
/// @return Calling Object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>& operator=(SymmetricMatrix<T>&& rhs);
/// @brief Copy assignment
/// @pre See SymmetricMatrix::operator=(const SymmetricMatrix<T>&);
/// @post Copies data from rhs to calling object
/// @param rhs Right hand side object
/// @return Calling Object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void set(const int m, const int n, const T& value);
/// @brief Mutator for individual elements
/// @pre Assignment must be defined on type T
/// @post The set value is updated
/// @param m row to set
/// @param n col to set
/// @param value Item value to set at m, n
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void get(const int m, const int n);
/// @brief Accessor for individual elements
/// @pre Assignment must be defined on type T
/// @param m row to get
/// @param n col to get
/// @return Item at m, n
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class SymmetricMatrix
/// @brief Symmetric Dense Matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class SymmetricMatrix: public AMatrix<T>
{
public:
  using ValueType = typename AMatrix<T>::ValueType;
  using ReferenceType = typename AMatrix<T>::ReferenceType;
  using ConstReferenceType = typename AMatrix<T>::ConstReferenceType;
  using PointerType = typename AMatrix<T>::PointerType;
  using ConstPointerType = typename AMatrix<T>::ConstPointerType;
  using SizeType = typename AMatrix<T>::SizeType;

  SymmetricMatrix(const int rowcols);
  SymmetricMatrix(const SymmetricMatrix<T>& other);
  SymmetricMatrix(SymmetricMatrix<T>&& other);
  virtual ~SymmetricMatrix();

  SymmetricMatrix<T>& operator=(const SymmetricMatrix<T>& rhs);
  SymmetricMatrix<T>& operator=(SymmetricMatrix<T>&& rhs);

  virtual ValueType get(const SizeType row, const SizeType col) const;
  virtual void set(const SizeType row, const SizeType col, const ValueType& value);
protected:
  Vector<ValueType> m_data;
};

#include "src/SymmetricMatrix.hpp"
#endif
