#include "Vector.hpp"
#include <utility>
#include <vector>
namespace MWP {
template <typename T> class MatrixCSR {
public:
  std::vector<unsigned int> _indexes;
  std::vector<T> _elements;
  std::vector<unsigned int> _pointers;
  unsigned int _rows;

  enum EigenvalueNumericMethod { POWER_METHOD };

public:
  MatrixCSR<T>() = default;
  MatrixCSR<T>(std::vector<unsigned int> indexes, std::vector<T> elements,
               std::vector<unsigned int> pointers, unsigned int rows);

public:
  Vector<T> operator*(const Vector<T> &vector) const;
  std::vector<std::pair<Vector<T>, double>>
  eigenvalue(EigenvalueNumericMethod eigtenValueNumericMethod);
  MatrixCSR<T> deflation(double eigenvalue, VectorD eigenvector);

private:
  std::vector<std::pair<Vector<T>, double>>
  powerMethodEigenvalue(unsigned int iterations = 5, double epsilon = 1e-10,
                        unsigned int qtdEigenpairs = 1);
};

typedef MatrixCSR<double> MatrixCSRD;
typedef MatrixCSR<int> MatrixCSRI;
} // namespace MWP
