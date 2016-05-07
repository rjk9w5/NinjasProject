
template <class T, class T_ForceFunction>
Poisson<T>::Poisson(
  const T_ForceFunction func, 
  const ABoundaryCondition<T>& constX, 
  const ABoundaryCondition<T> constY): f(func), BC({constX, constY})
{
}


template <class T, class T_ForceFunction>
DenseMatrix<T> Poisson<T>::solve(const ALinSysSolver& solver, const size_t N)
{
  SizeType n = solution_dims-2;
  DenseMatrix<T> solution(N,N);
  BandedMatrix<T> A(n*n, n*n, 2, 2);
  ValueType h = static_cast<ValueType>(BC[0].upper_bound() - BC[0].lower_bound())/N;
  ValueType x,y;
  // Note: For additional robustness, a step-size parameter may be considered
  //       for the constant Y, or variable x. Because of the symetric nature
  //       of the perscribed problem this was ignored but could be added later.

  for(SizeType i=0; i < n; ++i)
  {
    x = BC[0].lower_bound() + h*i;

    for(SizeType j=0; j < n; ++j)
    {
      y = BC[1].lower_bound() + h*j;
      b(i*n + j) = h*h*f(x,y);

      if(i==2)
        b(i*n + j) = b(i*n + j) - BC[0].lower(y);

      if(i==n+1)
        b(i*n + j) = b(i*n + j) - BC[0].upper(y);

      if(j==2)
        b(i*n + j) = b(i*n + j) - BC[1].lower(x);

      if(j==n+1)
        b(i*n + j) = b(i*n + j) - BC[1].upper(x);
    }
  }

  std::cout << b << '\n';
}