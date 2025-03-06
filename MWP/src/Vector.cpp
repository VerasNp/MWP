#include "Vector.hpp"
// #include <cmath>
// #include <iostream>
// #include <stdexcept>

using namespace MWP;

template <typename T> Vector<T>::Vector() {
  this->_rows = 0;
  this->_columns = 0;
  this->_size = 0;
  this->_elements = std::vector<T>();
}

template <typename T>
Vector<T>::Vector(unsigned int size, VectorType vectorType) {
  if (size == 0) {
    throw std::runtime_error("The row or column attribute cannot be zero");
  }
  if (vectorType == COLUMN_VECTOR) {
    this->_rows = size;
    this->_columns = 1;
  } else {
    this->_rows = 1;
    this->_columns = size;
  }
  this->_size = size;
  this->_elements.resize(this->_size);
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_columns; j++) {
      this->_elements[i * this->_columns + j] = (T)0;
    }
  }
}

template <typename T>
Vector<T>::Vector(std::vector<T> elements, unsigned int size,
                  VectorType vectorType) {
  if (size == 0) {
    throw std::runtime_error("The row or column attribute cannot be zero!");
  }
  if (elements.size() != size) {
    throw std::runtime_error(
        "The amount of elements do not match with the vector size!");
  }
  if (vectorType == COLUMN_VECTOR) {
    this->_rows = size;
    this->_columns = 1;
  } else {
    this->_rows = 1;
    this->_columns = size;
  }
  this->_size = size;
  this->_elements = elements;
}

template <typename T> T Vector<T>::operator[](unsigned int index) const {
  if (index >= this->_size) {
    throw std::runtime_error("Index out of bounds");
  }
  return this->_elements[index];
}

template <typename T> T &Vector<T>::operator[](unsigned int index) {
  if (index >= this->_size) {
    throw std::runtime_error("Index out of bounds");
  }
  return this->_elements[index];
}

// template <typename T>
// Vector<T> Vector<T>::operator+(const Vector<T> &vector) const {
//   if (this->_rows != vector._rows || this->_columns != vector._columns) {
//     throw std::runtime_error(
//         "Invalid vectors dimensions for addition operation");
//   }
//   Vector<T> result(this->_elements, this->_rows, this->_columns);
//   for (int i = 0; i < this->_size; i++) {
//     result._elements[i] = this->_elements[i] + vector._elements[i];
//   }
//   return result;
// }

// template <typename T>
// Vector<T> Vector<T>::operator-(const Vector<T> &vector) const {
//   if (this->_rows != vector._rows || this->_columns != vector._columns) {
//     throw std::runtime_error(
//         "Invalid vectors dimensions for subtraction operation");
//   }
//   Vector<T> result(this->_elements, this->_rows, this->_columns);
//   for (int i = 0; i < this->_size; i++) {
//     result._elements[i] = this->_elements[i] - vector._elements[i];
//   }
//   return result;
// }

// template <typename T> Vector<T> Vector<T>::operator*(T scalar) const {
//   Vector<T> result(this->_elements, this->_rows, this->_columns);
//   for (int i = 0; i < this->_size; i++) {
//     result._elements[i] = this->_elements[i] * scalar;
//   }
//   return result;
// }

// template <typename T>
// Vector<T> Vector<T>::operator*(const Vector<T> &vector) const {
//   if (this->_columns != vector._rows) {
//     throw std::runtime_error(
//         "Invalid dimensions for vector-vector multiplication");
//   }
//   Vector<T> result(this->_rows, vector._columns);
//   for (int i = 0; i < this->_rows; i++) {
//     result[i] = (T)0;
//     for (int j = 0; j < this->_columns; j++) {
//       result[i] += this->_elements[i * this->_columns + j] * vector[j];
//     }
//   }
//   return result;
// }

// template <typename T>
// Vector<T> Vector<T>::projectedOnto(const Vector<T> &vector) {
//   if (vector._columns != 1) {
//     throw std::runtime_error(
//         "Invalid vectors dimensions for projection operation");
//   }
//   Vector<T> transposedVector = transposeVector(vector);
//   Vector<T> projectionVector =
//       vector * ((transposedVector * *this)[0] / (transposedVector *
//       vector)[0]);
//   return projectionVector;
// }

// template <typename T> double Vector<T>::norm2() const {
//   double sum = 0.0f;
//   for (T element : this->_elements) {
//     sum += std::pow(element, 2);
//   }
//   return std::sqrt(sum);
// }

template class MWP::Vector<double>;
template class MWP::Vector<int>;