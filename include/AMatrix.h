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
/// @fn bool AMatrix<T>::equalTo(const AMatrix<T>& other) const;
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
/// @class AMatrix<T>
/// @brief Abstract Matrix Class
//////////////////////////////////////////////////////////////////////
template<class T>
class AMatrix
{
public:
  AMatrix(const MatrixType& type, const int m, const int n);
  AMatrix(const AMatrix& other);
  AMatrix(AMatrix&& other);
  virtual ~AMatrix();

  int rows() const { return m_rows; }
  int cols() const { return m_cols; }

  virtual T get(const int m, const int n) const = 0;
  virtual Vector<T> getRow(const int m) const = 0;
  virtual Vector<T> getCol(const int n) const = 0;

  virtual void set(const int m, const int n, const T& value) = 0;
  virtual void setRow(const int m, const Vector<T>& values) = 0;
  virtual void setCol(const int n, const Vector<T>& values) = 0;

  MatrixType type() const { return m_type; }

  virtual std::istream& input(std::istream& stream) = 0;
  virtual std::ostream& output(std::ostream& stream) const = 0;
  virtual bool equalTo(const AMatrix<T>& other) const = 0;

protected:
  MatrixType m_type;
  int m_rows;
  int m_cols;

};

template<class T>
std::istream& operator>>(std::istream& lhs, AMatrix<T>& rhs) { return rhs.input(lhs); }

template<class T>
std::ostream& operator<<(std::ostream& lhs, const AMatrix<T>& rhs) { return rhs.output(lhs); }

template<class T>
bool operator==(const AMatrix<T>& lhs, const AMatrix<T>& rhs) { return lhs.equalTo(rhs); }

template<class T>
bool operator!=(const AMatrix<T>& lhs, const AMatrix<T>& rhs) { return !(lhs == rhs); }

#include "src/AMatrix.hpp"
#endif
