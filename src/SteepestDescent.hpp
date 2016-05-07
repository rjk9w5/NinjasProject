//////////////////////////////////////////////////////////////////////
/// @file SteepestDescent.hpp
/// @author Russley Shaw & Ryan Krattiger
/// @brief Implementation of the Steepest Descent solver
//////////////////////////////////////////////////////////////////////

template<class T>
Vector<T> SteepestDescent<T>::operator()(const BandedMatrix<T>& aMatrix, const Vector<T>& bVector) const
{
  Vector<T> solution(bVector), sk;    //   x = b;
  LpNorm<2, T> norm;
  T alpha, errv=1;
  int it;

  sk = bVector - aMatrix*solution;    // sk = b - A*x;
  it = 0;                             // it = 1;
  while(errv > iterative::TOLERANCE)  // while(norm(sk) > 1e-7)
  {
    alpha = (sk*sk)/(sk*(aMatrix*sk));//   alpha = dot(sk,sk)/dot(sk,A*sk);
    solution += alpha*sk;             //   x = x + alpha*sk;
    sk = bVector - aMatrix*solution;  //   sk = b - A*x;
    errv = norm(sk);                  //   errv(it) = norm(sk);
    it++;                             //   it = it + 1;
  }                                   // end while

  std::cout << "Iterations: " << it << '\n';

  return solution;
}
