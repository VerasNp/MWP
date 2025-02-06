#include "LinSys.hpp"
#include <stdexcept>

using namespace MWP;

template <typename T>
LinSys<T>::LinSys(Matrix<T> coefficients, Vector<T> constants) {
  if (coefficients._columns != constants._rows) {
    throw std::runtime_error("Incompatible dimension of coefficient matrix "
                             "with the constants vector");
  }
  if (constants._columns > 1) {
    throw std::runtime_error("Incompatible constants vector dimension");
  }
  this->coefficients = coefficients;
  Vector<T> variables(constants._rows, constants._columns);
  this->variables = this->constants = constants;
}

template class MWP::LinSys<double>;
template class MWP::LinSys<int>;