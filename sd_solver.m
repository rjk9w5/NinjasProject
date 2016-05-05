function [x, it, errv] = sd_solver(A,b)
  x = b;
  sk = b - A*x;
  it = 1;
  while(norm(sk) > 1e-7)
    alpha = dot(sk,sk)/dot(sk,A*sk);
    x = x + alpha*sk;
    sk = b - A*x;
    errv(it) = norm(sk);
    it = it + 1;
  end
end