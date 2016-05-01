//////////////////////////////////////////////////////////////////////
/// @file   QrDecomposition.h
/// @author Russley Shaw
/// @brief  Functor header & implementation of QR decomposition
//////////////////////////////////////////////////////////////////////

#ifndef QRDECOMPOSITION_H
#define QRDECOMPOSITION_H

#include "AMatrix.h"
#include "DenseMatrix.h"
#include "Vector.h"
#include "LpNorm.h"

//////////////////////////////////////////////////////////////////////
/// @fn     QrDecomp<T>::operator()(const DenseMatrix<T>&, DenseMatrix<T>&, DenseMatrix<T>&)
/// @brief  Decomposes A(aMatrix) into Q(qMatrix) and R(rMatrix)
/// @pre    See operator*(MathVector<T>, MathVector<T>)
///         See T::operator+=(T)
///
/// @post   qMatrix and rMatrix are resized and updated with respective Q, R matricies
/// @param  aMatrix Original matrix; matrix to decompose
/// @param  qMatrix Q matrix; To be changed and given back to caller
/// @param  rMatrix R matrix; To be changed and given back to caller
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn     QrDecomp<T>::sumRandQ(const DenseMatrix<T>&, const DenseMatrix<T>&, const int)
/// @brief  Helper function to calculate sum of next rMatrix and current qMatrix
/// @pre    operator*(T, MathVector<T>) must be defined for scalar multiplication on a vector
/// @param  qMatrix Q Matrix; used in calculation
/// @param  rMatrix R Matrix; used in calculation
/// @param  k current summation iteration value
/// @return Sum of rMatrix[i][k+1] * qMatrix[i]
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class QrDecomp
/// @brief Fuctor for QR Decomposition calculations
//////////////////////////////////////////////////////////////////////
template<class T>
class QrDecomp
{
public:
  void operator()(const DenseMatrix<T>& A, DenseMatrix<T>& Q, DenseMatrix<T>& R)
  {
    LpNorm<2, T> norm2;

    if(A.rows() != A.cols())
    {
      throw std::length_error("Domain error - Given matrix must be a square matrix");
    }

    const int SIZE = A.rows();

    if(SIZE < 2)
    {
      throw std::length_error("Domain error - Given matrix must be at least 2 by 2");
    }

    Q = DenseMatrix<T>(SIZE, SIZE);
    R = DenseMatrix<T>(SIZE, SIZE);

    //Taking the 2 norm
    R.set(0, 0, norm2(A.getCol(0)) ); //rMatrix[0][0] = norm2(aColMatrix[0]);

    if( norm2(A.getCol(0) ) == 0) //if( norm2(aColMatrix[0]) == 0)
    {
      throw std::domain_error("Domain error - Cannot divide by zero");
    }

    //This gives us
    Q.setRow(0, A.getCol(0) * (1.0l/norm2(A.getCol(0))) );//qMatrix[0] = aColMatrix[0] * (1.0/norm2(aColMatrix[0])) ;

    //Taking the dot product of this with Q[1] we get
    R.set(0, 1, A.getCol(1) * Q.getRow(0)); //rMatrix[0][1] = aColMatrix[1] * qMatrix[0];

    //Again taking the 2 norm, we have
    R.set(1, 1, norm2(A.getCol(1) - R.get(0, 1) * Q.getRow(0) )  );

    if( R.get(0, 0) == 0 )
    {
      throw std::domain_error("Cannot divide by zero");
    }

    //This gives us
    Q.setRow(1, 1.0l/(R.get(1, 1)) * (A.getCol(1) - R.get(0, 1) * Q.getRow(0)) );//qMatrix[1] = 1.0/(rMatrix[1][1]) * (aColMatrix[1] - rMatrix[0][1] * qMatrix[0]);

    for(int k = 1; k < SIZE-1; k++)
    {
      for(int i = 0; i <= k; i++)
      {
        R.set(i, k+1, A.getCol(k+1) * Q.getRow(i));
        //rMatrix[i][k+1] = aColMatrix[k+1] * qMatrix[i];
      }

      //rMatrix[k+1][k+1] = norm2(aColMatrix[k+1] - sumRandQ(qMatrix, rMatrix, k));
      R.set(k+1, k+1, norm2(A.getCol(k+1) - sumRandQ(Q, R, k) ));

      if( R.get(k+1, k+1) == 0 )
      {
        throw std::domain_error("Domain error - Cannot divide by zero");
      }

      Q.setRow(k+1, (1.0l/R.get(k+1, k+1)) * (A.getCol(k+1) - sumRandQ(Q, R, k)) );
    }
    Q = Q.transpose();
    return;
  }

  Vector<T> sumRandQ(const DenseMatrix<T>& Q, const DenseMatrix<T>& R, const int k) const
  {
    Vector<T> sum(Q.rows());
    for(int i = 0; i <= k; i++)
    {
      sum += R.get(i,k+1) * Q.getRow(i);
    }
    return sum;
  }

private:


};


#endif
