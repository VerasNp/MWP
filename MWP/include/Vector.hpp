#pragma once

#include <cmath>
#include <vector>

namespace MWP {

template <typename T> class Vector {
public:
  std::vector<T> _elements;
  unsigned int _rows;
  unsigned int _columns;
  unsigned int _size;

public:
  /**
   * @brief Default constructor for vector
   *
   * Init a empty vector and size equal to zero
   *
   */
  Vector();

  /**
   * @brief Constructor for the Vector class.
   *
   * This constructor initializes the vector with the given number of rows and
   * columns and set all elements to zero.
   *
   * It's recommended fill the row (for column vector) or column (for row
   * vector) param.
   *
   * @tparam T The type of the vector elements.
   * @param rows The number of rows in the vector.
   * @param columns The number of columns in the vector.
   */
  Vector(unsigned int rows, unsigned int columns);

  /**
   * @brief Constructor for given elements and number of rows and columns
   *
   * Init the vector with given columns, rows and set the given
   * elements
   *
   * @tparam T The data type of the vector elements.
   * @param elements The elements of vector.
   * @param rows The number of rows in the vector.
   * @param columns The number of columns in the vector.
   */
  Vector(std::vector<T> elements, unsigned int rows, unsigned int columns);

public:
  /**
   * @brief Access the vector components by index
   *
   * This method allows for the access of the vector components by index.
   *
   * @param index The index of the component
   * @return The value of the component
   */
  T operator[](int index) const;

  /**
   * @brief Access the vector components by index
   *
   * This method allows for the access of the vector components by index.
   *
   * @param index The index of the component
   * @return The reference to the component
   */
  T &operator[](int index);

  /**
   * @brief Overloads the addition operator for Vector objects.
   *
   * This operator allows for the addition of two Vector objects.
   * It returns a new Vector object whose components are the sum
   * of the corresponding components of the two input vectors.
   *
   * @tparam T The type of the vector components.
   * @param vector The vector to be added to the current vector.
   * @return A new Vector object that is the result of the vector addition.
   */
  Vector<T> operator+(const Vector<T> &vector) const;

  /**
   * @brief Overloads the addition assignment operator for Vector objects.
   *
   * This operator allows for the addition of two Vector objects.
   * It modifies the current vector by adding the components of the
   * input vector to the corresponding components of the current vector.
   *
   * @tparam T The type of the vector components.
   * @param vector The vector to be added to the current vector.
   * @return A reference to the current vector after the addition.
   */
  Vector<T> &operator+=(const Vector<T> &vector);

  /**
   * @brief Overloads the subtraction operator for Vector objects.
   *
   * This operator allows for the subtraction of two Vector objects.
   * It returns a new Vector object whose components are the difference
   * of the corresponding components of the two input vectors.
   *
   * @tparam T The type of the vector components.
   * @param vector The vector to be subtracted from the current vector.
   * @return A new Vector object that is the result of the vector subtraction.
   */
  Vector<T> operator-(const Vector<T> &vector) const;

  /**
   * @brief Overloads the subtraction assignment operator for Vector objects.
   *
   * This operator allows for the subtraction of two Vector objects.
   * It modifies the current vector by subtracting the components of the
   * input vector from the corresponding components of the current vector.
   *
   * @tparam T The type of the vector components.
   * @param vector The vector to be subtracted from the current vector.
   * @return A reference to the current vector after the subtraction.
   */
  Vector<T> &operator-=(const Vector<T> &vector);

  /**
   * @brief Overloads the multiplication operator for Vector objects.
   *
   * This operator allows for the multiplication of a Vector object by a
   * scalar. It returns a new Vector object whose components are the product
   * of the corresponding components of the input vector and the scalar.
   *
   * @tparam T The type of the vector components.
   * @param scalar The scalar value to multiply the vector by.
   * @return A new Vector object that is the result of the vector-scalar
   * multiplication.
   */
  Vector<T> operator*(T scalar) const;

  /**
   * @brief Overloads the multiplication assignment operator for Vector
   * objects.
   *
   * This operator allows for the multiplication of a Vector object by a
   * scalar. It modifies the current vector by multiplying the components of the
   * vector by the scalar value.
   *
   * @tparam T The type of the vector components.
   * @param scalar The scalar value to multiply the vector by.
   * @return A reference to the current vector after the multiplication.
   */
  Vector<T> &operator*=(T scalar);

};

typedef Vector<double> VectorD;
typedef Vector<int> VectorI;

} // namespace MWP