#include "MathUtils.hpp"
#include "complex.h"
#include <cmath>
#include <complex>
#include <stdexcept>

template <typename T>
MWP::QuadraticEquationReturn<T>
MWP::solveQuadraticEquation(T firstConstantTerm, T secondConstantTerm,
                            T thirdConstantTerm) {
  if (firstConstantTerm == 0) {
    throw std::runtime_error("Not a valid quadratic equation");
  }
  T delta = static_cast<T>(((secondConstantTerm * secondConstantTerm) -
                            (4 * (firstConstantTerm * thirdConstantTerm))));
  double inv = (double)1 / (2 * firstConstantTerm);
  T firstRootReal, secondRootReal, firstRootImag, secondRootImag;
  if (delta > 0) {
    firstRootReal = (-secondConstantTerm + std::sqrt(delta)) * inv;
    secondRootReal = (-secondConstantTerm - std::sqrt(delta)) * inv;
  } else if (delta == 0) {
    firstRootReal = -secondConstantTerm * inv;
    secondRootReal = -secondConstantTerm * inv;
  } else {
    std::complex<T> firstConstantTermComplex = firstConstantTerm;
    std::complex<T> secondConstantTermComplex = secondConstantTerm;
    std::complex<T> thirdConstantTermComplex = thirdConstantTerm;
    std::complex<T> delta =
        ((secondConstantTermComplex * secondConstantTermComplex) -
         (T(4) * (firstConstantTermComplex * thirdConstantTermComplex)));
    std::complex<T> inv =
        std::complex<T>(T(1), T(0)) / (T(2) * firstConstantTermComplex);
    std::complex<T> firstRoot =
        (-secondConstantTermComplex + std::sqrt(delta)) * inv;
    std::complex<T> secondRoot =
        (-secondConstantTermComplex - std::sqrt(delta)) * inv;
    firstRootReal = firstRoot.real();
    secondRootReal = secondRoot.real();
    firstRootImag = firstRoot.imag();
    secondRootImag = secondRoot.imag();
  }
  QuadraticEquationReturn<T> quadraticEquationReturn;
  quadraticEquationReturn.delta = delta;
  quadraticEquationReturn.firstRootReal = firstRootReal;
  quadraticEquationReturn.secondRootReal = secondRootReal;
  quadraticEquationReturn.firstRootImag = firstRootImag;
  quadraticEquationReturn.secondRootImag = secondRootImag;
  return quadraticEquationReturn;
}

template MWP::QuadraticEquationReturn<float>
MWP::solveQuadraticEquation<float>(float, float, float);
template MWP::QuadraticEquationReturn<int>
MWP::solveQuadraticEquation<int>(int, int, int);
template MWP::QuadraticEquationReturn<double>
MWP::solveQuadraticEquation<double>(double, double, double);