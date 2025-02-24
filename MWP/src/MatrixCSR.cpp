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
MatrixCSR<T> MatrixCSR<T>::operator*(const Vector<T> &vector) const {
  for (unsigned int i = 0; i < this->_pointers.size(); i++) {
    for (unsigned int j = this->_pointers[i]; j < this->_pointers[i + 1]; j++) {
      std::cout << this->_elements[j] << '\n';
    }
  }
  return {};
}

template class MWP::MatrixCSR<double>;
template class MWP::MatrixCSR<int>;