#include "Matrix.hpp"
#include <stdexcept>
#include <vector>

using namespace MWP;

template <typename T>
Matrix<T>::Matrix(std::vector<T> matrix, unsigned int rows,
                  unsigned int columns) {
  _rows = rows;
  _columns = columns;
  _size = rows * columns;
  _matrix = matrix;
}

template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns) {
  this->_rows = rows;
  this->_columns = columns;
  this->_size = rows * columns;
  _matrix.resize(this->_size);
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_columns; j++) {
      this->_matrix[i * this->_columns + j] = (T)0;
    }
  }
}

template <typename T> T Matrix<T>::operator[](unsigned int index) const {
  if (index < 0 || index > this->_size - 1) {
    throw std::runtime_error("Index out of bounds");
  }
  return this->_matrix[index];
}

template <typename T> T &Matrix<T>::operator[](unsigned int index) {
  if (index < 0 || index > this->_size - 1) {
    throw std::runtime_error("Index out of bounds");
  }
  return this->_matrix[index];
}

template <typename T> Matrix<T> Matrix<T>::operator*(T scalar) const {
  Matrix<T> result(this->_matrix, this->_rows, this->_columns);
  for (int i = 0; i < result._rows; i++) {
    for (int j = 0; j < result._columns; j++) {
      result._matrix[i * result._columns + j] =
          this->_matrix[i * result._columns + j] * scalar;
    }
  }
  return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &matrix) const {
  if (this->_columns != matrix._rows) {
    throw std::runtime_error("Invalid matrix dimensions");
  }
  Matrix<T> result(this->_rows, matrix._columns);
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < matrix._columns; j++) {
      result._matrix[i * matrix._columns + j] = (T)0;
      for (int k = 0; k < this->_columns; k++) {
        result._matrix[i * matrix._columns + j] +=
            this->_matrix[i * this->_columns + k] *
            matrix._matrix[k * matrix._columns + j];
      }
    }
  }
  return result;
}

template <typename T>
Vector<T> Matrix<T>::operator*(const Vector<T> &vector) const {
  if (this->_columns != vector.Size()) {
    throw std::runtime_error(
        "Invalid dimensions for matrix-vector multiplication");
  }
  Vector<T> result(this->_rows);
  for (int i = 0; i < this->_rows; i++) {
    result[i] = (T)0;
    for (int j = 0; j < this->_columns; j++) {
      result[i] += this->_matrix[i * this->_columns + j] * vector[j];
    }
  }
  return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &matrix) const {
  if (this->_rows != matrix._rows || this->_columns != matrix._columns) {
    throw std::runtime_error("Invalid dimensions");
  }
  Matrix<T> result(this->_matrix, this->_rows, this->_columns);
  for (int i = 0; i < result._rows; i++) {
    for (int j = 0; j < result._columns; j++) {
      result._matrix[i * result._columns + j] =
          this->_matrix[i * result._columns + j] +
          matrix._matrix[i * result._columns + j];
    }
  }
  return result;
}

template class MWP::Matrix<double>;
template class MWP::Matrix<int>;