function [x, it, errv] = liebmann(A,b)
  x = b;
  r = b - A*x;
  it = 1;
  while(norm(r) > 1e-7)
    for i = 1:1:max(size(b))
      x(i) = (b(i) - dot(A(i,:),x) + A(i,i)*x(i))/A(i,i);
    end
    r = b - A*x;
    errv(it) = norm(r);
    it = it + 1;
  end
end