//////////////////////////////////////////////////////////////////////
/// @file SymDenseMatrix
/// @author Your name and class section here
/// @brief A brief description of the file
//////////////////////////////////////////////////////////////////////

#ifndef SYM_DENSE_MATRIX_H
#define SYM_DENSE_MATRIX_H

#include "DenseMatrix.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn SymDenseMatrix(const int);
/// @brief M x M constructor
/// @pre See SymDenseMatrix<T>(const int)
/// @post Constructs Upper triangular matrix with M x M size
/// @param m Size to allocate for Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymDenseMatrix(const SymDenseMatrix<T>&);
/// @brief Copy constructor
/// @pre See SymDenseMatrix<T>(const SymDenseMatrix<T>&)
/// @post Constructs copied object
/// @param other Object to be copied
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymDenseMatrix(SymDenseMatrix<T>&&);
/// @brief Move constructor
/// @pre See SymDenseMatrix<T>(SymDenseMatrix<T>&&)
/// @post Moves to copied object
/// @param other Object to be moved
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymDenseMatrix<T>& operator=(const SymDenseMatrix<T>& rhs);
/// @brief Copy assignment
/// @pre See SymDenseMatrix::operator=(const SymDenseMatrix<T>&);
/// @post Copies data from rhs to calling object
/// @param rhs Right hand side object
/// @return Calling Object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymDenseMatrix<T>& operator=(SymDenseMatrix<T>&& rhs);
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
/// @class SymDenseMatrix
/// @brief Symmetric Dense Matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class SymDenseMatrix: public DenseMatrix<T>
{
public:
  SymDenseMatrix(const int m);
  SymDenseMatrix(const SymDenseMatrix<T>& other);
  SymDenseMatrix(SymDenseMatrix<T>&& other);
  virtual ~SymDenseMatrix();

  SymDenseMatrix<T>& operator=(const SymDenseMatrix<T>& rhs);
  SymDenseMatrix<T>& operator=(SymDenseMatrix<T>&& rhs);

  virtual T get(const int m, const int n) const { return DenseMatrix<T>::get(m, n); }
  virtual void set(const int m, const int n, const T& value);
};

#include "src/SymDenseMatrix.hpp"
#endif
