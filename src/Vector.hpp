////////////////////////////////////////////////////////////////////////////////
/// @file Vector.hpp
/// @author Russley Shaw
/// @brief Implementation of Vector
////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iomanip>


template<class T>
Vector<T>::Vector(): m_size(0), m_capacity(0), m_data(new T[0])
{
}

template<class T>
Vector<T>::Vector(const SizeType count): m_size(count), m_capacity(count),  m_data(new T[count])
{
}

template<class T>
Vector<T>::Vector(const Vector<T>& other): m_size(other.m_size), m_capacity(other.m_capacity), m_data( new T[m_capacity] )
{
  assert(m_capacity >= m_size);

  std::copy(other.m_data.get(), other.m_data.get()+m_size, m_data.get());
}

template<class T>
Vector<T>::Vector(Vector<T>&& other): m_size(other.m_size), m_capacity(other.m_capacity), m_data(std::move(other.m_data))
{
  assert(m_capacity >= m_size);

  other.m_size = 0;
  other.m_capacity = 0;
  other.m_data.reset(nullptr);
}

template<class T>
Vector<T>::Vector(const std::initializer_list<T>& l): m_size(l.size()), m_capacity(l.size()), m_data(new T[m_capacity])
{
  std::copy(l.begin(), l.end(), m_data.get());
}

template<class T>
Vector<T>::~Vector()
{
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
  assert(m_capacity >= m_size);
  assert(rhs.m_capacity >= rhs.m_size);
  if(this != &rhs)
  {
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_data.reset( new T[m_capacity] );
    std::copy(rhs.m_data.get(), rhs.m_data.get()+m_size, m_data.get());
  }
  return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs)
{
  assert(m_capacity >= m_size);
  assert(rhs.m_capacity >= rhs.m_size);
  if(this != &rhs)
  {
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_data = std::move(rhs.m_data);

    rhs.m_size = 0;
    rhs.m_capacity = 0;
    rhs.m_data.reset(nullptr);
  }
  return *this;
}

////////////////////////////////////////////////////////////////////////////////
///
/// Element Access
///
////////////////////////////////////////////////////////////////////////////////

template<class T>
typename Vector<T>::ReferenceType Vector<T>::at(const SizeType pos)
{
  assert(m_capacity >= m_size);
  if(pos >= m_size)
  {
    throw std::out_of_range("T& Vector<T>::at(const SizeType pos) - pos out of range");
  }
  return m_data[pos];
}

template<class T>
typename Vector<T>::ConstReferenceType Vector<T>::at(const SizeType pos) const
{
  assert(m_capacity >= m_size);
  if(pos >= m_size)
  {
    throw std::out_of_range("ConstReferenceType Vector<T>::at(const SizeType pos) const - pos out of range");
  }
  return m_data[pos];
}

template<class T>
typename Vector<T>::ReferenceType Vector<T>::front()
{
  assert(m_capacity >= m_size);
  if(m_size > 0)
  {
    return m_data[0];
  }
  else
  {
    throw std::length_error("Vector's size must be greater than 0 to access front");
  }
}

template<class T>
typename Vector<T>::ConstReferenceType Vector<T>::front() const
{
  assert(m_capacity >= m_size);
  if(m_size > 0)
  {
    return m_data[0];
  }
  else
  {
    throw std::length_error("Vector's size must be greater than 0 to access front");
  }
}

template<class T>
typename Vector<T>::ReferenceType Vector<T>::back()
{
  assert(m_capacity >= m_size);
  if(m_size > 0)
  {
    return m_data[m_size-1];
  }
  else
  {
    throw std::length_error("Vector's size must be greater than 0 to access back");
  }
}

template<class T>
typename Vector<T>::ConstReferenceType Vector<T>::back() const
{
  assert(m_capacity >= m_size);
  if(m_size > 0)
  {
    return m_data[m_size-1];
  }
  else
  {
    throw std::length_error("Vector's size must be greater than 0 to access back");
  }
}

////////////////////////////////////////////////////////////////////////////////
///
/// Capacity
///
////////////////////////////////////////////////////////////////////////////////

