#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::Vector()
/// @brief Default constructor - constructs with no data
/// @post The vector is initialized with no capacity
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::Vector(const int)
/// @brief Sized constructor - Construct with count elements
/// @post The vector is constructed with count size and capacity
/// @post Throws std::out_of_range if count is less than 0
/// @param count Number of elements to allocate space for
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::Vector(const Vector<ValueType&)
/// @brief Copy constructor - Copies other to new object
/// @post Constructs vector with copy of other
/// @param other vector to copy
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::Vector(Vector<ValueType&&)
/// @brief Move constructor - Constructs vector by moving contents from other
/// @post Vector constructed with other's contents and other is cleared out
/// @param other Vector to move from
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::~Vector()
/// @brief Destructor - ready the object for removal
/// @post all dynamic data is freed
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::operator=(const Vector<ValueType&)
/// @brief Copy assignment - copy rhs to this object
/// @post This vector's data is replaced by a copy of rhs's data
/// @param rhs Vector to copy from
/// @return reference to updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::operator=(Vector<ValueType&&)
/// @brief Move Assignment - Move data from rhs to this vector
/// @post Destroy existing data, move data from rhs, clear out rhs
/// @param rhs Vector to move from
/// @return reference to updated calling object
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::at(const int)
/// @brief Element introspection - includes bounds checking
/// @post Throws std::out_of_range if pos is not in interval [0, size())
/// @param pos description of the parameter
/// @return reference to indexed element
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::at(const int) const
/// @brief Element introspection - includes bounds checking
/// @post Throws std::out_of_range if pos is not in interval [0, size())
/// @param pos description of the parameter
/// @return constant reference to indexed element
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::operator[](const int)
/// @brief Element introspection - excludes bounds checking
/// @param pos description of the parameter
/// @return reference to indexed element
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::operator[](const int) const
/// @brief Element introspection - excludes bounds checking
/// @param pos description of the parameter
/// @return constant reference to indexed element
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::front()
/// @brief Retrieves the first element
/// @post Throws std::length_error if empty
/// @return Reference to first item in vector
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::back()
/// @brief Retrieves the last element
/// @post Throws std::length_error if empty
/// @return Reference to last item in vector
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::begin()
/// @brief Pointer to the beginning of data
/// @return Pointer to beginning of data
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::end()
/// @brief Pointer to one past the last element
/// @return Pointer to one past the last element
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::end() const
/// @brief Pointer to one past the last element
/// @return Constant pointer to one past the last element
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::empty() const
/// @brief Whether the vector is empty or not
/// @return true if empty, false if not empty
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::size() const
/// @brief Current size of the vector - the currently accessable elements
/// @return Number of currently accessable elements
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::reserve(const int)
/// @brief Expand or shrink the vector's internal capacity,
///        helps to prevent lots of array resizing
/// @pre T is copy assignable
/// @post The vector's capacity is changed, keeping as many live elements as it can
/// @post Throws std::out_of_range if capacity is less than 0
/// @post shrinks size if reserving a smaller than original capacity
/// @param capacity Desired new capacity
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::capacity() const
/// @brief Get the internal capacity of the vector
/// @return Internal vector capacity
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::clear()
/// @brief Removes all elements from vector, sets size and capacity to 0
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::insert(const int, const T&)
/// @brief Insert value into vector at position pos
/// @post Value is inserted into index pos and other values are shifted right
/// @post Throws std::out_of_range if pos is not in interval [0, m_size]
/// @post Inserting into m_size is equivalent to pushBack
/// @post Updates capacity if size == capacity
/// @param pos location to insert into
/// @param value Item to insert
/// @return description of the return
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::erase(const int pos)
/// @brief Erase item from index pos, shift items left if needed
/// @post Item at pos is removed and items to the right are shifted left
/// @post Throws std::out_of_range if outside of interval [0, size)
/// @param pos Index to remove
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::pushBack(const T& value)
/// @brief Insert an item to the back of the vector
/// @pre See insert(int, T)
/// @post See insert(int, T)
/// @param value Item to insert to back
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::popBack()
/// @brief Remove an item off the back of the vector
/// @post Removes the last item from the vector
/// @post Throws std::length_error if no items in vector
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::resize(const int size)
/// @brief Set capacity and mark for usage
/// @post Reserves size data & retains as much data as it can
/// @post Throws std::out_of_range if given size is less than 0
/// @param size New requested size of Vector
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::swap(Vector<ValueType& other)
/// @brief Swap this vector's contents with other vector
/// @post This vector and other vector's contents have been swapped
/// @param other Vector to swap with
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::operator+=(constVector<ValueType& rhs)
/// @brief Add rhs vector to calling object
/// @pre operator+=(T, T) must be defined
/// @post Calling object's data is updated
/// @post Throws length error if sizes are different
/// @param rhs Right hand side vector
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType::operator-=(constVector<ValueType& rhs)
/// @brief Subtract rhs vector from calling object
/// @pre operator-=(T, T) must be defined
/// @post Calling object's data is updated
/// @post Throws length error if sizes are different
/// @param rhs Right hand side vector
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType& Vector<ValueType::operator*=(const T& rhs)
/// @brief Scalar vector multiplication
/// @pre operator*=(T, T) must be defined
/// @post Calling object's data is updated
/// @param rhs Right hand side scalar
/// @return Calling object is returned
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator==(const Vector<ValueType& lhs, const Vector<ValueType& rhs)
/// @brief If the two vectors are equivalent (data & size)
/// @param lhs Left hand side vector
/// @param rhs Right hand side vector
/// @return if the two vectors are equivalent
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator!=(const Vector<ValueType& lhs, const Vector<ValueType& rhs)
/// @brief If the two vectors are not equivalent (data & size)
/// @param lhs Left hand side vector
/// @param rhs Right hand side vector
/// @return if the two vectors are not equivalent
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator+(const Vector<ValueType& lhs, const Vector<ValueType& rhs)
/// @brief Adds two vectors together
/// @pre See Vector<ValueType::operator+=(const Vector&).
/// @post Throw std::length_error if vectors are not same size
/// @param lhs Left hand size vector
/// @param rhs Right hand side vector
/// @return Vector representing the addition of the two
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator-(const Vector<ValueType& lhs, const Vector<ValueType& rhs)
/// @brief Subtracts rhs from lhs
/// @pre See Vector<ValueType::operator-=(const Vector&).
/// @post Throw std::length_error if vectors are not same size
/// @param lhs Left hand size vector
/// @param rhs Right hand side vector
/// @return Vector representing the subtraction of the two
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator*(const T& lhs, const Vector<ValueType& rhs)
/// @brief Scalar & vector multiplication
/// @pre operator*(T, T) must be defined
/// @param lhs Left hand side scalar
/// @param rhs Right hand side vector
/// @return Vector of scalar multiplication
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator*(const Vector<ValueType& lhs, const T& rhs)
/// @brief Scalar & vector multiplication
/// @pre operator*(T, T) must be defined
/// @param lhs Left hand side vector
/// @param rhs Right hand side scalar
/// @return Vector of scalar multiplication
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Vector<ValueType operator-(const Vector<ValueType& lhs)
/// @brief Negates the values of the vector
/// @pre operator-(T) is defined
/// @param lhs Left Hand Side vector to negate
/// @return Negated vector
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator<<(std::ostream&, const Vector<ValueType&)
/// @brief Insertion operator - insert into stream
/// @pre operator<<(std::ostream&, T) is defined
/// @post stream is updated with matrix data
/// @param lhs output stream
/// @param rhs vector to output
/// @return updated output stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn operator>>(std::istream&, Vector<ValueType&)
/// @brief Extraction operator - extract into vector
/// @pre operator>>(std::istream&, T) is defined
/// @post stream is updated
/// @param lhs input stream
/// @param rhs vector to set
/// @return updated input stream
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class Vector<ValueType
/// @brief Dynamic & variable mathematical vector & storage
//////////////////////////////////////////////////////////////////////
template<class T>
class Vector
{
public:
  typedef T ValueType;
  typedef T& ReferenceType;
  typedef const T& ConstReferenceType;
  typedef T* PointerType;
  typedef const T* ConstPointerType;
  typedef size_t  SizeType;

