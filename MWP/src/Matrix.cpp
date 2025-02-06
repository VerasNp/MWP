#include "Matrix.hpp"
#include <stdexcept>
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
  Vector<T> result(1, this->_rows);
  for (int i = 0; i < this->_rows; i++) {
    result[i] = (T)0;
    for (int j = 0; j < this->_columns; j++) {
      result[i] += this->_elements[i * this->_columns + j] * vector[j];
    }
  }
  return result;
}

template <typename T> Matrix<T> &Matrix<T>::Transpose() {
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

template class MWP::Matrix<double>;
template class MWP::Matrix<int>;