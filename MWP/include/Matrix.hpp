#pragma once

#include <cstddef>
#include <vector>
#include "Vector.hpp"
namespace MWP {
template <typename T> class Matrix {
public:
  std::vector<T> _matrix;
  unsigned int _rows;
  unsigned int _columns;
  unsigned int _size;

public:
  /**
   * @brief Construct a new Matrix< T> object
   *
   * @param matrix
   */
  Matrix<T>(std::vector<T> matrix, unsigned int rows, unsigned int columns);
  /**
   * @brief Constructor for the Matrix class.
   *
   * This constructor initializes the matrix with the given number of rows and
   * columns.
   *
   * @tparam T The type of the matrix elements.
   * @param rows The number of rows in the matrix.
   * @param columns The number of columns in the matrix.
   */
  Matrix<T>(unsigned int rows, unsigned int columns);

  /**
   * @brief Constructor for the Matrix class.
   *
   * This constructor initializes the matrix with the given number of rows and
   * columns and the given matrix values.
   *
   * @tparam T The type of the matrix elements.
   * @param rows The number of rows in the matrix.
   * @param columns The number of columns in the matrix.
   * @param matrix The matrix values.
   */
  Matrix<T>(size_t rows, size_t columns, std::vector<T> matrix);

public:
  /**
   * @brief Access the matrix components by index
   *
   * This method allows for the access of the matrix components by index.
   *
   * @param index The index of the component
   * @return The value of the component
   */
  T operator[](unsigned int index) const;

  /**
   * @brief Access the matrix components by index
   *
   * This method allows for the access of the matrix components by index.
   *
   * @param index The index of the component
   * @return The reference to the component
   */
  T &operator[](unsigned int index);

  /**
   * @brief
   *
   * @param rowIndex
   * @param columnsIndex
   * @return T
   */
  T operator()(unsigned int rowIndex, unsigned int columnsIndex) const;

  /**
   * @brief
   *
   * @param rowIndex
   * @param columnsIndex
   * @return T&
   */
  T &operator()(unsigned int rowIndex, unsigned int columnsIndex);

  /**
  * @brief Overloads the multiplication operator for Matrix objects.
  *
  * This operator allows for the multiplication of a Matrix object by a
  scalar.
  *
  * @tparam T The type of the matrix elements.
  * @param scalar The scalar value to multiply the matrix by.
  * @return A new Matrix object that is the result of the matrix-scalar
  * multiplication.
  */
  Matrix<T> operator*(T scalar) const;

  /**
   * @brief Overloads the multiplication operator for Matrix objects.
   *
   * This operator allows for the multiplication of two Matrix objects.
   *
   * @tparam T The type of the matrix elements.
   * @param matrix The matrix to be multiplied by the current matrix.
   * @return A new Matrix object that is the result of the matrix
   * multiplication.
   */
  Matrix<T> operator*(const Matrix<T> &matrix) const;

  
  Vector<T> operator*(const Vector<T> &vector) const;

  /**
   * @brief Overloads the addition operator for Matrix objects.
   *
   * This operator allows for the addition of two Matrix objects.
   *
   * @tparam T The type of the matrix elements.
   * @param matrix The matrix to be added to the current matrix.
   * @return A new Matrix object that is the result of the matrix addition.
   */
  Matrix<T> operator+(const Matrix<T> &matrix) const;
};
typedef Matrix<double> MatrixD;
typedef Matrix<int> MatrixI;
} // namespace MWP