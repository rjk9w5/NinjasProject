//////////////////////////////////////////////////////////////////////
/// @file UpperTriMatrix.h
/// @author Russley Shaw
/// @brief Upper Triangular Matrix
//////////////////////////////////////////////////////////////////////

#ifndef UPPER_TRI_MATRIX_H
#define UPPER_TRI_MATRIX_H

#include "SymDenseMatrix.h"
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
/// @brief Upper  Tridiagonal Matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class UpperTriMatrix: public SymDenseMatrix<T>
{
public:
  UpperTriMatrix(const int m);
  UpperTriMatrix(const UpperTriMatrix<T>& other);
  UpperTriMatrix(UpperTriMatrix<T>&& other);
  virtual ~UpperTriMatrix();

  UpperTriMatrix<T>& operator=(const UpperTriMatrix<T>& rhs);
  UpperTriMatrix<T>& operator=(UpperTriMatrix<T>&& rhs);

  virtual void set(const int m, const int n, const T& value);
  virtual T get(const int m, const int n) const;
};

#include "src/UpperTriMatrix.hpp"
#endif
