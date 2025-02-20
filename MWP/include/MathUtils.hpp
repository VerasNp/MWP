#include <cmath>
namespace MWP {

template <typename T> struct QuadraticEquationReturn {
  T delta;
  T firstRootReal;
  T firstRootImag;
  T secondRootReal;
  T secondRootImag;
};

/**
 * @brief
 *
 * @tparam T
 * @param firstConstantTerm
 * @param secondConstantTerm
 * @param thirdConstantTerm
 * @return std::tuple<T, T, T>
 */
template <typename T>
QuadraticEquationReturn<T> solveQuadraticEquation(T firstConstantTerm,
                                                  T secondConstantTerm,
                                                  T thirdConstantTerm);
} // namespace MWP
