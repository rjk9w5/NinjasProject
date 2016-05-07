//////////////////////////////////////////////////////////////////////
/// @file TridiagMatrix.h
/// @author Russley Shaw
/// @brief Tridiagonal Matrix header file
//////////////////////////////////////////////////////////////////////

#ifndef TRIDIAGONAL_MATRIX_H
#define TRIDIAGONAL_MATRIX_H

#include <iostream>

#include "BandedMatrix.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::TridiagMatrix(const TridiagMatrix<T>&)
/// @brief Copy constructor - copies src to new TridiagMatrix
/// @post The matrix is initialized with a copy of src's data
/// @param src TridiagMatrix to copy from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::TridiagMatrix(TridiagMatrix<T>&&)
/// @brief Move constructor - moves data from src to new TridiagMatrix
/// @post Old object is emptied and new object has contents of old
/// @param src TridiagMatrix to move from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::TridiagMatrix(const int)
/// @brief Rectangular Constructor - constructs a rectangular TridiagMatrix
/// @post Constructs a TridiagMatrix with m rows and n columns
/// @post Throws std::out_of_range if m or n are less than 0
/// @param size Number of rows & columns
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::~TridiagMatrix()
/// @brief Destructor - deallocates internal data
/// @post The object is ready to be destroyed
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::operator=(const TridiagMatrix<T>&)
/// @brief Copy assignment - copies src to this object
/// @post This TridiagMatrix is a copy of src
/// @param src TridiagMatrix to copy from
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::operator=(TridiagMatrix<T>&&)
/// @brief Move assignment - moves from src to this object
/// @post This object has the old contents of src and src is empty
/// @param src TridiagMatrix to move from
/// @param paramName2 description of the parameter
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::get(const int, const int)
/// @brief Item introspection - access matrix element at given row & column
/// @post Throws std::out_of_range if row or col are out of bounds of matrix dimensions
/// @param row Row index to access
/// @param col Column index to access
/// @return Copy of data at given row and column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::set(const int, const int, const T&)
/// @brief Item modification - modify matrix element at given row & column
/// @pre Copy assignment should be defined for T
/// @post The value at the row & column is updated with values
/// @post Throws std::out_of_range if row or col are out of matrix bounds
/// @param row Row index
/// @param col Column index
/// @param value Value to copy to row & column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const TridiagMatrix<T>&)
/// @brief copies from other to CO
/// @post CO is now a copy of other
/// @param other Matrix to copy from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn swap(TridiagMatrix<T>&)
/// @brief swaps CO with other
/// @post CO and other are swapped
/// @param other Matrix to swap with
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn move(TridiagMatrix<T>&&)
/// @brief move other to CO
/// @post other becomes unusable, CO becomes other
/// @param other Matrix to move
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class TridiagMatrix
/// @brief Tridiagonal Matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class TridiagMatrix: public BandedMatrix<T>
{
public:
  using ValueType = typename AMatrix<T>::ValueType;
  using ReferenceType = typename AMatrix<T>::ReferenceType;
  using ConstReferenceType = typename AMatrix<T>::ConstReferenceType;
  using PointerType = typename AMatrix<T>::PointerType;
  using ConstPointerType = typename AMatrix<T>::ConstPointerType;
  using SizeType = typename AMatrix<T>::SizeType;

  TridiagMatrix(const SizeType size);
  TridiagMatrix(const TridiagMatrix<T>& src);
  TridiagMatrix(TridiagMatrix<T>&& src);
  virtual ~TridiagMatrix() {}

  TridiagMatrix<T>& operator=(const TridiagMatrix<T>& other);
  TridiagMatrix<T>& operator=(TridiagMatrix<T>&& other);

  TridiagMatrix<T>& copy(const TridiagMatrix<T>& other) { return BandedMatrix<T>::copy(other); }
  TridiagMatrix<T>& swap(TridiagMatrix<T>& other) { return BandedMatrix<T>::swap(other); }
  TridiagMatrix<T>& move(TridiagMatrix<T>&& other) { return BandedMatrix<T>::move(other); }

  virtual MatrixType type() const { return MatrixType::TRIDIAGONAL; }
};

#include "src/TridiagMatrix.hpp"
#endif
