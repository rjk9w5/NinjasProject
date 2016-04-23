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
