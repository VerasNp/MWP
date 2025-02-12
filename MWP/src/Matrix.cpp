#include "Matrix.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace MWP;

template <typename T> Matrix<T>::Matrix() {
  _rows = 0;
  _columns = 0;
  _size = 0;
  _elements = std::vector<T>();
}

template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns) {
  if (columns == 0 || rows == 0) {
    throw std::runtime_error("The row or column attribute cannot be zero");
  }
  this->_rows = rows;
  this->_columns = columns;
  this->_size = rows * columns;
  _elements.resize(this->_size);
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_columns; j++) {
      this->_elements[i * this->_columns + j] = (T)0;
    }
  }
}

template <typename T>
Matrix<T>::Matrix(std::vector<T> elements, unsigned int rows,
                  unsigned int columns) {
  if (columns == 0 || rows == 0) {
    throw std::runtime_error("The row or column attribute cannot be zero");
  }
  if (elements.size() != columns * rows) {
    throw std::runtime_error(
        "The amount of elements do not match with the matrix size");
  }
  _rows = rows;
  _columns = columns;
  _size = rows * columns;
  _elements = elements;
}

template <typename T> T Matrix<T>::operator[](unsigned int index) const {
  if (index > this->_size - 1) {
    throw std::runtime_error("Index out of bounds");
  }
  return this->_elements[index];
}

template <typename T> T &Matrix<T>::operator[](unsigned int index) {
  if (index > this->_size - 1) {
    throw std::runtime_error("Index out of bounds");
  }
  return this->_elements[index];
}

template <typename T>
T Matrix<T>::operator()(unsigned int rowIndex,
                        unsigned int columnsIndex) const {
  if (rowIndex > this->_size - 1 || columnsIndex > this->_size) {
    throw std::runtime_error("Index out of bounds");
  }
  return this->_elements[rowIndex * this->_columns + columnsIndex];
}

template <typename T>
T &Matrix<T>::operator()(unsigned int rowIndex, unsigned int columnsIndex) {
  if (rowIndex > this->_size - 1 || columnsIndex > this->_size) {
    throw std::runtime_error("Index out of bounds");
  }
  return this->_elements[rowIndex * this->_columns + columnsIndex];
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &matrix) const {
  if (this->_rows != matrix._rows || this->_columns != matrix._columns) {
    throw std::runtime_error(
        "Invalid matrices dimensions for addition operation");
  }
  Matrix<T> result(this->_rows, this->_columns);
  for (int i = 0; i < result._rows; i++) {
    for (int j = 0; j < result._columns; j++) {
      result._elements[i * result._columns + j] =
          this->_elements[i * result._columns + j] +
          matrix._elements[i * result._columns + j];
    }
  }
  return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &matrix) const {
  if (this->_rows != matrix._rows || this->_columns != matrix._columns) {
    throw std::runtime_error(
        "Invalid matrices dimensions for subtraction operation");
  }
  Matrix<T> result(this->_rows, this->_columns);
  for (int i = 0; i < result._rows; i++) {
    for (int j = 0; j < result._columns; j++) {
      result._elements[i * result._columns + j] =
          this->_elements[i * result._columns + j] -
          matrix._elements[i * result._columns + j];
    }
  }
  return result;
}

template <typename T> Matrix<T> Matrix<T>::operator*(T scalar) const {
  Matrix<T> result(this->_rows, this->_columns);
  for (int i = 0; i < result._rows; i++) {
    for (int j = 0; j < result._columns; j++) {
      result._elements[i * result._columns + j] =
          this->_elements[i * result._columns + j] * scalar;
    }
  }
  return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &matrix) const {
  if (this->_columns != matrix._rows) {
    throw std::runtime_error(
        "Invalid matrices dimensions for multiplication operation");
  }
  Matrix<T> result(this->_rows, matrix._columns);
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < matrix._columns; j++) {
      for (int k = 0; k < this->_columns; k++) {
        result._elements[i * matrix._columns + j] +=
            this->_elements[i * this->_columns + k] *
            matrix._elements[k * matrix._columns + j];
      }
    }
  }
  return result;
}

template <typename T>
Vector<T> Matrix<T>::operator*(const Vector<T> &vector) const {
  if (this->_columns != vector._rows || vector._columns != 1) {
    throw std::runtime_error(
        "Invalid dimensions for matrix-vector multiplication");
  }
  Vector<T> result(this->_rows, vector._columns);
  for (int i = 0; i < this->_rows; i++) {
    result[i] = (T)0;
    for (int j = 0; j < this->_columns; j++) {
      result[i] += this->_elements[i * this->_columns + j] * vector[j];
    }
  }
  return result;
}

template <typename T> Matrix<T> &Matrix<T>::transpose() {
  std::vector<T> transposedElements;
  transposedElements.resize(this->_size);
  const int rows = this->_rows;
  const int columns = this->_columns;
  this->_rows = columns;
  this->_columns = rows;
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_columns; j++) {
      transposedElements[i * this->_columns + j] =
          this->_elements[j * this->_rows + i];
    }
  }
  this->_elements = transposedElements;
  return *this;
}

