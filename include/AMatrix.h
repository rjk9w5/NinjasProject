//////////////////////////////////////////////////////////////////////
/// @file AMatrix.h
/// @author Russley Shaw
/// @brief Header for Abstract Matrix
//////////////////////////////////////////////////////////////////////

#ifndef ABSTRACT_MATRIX_H
#define ABSTRACT_MATRIX_H

#include "MatrixType.h"
#include "Vector.h"

#include <iostream>
#include <memory>
#include <initializer_list>
#include <string>

//////////////////////////////////////////////////////////////////////
/// @fn int AMatrix<T>::rows() const;
/// @brief Gets the number of rows in the matrix
/// @return Number of rows
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn int AMatrix<T>::cols() const;
/// @brief Gets the number of cols in the matrix
/// @return Number of columns
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn T AMatrix<T>::get(const int row, const int col) const
/// @brief Gets element at row & colummn
/// @param row Row index
/// @param col Column index
/// @return Value of item at row & column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn T AMatrix<T>::getRows(const int row) const
/// @brief Gets elements at row
/// @param row Row index
/// @return Values of item at column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn T AMatrix<T>::getCols(const int col) const
/// @brief Gets elements at column
/// @param col Column index
/// @return Values of item at column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn T AMatrix<T>::set(const int row, const int col, const T& value) const
/// @brief Sets element at row & colummn with value
/// @post Item at row & column is updated
/// @param row Row index
/// @param col Column index
/// @param value Value to set at row & column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn  AMatrix<T>::setRows(const int row, const Vector<T>&)
/// @brief Sets elements at row with given vector
/// @param row Row index
/// @return Values of item at column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn void AMatrix<T>::setCols(const int col const Vector<T>&)
/// @brief Gets elements at column
/// @param col Column index
/// @return Values of item at column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn MatrixType AMatrix<T>::type() const;
/// @brief Gets type specified by enumeration
/// @return Enumeration of type
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn std::istream& AMatrix<T>::input(std::istream& stream);
/// @brief retrieves matrix from virtual interface.
/// @pre size must be set before inserting data from stream
/// @post Updates matrix with correct data
/// @return updated input stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn std::ostream& AMatrix<T>::output(std::ostream& stream);
/// @brief outputs matrix from virtual interface to stream.
/// @pre operator<<(ostream, T) must be defined
/// @post Updates matrix with correct data
/// @return updated input stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn bool AMatrix<T>::isEqual(const AMatrix<T>& other) const;
/// @brief provides interface for equating equality
/// @pre operator==(T, T) must be defined
/// @return whether matricies are equivalent or not
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn std::istream& operator>>(std::istream& lhs, AMatrix<T>& rhs)
/// @brief Implements generalized virtual extraction operator
/// @param lhs input stream
/// @param rhs Matrix to input into
/// @return Updated input stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn std::ostream& operator>>(std::ostream& lhs, AMatrix<T>& rhs)
/// @brief Implements generalized virtual insertion operator
/// @param lhs output stream
/// @param rhs Matrix to output into
/// @return Updated output stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator*(const AMatrix<T>&, const Vector<T>&);
/// @brief Matrix & Vector multiplication
/// @param lhs Matrix to multiply
/// @param rhs Vector to multiply with
/// @return Vector<T> - Vector of product of Matrix * Vector
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
/// @class AMatrix<T>
/// @brief Abstract Matrix Class
//////////////////////////////////////////////////////////////////////
template<class T>
class AMatrix
{
public:
  typedef T ValueType;
  typedef T& ReferenceType;
  typedef const T& ConstReferenceType;
  typedef T* PointerType;
  typedef const T* ConstPointerType;
  typedef size_t  SizeType;

  AMatrix(const SizeType rows, const SizeType cols);
  AMatrix(const AMatrix<T>& other);
  AMatrix(AMatrix<T>&& other);
  virtual ~AMatrix(){}

  SizeType rows() const { return m_rows; }
  SizeType cols() const { return m_cols; }

  virtual ValueType get(const SizeType row, const SizeType col) const = 0;
  virtual Vector<T> getRow(const SizeType row) const;
  virtual Vector<T> getCol(const SizeType col) const;

  virtual void set(const SizeType row, const SizeType col, ConstReferenceType value) = 0;
  virtual void setRow(const SizeType row, const Vector<T>& values);
  virtual void setCol(const SizeType col, const Vector<T>& values);

  virtual MatrixType type() const = 0;

  AMatrix<T>& copy(const AMatrix<T>& other);
  AMatrix<T>& swap(AMatrix<T>& other);
  AMatrix<T>& move(AMatrix<T>&& other);

  virtual std::istream& input(std::istream& stream);
  virtual std::ostream& output(std::ostream& stream) const;
  virtual std::ostream& outputOctave(std::ostream& stream, const std::string& filename) const;
  virtual bool isEqual(const AMatrix<T>& other) const;

protected:
  SizeType m_rows;
  SizeType m_cols;

};

template<class T>
std::istream& operator>>(std::istream& lhs, AMatrix<T>& rhs) { return rhs.input(lhs); }

template<class T>
std::ostream& operator<<(std::ostream& lhs, const AMatrix<T>& rhs) { return rhs.output(lhs); }

template<class T>
bool operator==(const AMatrix<T>& lhs, const AMatrix<T>& rhs) { return lhs.isEqual(rhs); }

template<class T>
bool operator!=(const AMatrix<T>& lhs, const AMatrix<T>& rhs) { return !lhs.isEqual(rhs); }

template <class T>
Vector<T> operator*(const AMatrix<T>& lhs, const Vector<T>& rhs);

#include "src/AMatrix.hpp"
#endif
