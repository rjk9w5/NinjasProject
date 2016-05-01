//////////////////////////////////////////////////////////////////////
/// @file tester.cpp
/// @author Russley Shaw
/// @brief Unit tester top level
//////////////////////////////////////////////////////////////////////

#include "RLib/include/Test.h"

#include "tests/test_Vector.h"

#include <iostream>


int main(int argc, char** argv)
{
  START_GLOBAL_TESTS;

  // Put functions containing tests here
  test_Vector();

  END_GLOBAL_TESTS;

  return 0;
}
