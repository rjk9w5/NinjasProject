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
/// @fn DenseMatrix<T>::DenseMatrix()
/// @brief Default constructor - constructs with no data
/// @post The matrix is initialized as a 0x0 matrix
//////////////////////////////////////////////////////////////////////

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
/// @fn DenseMatrix<T>::DenseMatrix(const int)
/// @brief Square matrix constructor - creates a square matrix
/// @post DenseMatrix is constructed with as a mn by mn DenseMatrix
/// @post Throws std::out_of_range if mn is less than 0
/// @param mn Number of rows and columns in the DenseMatrix
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
/// @fn DenseMatrix<T>::rows()
/// @brief Row number accessor - gets the number of rows in the DenseMatrix
/// @return The number of rows
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::cols()
/// @brief Column number accessor - gets the number of columns in the DenseMatrix
/// @return The number of columns
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
/// @fn DenseMatrix<T>::getRow(const int row)
/// @brief Row-wise accessor - gets the row as a Vector
/// @post Throws std::out_of_range if row is out of bounds (from get(int, int))
/// @param row Row index
/// @return Vector of values at given row
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::getCol(const int)
/// @brief Column-wise accessor - gets the col as a Vector
/// @post Throws std::out_of_range if row is out of bounds (from get(int, int))
/// @param col Column index
/// @return Vector of values at given column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::setRow(const int, const Vector<T>&)
/// @brief Row-wise mutator - set the values at the given row
/// @post The row at the given index is updated with values from data
/// @post Throws std::length_error if row out of bounds or data not same size
/// @param row Row index to set
/// @param data Data to copy over existing data
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::setCol(const int, const Vector<T>&)
/// @brief Column-wise mutator - set the values at the given column
/// @post The column at the given index is updated with values from data
/// @post Throws std::length_error if column out of bounds or data not same size
/// @param col Column index to set
/// @param data Data to copy over existing data
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T>::transpose()
/// @brief Returns a transposed matrix
/// @return A transposed version of the calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn std::istream& DenseMatrix<T>::input(std::istream& stream);
/// @brief retrieves matrix from virtual interface.
/// @pre size must be set before inserting data from stream
/// @post Updates matrix with correct data
/// @return updated input stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn std::ostream& DenseMatrix<T>::output(std::ostream& stream);
/// @brief outputs matrix from virtual interface to stream.
/// @pre operator<<(ostream, T) must be defined
/// @post Updates matrix with correct data
/// @return updated input stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn bool DenseMatrix<T>::equalTo(const AMatrix<T>& other) const;
/// @brief provides interface for equating equality
/// @pre operator==(T, T) must be defined
/// @return whether matricies are equivalent or not
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DenseMatrix<T> operator*(const DenseMatrix<T>&, const DenseMatrix<T>&);
/// @brief Dense matrix multiplication
/// @pre A(N, M) * A(M, O) = A(N, O), operator+(T, T), operator*(T, T)
/// @post Exception occurs if M sizes are different
/// @param rhs Right hand Matrix
/// @param lhs Left Hand Matrix
/// @return Matrix multiplication result
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
