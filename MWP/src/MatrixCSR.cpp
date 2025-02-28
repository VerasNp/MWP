#include "MatrixCSR.hpp"
#include "Vector.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace MWP;

template <typename T>
MatrixCSR<T>::MatrixCSR(std::vector<unsigned int> indexes,
                        std::vector<T> elements,
                        std::vector<unsigned int> pointers, unsigned int rows) {
  this->_elements = elements;
  this->_indexes = indexes;
  if (this->_elements.size() != this->_indexes.size()) {
    std::runtime_error("Elements do not match with indexes!");
  }
  this->_pointers = pointers;
  if (this->_pointers.back() != this->_elements.size()) {
    std::runtime_error("Pointer do not match with elements!");
  }
  this->_rows = rows;
}

template <typename T>
Vector<T> MatrixCSR<T>::operator*(const Vector<T> &vector) const {
  Vector<T> result(vector._rows, 1);
  for (unsigned int i = 0; i < this->_pointers.size() - 1; i++) {
    T sum = (T)0;
    for (unsigned int j = this->_pointers[i]; j < this->_pointers[i + 1]; j++) {
      sum += this->_elements[j] * vector._elements[this->_indexes[j]];
    }
    result._elements[i] = sum;
  }
  return result;
}

template <typename T>
std::vector<std::pair<Vector<T>, double>>
MWP::MatrixCSR<T>::eigenvalue(EigenvalueNumericMethod eigenvalueNumericMethod) {
  if (eigenvalueNumericMethod == POWER_METHOD) {
    return this->powerMethodEigenvalue();
  } else {
    throw std::runtime_error("Unknown numeric method to find eigenvalue");
  }
}

template <typename T>
std::vector<std::pair<Vector<T>, double>>
MatrixCSR<T>::powerMethodEigenvalue(unsigned int iterations, double epsilon,
                                    unsigned int qtdEigenpairs) {
  Vector<T> x = randomColumnVector<T>(this->_rows, 10, 20);
  std::vector<std::pair<Vector<T>, double>> eigenPairs;
  eigenPairs.reserve(qtdEigenpairs);
  for (unsigned int iteration = 0; iteration < iterations; iteration++) {
    Vector<T> newX = (*this) * x;
    newX = newX * (1 / (*this * newX).norm2());
    Vector<T> diff = newX - x;
    if (diff.norm2() < epsilon) {
      break;
    }
    x = newX;
  }
  Vector<T> newX = *this * x;
  double eigenvalue =
      ((transposeVector(x) * newX) * (1 / (transposeVector(x) * x)[0]))[0];
  std::pair<Vector<T>, double> eigenPair(newX, eigenvalue);
  eigenPairs.push_back(eigenPair);
  return eigenPairs;
}

template <typename T>
MatrixCSR<T> MatrixCSR<T>::deflation(double eigenvalue, VectorD eigenvector) {}

template class MWP::MatrixCSR<double>;
template class MWP::MatrixCSR<int>;