  Vector();
  Vector(const SizeType size);
  Vector(const Vector<ValueType>& other);
  Vector(Vector<ValueType>&& other);
  Vector(const std::initializer_list<ValueType>& l);
  virtual ~Vector() {}

  Vector<ValueType>& operator=(const Vector<ValueType>& rhs);
  Vector<ValueType>& operator=(Vector<ValueType>&& rhs);

  ////////////////////////////////////////////////////////////////////////////////
  /// Element access
  ////////////////////////////////////////////////////////////////////////////////
  ReferenceType at(const SizeType pos);
  ConstReferenceType at(const SizeType pos) const;

  ReferenceType operator[](const SizeType pos) { return m_data[pos]; }
  ConstReferenceType operator[](const SizeType pos) const { return m_data[pos]; }

  ReferenceType front();
  ConstReferenceType front() const;
  ReferenceType back();
  ConstReferenceType back() const;

  ////////////////////////////////////////////////////////////////////////////////
  /// Iterators
  ////////////////////////////////////////////////////////////////////////////////
  PointerType begin() { return m_data.get(); }
  ConstPointerType begin() const { return m_data.get(); }
  PointerType end() { return m_data.get() + m_size; }
  ConstPointerType end() const { return m_data.get() + m_size; }

  ////////////////////////////////////////////////////////////////////////////////
  /// Capacity
  ////////////////////////////////////////////////////////////////////////////////
  bool empty() const { return m_size == 0; }
  SizeType size() const { return m_size; }
  void resize(const SizeType size);
  SizeType capacity() const { return m_capacity; }
  void reserve(const SizeType capacity);
  void shrink();

