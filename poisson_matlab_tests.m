
n = 4;
m = 4;
I = spdiags([-1].*ones(n,1), [0],n,n);
B = spdiags([-1 4 -1].*ones(n,1), [-1 0 1],n,n);

A = sparse(m*(n+1)*n/2 + m*n);

A(1:n,1:n) = B;
A(1:n,n+1:2*n) = I;

for j=n+1:n:(m-1)*n
  A(j:j+n-1,j:j+n-1) = B;
  A(j:j+n-1,j+n:j+2*n-1) = I;
  A(j:j+n-1,j-n:j-1) = I;  
end

A(n*(m-1)+1:n*m, n*(m-1)+1:n*m) = B;
A(n*(m-1)+1:n*m, n*(m-2)+1:n*(m-1)) = I;



x = linspace(0,1,100);
y = x;

[X,Y] = meshgrid(x,y);

u_af = @(xx,yy) (1 - xx.^2).*(1 + yy.^2);

u_a = u_af(X,Y);

figure(1)
surf(X,Y,u_a)
title('Analytical Solution Plot')
ylabel('y')
xlabel('x')
zlabel('u(x,y)')