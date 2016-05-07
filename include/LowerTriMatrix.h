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
