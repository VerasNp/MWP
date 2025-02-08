#pragma once

#include "Vector.hpp"
#include <stdexcept>
#include <utility>
#include <vector>
#include <cmath>

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
   * @brief Constructor for given elements and number of rows and columns
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
  Vector<T> operator*(const Vector<T> &vector) const;
  

  // TODO: Implement
  double det() const;

  // TODO: Implement
  Matrix<T> inverse() const;

  /**
   * @brief Transpose the current matrix
   *
   * Transpose operation, all the row elements turn into column elements and
   * vice versa
   *
   * @return Matrix<T> Transposed matrix
   */
  Matrix<T> &transpose();

  /**
   * @brief Check if the matrix is square
   *
   * Square matrices have its number of rows equal to the number of columns.
   *
   * @return true Is a square matrix
   * @return false Is not a square matrix
   */
  bool isSquare();

  /**
   * @brief Check if the matrix is lower triangular
   *
   * Lower triangular matrix is a is a special kind of square matrix with all
   * the elements above the main diagonal are zero.
   *
   * @return true Is a lower triangular matrix
   * @return false Is not a lower triangular matrix
   */
  bool isLowerTriangular();

  /**
   * @brief Check if the matrix is upper triangular
   *
   * Upper triangular matrix is a is a special kind of square matrix with all
   * the elements below the main diagonal are zero.
   *
   * @return true Is a upper triangular matrix
   * @return false Is not a upper triangular matrix
   */
  bool isUpperTriangular();

  /**
   * @brief Factors the matrix using lower-upper decomposition
   *
   * Factors the matrix as the product of a lower triangular matrix and an upper
   * triangular matrix.
   *
   * @return std::pair<Matrix<T>, Matrix<T>> Lower triangular matrix and an
   * upper triangular matrix
   */
  std::pair<Matrix<double>, Matrix<double>> LUDecomposition();
 
  
  /**
   * @brief Returns the requested submatrix.
   *
   * Produces a new matrix that is a submatrix of the calling object.
   *
   * @tparam T The type of the matrix elements.
   * @param startRow Initial row.
   * @param startCol Initial col.
   * @param endRow Final row.
   * @param endCol Final col.
   * @return A new Matrix object that is a submatrix of this one.
   */
  MWP::Matrix<T> subMatrix(unsigned int startRow, unsigned int endRow, unsigned int startCol, unsigned int endCol) const;
  
  /**
   * @brief Replaces a submatrix of the current matrix with another smaller matrix.
   *
   * This method replaces a portion of the current matrix (starting at the specified
   * row and column indices) with the elements of the smaller matrix.
   *
   * @param smallerMatrix The smaller matrix to insert into the current matrix.
   * @param startRow The starting row index in the current matrix.
   * @param startCol The starting column index in the current matrix.
   * @throws std::out_of_range If the smaller matrix does not fit within the bounds
   *         of the current matrix at the specified starting indices.
   */
  void replaceSubmatrix(const Matrix<T>& smallerMatrix, unsigned int startRow, unsigned int startCol);
  
  /**
   * @brief Get the largest column number in modulo.
   *
   * @param col Index of the target column.
   * @return Largest number of the column in module.
   * @throws std::out_of_range If the col index is out of bounds.
   */
  T colMax(unsigned int col) const;
  
  /**
   * @brief Norm2 of the matrix.
   *
   * @return Norm of matrix.
   */
  T norm2() const;
  
  /**
   * @brief QR decomposition of a mxn matrix.
   * 
   * @return An orthogonal vector Q and an upper triangular vector R.
   *
   */
  std::pair<Matrix<T>,Matrix<T>> QRdecomp() const;
  
};
typedef Matrix<double> MatrixD;
typedef Matrix<int> MatrixI;
} // namespace MWP



/**
 * @brief Transpose the current matrix
 *
 * Transpose operation, all the row elements turn into column elements and
 * vice versa
 *
 * @return Matrix<T> Transposed matrix
 */
template <typename T>
inline MWP::Matrix<T> TransposeMatrix(const MWP::Matrix<T> &matrix) {
  MWP::Matrix<T> transposedMatrix(matrix._columns, matrix._rows);
  for (int i = 0; i < transposedMatrix._rows; i++) {
    for (int j = 0; j < transposedMatrix._columns; j++) {
      transposedMatrix._elements[i * transposedMatrix._columns + j] =
          matrix._elements[j * transposedMatrix._rows + i];
    }
  }
  return transposedMatrix;
}

/**
 * @brief Creates an identity matrix
 *
 * Returns a matrix where all the elements in the main diagonal are one.
 *
 * @tparam T The type of the matrix elements.
 * @param rows Number of rows.
 * @param columns Number of columns.
 * @return MWP::Matrix<T> The identity matrix.
 */
template <typename T>
inline MWP::Matrix<T> IdentityMatrix(unsigned int rows, unsigned int columns) {
  if (rows != columns) {
    throw std::runtime_error("An identity matrix should have number of rows "
                             "equal to the number of columns");
  }
  MWP::Matrix<T> identityMatrix(rows, columns);
  for (int i = 0; i < identityMatrix._rows; i++) {
    for (int j = 0; j < identityMatrix._columns; j++) {
      if (i == j) {
        identityMatrix._elements[i * identityMatrix._columns + j] = (T)1;
      }
    }
  }
  return identityMatrix;
}

/**
 * @brief Evaluate the nth householder submatrix
 *
 * Zeros out all columns below the nth diagonal element
 *
 * @param A Matrix to be zeroed
 * @return [A,u] Pair.
 */

template <typename T>
inline std::pair<MWP::Matrix<T>,MWP::Matrix<T>> hh(const MWP::Matrix<T> &A){

  MWP::Matrix<T> A_star = A;
  MWP::Matrix<T> x = A_star.subMatrix(0,A_star._rows,0,1);//column vector
  MWP::Matrix<T> hu;
  T beta;
  T maxVal = x.colMax(0);
  x = x*((T)1.0f/maxVal);
  
  T colNorm = x.norm2();
  hu = x;
  if(hu[0]>=0){
    hu[0] = hu[0] + colNorm;
  }
  else{
    hu[0] = hu[0] - colNorm;
  }
  
  T huNorm = hu.norm2();
  
  if(huNorm >= 10e-17){
    beta = (T)2.f/(huNorm*huNorm);
  }
  else{
    beta = (T)0.f;
  }
  
  A_star = A_star - (hu*beta)*(TransposeMatrix(hu)*A_star);
  return {A_star,hu};
}

template <typename T>
inline std::pair<MWP::MatrixD, MWP::MatrixD> GS(const MWP::Matrix<T> &matrix) {
  // TODO: Check if columns are L.I
  MWP::Matrix<T> QMatrix(matrix._rows, matrix._columns);
  MWP::Matrix<T> RMatrix(matrix._rows, matrix._columns);
}
