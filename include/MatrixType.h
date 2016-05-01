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
  SPARSE,
  TRIDIAGONAL,
  DIAGONAL,
  UPPERTRI,
  LOWERTRI,
  SYMMETRIC_DENSE,
  COUNT, //Count of MatrixTypes
  INVALID
};

#endif
