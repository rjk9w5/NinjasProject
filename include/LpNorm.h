//////////////////////////////////////////////////////////////////////
/// @file LpNorm.h
/// @author Russley Shaw
/// @brief A templated implementation of a Lp-Norm
//////////////////////////////////////////////////////////////////////

#ifndef LP_NORM_H
#define LP_NORM_H

#include "Vector.h"
#include <cmath>

//////////////////////////////////////////////////////////////////////
/// @class LpNorm
/// @brief a templated functor of a Lp-Norm
//////////////////////////////////////////////////////////////////////
template<int n, class T>
class LpNorm
{
public:
  T operator()(const Vector<T>& v) const;
};

//////////////////////////////////////////////////////////////////////
/// @fn     LpNorm<n, T>::operator(const MathVector<T>&) const
/// @brief  Performs Lp-norm on supplied MathVector
/// @pre    n must not be in interval [0, 1)
///         operator/(double, T) must be defined
/// @post   Performs Lp-norm on supplied MathVector
/// @param  v MathVector to perform norm on
/// @return value produced by norm operation
//////////////////////////////////////////////////////////////////////
template<int n, class T>
T LpNorm<n, T>::operator()(const Vector<T>& v) const
{
  T sum = 0;
  for(int i = 0; i < v.size(); i++)
  {
    sum += std::pow(v[i], n);
  }
  return std::pow( sum, 1.0l/static_cast<long double>(n) );
}

#endif
