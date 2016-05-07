
#include <fstream>

template <class T, class T_XBound, class T_YBound, class T_ForcingFunction>
// DenseMatrix<T> Poisson<T, T_ForceFunction>::solve(const ALinSysSolver<T, BandedMatrix<T>>& solver, const size_t N)
DenseMatrix<T> Poisson<T, T_XBound, T_YBound, T_ForcingFunction>::solve(const size_t N)
{
  int n = N-2, index;
  DenseMatrix<T> solution(N,N);
  BandedMatrix<T> A(n*n, n*n, n, n);
  Vector<T> b(n*n);
  ValueType h = fabs(static_cast<ValueType>(m_xBound.upper_bound() - m_xBound.lower_bound()))/(N-1);
  Vector<T> x(N),y(N);
  GaussSeidel<T> solver;
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
      if(index%n > 0)
      { // 1 left of center
        std::cout << index-1 << '\n';
        A.set(index, index-1, 1);
      }
      if(index%n < n-1)
      { // 1 right of center
        std::cout << index+1 << '\n';
        A.set(index, index+1, 1);
      }

      if(index>=n)
      { // n left of center
        std::cout << index-n << '\n';
        A.set(index, index-n, 1);
      }
      if(index < n*(n-1))
      { // n right of center
        std::cout << index+n << '\n';
        A.set(index, index+n, 1);
      }
      A.set(index, index, -4);

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
  } // Make b vector and A Matrix

  b = solver(A,b);

  std::ofstream fout;
  fout.open("pois_res.m");
  fout << "u_inners = [" << b << "];\n";
  fout.close();

  index = 0;
  for(SizeType i=0; i<N; ++i)
  { // for i = 2:1:n+1
    for(SizeType j=0; j<N; ++j)
    {//   for j = 2:1:m+1
      if((i>=1 && i<=n)&&(j>=1 && j<=n))
      {
        solution.set(i,j,b[index]);//     % Ul(i,j) = u_innerl(index);
        index++;//     index = index + 1;
      }
      else
      {
        if(i==0)
          solution.set(i,j,m_xBound.lower(y[j]));
        else if(i==n+1)
          solution.set(i,j,m_xBound.upper(y[j]));
        else if(j==0)
          solution.set(i,j,m_yBound.lower(x[i]));
        else if(j==n+1)
          solution.set(i,j,m_yBound.upper(x[i]));
      }
    }//   end
  }// end

  // std::cout << A << '\n';
  // A.output(std::cout) << '\n';
  // std::cout << b << '\n';
  return solution;
}