template <typename T> bool Matrix<T>::isSquare() const {
  return this->_rows == this->_columns;
}

template <typename T> bool Matrix<T>::isLowerTriangular()  const {
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_columns; j++) {
      if (i < j && std::abs((this->_elements[i * this->_columns + j])) > 10e-10) {
        std::cout << this->_elements[i * this->_columns + j] << '\n';
        return false;
      }
    }
  }
  return true;
}

template <typename T> bool Matrix<T>::isUpperTriangular() const  {
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_columns; j++) {
      if (i > j && std::abs((this->_elements[i * this->_columns + j])) > 10e-10) {
        std::cout << this->_elements[i * this->_columns + j] << '\n';
        return false;
      }
    }
  }
  return true;
}

template <typename T> std::pair<MatrixD, MatrixD> Matrix<T>::LUDecomposition() {
  if (this->_rows != this->_columns) {
    throw std::runtime_error(
        "The matrix should be square to be decomposed into LU matrices!");
  }
  MatrixD LMatrix = IdentityMatrix<double>(this->_rows, this->_columns);
  std::vector<double> elementsDouble(this->_elements.begin(),
                                     this->_elements.end());
  MatrixD UMatrix(elementsDouble, this->_rows, this->_columns);
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_columns; j++) {
      if (i > j) {
        LMatrix[i * this->_columns + j] =
            UMatrix[i * this->_columns + j] / UMatrix[j * this->_columns + j];
        for (int k = j; k < this->_columns; k++) {
          UMatrix[i * this->_columns + k] -=
              LMatrix[i * this->_columns + j] * UMatrix[j * this->_columns + k];
        }
      }
    }
  }
  return std::pair<MatrixD, MatrixD>{LMatrix, UMatrix};
}

template <typename T>
MWP::Matrix<T>
MWP::Matrix<T>::subMatrix(unsigned int startRow, unsigned int endRow,
                          unsigned int startCol, unsigned int endCol) const {
  if (startRow > endRow || startCol >= endCol || endRow > _rows ||
      endCol > _columns) {
    throw std::out_of_range("Invalid submatrix range");
  }

  unsigned int subRows = endRow - startRow;
  unsigned int subCols = endCol - startCol;
  std::vector<T> subElements(subRows * subCols);

  for (unsigned int i = startRow; i < endRow; i++) {
    for (unsigned int j = startCol; j < endCol; j++) {
      subElements[(i - startRow) * subCols + (j - startCol)] =
          _elements[i * _columns + j];
    }
  }

  return Matrix<T>(subElements, subRows, subCols);
}

template <typename T>
void MWP::Matrix<T>::replaceSubmatrix(const Matrix<T> &smallerMatrix,
                                      unsigned int startRow,
                                      unsigned int startCol) {
  if (startRow + smallerMatrix._rows > _rows ||
      startCol + smallerMatrix._columns > _columns) {
    throw std::out_of_range("Smaller matrix does not fit within the larger "
                            "matrix at the specified indices.");
  }

  for (unsigned int i = 0; i < smallerMatrix._rows; i++) {
    for (unsigned int j = 0; j < smallerMatrix._columns; j++) {
      unsigned int largerIndex = (startRow + i) * _columns + (startCol + j);
      _elements[largerIndex] = smallerMatrix(i, j);
    }
  }
}

template <typename T> T MWP::Matrix<T>::colMax(unsigned int col) const {
  if (col >= _columns) {
    throw std::out_of_range("Out of range column.");
  }
  T max = std::abs(this->operator()(0, col));
  T current;
  for (int i = 1; i < _rows; i++) {
    current = std::abs(this->operator()(i, col));
    if (current > max) {
      max = current;
    }
  }
  return max;
}

template <typename T> T MWP::Matrix<T>::norm2() const {
  T sum = 0;
  for (T e : _elements) {
    sum += (e * e);
  }
  return std::sqrt(sum);
}

template <typename T>
std::pair<MWP::Matrix<T>, MWP::Matrix<T>> MWP::Matrix<T>::QRdecomp() const {
  MWP::Matrix<T> R = *this;
  MWP::Matrix<T> Q = IdentityMatrix<T>(this->_rows, this->_rows);
  unsigned int k = std::min(this->_rows - 1, this->_columns);
  std::pair<MWP::Matrix<T>, MWP::Matrix<T>> ru;
  for (int i = 0; i < k; i++) {
    ru = hh(R.subMatrix(i, R._rows, i, R._columns));
    R.replaceSubmatrix(ru.first, i, i);
    Matrix<T> uh = ru.second;
    T uhNorm = uh.norm2();
    Matrix<T> qsub = Q.subMatrix(0, Q._rows, i, Q._columns);
    Matrix<T> qres = qsub - (qsub * (2.f / (uhNorm * uhNorm))) *
                                (uh * TransposeMatrix<T>(uh)); // qsub - qumul;
    Q.replaceSubmatrix(qres, 0, i);
  }
  return {Q, R};
}

template class MWP::Matrix<double>;
template class MWP::Matrix<int>;