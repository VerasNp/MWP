#include "LinSys.hpp"
#include <stdexcept>
#include <utility>

using namespace MWP;
template class MWP::LinSys<double>;
template class MWP::LinSys<int>;

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
  Vector<T> variables(coefficients._columns, constants._columns);
  this->_variables = variables;
  this->_constants = constants;
  this->_coefficients = coefficients;
}

template <typename T> void LinSys<T>::solveForwardSubstitution() {
  if (this->_coefficients.isLowerTriangular()) {
    this->_variables._elements[0] =
        this->_constants._elements[0] / this->_coefficients._elements[0];
    for (int i = 1; i < this->_coefficients._rows; i++) {
      double sum = (T)0;
      for (int j = 0; j <= i - 1; j++) {
        sum +=
            this->_coefficients._elements[i * this->_coefficients._rows + j] *
            this->_variables._elements[j];
      }
      this->_variables._elements[i] =
          (1.0f / this->_coefficients
                      ._elements[i * this->_coefficients._columns + i]) *
          (this->_constants._elements[i] - sum);
    }
  } else {
    throw std::runtime_error(
        "The given linear system is not a lower triangular "
        "linear system of equations");
  }
}

template <typename T> void LinSys<T>::solveBackSubstitution() {
  if (this->_coefficients.isUpperTriangular()) {
    this->_variables._elements[this->_coefficients._rows - 1] =
        this->_constants._elements[this->_coefficients._rows - 1] /
        this->_coefficients(this->_coefficients._rows - 1,
                            this->_coefficients._rows - 1);
    for (int i = this->_coefficients._rows - 2; i >= 0; i--) {
      double sum = (T)0;
      for (int j = i + 1; j < this->_coefficients._rows; j++) {
        sum +=
            this->_coefficients._elements[i * this->_coefficients._rows + j] *
            this->_variables._elements[j];
      }
      this->_variables._elements[i] =
          (1.0f / this->_coefficients
                      ._elements[i * this->_coefficients._columns + i]) *
          (this->_constants._elements[i] - sum);
    }
  } else {
    throw std::runtime_error(
        "The given linear system is not an upper triangular "
        "linear system of equations");
  }
}

template <typename T>
void LinSys<T>::solve(LinSys<T>::SolverMethod solverMethod) {
  if (solverMethod == LU) {
    this->solveWithLUMethod();
  }
}

template <typename T> void LinSys<T>::solveWithLUMethod() {
  Vector<double> doubleConstants(_constants._rows, _constants._columns);
  for (size_t i = 0; i < _constants._elements.size(); ++i) {
    doubleConstants._elements[i] = static_cast<double>(_constants._elements[i]);
  }
  std::pair<MatrixD, MatrixD> LUCoefficientMatrixes =
      this->_coefficients.LUDecomposition();
  LinSys<double> LSystem(LUCoefficientMatrixes.first, doubleConstants);
  LSystem.solveForwardSubstitution();
  LinSys<double> USystem(LUCoefficientMatrixes.second, LSystem._variables);
  USystem.solveBackSubstitution();
  Vector<T> convVariables(USystem._variables._rows,
                          USystem._variables._columns);
  for (size_t i = 0; i < USystem._variables._elements.size(); ++i) {
    convVariables._elements[i] =
        static_cast<T>(USystem._variables._elements[i]);
  }
  this->_variables = convVariables;
}
