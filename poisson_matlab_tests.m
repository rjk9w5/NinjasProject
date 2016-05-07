clear all
close all
clc
% Input constraints
x_min = 0;
x_max = 1;
y_min = 0;
y_max = 1;

lx0_bound = @(yy) 1 + yy.^2;
ux1_bound = @(yy) 0;

ly0_bound = @(xx) 1 - xx.^2;
uy1_bound = @(xx) 2.*ly0_bound(xx);

f = @(xx,yy) -2*(xx^2 + yy^2);

% Solution grid sizing
N = 1000;
M = 1000;
n = N-2;
m = M-2;

x = linspace(x_min,x_max,N);
y = linspace(y_min,y_max,M);

% lam = (m/n)^2;

% h = 1/(N-1);

% Initialize A and b building blocks
% I = spdiags([1].*ones(n,1), [0],n,n);
% B = spdiags([1 -2*(lam + 1) 1].*ones(n,1), [-1 0 1],n,n);
% b = zeros(n*m,1);
% U = zeros(N,M);

% Assign boundary conditions to solution matrix
% U(1,:) = lx0_bound(y);
% U(end,:) = ux1_bound(y);
% U(:,1) = ly0_bound(x);
% U(:,end) = uy1_bound(x);

% % Initialize A as a sparse matrix
% A = sparse(m*(n+1)*n/2 + m*n);

% % Assign values to A
% A(1:n,1:n) = B;
% A(1:n,n+1:2*n) = I;

% for j=n+1:n:(m-1)*n
%   A(j:j+n-1,j:j+n-1) = B;
%   A(j:j+n-1,j+n:j+2*n-1) = I;
%   A(j:j+n-1,j-n:j-1) = I;  
% end

% A(n*(m-1)+1:n*m, n*(m-1)+1:n*m) = B;
% A(n*(m-1)+1:n*m, n*(m-2)+1:n*(m-1)) = I;

% % Assign values to b
% index = 1;
% for i = 2:1:n+1
%   for j = 2:1:m+1
%     b(index) = (h^2)*f(x(i),y(j));
%     f(x(i),y(j))

%     if(i==2)
%       b(index) = b(index) - lx0_bound(y(j));
%       lx0_bound(y(j));
%       index;
%     end

%     if(i==n+1)
%       b(index) = b(index) - ux1_bound(y(j));
%       ux1_bound(y(j));
%       index;
%     end

%     if(j==2)
%       b(index) = b(index) - ly0_bound(x(i));
%       ly0_bound(x(i));
%       index;
%     end

%     if(j==m+1)
%       b(index) = b(index) - uy1_bound(x(i));
%       uy1_bound(x(i));
%       index;
%     end
%     index = index + 1;
%   end
% end
% b'

% u_inner = A\b;
% [u_inners, its, errvs] = sd_solver(A,b);
% its
% [u_innerl, itl, errvl] = liebmann(A,b);
% itl

fign=1;
% pois_res;
% figure(fign)
% semilogy(1:1:its-1,errvs, 'LineWidth', 2)
% title('Error plot for Steepest Decent')
% xlabel('Iteration')
% ylabel('Error (||r||)')
% fign = fign + 1;

% figure(fign)
% semilogy(1:1:itl-1,errvl, 'LineWidth', 2)
% title('Error plot for Liebmann Iteration')
% xlabel('Iteration')
% ylabel('Error (||r||)')
% fign = fign + 1;

% Us = U;
% Ul = U;

% index = 1;
% for i = 2:1:n+1
%   for j = 2:1:m+1
%     Us(i,j) = u_inners(index);
%     Ul(i,j) = u_innerl(index);
%     index = index + 1;
%   end
% end

[X,Y] = meshgrid(x,y);

u_af = @(xx,yy) (1 - xx.^2).*(1 + yy.^2);

u_a = u_af(X,Y);

% figure(fign)
% hold on
% surf(X,Y,Us')
% title('Steepest Decent Solution Plot')
% ylabel('y')
% xlabel('x')
% zlabel('u(x,y)')
% fign = fign + 1;

% pois_res_U

% sm = 0;
asm = 0;
for i = 1:1:N
  for j = 1:1:M
    % sm = sm + U(i,j);
    asm = asm + u_a(i,j);
  end
end

% avg = sm/(N*N);
aavg = asm/(N*N)
% avg
% x = linspace(x_min, x_max, size(U)(1));
% y = linspace(y_min, y_max, size(U)(1));
% [X,Y] = meshgrid(x,y);
% figure(fign)
% hold on
% surf(X,Y,U')
% title('Liebmann Iteration Solution Plot')
% ylabel('y')
% xlabel('x')
% zlabel('u(x,y)')
% fign = fign + 1;

% figure(fign)
% hold on
% surf(X,Y,u_a)
% title('Analytical Solution Plot')
% ylabel('y')
% xlabel('x')
% zlabel('u(x,y)')
% fign = fign + 1;

% input('Pause...')