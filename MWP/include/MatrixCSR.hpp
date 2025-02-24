#include "Vector.hpp"
#include <vector>
namespace MWP {
template <typename T> class MatrixCSR {
public:
  std::vector<unsigned int> _indexes;
  std::vector<T> _elements;
  std::vector<unsigned int> _pointers;

public:
  MatrixCSR<T>();
  MatrixCSR<T>(std::vector<unsigned int> indexes, std::vector<T> elements,
               std::vector<unsigned int> pointers);

public:
  MatrixCSR<T> operator*(const Vector<T> &vector) const;
};

typedef MatrixCSR<double> MatrixCSRD;
typedef MatrixCSR<int> MatrixCSRI;
} // namespace MWP
