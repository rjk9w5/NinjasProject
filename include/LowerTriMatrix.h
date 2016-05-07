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
/// @fn LowerTriMatrix<T>::LowerTriMatrix(const LowerTriMatrix<T>&)
/// @brief Copy constructor - copies src to new LowerTriMatrix
/// @post The matrix is initialized with a copy of src's data
/// @param src LowerTriMatrix to copy from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>::LowerTriMatrix(LowerTriMatrix<T>&&)
/// @brief Move constructor - moves data from src to new LowerTriMatrix
/// @post Old object is emptied and new object has contents of old
/// @param src LowerTriMatrix to move from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>::LowerTriMatrix(const int)
/// @brief Rectangular Constructor - constructs a rectangular LowerTriMatrix
/// @post Constructs a LowerTriMatrix with m rows and n columns
/// @post Throws std::out_of_range if m or n are less than 0
/// @param size Number of rows & columns
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>::~LowerTriMatrix()
/// @brief Destructor - deallocates internal data
/// @post The object is ready to be destroyed
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>::operator=(const LowerTriMatrix<T>&)
/// @brief Copy assignment - copies src to this object
/// @post This LowerTriMatrix is a copy of src
/// @param src LowerTriMatrix to copy from
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>::operator=(LowerTriMatrix<T>&&)
/// @brief Move assignment - moves from src to this object
/// @post This object has the old contents of src and src is empty
/// @param src LowerTriMatrix to move from
/// @param paramName2 description of the parameter
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>::get(const int, const int)
/// @brief Item introspection - access matrix element at given row & column
/// @post Throws std::out_of_range if row or col are out of bounds of matrix dimensions
/// @param row Row index to access
/// @param col Column index to access
/// @return Copy of data at given row and column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LowerTriMatrix<T>::set(const int, const int, const T&)
/// @brief Item modification - modify matrix element at given row & column
/// @pre Copy assignment should be defined for T
/// @post The value at the row & column is updated with values
/// @post Throws std::out_of_range if row or col are out of matrix bounds
/// @param row Row index
/// @param col Column index
/// @param value Value to copy to row & column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const LowerTriMatrix<T>&)
/// @brief copies from other to CO
/// @post CO is now a copy of other
/// @param other Matrix to copy from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn swap(LowerTriMatrix<T>&)
/// @brief swaps CO with other
/// @post CO and other are swapped
/// @param other Matrix to swap with
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn move(LowerTriMatrix<T>&&)
/// @brief move other to CO
/// @post other becomes unusable, CO becomes other
/// @param other Matrix to move
/// @return updated calling object
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
