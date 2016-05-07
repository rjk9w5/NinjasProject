//////////////////////////////////////////////////////////////////////
/// @file BandedMatrix.h
/// @author Russley Shaw
/// @brief Dense Matrix Header
//////////////////////////////////////////////////////////////////////

#ifndef BANDED_MATRIX_H
#define BANDED_MATRIX_H

#include "AMatrix.h"
#include "DenseMatrix.h"

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

#include "src/BandedMatrix.hpp"
#endif
