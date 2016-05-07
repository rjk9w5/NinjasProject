# Ninjas Project
Ryan Krattiger and Russley Shaw

## Objective
Solve the Poisson Equation for a simple case. The problem is presented as such...

<table>
  <tr>
    <th>
      U<sub>xx</sub> + U<sub>yy</sub> = 2(x<sup>2</sup> + y<sup>2</sup>)
    </th>
    <th>
      D: 0 < x < 1 and 0 < y < 1
    </th>
  </tr>
  <tr>
    <th>
      with boundary conditions (BC) as
    <th>
  </tr>
  <tr>
    <th>U(x,0) = 1 - x<sup>2</sup></th>
    <th>U(x,1) = 2(1 - x<sup>2</sup>)</th>
    <th>0 < x < 1</th>
  </tr>
  <tr>
    <th>U(0,y) = 1 + y<sup>2</sup></th>
    <th>U(1,y) = 0</th>
    <th>0 < y < 1</th>
  </tr>
</table>

The analytical solution is known to be...

U(x,y) = (1 - x<sup>2</sup>)(1 + y<sup>2</sup>)

## Code notes

### Data Structures
Data structures that are commonly used in linear algebra are Vectors and Matrices. In order to take advantage of special matrices, a interface is used and derived into the following listed matrices. 

#### Vector
Underlying data structure, operators like a hybrid of the STL vector and a math Vector.

#### AMatrix
Abstract matrix type, defines the interface for all other matrix types.

#### DenseMatrix
A data structure for densely packed matrix data.

#### BandedMatrix
A matrix that holds banded matrix data. Assumes a relatively dense banding between the center band and the outer bands.

#### TriDiagonalMatrix
A tridiagonal matrix, derived from the BandedMatrix

#### Upper/LowerMatrix
Also can be used as a Triangle matrix. Store the upper and lower triangle data respectively. This matrix is assumed to always be square.

#### SymetricMatrix
Stores a dense set of matrix data that is symmetric. This matrix is assumed to always be square.

### Numeric Solvers
Solvers that are used to solver numerical problems in linear algebra.

#### Poisson
A Poisson solver that handles all Poisson equations taking BoundaryConditions and a Forcing function. The solver allows the user to define the number of points to solve over.

#### SteepestDescent
Steepest descent optimization scheme implemented for matrix solving.

#### GaussSeidel
The iterative Gauss-Seiedel method, also known as Liebmann method, to solving systems of linear equations.

### Utilities

#### BoundaryConditions
A class to store upper and lower boundary conditions. Currently only for a 2D domain of x and y.

#### AFunctorxy
An abstract functor class that is used to the Poisson forcing function. 

#### RLib
A unit testing library

### Testing
There are unit tests made up and exist in the `/test` folder and are compiled in the command `make test`. 

### Driver
The driver is the main program that demonstrates the usage of this class library using the Poisson solver. Additionally it includes important unit tests. At this stage tester.cpp and driver.cpp are very similar in funcitonality. However, driver is intended to be a demonstration of general usage as it would be done by scientists and engineers.