template<class T>
void Vector<T>::reserve(const SizeType capacity)
{
  assert(m_capacity >= m_size);

  std::unique_ptr<T[]> tmp( new T[capacity] );
  m_size = std::min(m_size, capacity);
  //Copy data
  for(SizeType i = 0; i < m_size; i++)
  {
    tmp[i] = m_data[i];
  }

  m_data.swap(tmp);
  m_capacity = capacity;

}

template<class T>
void Vector<T>::shrink()
{
  assert(m_capacity >= m_size);
  reserve(m_size);
}

////////////////////////////////////////////////////////////////////////////////
/// Modifiers
////////////////////////////////////////////////////////////////////////////////


template<class T>
void Vector<T>::clear()
{
  m_size = 0;
  m_capacity = 0;
  m_data.reset( new T[0] );
}

template<class T>
void Vector<T>::insert(const SizeType pos, ConstReferenceType value)
{
  assert(m_capacity >= m_size);

  if(pos < 0 || pos > m_size)
  {
    throw std::out_of_range("Given pos must be in interval [0, m_size]");
  }

  //reserve if current capacity not big enough
  if(m_size == m_capacity)
  {
    reserve(m_capacity + 8);
  }

  //Scooch values [pos, m_size) right 1
  for(SizeType i = m_size-1; i >= pos; i--)
  {
    m_data[i+1] = m_data[i];
  }

  //Insert value
  m_data[pos] = value;
  m_size++;
}

template<class T>
void Vector<T>::erase(const SizeType pos)
{
  assert(m_capacity >= m_size);

  if(pos >= m_size)
  {
    std::out_of_range("Cannot remove beyond interval [0, size)");
  }

  //Scooch values [pos, m_size) to the left
  for(SizeType i = pos + 1; i < m_size; i++)
  {
    m_data[i-1] = m_data[i];
  }
  m_size--;
}


template<class T>
void Vector<T>::pushBack(const T& value)
{
  assert(m_capacity >= m_size);
  insert(m_size, value);
}

template<class T>
void Vector<T>::popBack()
{
  assert(m_capacity >= m_size);

  if(m_size == 0)
  {
    throw std::length_error("Unable to popBack() when size is 0");
  }

  erase(m_size-1);
}


template<class T>
void Vector<T>::resize(const SizeType size)
{
  assert(m_capacity >= m_size);

  reserve(size);
  m_size = size;
}

template<class T>
void Vector<T>::swap(Vector<T>& other)
{
  assert(m_capacity >= m_size);
  assert(other.m_capacity >= other.m_size);

  std::swap(m_size, other.m_size);
  std::swap(m_capacity, other.m_size);
  std::swap(m_data, other.m_data);
}

template<class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& rhs)
{
  if(this->size() != rhs.size())
  {
    throw std::length_error("Vector<T>& Vector<T>::operator+=(const Vector<T>&) - Calling object and rhs must have same size");
  }

  for(int i = 0; i < this->size(); i++)
  {
    m_data[i] += rhs.m_data[i];
  }
  return *this;
}

template<class T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& rhs)
{
  if(this->size() != rhs.size())
  {
    throw std::length_error("Vector<T>& Vector<T>::operator+=(const Vector<T>&) - Calling object and rhs must have same size");
  }

  for(SizeType i = 0; i < this->size(); i++)
  {
    m_data[i] -= rhs.m_data[i];
  }
  return *this;
}

template<class T>
Vector<T>& Vector<T>::operator*=(const T& rhs)
{
  for(SizeType i = 0; i < m_size; i++)
  {
    m_data[i] *= rhs;
  }
  return *this;
}

template<class T>
bool Vector<T>::isEqual(const Vector<T>& other) const
{
  if(m_size != other.m_size)
  {
    return false;
  }

  for(SizeType i = 0; i < other.m_size; i++)
  {
    if(m_data[i] != other.m_data[i])
    {
      return false;
    }
  }

  return true;
}

template<class T>
std::ostream& Vector<T>::output(std::ostream& stream) const
{
  for(SizeType i = 0; i < m_size; i++)
  {
    stream << std::setw(16) << std::setprecision(8) << std::fixed << m_data[i];
  }
  return stream;
}

template<class T>
std::istream& Vector<T>::input(std::istream& stream)
{
  for(SizeType i = 0; i < m_size; i++)
  {
    stream >> m_data[i];
  }
  return stream;
}
