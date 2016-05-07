
#ifndef PROJECT_PARAMETERS_H
#define PROJECT_PARAMETERS_H

#include "BoundaryCondition.h"
#include "Functor.h"

// Information Provided for the Boundary Conditions were Y is constant and X
//   is constant respectively...

template <class T>
class Forcing: public AFunctorxy<T>
{
public:
  virtual T operator()(const T& x, const T& y) { return -2*(x*x + y*y); }
};

template <class T>
class ConstY: public ABoundaryCondition<T>
{
public:
  virtual T upper(const T &x) { return 2*(1 - x*x); }
  virtual T lower(const T &x) { return (1 - x*x); }
  virtual T upper_bound() { return 1; }
  virtual T lower_bound() { return 0; }
};

template <class T>
class ConstX: public ABoundaryCondition<T>
{
public:
  virtual T upper(const T &y) { return 0; }
  virtual T lower(const T &y) { return 1 + y*y; }
  virtual T upper_bound() { return 1; }
  virtual T lower_bound() { return 0; }
};

#endif
