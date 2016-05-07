//////////////////////////////////////////////////////////////////////
/// @file UpperTriMatrix.h
/// @author Russley Shaw
/// @brief Upper Triangular Matrix
//////////////////////////////////////////////////////////////////////

#ifndef UPPER_TRIANGULAR_MATRIX_H
#define UPPER_TRIANGULAR_MATRIX_H

#include "SymmetricMatrix.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix(const int);
/// @brief M x M constructor
/// @pre See SymDenseMatrix<T>(const int)
/// @post Constructs Upper triangular matrix with M x M size
/// @param m Size to allocate for Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix(const UpperTriMatrix<T>&);
/// @brief Copy constructor
/// @pre See SymDenseMatrix<T>(const SymDenseMatrix<T>&)
/// @post Constructs copied object
/// @param other Object to be copied
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix(UpperTriMatrix<T>&&);
/// @brief Move constructor
/// @pre See SymDenseMatrix<T>(SymDenseMatrix<T>&&)
/// @post Moves to copied object
/// @param other Object to be moved
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>& operator=(const UpperTriMatrix<T>& rhs);
/// @brief Copy assignment
/// @pre See SymDenseMatrix::operator=(const SymDenseMatrix<T>&);
/// @post Copies data from rhs to calling object
/// @param rhs Right hand side object
/// @return Calling Object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>& operator=(UpperTriMatrix<T>&& rhs);
/// @brief Copy assignment
/// @pre See SymDenseMatrix::operator=(const SymDenseMatrix<T>&);
/// @post Copies data from rhs to calling object
/// @param rhs Right hand side object
/// @return Calling Object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void set(const int m, const int n, const T& value);
/// @brief Mutator for individual elements
/// @pre Assignment must be defined on type T
/// @post The set value is updated. Throws if set is in lower triangle
/// @param m row to set
/// @param n col to set
/// @param value Item value to set at m, n
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void get(const int m, const int n);
/// @brief Accessor for individual elements
/// @pre Assignment must be defined on type T
/// @post The set value is updated. Throws if set is in lower triangle
/// @param m row to get
/// @param n col to get
/// @return Item at m, n
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class UpperTriMatrix
/// @brief Upper  Triangular Matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class UpperTriMatrix: public SymmetricMatrix<T>
{
public:
  using ValueType = typename AMatrix<T>::ValueType;
  using ReferenceType = typename AMatrix<T>::ReferenceType;
  using ConstReferenceType = typename AMatrix<T>::ConstReferenceType;
  using PointerType = typename AMatrix<T>::PointerType;
  using ConstPointerType = typename AMatrix<T>::ConstPointerType;
  using SizeType = typename AMatrix<T>::SizeType;

  UpperTriMatrix(const SizeType size);
  UpperTriMatrix(const UpperTriMatrix<T>& other);
  UpperTriMatrix(UpperTriMatrix<T>&& other);
  virtual ~UpperTriMatrix(){}

  virtual MatrixType type() const { return MatrixType::UPPERTRI; }

  UpperTriMatrix<T>& operator=(const UpperTriMatrix<T>& other);
  UpperTriMatrix<T>& operator=(UpperTriMatrix<T>&& other);

  virtual ValueType get(const SizeType row, const SizeType col) const;
  virtual void set(const SizeType row, const SizeType col, ConstReferenceType value);

  UpperTriMatrix<T>& copy(const UpperTriMatrix<T>& other) { return BandedMatrix<T>::copy(other); }
  UpperTriMatrix<T>& swap(UpperTriMatrix<T>& other) { return BandedMatrix<T>::swap(other); }
  UpperTriMatrix<T>& move(UpperTriMatrix<T>&& other) { return BandedMatrix<T>::move(other); }
};

#include "src/UpperTriMatrix.hpp"
#endif
