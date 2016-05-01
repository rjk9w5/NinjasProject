//////////////////////////////////////////////////////////////////////
/// @file TridiagMatrix.h
/// @author Russley Shaw
/// @brief Tridiagonal Matrix header file
//////////////////////////////////////////////////////////////////////

#ifndef TRIDIAGONAL_MATRIX_H
#define TRIDIAGONAL_MATRIX_H

#include <iostream>

#include "AMatrix.h"
#include "DenseMatrix.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::TridiagMatrix()
/// @brief Default constructor - Initializes with no data
/// @post Matrix is initialized with no data
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::TridiagMatrix(const int)
/// @brief Square matrix constructor - Initializes square matrix
/// @post Throws if 0 or less value given to Vector ( see Vector(int) )
/// @param mn Rows & columns to initialize matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::TridiagMatrix(const TridiagMatrix<T>&)
/// @brief Copy constructor - copies data from src to new object
/// @pre See Vector<T>(const Vector<T>&)
/// @post New object copy of src
/// @param src Matrix to copy
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::TridiagMatrix(TridiagMatrix<T>&&)
/// @brief Move constructor - construct a new Matrix by moving src
/// @pre See Vector<T>(Vector<T>&&)
/// @post New object contains src's contents and src is empty
/// @param src Matrix to move from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::TridiagMatrix(const Vector<T>&, const Vector<T>&, const Vector<T>&)
/// @brief Banded constructor - create Tridiagonal from bands
/// @post New object constructed with copied bands
/// @post Throws std::length_error if bands are not proper length
/// @param superData Data above the diagonal
/// @param mainData on the diagonal
/// @param subData below the diagonal
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::~TridiagMatrix()
/// @brief Destructor - prepares object for removal
/// @post The object is ready to be removed
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::operator=(const TridiagMatrix<T>&)
/// @brief Copy assignment - copies from src into this object
/// @post This object is a copy of src
/// @param src Matrix to copy
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::operator=(TridiagMatrix<T>&&)
/// @brief Move assignment - moves data from src to this object
/// @post Data is moved from src to this object and src is empty
/// @param src Matrix to move from
/// @return This object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::get(const int, const int)
/// @brief Item introspection - get item at given row & column
/// @post Throws std::out_of_range if out of bounds of matrix
/// @param row Row index
/// @param col Column index
/// @return Value at row & column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::set(const int, const int, const T&)
/// @brief Item mutator - set elements of matrix
/// @post Throws std::domain_error if attempting to set outside of tri diagonals
/// @param row Row index
/// @param col Column index
/// @param value Value to set at row & col
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::getRow(const int)
/// @brief Accesses an entire row
/// @post Throws std::out_of_range if out of bounds of matrix
/// @param row Row index
/// @return Vector of copied elements at given row
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::setRow(const int, const Vector<T>&)
/// @brief Item mutator - set elements of matrix
/// @post Throws std::domain_error if attempting to set outside of tri diagonals
/// @param row Row index
/// @param values Values to set at row
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::getCol(const int)
/// @brief Accesses an entire column
/// @post Throws std::out_of_range if out of bounds of matrix
/// @param col Column index
/// @return Vector of copied elements at given column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TridiagMatrix<T>::setCol (const int, const Vector<T>&)
/// @brief Sets entire column
/// @post Throws std::domain_error if attempting to set outside of tri diagonals
/// @param col Column index
/// @param values Values to set at column
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn std::ostream& output(std::ostream& stream) const;
/// @brief output matrix to stream
/// @pre operator<<(ostream, T) must be availible
/// @post The matrix data is inserted into the stream
/// @param stream Stream to push calling object into
/// @return Updated stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn std::ostream& input(std::istream& stream) const;
/// @brief input matrix from stream
/// @pre operator>>istream, T) must be availible, size of matrix must be set
/// @post Stream data is inserted into calling object
/// @param stream Stream to push calling object into
/// @return Updated stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn bool equalTo(const AMatrix<T>& other) const;
/// @brief compare equivalency of matrix
/// @pre T::operator==(T) is defined
/// @param other Object to compare against
/// @return whether the objects are the same or not
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class TridiagMatrix
/// @brief Tridiagonal Matrix
//////////////////////////////////////////////////////////////////////
template<class T>
class TridiagMatrix: public AMatrix<T>
{
public:
  TridiagMatrix();
  TridiagMatrix(const int m, const int n);
  TridiagMatrix(const TridiagMatrix<T>& src);
  TridiagMatrix(TridiagMatrix<T>&& src);
  ~TridiagMatrix();

  virtual T get(const int row, const int col) const;
  virtual Vector<T> getRow(const int row) const;
  virtual Vector<T> getCol(const int col) const;

  virtual void set(const int row, const int col, const T& value);
  virtual void setRow(const int row, const Vector<T>& values);
  virtual void setCol(const int col, const Vector<T>& values);

  virtual std::istream& input(std::istream& stream);
  virtual std::ostream& output(std::ostream& stream) const;
  virtual bool equalTo(const AMatrix<T>& other) const;

protected:
  DenseMatrix<T> m_data;

};

#include "src/TridiagMatrix.hpp"
#endif
