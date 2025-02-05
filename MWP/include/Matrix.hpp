#pragma once

#include <vector>

namespace MWP {
template <typename T> class Matrix {
public:
  std::vector<T> _elements;
  unsigned int _rows;
  unsigned int _columns;
  unsigned int _size;

public:
  /**
   * @brief Default constructor for matrix
   *
   * Init a empty matrix and size equal to zero
   *
   */
  Matrix<T>();

  /**
   * @brief Constructor for the Matrix class.
   *
   * This constructor initializes the matrix with the given number of rows and
   * columns and set all elements to zero.
   *
   * @tparam T The type of the matrix elements.
   * @param rows The number of rows in the matrix.
   * @param columns The number of columns in the matrix.
   */
  Matrix<T>(unsigned int rows, unsigned int columns);

  /**
   * @brief Constructor for given number of rows and columns
   *
   * Init the matrix with given columns, rows and set the given
   * elements
   *
   * @tparam T The data type of the matrix elements.
   * @param elements The elements of matrix.
   * @param rows The number of rows in the matrix.
   * @param columns The number of columns in the matrix.
   */
  Matrix<T>(std::vector<T> elements, unsigned int rows, unsigned int columns);

public:
  /**
   * @brief Access the matrix element by index.
   *
   * This method allows to access a matrix element by the index.
   *
   * @tparam T The data type of the matrix elements
   * @param index The index of the element.
   * @return The value of the element.
   */
  T operator[](unsigned int index) const;

  /**
   * @brief Access the matrix element by index.
   *
   * This method allows to access a matrix element by the index.
   *
   * @tparam T The data type of the matrix elements
   * @param index The index of the element.
   * @return The reference to the element.
   */
  T &operator[](unsigned int index);

  /**
   * @brief Access the matrix components by row index and column index.
   *
   * This method allows to access a matrix element by its position, using column
   * and row indexes.
   *
   * @tparam T description
   * @param rowIndex The row index of the element position.
   * @param columnsIndex The column index of the element position.
   * @return The element in the asked position.
   */
  T operator()(unsigned int rowIndex, unsigned int columnsIndex) const;

  /**
   * @brief Access the matrix components by row index and column index.
   *
   * This method allows to access a matrix element by its position, using column
   * and row indexes.
   *
   * @tparam T description
   * @param rowIndex The row index of the element position.
   * @param columnsIndex The column index of the element position.
   * @return The element in the asked position.
   */
  T &operator()(unsigned int rowIndex, unsigned int columnsIndex);

  /**
   * @brief Overloads the addition operator for Matrix objects.
   *
   * This operator allows for the addition of two Matrix objects.
   *
   * @tparam T The type of the matrix elements.
   * @param matrix The matrix to be added to the current matrix.
   * @return A new Matrix object that is the result of the matrix
   * addition.
   */
  Matrix<T> operator+(const Matrix<T> &matrix) const;

  /**
   * @brief Overloads the addition operator for Matrix objects.
   *
   * This operator allows for the addition of two Matrix objects.
   *
   * @tparam T The type of the matrix elements.
   * @param matrix The matrix to be added to the current matrix.
   * @return A new Matrix object that is the result of the matrix
   * addition.
   */
  Matrix<T> &operator+(const Matrix<T> &matrix); 

  /**
   * @brief Overloads the subtraction operator for Matrix objects.
   *
   * This operator allows for the addition of two Matrix objects.
   *
   * @tparam T The type of the matrix elements.
   * @param matrix The matrix to be subtracted to the current matrix.
   * @return A new Matrix object that is the result of the matrix
   * subtraction.
   */
  Matrix<T> operator-(const Matrix<T> &matrix) const;

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

  // TODO: Implement
  double Det() const;

  // TODO: Implement
  Matrix<T> Inverse() const;
};
typedef Matrix<double> MatrixD;
typedef Matrix<int> MatrixI;
} // namespace MWP