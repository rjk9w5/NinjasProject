//////////////////////////////////////////////////////////////////////
/// @file LowerTriMatrix.h
/// @author Russley Shaw
/// @brief Lower Triangular Matrix
//////////////////////////////////////////////////////////////////////

#ifndef LOWER_TRIANGULAR_MATRIX_H
#define LOWER_TRIANGULAR_MATRIX_H

#include "SymmetricMatrix.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix(const int);
/// @brief M x M constructor
/// @pre See SymDenseMatrix<T>(const int)
/// @post Constructs Upper triangular matrix with M x M size
/// @param m Size to allocate for Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix(const LowerTriMatrix<T>&);
/// @brief Copy constructor
/// @pre See SymDenseMatrix<T>(const SymDenseMatrix<T>&)
/// @post Constructs copied object
/// @param other Object to be copied
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix(LowerTriMatrix<T>&&);
/// @brief Move constructor
/// @pre See SymDenseMatrix<T>(SymDenseMatrix<T>&&)
/// @post Moves to copied object
/// @param other Object to be moved
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>& operator=(const LowerTriMatrix<T>& rhs);
/// @brief Copy assignment
/// @pre See SymDenseMatrix::operator=(const SymDenseMatrix<T>&);
/// @post Copies data from rhs to calling object
/// @param rhs Right hand side object
/// @return Calling Object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>& operator=(LowerTriMatrix<T>&& rhs);
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
/// @class LowerTriMatrix
/// @brief Lower Triangular Matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class LowerTriMatrix: public SymmetricMatrix<T>
{
public:
  using ValueType = typename AMatrix<T>::ValueType;
  using ReferenceType = typename AMatrix<T>::ReferenceType;
  using ConstReferenceType = typename AMatrix<T>::ConstReferenceType;
  using PointerType = typename AMatrix<T>::PointerType;
  using ConstPointerType = typename AMatrix<T>::ConstPointerType;
  using SizeType = typename AMatrix<T>::SizeType;

  LowerTriMatrix(const SizeType size);
  LowerTriMatrix(const LowerTriMatrix<T>& other);
  LowerTriMatrix(LowerTriMatrix<T>&& other);
  virtual ~LowerTriMatrix(){}

  virtual MatrixType type() const { return MatrixType::LOWERTRI; }

  LowerTriMatrix<T>& operator=(const LowerTriMatrix<T>& other);
  LowerTriMatrix<T>& operator=(LowerTriMatrix<T>&& other);

  virtual ValueType get(const SizeType row, const SizeType col) const;
  virtual void set(const SizeType row, const SizeType col, ConstReferenceType value);

  LowerTriMatrix<T>& copy(const LowerTriMatrix<T>& other) { return BandedMatrix<T>::copy(other); }
  LowerTriMatrix<T>& swap(LowerTriMatrix<T>& other) { return BandedMatrix<T>::swap(other); }
  LowerTriMatrix<T>& move(LowerTriMatrix<T>&& other) { return BandedMatrix<T>::move(other); }
};

#include "src/LowerTriMatrix.hpp"
#endif
