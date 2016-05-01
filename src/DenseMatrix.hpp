//////////////////////////////////////////////////////////////////////
/// @file DenseMatrix.hpp
/// @author Russley Shaw
/// @brief Implementation of Dense Matrix
//////////////////////////////////////////////////////////////////////

#include <iomanip>

template<class T>
DenseMatrix<T>::DenseMatrix(const int m, const int n): AMatrix<T>(MatrixType::DENSE, m, n), m_data(m*n)
{
  assert(this->m_rows >= 0);
  assert(this->m_cols >= 0);
}

template<class T>
DenseMatrix<T>::DenseMatrix(const std::initializer_list< Vector<T> >& rows)
  :AMatrix<T>(MatrixType::DENSE, rows.size(),rows.size() == 0 ? 0 : rows.begin()->size() ),
  m_data(this->m_rows * this->m_cols)
{
  int i = 0;
  for(auto& row: rows)
  {
    for(int j = 0; j < row.size(); j++)
    {
      set(i, j, row[j]);
    }
    i++;
  }
  assert(this->m_cols >= 0);
  assert(this->m_rows >= 0);
}

template<class T>
DenseMatrix<T>::DenseMatrix(const DenseMatrix<T>& other): AMatrix<T>(other), m_data(other.m_data)
{
  assert(this->m_cols >= 0);
  assert(this->m_rows >= 0);
}

template<class T>
DenseMatrix<T>::DenseMatrix(DenseMatrix<T>&& other): AMatrix<T>(other), m_data(other.m_data)
{
  assert(this->m_cols >= 0);
  assert(this->m_rows >= 0);
}

template<class T>
DenseMatrix<T>::~DenseMatrix()
{
}

template<class T>
DenseMatrix<T>& DenseMatrix<T>::operator=(const DenseMatrix<T>& other)
{
  if(this != &other)
  {
    this->m_rows = other.m_rows;
    this->m_cols = other.m_cols;
    this->m_data = other.m_data;
  }
  assert(this->m_rows >= 0);
  assert(this->m_cols >= 0);
  return *this;
}

template<class T>
DenseMatrix<T>& DenseMatrix<T>::operator=(DenseMatrix<T>&& other)
{
  if(this != &other)
  {
    this->m_rows = other.m_rows;
    this->m_cols = other.m_cols;
    m_data = std::move(other.m_data);

    other.m_rows = 0;
    other.m_cols = 0;
  }
  assert(this->m_rows >= 0);
  assert(this->m_cols >= 0);
  return *this;
}

template<class T>
T DenseMatrix<T>::get(const int row, const int col) const
{
  if(row < 0 || row >= this->rows() || col < 0 || col >= this->cols())
  {
    throw std::out_of_range("Given row, col must be in interval [0, rows), [0, cols)");
  }

  return m_data[row * this->cols() + col];
}

template<class T>
Vector<T> DenseMatrix<T>::getRow(const int row) const
{
  Vector<T> data( this->cols() );
  for(int i = 0; i < data.size(); i++)
  {
    data[i] = get(row, i);
  }
  return data;
}

template<class T>
Vector<T> DenseMatrix<T>::getCol(const int col) const
{
  Vector<T> data( this->rows() );
  for(int i = 0; i < data.size(); i++)
  {
    data[i] = get(i, col);
  }
  return data;
}

template<class T>
void DenseMatrix<T>::set(const int row, const int col, const T& value)
{
  if(row < 0 || row >= this->rows() || col < 0 || col >= this->cols())
  {
    throw std::out_of_range("Given row, col must be in interval [0, rows), [0, cols)");
  }

  m_data[row * this->cols() + col] = value;
}

template<class T>
void DenseMatrix<T>::setRow(const int row, const Vector<T>& data)
{
  if(data.size() != this->cols() || row < 0 || row >= this->rows() )
  {
    throw std::length_error("Given row must be valid");
  }

  for(int i = 0; i < this->cols(); i++)
  {
    this->set(row, i, data[i]);
  }
}

template<class T>
void DenseMatrix<T>::setCol(const int col, const Vector<T>& data)
{
  if(data.size() != this->rows() || col < 0 || col >= this->cols() )
  {
    throw std::length_error("Given col must be valid");
  }

  for(int i = 0; i < this->rows(); i++)
  {
    this->set(i, col, data[i]);
  }
}

template<class T>
std::istream& DenseMatrix<T>::input(std::istream& stream)
{
  T elem;
  for(int i = 0; i < this->rows(); i++)
  {
    for(int j = 0; j < this->cols(); j++)
    {
      stream >> elem;
      this->set(i, j, elem);
    }
  }
  return stream;
}

template<class T>
std::ostream& DenseMatrix<T>::output(std::ostream& stream) const
{
  for(int i = 0; i < this->rows(); i++)
  {
    for(int j = 0; j < this->cols(); j++)
    {
      stream << std::setw(16) << std::setprecision(12) << std::fixed << this->get(i, j) << " ";
    }
    stream << std::endl;
  }
  return stream;
}

template<class T>
bool DenseMatrix<T>::equalTo(const AMatrix<T>& other) const
{
  if(this->rows() != other.rows() || this->cols() != other.cols() )
  {
    return false;
  }

  for(int i = 0; i < this->rows(); i++)
  {
    for(int j = 0; j < this->cols(); j++)
    {
      if(this->get(i, j) != other.get(i, j))
      {
        return false;
      }
    }
  }
  return true;
}

template<class T>
DenseMatrix<T> operator*(const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs)
{
  if(lhs.cols() != rhs.rows())
  {
    throw std::length_error("DenseMatrix<T> operator*(const DenseMatrix<T>&, const DenseMatrix<T>&) - lhs must have same number columns as rhs has rows");
  }
  int n = lhs.rows();
  int m = lhs.cols();
  int p = rhs.cols();
  DenseMatrix<T> product(lhs.rows(), rhs.cols());
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < p; j++)
    {
      product.set(i, j, 0);
      for(int k = 0; k < m; k++)
      {
        product.set(i, j, product.get(i, j) + lhs.get(i, k)*rhs.get(k, j));
      }

    }
  }
  return product;
}

template<class T>
DenseMatrix<T> DenseMatrix<T>::transpose() const {
  DenseMatrix<T> t(this->cols(), this->rows());

  for(int iRow = 0; iRow < this->rows(); iRow++)
  {
    for(int iCol = 0; iCol < this->cols(); iCol++)
    {
      t.set(iCol, iRow, this->get(iRow, iCol));
    }
  }

  return t;
}
