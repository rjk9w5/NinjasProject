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
/// @fn UpperTriMatrix<T>::UpperTriMatrix(const UpperTriMatrix<T>&)
/// @brief Copy constructor - copies src to new UpperTriMatrix
/// @post The matrix is initialized with a copy of src's data
/// @param src UpperTriMatrix to copy from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>::UpperTriMatrix(UpperTriMatrix<T>&&)
/// @brief Move constructor - moves data from src to new UpperTriMatrix
/// @post Old object is emptied and new object has contents of old
/// @param src UpperTriMatrix to move from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>::UpperTriMatrix(const int)
/// @brief Rectangular Constructor - constructs a rectangular UpperTriMatrix
/// @post Constructs a UpperTriMatrix with m rows and n columns
/// @post Throws std::out_of_range if m or n are less than 0
/// @param size Number of rows & columns
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>::~UpperTriMatrix()
/// @brief Destructor - deallocates internal data
/// @post The object is ready to be destroyed
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>::operator=(const UpperTriMatrix<T>&)
/// @brief Copy assignment - copies src to this object
/// @post This UpperTriMatrix is a copy of src
/// @param src UpperTriMatrix to copy from
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>::operator=(UpperTriMatrix<T>&&)
/// @brief Move assignment - moves from src to this object
/// @post This object has the old contents of src and src is empty
/// @param src UpperTriMatrix to move from
/// @param paramName2 description of the parameter
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>::get(const int, const int)
/// @brief Item introspection - access matrix element at given row & column
/// @post Throws std::out_of_range if row or col are out of bounds of matrix dimensions
/// @param row Row index to access
/// @param col Column index to access
/// @return Copy of data at given row and column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UpperTriMatrix<T>::set(const int, const int, const T&)
/// @brief Item modification - modify matrix element at given row & column
/// @pre Copy assignment should be defined for T
/// @post The value at the row & column is updated with values
/// @post Throws std::out_of_range if row or col are out of matrix bounds
/// @param row Row index
/// @param col Column index
/// @param value Value to copy to row & column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const UpperTriMatrix<T>&)
/// @brief copies from other to CO
/// @post CO is now a copy of other
/// @param other Matrix to copy from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn swap(UpperTriMatrix<T>&)
/// @brief swaps CO with other
/// @post CO and other are swapped
/// @param other Matrix to swap with
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn move(UpperTriMatrix<T>&&)
/// @brief move other to CO
/// @post other becomes unusable, CO becomes other
/// @param other Matrix to move
/// @return updated calling object
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
