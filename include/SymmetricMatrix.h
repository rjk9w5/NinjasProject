//////////////////////////////////////////////////////////////////////
/// @file SymmetricMatrix
/// @author Your name and class section here
/// @brief A brief description of the file
//////////////////////////////////////////////////////////////////////

#ifndef SYMMETRIC_MATRIX_H
#define SYMMETRIC_MATRIX_H

#include "AMatrix.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>::SymmetricMatrix(const SymmetricMatrix<T>&)
/// @brief Copy constructor - copies src to new SymmetricMatrix
/// @post The matrix is initialized with a copy of src's data
/// @param src SymmetricMatrix to copy from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>::SymmetricMatrix(SymmetricMatrix<T>&&)
/// @brief Move constructor - moves data from src to new SymmetricMatrix
/// @post Old object is emptied and new object has contents of old
/// @param src SymmetricMatrix to move from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>::SymmetricMatrix(const int)
/// @brief Rectangular Constructor - constructs a rectangular SymmetricMatrix
/// @post Constructs a SymmetricMatrix with m rows and n columns
/// @post Throws std::out_of_range if m or n are less than 0
/// @param size Number of rows & columns
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>::~SymmetricMatrix()
/// @brief Destructor - deallocates internal data
/// @post The object is ready to be destroyed
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>::operator=(const SymmetricMatrix<T>&)
/// @brief Copy assignment - copies src to this object
/// @post This SymmetricMatrix is a copy of src
/// @param src SymmetricMatrix to copy from
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>::operator=(SymmetricMatrix<T>&&)
/// @brief Move assignment - moves from src to this object
/// @post This object has the old contents of src and src is empty
/// @param src SymmetricMatrix to move from
/// @param paramName2 description of the parameter
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>::get(const int, const int)
/// @brief Item introspection - access matrix element at given row & column
/// @post Throws std::out_of_range if row or col are out of bounds of matrix dimensions
/// @param row Row index to access
/// @param col Column index to access
/// @return Copy of data at given row and column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SymmetricMatrix<T>::set(const int, const int, const T&)
/// @brief Item modification - modify matrix element at given row & column
/// @pre Copy assignment should be defined for T
/// @post The value at the row & column is updated with values
/// @post Throws std::out_of_range if row or col are out of matrix bounds
/// @param row Row index
/// @param col Column index
/// @param value Value to copy to row & column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const SymmetricMatrix<T>&)
/// @brief copies from other to CO
/// @post CO is now a copy of other
/// @param other Matrix to copy from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn swap(SymmetricMatrix<T>&)
/// @brief swaps CO with other
/// @post CO and other are swapped
/// @param other Matrix to swap with
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn move(SymmetricMatrix<T>&&)
/// @brief move other to CO
/// @post other becomes unusable, CO becomes other
/// @param other Matrix to move
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class SymmetricMatrix
/// @brief Symmetric Dense Matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class SymmetricMatrix: public AMatrix<T>
{
public:
  using ValueType = typename AMatrix<T>::ValueType;
  using ReferenceType = typename AMatrix<T>::ReferenceType;
  using ConstReferenceType = typename AMatrix<T>::ConstReferenceType;
  using PointerType = typename AMatrix<T>::PointerType;
  using ConstPointerType = typename AMatrix<T>::ConstPointerType;
  using SizeType = typename AMatrix<T>::SizeType;

  SymmetricMatrix(const SizeType size);
  SymmetricMatrix(const SymmetricMatrix<T>& other);
  SymmetricMatrix(SymmetricMatrix<T>&& other);
  virtual ~SymmetricMatrix(){}

  virtual MatrixType type() const { return MatrixType::SYMMETRIC; }

  SymmetricMatrix<T>& operator=(const SymmetricMatrix<T>& other);
  SymmetricMatrix<T>& operator=(SymmetricMatrix<T>&& other);

  virtual ValueType get(const SizeType row, const SizeType col) const;
  virtual void set(const SizeType row, const SizeType col, ConstReferenceType value);

  SymmetricMatrix<T>& copy(const SymmetricMatrix<T>& other);
  SymmetricMatrix<T>& swap(SymmetricMatrix<T>& other);
  SymmetricMatrix<T>& move(SymmetricMatrix<T>&& other);

  friend void test_SymmetricMatrix();
protected:
  Vector<ValueType> m_data;

  SizeType rowColToIndex(const SizeType row, const SizeType col) const;
};

#include "src/SymmetricMatrix.hpp"
#endif
