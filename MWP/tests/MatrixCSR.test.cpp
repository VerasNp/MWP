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
                               matrixCSRIPointers, 3);
    CHECK(matrixCSRI._elements == matrixCSRIElements);
    CHECK(matrixCSRI._pointers == matrixCSRIPointers);
    CHECK(matrixCSRI._indexes == matrixCSRIIndexes);
  }
  SUBCASE("Test the Multiplication of a matrix with vector") {
    MWP::MatrixCSRI matrixCSRI({0, 2, 1, 0, 1}, {1, 2, 3, 4, 2}, {0, 2, 3, 5},
                               3);
    MWP::VectorI vectorI({2, 1, 4}, 3, 1);
    MWP::VectorI resultMatVec = matrixCSRI * vectorI;
    CHECK(resultMatVec[0] == 10);
    CHECK(resultMatVec[1] == 3);
    CHECK(resultMatVec[2] == 10);
    MWP::MatrixCSRI matrixCSRI2(
        {0, 1, 4, 0, 1, 2, 1, 2, 3, 1, 2, 3, 0, 1, 2, 4},
        {1, 2, 3, 2, 3, 4, 4, 1, 2, 1, 2, 1, 3, 2, 1, 2}, {0, 3, 6, 9, 12, 16},
        5);
    MWP::VectorI vectorI2({5, 3, 4, 1, 9}, 5, 1);
    MWP::VectorI resultMatVec2 = matrixCSRI2 * vectorI2;
    CHECK(resultMatVec2[0] == 38);
    CHECK(resultMatVec2[1] == 35);
    CHECK(resultMatVec2[2] == 18);
    CHECK(resultMatVec2[3] == 12);
    CHECK(resultMatVec2[4] == 43);
  }
  SUBCASE("Test the power method on CSR matrix") {
    MWP::MatrixCSRD matrixCSRD({0, 1, 4, 0, 1, 2, 1, 2, 3, 1, 2, 3, 0, 1, 2, 4},
                               {1.0, 2.0, 3.0, 2.0, 3.0, 4.0, 4.0, 1.0, 2.0,
                                1.0, 2.0, 1.0, 3.0, 2.0, 1.0, 2.0},
                               {0, 3, 6, 9, 12, 16}, 5);
    CHECK(matrixCSRD.eigenvalue((MWP::MatrixCSRD::POWER_METHOD))[0].first[0] ==
          doctest::Approx(0.808));
    CHECK(matrixCSRD.eigenvalue((MWP::MatrixCSRD::POWER_METHOD))[0].second ==
          doctest::Approx(7.43968));
  }
}