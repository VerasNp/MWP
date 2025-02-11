#include "LinSys.hpp"
#include <iostream>
#include <stdexcept>

using namespace MWP;

template <typename T>
LinSys<T>::LinSys(Matrix<T> coefficients, Vector<T> constants) {
  if (coefficients._rows != constants._rows) {
    throw std::runtime_error("Incompatible dimension of coefficient matrix "
                             "with the constants vector");
  }
  if (constants._columns > 1) {
    throw std::runtime_error("Incompatible constants vector dimension");
  }
  if (coefficients._rows == 1) {
    throw std::runtime_error("Incompatible coefficient matrix dimension");
  }
  this->coefficients = coefficients;
  Vector<T> variables(coefficients._columns, constants._columns);
  this->variables = variables;
  this->constants = constants;
}

template <typename T> void LinSys<T>::solveForwardSubstitution() {
  if (this->coefficients.isLowerTriangular()) {
    this->variables._elements[0] =
        this->constants._elements[0] / this->coefficients._elements[0];
    for (int i = 1; i < this->coefficients._rows; i++) {
      double sum = (T)0;
      for (int j = 0; j <= i - 1; j++) {
        sum += this->coefficients._elements[i * this->coefficients._rows + j] *
               this->variables._elements[j];
      }
      this->variables._elements[i] =
          (1.0f /
           this->coefficients._elements[i * this->coefficients._columns + i]) *
          (this->constants._elements[i] - sum);
    }
  } else {
    throw std::runtime_error(
        "The given linear system is not a lower triangular "
        "linear system of equations");
  }
}

template <typename T> void LinSys<T>::solveBackSubstitution() {
  if (this->coefficients.isUpperTriangular()) {
    this->variables._elements[this->coefficients._rows - 1] =
        this->constants._elements[this->coefficients._rows - 1] /
        this->coefficients(this->coefficients._rows - 1,
                           this->coefficients._columns - 1);
    for (int i = this->coefficients._rows - 2; i >= 0; i--) {
      double sum = (T)0;
      for (int j = i + 1; j < this->coefficients._columns; j++) {
        sum += this->coefficients._elements[i * this->coefficients._columns + j] *
               this->variables._elements[j];
      }
      this->variables._elements[i] =
          (1.0f /
           this->coefficients._elements[i * this->coefficients._columns + i]) *
          (this->constants._elements[i] - sum);
    }
  } else {
    throw std::runtime_error(
        "The given linear system is not an upper triangular "
        "linear system of equations");
  }
}

template class MWP::LinSys<double>;
template class MWP::LinSys<int>;