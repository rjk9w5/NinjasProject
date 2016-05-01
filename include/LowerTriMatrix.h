//////////////////////////////////////////////////////////////////////
/// @file LowerTriMatrix.h
/// @author Russley Shaw
/// @brief Lower Triangular Matrix
//////////////////////////////////////////////////////////////////////

#ifndef LOWER_TRI_MATRIX_H
#define LOWER_TRI_MATRIX_H

#include "SymDenseMatrix.h"
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
class LowerTriMatrix: public SymDenseMatrix<T>
{
public:
  LowerTriMatrix(const int m);
  LowerTriMatrix(const LowerTriMatrix<T>& other);
  LowerTriMatrix(LowerTriMatrix<T>&& other);
  virtual ~LowerTriMatrix();

  LowerTriMatrix<T>& operator=(const LowerTriMatrix<T>& rhs);
  LowerTriMatrix<T>& operator=(LowerTriMatrix<T>&& rhs);

  virtual void set(const int m, const int n, const T& value);
  virtual T get(const int m, const int n) const;
};

#include "src/LowerTriMatrix.hpp"
#endif
