#pragma once

#include "Matrix.hpp"
#include <cmath>
#include <cstddef>
#include <random>
#include <vector>

namespace MWP {

template <typename T> class Vector : public Matrix<T> {
public:
  enum VectorFormat { ROW_VECTOR, COLUMN_VECTOR, UNDEFINED };

public:
  VectorFormat _vectorFormat;

public:
  /**
   * @brief Default constructor for vector
   *
   * This constructor initializes a vector with empty elements and size equal to
   * zero
   */
  Vector();

  /**
   * @brief Inits a vector with given size and type.
   *
   * This constructor initializes a vector with the provided size and
   * type.
   *
   * @param size The size of the vector.
   * @param vectorType The type of the vector (ROW_VECTOR or COLUMN_VECTOR).
   */
  Vector(unsigned int size, VectorFormat vectorType);

  /**
   * @brief Inits a vector with given elements, vector size and vector type
   *
   * This constructor initializes a vector with the provided elements, size, and
   * type.
   *
   * @param elements A vector containing the elements to initialize the vector
   * with.
   * @param size The size of the vector.
   * @param vectorType The type of the vector (ROW_VECTOR or COLUMN_VECTOR).
   */
  Vector(std::vector<T> elements, unsigned int size, VectorFormat vectorType);

public:
  /**
   * @brief Access the vector components by index
   *
   * This method allows for the access of the vector components by index.
   *
   * @param index The index of the component
   * @return The value of the component
   */
  T operator[](unsigned int index) const;

  /**
   * @brief Access the vector components by index
   *
   * This method allows for the access of the vector components by index.
   *
   * @param index The index of the component
   * @return The reference to the component
   */
  T &operator[](unsigned int index);

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
  template <typename U> Vector<T> operator+(const Vector<U> &vector) const;

  /**
   * @brief Overloads the subtraction operator for Vector objects.
   *
   * This operator allows for the subtraction of two Vector objects.
   * It returns a new Vector object whose components are the difference
   * of the corresponding components of the two input vectors.
   *
   * @tparam T The type of the vector components.
   * @param vector The vector to be subtracted from the current vector.
   * @return A new Vector object that is the result of the vector
   subtraction.
   */
  template <typename U> Vector<T> operator-(const Vector<U> &vector) const;

  /**
   * @brief Overloads the multiplication operator for Vector objects.
   *
   * This operator allows for the multiplication of a Vector object by a
   * scalar. It returns a new Vector object whose components are the
   product
   * of the corresponding components of the input vector and the scalar.
   *
   * @tparam T The type of the vector components.
   * @param scalar The scalar value to multiply the vector by.
   * @return A new Vector object that is the result of the vector-scalar
   * multiplication.
   */
  Vector<T> operator*(T scalar) const;

  //   /**
  //    * @brief Overloads the multiplication operator for Vector objects.
  //    *
  //    * This operator allows for the multiplication of two Vector objects.
  //    *
  //    * @tparam T The type of the vector elements.
  //    * @param vector The vector to be multiplied by the current vector.
  //    * @return A new Vector object that is the result of the vector
  //    * multiplication.
  //    */
  //   Vector<T> operator*(const Vector<T> &vector) const;

  //   /**
  //    * @brief Computes the projection of the current vector onto another
  //    vector.
  //    *
  //    * @param vector The vector onto which the current vector is projected.
  //    * @return Vector<T> A new vector representing the projection of the
  //    current
  //    * vector onto the input vector.
  //    */
  //   Vector<T> projectedOnto(const Vector<T> &vector);

  //   /**
  //    * @brief
  //    *
  //    * @return double
  //    */
  //   double norm2() const;
};

typedef Vector<double> VectorD;
typedef Vector<int> VectorI;
} // namespace MWP

// template <typename T>
// inline MWP::Vector<T> transposeVector(const MWP::Vector<T> &vector) {
//   MWP::Vector<T> transposedVector(vector._elements, vector._columns,
//                                   vector._rows);
//   return transposedVector;
// }

// template <typename T>
// inline T Dot(const MWP::Vector<T> &vector1, const MWP::Vector<T> &vector2) {
//   // TODO: Check compatibility
//   T sum = (T)0;
//   for (int i = 0; i < vector1._size; i++) {
//     sum += vector1._elements[i] * vector2._elements[i];
//   }
//   return sum;
// }

// template <typename T>
// inline MWP::Matrix<T> toMatrix(const MWP::Vector<T> &vector) {
//   return MWP::Matrix<T>(vector._elements, vector._rows, vector._columns);
// }

// /**
//  * @brief
//  *
//  * @tparam T
//  * @param rows
//  * @param min
//  * @param max
//  * @return MWP::Vector<T>
//  */
// template <typename T>
// inline MWP::Vector<T> randomColumnVector(unsigned int rows, int min = 0,
//                                          int max = 1) {
//   std::mt19937 gen(42);
//   std::uniform_real_distribution<> dis(min, max);
//   MWP::Vector<T> randomVector(rows, 1);
//   for (int i = 0; i < randomVector._size; i++) {
//     randomVector._elements[i] = dis(gen);
//   }
//   return randomVector;
// }

// /**
//  * @brief Should generate a random row vector with given number of rows
//  *
//  * @tparam T Type of
//  * @param columns
//  * @param min
//  * @param max
//  * @return MWP::Vector<T>
//  */
// template <typename T>
// inline MWP::Vector<T> randomRowVector(unsigned int columns, int min = 0,
//                                       int max = 1) {
//   std::mt19937 gen(42);
//   std::uniform_real_distribution<> dis(min, max);
//   MWP::Vector<T> randomVector(1, columns);
//   for (int i = 0; i < randomVector._size; i++) {
//     randomVector._elements[i] = dis(gen);
//   }
//   return randomVector;
// }