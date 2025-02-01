#include "Vector.hpp"
#include <iostream>
#include <stdexcept>

using namespace MWP;

template <typename T> Vector<T>::Vector(std::vector<T> components) {
  _vector.resize(components.size());
  for (int i = 0; i < components.size(); i++) {
    _vector[i] = components[i];
  }
}

template <typename T> Vector<T>::Vector(unsigned int rows) {
  _vector.resize(rows);
  for (int i = 0; i < rows; i++) {
    _vector[i] = (T)0;
  }
}

template <typename T> unsigned int Vector<T>::Size() const {
  return this->_vector.size();
}

template <typename T> T Vector<T>::operator[](int index) const {
  if (index < 0 || index > this->Size() - 1) {
    throw std::runtime_error("Index out of bounds");
  }
  return _vector[index];
}

template <typename T> T &Vector<T>::operator[](int index) {
  if (index < 0 || index > this->Size() - 1) {
    throw std::runtime_error("Index out of bounds");
  }
  return _vector[index];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &vector) const {
  Vector<T> result(this->_vector);
  for (int i = 0; i < this->Size(); i++) {
    result._vector[i] = this->_vector[i] + vector._vector[i];
  }
  return result;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &vector) {
  for (int i = 0; i < this->Size(); i++) {
    this->_vector[i] += vector._vector[i];
  }
  return *this;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &vector) const {
  Vector<T> result(this->_vector);
  for (int i = 0; i < this->Size(); i++) {
    result._vector[i] = this->_vector[i] - vector._vector[i];
  }
  return result;
}

template <typename T>
Vector<T> &Vector<T>::operator-=(const Vector<T> &vector) {
  for (int i = 0; i < this->Size(); i++) {
    this->_vector[i] -= vector._vector[i];
  }
  return *this;
}

template <typename T> Vector<T> Vector<T>::operator*(T scalar) const {
  Vector<T> result(this->_vector);
  for (int i = 0; i < this->Size(); i++) {
    result._vector[i] = this->_vector[i] * scalar;
  }
  return result;
}

template <typename T> Vector<T> &Vector<T>::operator*=(T scalar) {
  for (int i = 0; i < this->Size(); i++) {
    this->_vector[i] *= scalar;
  }
  return *this;
}

template class MWP::Vector<double>;
template class MWP::Vector<int>;