#include "Vector.hpp"
#include <cstddef>
// #include <cmath>
// #include <iostream>
// #include <stdexcept>

using namespace MWP;

template <typename T> Vector<T>::Vector() {
  this->_rows = 0;
  this->_columns = 0;
  this->_size = 0;
  this->_elements = std::vector<T>();
  this->_vectorFormat = UNDEFINED;
}

template <typename T>
Vector<T>::Vector(unsigned int size, VectorFormat vectorFormat) {
  if (size == 0) {
    throw std::runtime_error("The row or column attribute cannot be zero");
  }
  if (vectorFormat == COLUMN_VECTOR) {
    this->_rows = size;
    this->_columns = 1;
  } else {
    this->_rows = 1;
    this->_columns = size;
  }
  this->_vectorFormat = vectorFormat;
  this->_size = size;
  this->_elements.resize(this->_size);
  for (unsigned int i = 0; i < this->_size; i++) {
    this->_elements[i] = (T)0;
  }
}

template <typename T>
Vector<T>::Vector(std::vector<T> elements, unsigned int size,
                  VectorFormat vectorFormat) {
  if (size == 0) {
    throw std::runtime_error("The row or column attribute cannot be zero!");
  }
  if (elements.size() != size) {
    throw std::runtime_error(
        "The amount of elements do not match with the vector size!");
  }
  if (vectorFormat == COLUMN_VECTOR) {
    this->_rows = size;
    this->_columns = 1;
  } else {
    this->_rows = 1;
    this->_columns = size;
  }
  this->_vectorFormat = vectorFormat;
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

template <typename T>
template <typename U>
Vector<T> Vector<T>::operator+(const Vector<U> &vector) const {
  if (this->_size != vector._size) {
    throw std::runtime_error(
        "Mismatch on vectors dimensions for addition operation");
  }
  if (this->_vectorFormat != vector._vectorFormat) {
    throw std::runtime_error(
        "Mismatch on vectors formats for addition operation");
  }
  Vector<T> result(this->_size, this->_vectorFormat);
  for (unsigned int i = 0; i < this->_size; i++) {
    result._elements[i] = static_cast<T>(this->_elements[i] +
                                         static_cast<T>(vector._elements[i]));
  }
  return result;
}

template <typename T>
template <typename U>
Vector<T> Vector<T>::operator-(const Vector<U> &vector) const {
  if (this->_size != vector._size) {
    throw std::runtime_error(
        "Mismatch on vectors dimensions for subtraction operation");
  }
  if (this->_vectorFormat != vector._vectorFormat) {
    throw std::runtime_error(
        "Mismatch on vectors formats for subtraction operation");
  }
  Vector<T> result(this->_size, this->_vectorFormat);
  for (unsigned int i = 0; i < this->_size; i++) {
    result._elements[i] = static_cast<T>(this->_elements[i] -
                                         static_cast<T>(vector._elements[i]));
  }
  return result;
}

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
template Vector<double> Vector<double>::operator+
    <double>(const Vector<double> &) const;
template Vector<double> Vector<double>::operator+
    <int>(const Vector<int> &) const;
template Vector<int> Vector<int>::operator+
    <double>(const Vector<double> &) const;
template Vector<int> Vector<int>::operator+ <int>(const Vector<int> &) const;
template Vector<double> Vector<double>::operator-
    <double>(const Vector<double> &) const;
template Vector<double> Vector<double>::operator-
    <int>(const Vector<int> &) const;
template Vector<int> Vector<int>::operator-
    <double>(const Vector<double> &) const;
template Vector<int> Vector<int>::operator- <int>(const Vector<int> &) const;