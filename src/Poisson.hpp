
template <class T>
Poisson<T>::Poisson(
  const AFunctorxy<T>& func, 
  const ABoundaryCondition<T>& constX, 
  const ABoundaryCondition<T>& constY): f(func), BC({constX, constY})
{
}


template <class T>
// DenseMatrix<T> Poisson<T, T_ForceFunction>::solve(const ALinSysSolver<T, BandedMatrix<T>>& solver, const size_t N)
DenseMatrix<T> Poisson<T>::solve(const size_t N)
{
  SizeType n = N-2;
  DenseMatrix<T> solution(N,N);
  BandedMatrix<T> A(n*n, n*n, 2, 2);
  Vector<T> b(n); 
  ValueType h = fabs(static_cast<ValueType>(BC[0]->upper_bound() - BC[0]->lower_bound()))/N;
  ValueType x,y;
  // Note: For additional robustness, a step-size parameter may be considered
  //       for the constant Y, or variable x. Because of the symetric nature
  //       of the perscribed problem this was ignored but could be added later.

  for(SizeType i=0; i < n; ++i)
  {
    x = BC[0]->lower_bound() + h*(i+1);

    for(SizeType j=0; j < n; ++j)
    {
      y = BC[1]->lower_bound() + h*(j+1);
      b[i*n + j] = h*h*f(x,y);

      if(i==0)
        b[i*n + j] = b[i*n + j] - BC[0]->lower(y-h);

      if(i==n-1)
        b[i*n + j] = b[i*n + j] - BC[0]->upper(y+h);

      if(j==0)
        b[i*n + j] = b[i*n + j] - BC[1]->lower(x-h);

      if(j==n-1)
        b[i*n + j] = b[i*n + j] - BC[1]->upper(x+h);
    }
  }

  std::cout << b << '\n';
}