#include "Matrix.hpp"
#include "Vector.hpp"

namespace MWP {
template <typename T> class LinSys {
public:
  Matrix<T> coefficients;
  Vector<T> variables;
  Vector<T> constants;

public:
  /**
   * @brief Inits the linear system
   *
   * Inits a linear system with given coefficient matrix and constant matrix.
   * The amount of variables should be equal to the amount of constants.
   *
   * @param coefficients
   * @param constants
   */
  LinSys(Matrix<T> coefficients, Vector<T> constants);

public:
  /**
   * @brief Linear System solver with the forward substitution algorithm
   *
   * The forward substitition algorithm will solve lower triangular linear
   * systems.
   */
  void ForwardSubstitution();
};
typedef LinSys<double> LinSysD;
typedef LinSys<int> LinSysI;
} // namespace MWP