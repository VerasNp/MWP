#include "MatrixCSR.hpp"
#include <iostream>
#include <vector>

using namespace MWP;

template <typename T>
MatrixCSR<T>::MatrixCSR(std::vector<unsigned int> indexes,
                        std::vector<T> elements,
                        std::vector<unsigned int> pointers) {
  this->_elements = elements;
  this->_pointers = pointers;
  this->_indexes = indexes;
}

template <typename T>
Vector<T> MatrixCSR<T>::operator*(const Vector<T> &vector) const {
  Vector<T> result(vector._rows, 1);
  for (unsigned int i = 0; i < this->_pointers.size(); i++) {
    T sum = 0;
    for (unsigned int j = this->_pointers[i]; j < this->_pointers[i + 1]; j++) {
      sum += this->_elements[j] * vector._elements[this->_indexes[j]];
    }
    result._elements[i] = sum;
  }
  return result;
}

template class MWP::MatrixCSR<double>;
template class MWP::MatrixCSR<int>;