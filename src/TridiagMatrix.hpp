////////////////////////////////////////////////////////////////////////////////
/// @file TridiagMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation for Tridiagonal Matrix
////////////////////////////////////////////////////////////////////////////////

template<class T>
TridiagMatrix<T>::TridiagMatrix(const SizeType size):
  BandedMatrix<T>(size, size, 1, 1)
{
}


template<class T>
TridiagMatrix<T>::TridiagMatrix(const TridiagMatrix<T>& other):
  BandedMatrix<T>(other)
{
}

template<class T>
TridiagMatrix<T>::TridiagMatrix(TridiagMatrix<T>&& other):
  BandedMatrix<T>(other)
{
}

template<class T>
TridiagMatrix<T>& TridiagMatrix<T>::operator=(const TridiagMatrix<T>& other)
{
  if(this != &other)
  {
    copy(other);
  }
  return *this;
}

template<class T>
TridiagMatrix<T>& TridiagMatrix<T>::operator=(TridiagMatrix<T>&& other)
{
  if(this != &other)
  {
    move(std::move(other));
  }
  return *this;
}
