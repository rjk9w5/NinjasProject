

template<class T>
Vector<T> GaussSeidel<T>::operator()(const BandedMatrix<T>& aMatrix, const Vector<T>& bVector)
{
  Vector<T> solution(bVector), r(bVector.size());//   x = b;
  LpNorm<2, T> norm;
  T alpha, errv=1;
  int it;

  r = bVector - aMatrix*solution; // r = b - A*x;
  it = 0; // it = 1;
  while(errv > iterative::TOLERANCE)// while(norm(r) > 1e-7)
  {
    for(int i=0; i<bVector.size(); ++i)//   for i = 1:1:max(size(b))
    {
      solution[i] = (bVector[i] - aMatrix.getRow(i)*solution + aMatrix.get(i,i)*solution[i])/aMatrix.get(i,i); //     x(i) = (b(i) - dot(A(i,:),x) + A(i,i)*x(i))/A(i,i);
    } //   end
    r = bVector - aMatrix*solution; //   r = b - A*x;
    errv = norm(r); //   errv(it) = norm(r);
    it++; //   it = it + 1;
  }// end

  std::cout << "Iterations: " << it << '\n';

  return solution;
}
