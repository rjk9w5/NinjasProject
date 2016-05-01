//////////////////////////////////////////////////////////////////////
/// @file DiagonalMatrix.h
/// @author Russley Shaw
/// @brief A diagonal matrix
//////////////////////////////////////////////////////////////////////

#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "TridiagMatrix.h"

//////////////////////////////////////////////////////////////////////
/// @fn DiagonalMatrix(const int);
/// @brief M x M constructor
/// @pre See DiagonalMatrix<T>(const int)
/// @post Constructs Upper triangular matrix with M x M size
/// @param m Size to allocate for Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DiagonalMatrix(const DiagonalMatrix<T>&);
/// @brief Copy constructor
/// @pre See DiagonalMatrix<T>(const DiagonalMatrix<T>&)
/// @post Constructs copied object
/// @param other Object to be copied
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DiagonalMatrix(DiagonalMatrix<T>&&);
/// @brief Move constructor
/// @pre See DiagonalMatrix<T>(DiagonalMatrix<T>&&)
/// @post Moves to copied object
/// @param other Object to be moved
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DiagonalMatrix<T>& operator=(const DiagonalMatrix<T>& rhs);
/// @brief Copy assignment
/// @pre See DiagonalMatrix::operator=(const DiagonalMatrix<T>&);
/// @post Copies data from rhs to calling object
/// @param rhs Right hand side object
/// @return Calling Object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DiagonalMatrix<T>& operator=(DiagonalMatrix<T>&& rhs);
/// @brief Copy assignment
/// @pre See DiagonalMatrix::operator=(const DiagonalMatrix<T>&);
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
/// @class DiagonalMatrix<T>
/// @brief Header of a diagonal matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class DiagonalMatrix: public TridiagMatrix<T>
{
public:
  DiagonalMatrix(const int m);
  DiagonalMatrix(const DiagonalMatrix<T>& other);
  DiagonalMatrix(DiagonalMatrix<T>&& other);
  virtual ~DiagonalMatrix();

  DiagonalMatrix<T>& operator=(const DiagonalMatrix<T>& other);
  DiagonalMatrix<T>& operator=(DiagonalMatrix<T>&& other);

  virtual T get(const int m, const int n) const;
  virtual void set(const int m, const int n, const T& value);
};



#include "src/DiagonalMatrix.hpp"
#endif
