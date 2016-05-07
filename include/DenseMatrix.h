//////////////////////////////////////////////////////////////////////
/// @file DenseMatrix.h
/// @author Russley Shaw
/// @brief Dense Matrix Header
//////////////////////////////////////////////////////////////////////

#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H

#include <initializer_list>
#include <iostream>
#include <memory>

#include "AMatrix.h"
#include "Vector.h"


//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::DenseMatrix(const DenseMatrix<T>&)
/// @brief Copy constructor - copies src to new DenseMatrix
/// @post The matrix is initialized with a copy of src's data
/// @param src DenseMatrix to copy from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::DenseMatrix(DenseMatrix<T>&&)
/// @brief Move constructor - moves data from src to new DenseMatrix
/// @post Old object is emptied and new object has contents of old
/// @param src DenseMatrix to move from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::DenseMatrix(const int, const int)
/// @brief Rectangular Constructor - constructs a rectangular DenseMatrix
/// @post Constructs a DenseMatrix with m rows and n columns
/// @post Throws std::out_of_range if m or n are less than 0
/// @param m Number of rows
/// @param n Number of columns
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::~DenseMatrix()
/// @brief Destructor - deallocates internal data
/// @post The object is ready to be destroyed
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::operator=(const DenseMatrix<T>&)
/// @brief Copy assignment - copies src to this object
/// @post This DenseMatrix is a copy of src
/// @param src DenseMatrix to copy from
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::operator=(DenseMatrix<T>&&)
/// @brief Move assignment - moves from src to this object
/// @post This object has the old contents of src and src is empty
/// @param src DenseMatrix to move from
/// @param paramName2 description of the parameter
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::get(const int, const int)
/// @brief Item introspection - access matrix element at given row & column
/// @post Throws std::out_of_range if row or col are out of bounds of matrix dimensions
/// @param row Row index to access
/// @param col Column index to access
/// @return Copy of data at given row and column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::set(const int, const int, const T&)
/// @brief Item modification - modify matrix element at given row & column
/// @pre Copy assignment should be defined for T
/// @post The value at the row & column is updated with values
/// @post Throws std::out_of_range if row or col are out of matrix bounds
/// @param row Row index
/// @param col Column index
/// @param value Value to copy to row & column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn getPtr(const SizeType, const SizeType)
/// @brief gets pointer at given row, col
/// @pre given row, col should be within bounds of matrix
/// @param row Row index
/// @param col Column index
/// @return pointer to value at row,col if exists, nullptr otherwise
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const DenseMatrix<T>&)
/// @brief copies from other to CO
/// @post CO is now a copy of other
/// @param other Matrix to copy from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn swap(DenseMatrix<T>&)
/// @brief swaps CO with other
/// @post CO and other are swapped
/// @param other Matrix to swap with
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn move(DenseMatrix<T>&&)
/// @brief move other to CO
/// @post other becomes unusable, CO becomes other
/// @param other Matrix to move
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class DenseMatrix<T>
/// @brief A dense, compact, retangular mathematical matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class DenseMatrix: public AMatrix<T>
{
public:
  using ValueType = typename AMatrix<T>::ValueType;
  using ReferenceType = typename AMatrix<T>::ReferenceType;
  using ConstReferenceType = typename AMatrix<T>::ConstReferenceType;
  using PointerType = typename AMatrix<T>::PointerType;
  using ConstPointerType = typename AMatrix<T>::ConstPointerType;
  using SizeType = typename AMatrix<T>::SizeType;

  DenseMatrix(const SizeType rows, const SizeType cols);
  DenseMatrix(const SizeType rows, const SizeType cols, const std::initializer_list< ValueType >& l);
  DenseMatrix(const DenseMatrix<T>& other);
  DenseMatrix(DenseMatrix<T>&& other);
  virtual ~DenseMatrix(){}

  virtual MatrixType type() const { return MatrixType::DENSE; }

  DenseMatrix<T>& operator=(const DenseMatrix<T>& other);
  DenseMatrix<T>& operator=(DenseMatrix<T>&& other);

  ValueType get(const SizeType row, const SizeType col) const;
  void set(const SizeType row, const SizeType col, ConstReferenceType value);

  ConstPointerType getPtr(const SizeType row, const SizeType col) const;

  DenseMatrix<T>& copy(const DenseMatrix<T>& other);
  DenseMatrix<T>& swap(DenseMatrix<T>& other);
  DenseMatrix<T>& move(DenseMatrix<T>&& other);

protected:
  Vector<ValueType> m_data;
};

#include "src/DenseMatrix.hpp"
#endif