  ////////////////////////////////////////////////////////////////////////////////
  /// Modifiers
  ////////////////////////////////////////////////////////////////////////////////
  void clear();
  void insert(const SizeType pos, ConstReferenceType value);
  void erase(const SizeType pos);
  void pushBack(ConstReferenceType value);
  void popBack();

  Vector<ValueType>& swap(Vector<ValueType>& other);
  Vector<ValueType>& copy(const Vector<ValueType>& other);
  Vector<ValueType>& move(Vector<ValueType>&& other);

  std::istream& input(std::istream& stream);
  std::ostream& output(std::ostream& stream) const;
  bool isEqual(const Vector<ValueType>& other) const;



  Vector<ValueType>& operator+=(const Vector<ValueType>& rhs);
  Vector<ValueType>& operator-=(const Vector<ValueType>& rhs);
  Vector<ValueType>& operator*=(ConstReferenceType rhs);

private:
  SizeType m_size;
  SizeType m_capacity;
  std::unique_ptr<ValueType[]> m_data;
};

////////////////////////////////////////////////////////////////////////////////
/// Non-member functions
////////////////////////////////////////////////////////////////////////////////
template<class T>
  bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) { return lhs.isEqual( rhs ); }
template<class T>
  bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) { return !lhs.isEqual( rhs ); }

template<class T>
  Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs) { return lhs += rhs; }
template<class T>
  Vector<T> operator-(Vector<T> lhs, const Vector<T>& rhs) { return lhs -= rhs; }

template<class T>
  T operator*(Vector<T> lhs, const Vector<T>& rhs) 
  { 
    // assert(lhs.size()==rhs.size());
    T ret = 0;
    for(int i=0; i < lhs.size(); ++i)
    {
      ret+=rhs[i]*lhs[i];
    }
    return ret; 
  }


template<class T>
  Vector<T> operator*(Vector<T> lhs, const T& rhs) { return lhs *= rhs; }
template<class T>
  Vector<T> operator*(const T& lhs, const Vector<T>& rhs) { return rhs * lhs; }

template<class T>
 std::ostream& operator<<(std::ostream& lhs, const Vector<T>& rhs) { return rhs.output(lhs); }
template<class T>
  std::istream& operator>>(std::istream& lhs, Vector<T>& rhs) { return rhs.input(lhs); }

#include "src/Vector.hpp"
#endif
