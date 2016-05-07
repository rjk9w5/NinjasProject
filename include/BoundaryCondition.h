//////////////////////////////////////////////////////////////////////
/// @file   BoundaryCondition.h
/// @author Ryan Krattiger
/// @brief  Abstract class object for holding the information about
///         boundaries.
//////////////////////////////////////////////////////////////////////

#ifndef ABSTRACT_BOUNDARY_CONDITION_H_
#define ABSTRACT_BOUNDARY_CONDITION_H_

#include "Vector.h"

template <class T> 
class ABoundaryCondition
{
  public: 
    typedef T ValueType;
    
    virtual T upper(const T&) = 0;
    virtual T lower(const T&) = 0;

    virtual T upper_bound() = 0;
    virtual T lower_bound() = 0;
};

#endif // ABSTRACT_BOUNDARY_CONDITION_H_