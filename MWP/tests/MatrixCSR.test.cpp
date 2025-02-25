#include "MatrixCSR.hpp"
#include "Vector.hpp"
#include "doctest/doctest.h"
#include <vector>

TEST_CASE("Test the Matrix CSR class") {
  SUBCASE("Test the initialization of a matrix using CSR") {
    std::vector<int> matrixCSRIElements = {1, 2, 3, 2, 3, 4, 4, 1,
                                           2, 1, 2, 1, 3, 2, 1, 2};
    std::vector<unsigned int> matrixCSRIIndexes = {0, 1, 4, 0, 1, 2, 1, 2,
                                                   3, 1, 2, 3, 0, 1, 2, 4};
    std::vector<unsigned int> matrixCSRIPointers = {0, 3, 6, 9, 12, 16};
    MWP::MatrixCSRI matrixCSRI(matrixCSRIIndexes, matrixCSRIElements,
                               matrixCSRIPointers);
    CHECK(matrixCSRI._elements == matrixCSRIElements);
    CHECK(matrixCSRI._pointers == matrixCSRIPointers);
    CHECK(matrixCSRI._indexes == matrixCSRIIndexes);
  }
  SUBCASE("Test the Multiplication of a matrix with vector") {
    MWP::MatrixCSRI matrixCSRI({0, 2, 1, 0, 1}, {1, 2, 3, 4, 2}, {0, 2, 3, 5});
    MWP::VectorI vectorI({2, 1, 4}, 3, 1);
    MWP::VectorI resultMatVec = matrixCSRI * vectorI;
    CHECK(resultMatVec[0] == 10);
    CHECK(resultMatVec[1] == 3);
    CHECK(resultMatVec[2] == 10);
  }
}