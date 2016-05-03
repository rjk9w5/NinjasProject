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

  BandedMatrix(const SizeType rows, const SizeType bands);
  BandedMatrix(const BandedMatrix<ValueType>& other);
  BandedMatrix(BandedMatrix<ValueType>&& other);

  BandedMatrix<T>& operator=(const BandedMatrix<T>& other);
  BandedMatrix<T>& operator=(BandedMatrix<T>&& other);

  ValueType get(const SizeType row, const SizeType col) const;

  void set(const SizeType row, const SizeType col, ConstReferenceType value);

  SizeType bands() const { return m_data.rows(); }

private:
  DenseMatrix<ValueType> m_data;
};

#include "src/BandedMatrix.hpp"
#endif
