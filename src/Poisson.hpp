
template <class T, class T_XBound, class T_YBound, class T_ForcingFunction>
// DenseMatrix<T> Poisson<T, T_ForceFunction>::solve(const ALinSysSolver<T, BandedMatrix<T>>& solver, const size_t N)
DenseMatrix<T> Poisson<T, T_XBound, T_YBound, T_ForcingFunction>::solve(const size_t N)
{
  SizeType n = N-2, index;
  DenseMatrix<T> solution(N,N);
  BandedMatrix<T> A(n*n, n*n, 2, 2);
  Vector<T> b(n*n);
  ValueType h = fabs(static_cast<ValueType>(m_xBound.upper_bound() - m_xBound.lower_bound()))/(N-1);
  Vector<T> x(N),y(N);
  // Note: For additional robustness, a step-size parameter may be considered
  //       for the constant Y, or variable x. Because of the symetric nature
  //       of the perscribed problem this was ignored but could be added later.

  for(SizeType i=0; i<N; ++i)
  {
    x[i] = m_xBound.lower_bound() + h*i;
    y[i] = m_yBound.lower_bound() + h*i;
  }

  std::cout << x << '\n' << y << '\n';

  std::cout << h << '\n';
  index = 0;
  for(SizeType i=1; i <= n; ++i)
  {
    for(SizeType j=1; j <= n; ++j)
    {
      // std::cout << i*n + j << ' ' << n*n << '\n';
      // assert(i*n + j < n*n);
      b[index] = h*h*m_forcingFunc(x[i],y[j]);
      std::cout << "Forcing: " << m_forcingFunc(x[i],y[j]) << '\n';

      if(i==1)
      {
        b[index] -= m_xBound.lower(y[j]);
        std::cout << "X-Lower: " << m_xBound.lower(y[j]) << '\n';
        // std::cout << b[i*n + j] << '\n';
      }

      if(i==n)
      {
        b[index] -= m_xBound.upper(y[j]);
        std::cout << "X-Upper: " << m_xBound.upper(y[j]) << '\n';
      }
      
      if(j==1)
      { 
        b[index] -= m_yBound.lower(x[i]);
        std::cout << "Y-Lower: " << m_yBound.lower(x[i]) << '\n';
        // std::cout << b[i*n + j] << '\n';
      }

      if(j==n)
      {
        std::cout << "Y-Upper: " << m_yBound.upper(x[i]) << '\n';
        b[index] -= m_yBound.upper(x[i]);
      }

      index++;
    }
  }

  std::cout << b << '\n';
  return solution;
}
