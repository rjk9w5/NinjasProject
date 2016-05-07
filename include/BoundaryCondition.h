#ifndef ABSTRACT_BOUNDARY_CONDITION_H_
#define ABSTRACT_BOUNDARY_CONDITION_H_

#include "Vector.h"

template <class T> 
class ABoundaryCondition
{
  public: 
    virtual T upper(const T&) = 0;
    virtual T lower(const T&) = 0;

    virtual T upper_bound() = 0;
    virtual T lower_bound() = 0;
};

#endif // ABSTRACT_BOUNDARY_CONDITION_H_