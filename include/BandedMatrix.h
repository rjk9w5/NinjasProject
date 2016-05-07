//////////////////////////////////////////////////////////////////////
/// @file BandedMatrix.h
/// @author Russley Shaw
/// @brief Specialization for banded matricies
//////////////////////////////////////////////////////////////////////

#ifndef BANDED_MATRIX_H
#define BANDED_MATRIX_H

#include <utility>

#include "AMatrix.h"
#include "DenseMatrix.h"

//////////////////////////////////////////////////////////////////////
/// @fn BandedMatrix(const SizeType, const SizeType, const SizeType, const SizeType)
/// @brief Constructor for row, col, upper bands, and lower bands
/// @post Throws exception if more bands than rows,cols
/// @param rows Number of rows
/// @param cols Number of columns
/// @param upperBands Number of lower bands
/// @param lowerBands Number of upper bands
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn BandedMatrix(const BandedMatrix<T>&)
/// @brief Copy constructor for banded matrix
/// @param other Banded matrix to copy from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn BandedMatrix(BandedMatrix<T>&&)
/// @brief Move constructor - moves from other to CO
/// @post Other is no longer a usable, valid, matrix
/// @param other Matrix to move from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator=(const BandedMatrix<T>&)
/// @brief Copy assignment, copies from other to CO
/// @post CO now is copy of other
/// @param other Matrix to copy from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator=(const BandedMatrix<T>&)
/// @brief Move assignment, moves from other to CO
/// @post other is an unusable, invalid Matrix
/// @param other Matrix to move from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn get(const SizeType, const SizeType) const
/// @brief Get copy of value at given row , column
/// @pre given row and column should be within size of Matrix
/// @param row Row index
/// @param col Column index
/// @return ValueType - Value at given row, col
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn set(const SizeType, const SizeType, ConstReferenceType)
/// @brief Setter for data at given row, col
/// @pre given row and column should be within size of matrix
/// @post sets to value at given row, col
/// @param row Row index
/// @param col Column index
/// @param value Value to set
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn getPtr(const SizeType, const SizeType)
/// @brief return pointer of data at given element
/// @pre row, col must be within bounds of matrix
/// @param row Row index
/// @param col Column index
/// @return pointer of data if exists, nullptr otherwise
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn getRow(const SizeType)
/// @brief specialized getRow for BandedMatrix
/// @pre row is a valid row within bounds of matrix
/// @param row Row index
/// @return Vector<T> list of elements at given row
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn output(std::ostream&) const
/// @brief Specialized outputter for Banded
/// @post inserts Matrix data into stream
/// @param stream Output stream to output to
/// @return updated stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn altOutput(std::ostream&) const
/// @brief Specialized outputter for dense data
/// @post inserts compact matrix data into stream
/// @param stream Stream to output to
/// @return updated stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const BandedMatrix<T>&)
/// @brief Copies BandedMatrix specific data from other
/// @post Copies from other into CO
/// @param other Matrix to copy from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn swap(BandedMatrix<T>& other)
/// @brief Swaps CO with other
/// @post CO and other have swapped
/// @param other Matrix to swap with
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn move(BandedMatrix<T>&&)
/// @brief Moves other to CO
/// @post other is an invalid Matrix, CO is what other was
/// @param other Matrix to move from
/// @return updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn upperBands() const
/// @brief number of upper bands
/// @return SizeType number of upper bands
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn lowerBands() const
/// @brief number of lower bands
/// @return SizeType number of lower bands
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator*(BandedMatrix<T>&, const Vector<T>&)
/// @brief Specialized Matrix * Vector multiplication
/// @param lhs Matrix to multiply
/// @param rhs Vector to multiply
/// @return Vector<T> - product
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class BandedMatrix
/// @brief Specialization for banded matricies
//////////////////////////////////////////////////////////////////////
template<class T>
class BandedMatrix: public AMatrix<T>
{
public:
  using ValueType = typename AMatrix<T>::ValueType;
  using ReferenceType = typename AMatrix<T>::ReferenceType;
  using ConstReferenceType = typename AMatrix<T>::ConstReferenceType;
  using PointerType = typename AMatrix<T>::PointerType;
  using ConstPointerType = typename AMatrix<T>::ConstPointerType;
  using SizeType = typename AMatrix<T>::SizeType;

  BandedMatrix(const SizeType rows, const SizeType cols, const SizeType upperBands, const SizeType lowerBands);
  BandedMatrix(const BandedMatrix<ValueType>& other);
  BandedMatrix(BandedMatrix<ValueType>&& other);

  virtual MatrixType type() const { return MatrixType::BANDED; }

  BandedMatrix<T>& operator=(const BandedMatrix<T>& other);
  BandedMatrix<T>& operator=(BandedMatrix<T>&& other);

  virtual ValueType get(const SizeType row, const SizeType col) const;
  virtual void set(const SizeType row, const SizeType col, ConstReferenceType value);

  virtual ConstPointerType getPtr(const SizeType row, const SizeType col) const;

  virtual Vector<ValueType> getRow(const SizeType row) const;

  virtual std::ostream& output(std::ostream& stream) const;
  virtual std::ostream& altOutput(std::ostream& stream) const;

  BandedMatrix<T>& copy(const BandedMatrix<T>& other);
  BandedMatrix<T>& swap(BandedMatrix<T>& other);
  BandedMatrix<T>& move(BandedMatrix<T>&& other);

  SizeType upperBands() const { return m_upperBands; }
  SizeType lowerBands() const { return m_lowerBands; }

private:
  SizeType m_upperBands;
  SizeType m_lowerBands;
  DenseMatrix<ValueType> m_data;

};

template <class T>
Vector<T> operator*(const BandedMatrix<T>& lhs, const Vector<T>& rhs)
{
  assert(lhs.cols() == rhs.size());
  Vector<T> ret(lhs.rows());

  for(int i = 0; i < lhs.rows(); i++)
  {
    int start = std::max(0, static_cast<int>(i) - static_cast<int>(lhs.lowerBands()) );
    int size = std::min(lhs.cols(), static_cast<int>(i) + lhs.upperBands() + 1);
    for(int j = start; j < size; j++)
    {
      ret[i] += (*(lhs.getPtr(i, j)) ) * rhs[j];
    }
  }
  return ret;
}

#include "src/BandedMatrix.hpp"
#endif
