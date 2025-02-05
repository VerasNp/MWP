#include "Matrix.hpp"
#include "doctest/doctest.h"
#include <stdexcept>
#include <vector>

TEST_CASE("Tests the matrix class") {
  SUBCASE("Should init a matrix with default values, 0 dimension (columns and "
          "rows) and no component") {
    MWP::MatrixD matrixD;
    CHECK(matrixD._columns == 0);
    CHECK(matrixD._rows == 0);
    CHECK(matrixD._size == 0);
    CHECK(matrixD._elements.empty());
  }
  SUBCASE("Should init a matrix with all zero components with given rows and "
          "columns") {
    MWP::MatrixD matrix1D(3, 1);
    for (int i = 0; i < matrix1D._rows; i++) {
      for (int j = 0; j < matrix1D._columns; j++) {
        CHECK(matrix1D[i * matrix1D._columns + j] == 0.0f);
        CHECK(matrix1D(i, j) == 0.0f);
      }
    }
    MWP::MatrixD matrix2D(1, 3);
    for (int i = 0; i < matrix2D._rows; i++) {
      for (int j = 0; j < matrix2D._columns; j++) {
        CHECK(matrix2D[i * matrix2D._columns + j] == 0.0f);
        CHECK(matrix2D(i, j) == 0.0f);
      }
    }
    MWP::MatrixI matrix1I(3, 3);
    for (int i = 0; i < matrix1I._rows; i++) {
      for (int j = 0; j < matrix1I._columns; j++) {
        CHECK(matrix1I[i * matrix1I._columns + j] == 0);
        CHECK(matrix1I(i, j) == 0);
      }
    }
    MWP::MatrixI matrix2I(1, 1);
    for (int i = 0; i < matrix2I._rows; i++) {
      for (int j = 0; j < matrix2I._columns; j++) {
        CHECK(matrix2I[i * matrix2I._columns + j] == 0);
        CHECK(matrix2I(i, j) == 0);
      }
    }
  }
  SUBCASE("Should not access element of matrix if index if out of bounds") {
    MWP::MatrixD matrix(1, 1);
    CHECK_THROWS_WITH_AS(matrix[1], "Index out of bounds", std::runtime_error);
    CHECK_THROWS_WITH_AS(matrix(1, 1), "Index out of bounds",
                         std::runtime_error);
  }
  SUBCASE("Should init a matrix with given elements, columns and rows") {
    SUBCASE("Should not init a matrix with given elements, columns and rows if "
            "the column or rows are equal to zero") {
      CHECK_THROWS_WITH_AS(
          MWP::MatrixD matrix1D(std::vector<double>({1.0f, 2.0f, 3.0f}), 0, 1),
          "The row or column attribute cannot be zero", std::runtime_error);
      CHECK_THROWS_WITH_AS(
          MWP::MatrixD matrix2D(std::vector<double>({1.0f, 2.0f, 3.0f}), 1, 0),
          "The row or column attribute cannot be zero", std::runtime_error);
    }
    SUBCASE("Should not init a matrix with given elements, columns and rows if "
            " the amount of elements do not match with the matrix size") {
      CHECK_THROWS_WITH_AS(
          MWP::MatrixD matrix2D(std::vector<double>({1.0f, 2.0f}), 1, 3),
          "The amount of elements do not match with the matrix size",
          std::runtime_error);
    }
    MWP::MatrixD matrixD(std::vector<double>({1.0f, 2.0f, 3.0f}), 3, 1);
    CHECK(matrixD[0] == 1.0f);
    CHECK(matrixD(0, 0) == 1.0f);
    CHECK(matrixD[1] == 2.0f);
    CHECK(matrixD(1, 0) == 2.0f);
    CHECK(matrixD[2] == 3.0f);
    CHECK(matrixD(2, 0) == 3.0f);
  }
  SUBCASE("Should sum two matrices") {
    SUBCASE("Should not sum two matrices with incompatible dimensions") {
      MWP::MatrixD matrix1D({1.0f, 2.0f, 3.0f}, 1, 3);
      MWP::MatrixD matrix2D({1.0f, 2.0f, 3.0f}, 3, 1);
      CHECK_THROWS_WITH_AS(matrix1D + matrix2D,
                           "Invalid matrices dimensions for addition operation",
                           std::runtime_error);
    }
    MWP::MatrixD matrix1D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 3, 2);
    MWP::MatrixD matrix2D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 3, 2);
    MWP::MatrixD matrixDRes = matrix1D + matrix2D;
    CHECK(matrixDRes(0, 0) == 2.0f);
    CHECK(matrixDRes(0, 1) == 4.0f);
    CHECK(matrixDRes(1, 0) == 6.0f);
    CHECK(matrixDRes(1, 1) == 8.0f);
    CHECK(matrixDRes(2, 0) == 10.0f);
    CHECK(matrixDRes(2, 1) == 12.0f);
  }
  SUBCASE("Should subtract two matrices") {
    SUBCASE("Should not subtract two matrices with incompatible dimensions") {
      MWP::MatrixD matrix1D({1.0f, 2.0f, 3.0f}, 1, 3);
      MWP::MatrixD matrix2D({1.0f, 2.0f, 3.0f}, 3, 1);
      CHECK_THROWS_WITH_AS(matrix1D - matrix2D,
                           "Invalid matrices dimensions for subtraction operation",
                           std::runtime_error);
    }
    MWP::MatrixD matrix1D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 3, 2);
    MWP::MatrixD matrix2D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 3, 2);
    MWP::MatrixD matrixDRes = matrix1D - matrix2D;
    CHECK(matrixDRes(0, 0) == 0.0f);
    CHECK(matrixDRes(0, 1) == 0.0f);
    CHECK(matrixDRes(1, 0) == 0.0f);
    CHECK(matrixDRes(1, 1) == 0.0f);
    CHECK(matrixDRes(2, 0) == 0.0f);
    CHECK(matrixDRes(2, 1) == 0.0f);
  }
  SUBCASE("Should multiply a matrix by a scalar") {
    MWP::MatrixD matrixD({1.0f, 2.0f, 3.0f}, 1, 3);
    MWP::MatrixD matrixDRes = matrixD * 3;
    CHECK(matrixDRes(0, 0) == 3.0f);
    CHECK(matrixDRes(0, 1) == 6.0f);
    CHECK(matrixDRes(0, 2) == 9.0f);
    MWP::MatrixI matrixI({1, 2, 3}, 3, 1);
    MWP::MatrixI matrixIRes = matrixI * 3;
    CHECK(matrixIRes(0, 0) == 3);
    CHECK(matrixIRes(1, 0) == 6);
    CHECK(matrixIRes(2, 0) == 9);
  }
  SUBCASE("Should multiply a matrix by another matrix") {
    SUBCASE("Should not multiply a matrix by another matrix with incompatible "
            "dimensions for multiplication operation") {
      MWP::MatrixD matrix1D({1.0f, 2.0f}, 1, 2);
      MWP::MatrixD matrix2D({1.0f}, 1, 1);
      CHECK_THROWS_WITH_AS(matrix1D * matrix2D,
                           "Invalid matrices dimensions for multiplication operation",
                           std::runtime_error);
    }
    MWP::MatrixD matrix1D({1.0f, 2.0f}, 1, 2);
    MWP::MatrixD matrix2D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 2,
                          3);
    MWP::MatrixD matrixDRes = matrix1D * matrix2D;
    CHECK(matrixDRes(0, 0) == 9.0f);
    CHECK(matrixDRes(0, 1) == 12.0f);
    CHECK(matrixDRes(0, 2) == 15.0f);
  }
}