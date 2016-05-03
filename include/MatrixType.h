//////////////////////////////////////////////////////////////////////
/// @file MatrixType.h
/// @author Russley Shaw
/// @brief Enumeration of types of matricies
//////////////////////////////////////////////////////////////////////

#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

enum MatrixType {
  ABSTRACT,
  DENSE,
  BANDED,
  TRIDIAGONAL,
  UPPERTRI,
  LOWERTRI,
  SYMMETRIC,
  COUNT, //Count of MatrixTypes
  INVALID
};

#endif
