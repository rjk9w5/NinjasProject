
template <class T, class T_XBound, class T_YBound, class T_ForcingFunction>
// DenseMatrix<T> Poisson<T, T_ForceFunction>::solve(const ALinSysSolver<T, BandedMatrix<T>>& solver, const size_t N)
DenseMatrix<T> Poisson<T, T_XBound, T_YBound, T_ForcingFunction>::solve(const size_t N)
{
  SizeType n = N-2;
  DenseMatrix<T> solution(N,N);
  BandedMatrix<T> A(n*n, n*n, 2, 2);
  Vector<T> b(n);
  ValueType h = fabs(static_cast<ValueType>(m_xBound.upper_bound() - m_xBound.lower_bound()))/N;
  ValueType x,y;
  // Note: For additional robustness, a step-size parameter may be considered
  //       for the constant Y, or variable x. Because of the symetric nature
  //       of the perscribed problem this was ignored but could be added later.

  for(SizeType i=0; i < n; ++i)
  {
    x = m_xBound.lower_bound() + h*(i+1);

    for(SizeType j=0; j < n; ++j)
    {
      y = m_yBound.lower_bound() + h*(j+1);
      b[i*n + j] = h*h*m_forcingFunc(x,y);

      if(i==0)
        b[i*n + j] = b[i*n + j] - m_xBound.lower(y-h);

      if(i==n-1)
        b[i*n + j] = b[i*n + j] - m_xBound.upper(y+h);

      if(j==0)
        b[i*n + j] = b[i*n + j] - m_yBound.lower(x-h);

      if(j==n-1)
        b[i*n + j] = b[i*n + j] - m_yBound.upper(x+h);
    }
  }

  std::cout << b << '\n';
  return solution;
}
