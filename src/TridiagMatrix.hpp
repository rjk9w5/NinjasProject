////////////////////////////////////////////////////////////////////////////////
/// @file TridiagMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation for Tridiagonal Matrix
////////////////////////////////////////////////////////////////////////////////

#include <utility>

#include "MatrixType.h"

template<class T>
TridiagMatrix<T>::TridiagMatrix(const SizeType size):
  DiagonalMatrix<T>(size, size, 1, 1)
{
}


template<class T>
TridiagMatrix<T>::TridiagMatrix(const TridiagMatrix<T>& other):
  DiagonalMatrix<T>(other)
{
}

template<class T>
TridiagMatrix<T>::TridiagMatrix(TridiagMatrix<T>&& other):
  DiagonalMatrix<T>(other)
{
}

template<class T>
TridiagMatrix<T> TridiagMatrix<T>::operator=(const TridiagMatrix<T>& other)
{
  if(this != &other)
  {
    copy(other)
  }
}
TridiagMatrix<T> operator=(TridiagMatrix<T>&& other);
