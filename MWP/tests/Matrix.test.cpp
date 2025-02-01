#include "Matrix.hpp"
#include "Vector.hpp"
#include "doctest/doctest.h"

TEST_CASE("Tests the matrix class") {
  SUBCASE("Should init a matrix with all zero components with given rows and "
          "columns") {
    MWP::MatrixD matrix1D(2, 2);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        CHECK(matrix1D[i * 2 + j] == 0.0f);
      }
    }
    MWP::MatrixI matrix1I(2, 2);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        CHECK(matrix1I[i * 2 + j] == 0);
      }
    }
    MWP::MatrixD matrix2D(2, 3);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        CHECK(matrix1I[i * 2 + j] == 0.0f);
      }
    }
    MWP::MatrixI matrix2I(2, 3);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        CHECK(matrix1I[i * 2 + j] == 0);
      }
    }
  }
  SUBCASE("Should multiply matrix by a scalar") {
    MWP::MatrixD matrixD({1.0f, 2.0f, 3.0f}, 1, 3);
    MWP::MatrixD matrixDRes = matrixD * 3;
    CHECK(matrixDRes[0] == 3.0f);
    CHECK(matrixDRes[1] == 6.0f);
    CHECK(matrixDRes[2] == 9.0f);
    MWP::MatrixI matrixI({1, 2, 3}, 1, 3);
    MWP::MatrixI matrixIRes = matrixI * 3;
    CHECK(matrixIRes[0] == 3);
    CHECK(matrixIRes[1] == 6);
    CHECK(matrixIRes[2] == 9);
  }
  SUBCASE("Should multiply matrix by other matrix") {
    MWP::MatrixD matrix1D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f,
                           10.0f, 11.0f, 12.0f},
                          3, 4);
    MWP::MatrixD matrix2D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f}, 4,
                          2);
    MWP::MatrixD matrix1DRes = matrix1D * matrix2D;
    CHECK(matrix1DRes[0] == 50.0f);
    CHECK(matrix1DRes[1] == 60.0f);
    CHECK(matrix1DRes[2] == 114.0f);
    CHECK(matrix1DRes[3] == 140.0f);
    CHECK(matrix1DRes[4] == 178.0f);
    CHECK(matrix1DRes[5] == 220.0f);
    MWP::MatrixI matrix1I(
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        4, 5);
    MWP::MatrixI matrix2I({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
                          5, 3);
    MWP::MatrixI matrix1IRes = matrix1I * matrix2I;
    CHECK(matrix1IRes[0] == 135);
    CHECK(matrix1IRes[1] == 150);
    CHECK(matrix1IRes[2] == 165);
    CHECK(matrix1IRes[3] == 310);
    CHECK(matrix1IRes[4] == 350);
    CHECK(matrix1IRes[5] == 390);
    CHECK(matrix1IRes[6] == 485);
    CHECK(matrix1IRes[7] == 550);
    CHECK(matrix1IRes[8] == 615);
    CHECK(matrix1IRes[9] == 660);
    CHECK(matrix1IRes[10] == 750);
    CHECK(matrix1IRes[11] == 840);
  }
  SUBCASE("Should multiply a matrix with a vector") {
    MWP::MatrixD matrixD({1.0f, 2.0f, 3.0f, 4.0f}, 2, 2);
    MWP::VectorD vectorD({1.0f, 2.0f});
    MWP::VectorD result = matrixD * vectorD;
    CHECK(result[0] == 5.0f);
    CHECK(result[1] == 11.0f);
  }
  SUBCASE("Should sum two matrices") {
    MWP::MatrixD matrix1D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 2, 3);
    MWP::MatrixD matrix2D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 2, 3);
    MWP::MatrixD matrixDRes = matrix1D + matrix2D;
    CHECK(matrixDRes[0] == 2.0f);
    CHECK(matrixDRes[1] == 4.0f);
    CHECK(matrixDRes[2] == 6.0f);
    CHECK(matrixDRes[3] == 8.0f);
    CHECK(matrixDRes[4] == 10.0f);
    CHECK(matrixDRes[5] == 12.0f);
  }
}