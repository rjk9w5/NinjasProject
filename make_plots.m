close all
clear all
clc
poisson_exact5
poisson_exact10
poisson_exact20
poisson_exact30
poisson_exact50

poisson_Ugs5
poisson_Ugs10
poisson_Ugs20
poisson_Ugs30
poisson_Ugs50


poisson_Usd5
poisson_Usd10
poisson_Usd20
poisson_Usd30
poisson_Usd50

fign = 1;

x = linspace(0,1, size(U5)(1));
y = linspace(0,1, size(U5)(2));
[X,Y] = meshgrid(x,y);

figure(fign)
surf(X, Y, Ugs5)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Gauss-Seidel Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, Usd5)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Steepest Descent Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, U5)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Actual Solution')
fign = fign + 1;

x = linspace(0,1, size(U10)(1));
y = linspace(0,1, size(U10)(2));
[X,Y] = meshgrid(x,y);

figure(fign)
surf(X, Y, Ugs10)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Gauss-Seidel Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, Usd10)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Steepest Descent Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, U10)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Actual Solution')
fign = fign + 1;

x = linspace(0,1, size(U20)(1));
y = linspace(0,1, size(U20)(2));
[X,Y] = meshgrid(x,y);

figure(fign)
surf(X, Y, Ugs20)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Gauss-Seidel Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, Usd20)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Steepest Descent Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, U20)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Actual Solution')
fign = fign + 1;

x = linspace(0,1, size(U30)(1));
y = linspace(0,1, size(U30)(2));
[X,Y] = meshgrid(x,y);

figure(fign)
surf(X, Y, Ugs30)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Gauss-Seidel Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, Usd30)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Steepest Descent Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, U30)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Actual Solution')
fign = fign + 1;

x = linspace(0,1, size(U50)(1));
y = linspace(0,1, size(U50)(2));
[X,Y] = meshgrid(x,y);

figure(fign)
surf(X, Y, Ugs50)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Gauss-Seidel Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, Usd50)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Steepest Descent Solution')
fign = fign + 1;

figure(fign)
surf(X, Y, U50)
xlabel('x')
ylabel('y')
zlabel('u(x,y)')
title('Actual Solution')

input('Pause...')

close all
clear all
clc