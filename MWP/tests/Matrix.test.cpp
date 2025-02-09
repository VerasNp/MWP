#include "Matrix.hpp"
#include "Vector.hpp"
#include "doctest/doctest.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <utility>
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
    SUBCASE("Should not init a matrix with all zero components if columns or "
            "rows are equal to zero") {
      CHECK_THROWS_WITH_AS(MWP::MatrixD matrix1D(0, 1),
                           "The row or column attribute cannot be zero",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(MWP::MatrixD matrix1D(1, 0),
                           "The row or column attribute cannot be zero",
                           std::runtime_error);
    }
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
  SUBCASE("Should access an element in the matrix") {
    SUBCASE("Should not access element of matrix if index if out of bounds") {
      MWP::MatrixD matrix(1, 1);
      CHECK_THROWS_WITH_AS(matrix[1], "Index out of bounds",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(matrix(1, 1), "Index out of bounds",
                           std::runtime_error);
    }
    MWP::MatrixD matrixD(std::vector<double>({1.0f}), 1, 1);
    CHECK(matrixD[0] == 1.0f);
    CHECK(matrixD(0, 0) == 1.0f);
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
      CHECK_THROWS_WITH_AS(
          matrix1D - matrix2D,
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
      CHECK_THROWS_WITH_AS(
          matrix1D * matrix2D,
          "Invalid matrices dimensions for multiplication operation",
          std::runtime_error);
    }
    MWP::MatrixD matrix1D({1.0f, 2.0f}, 1, 2);
    MWP::MatrixD matrix2D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 2, 3);
    MWP::MatrixD matrixDRes = matrix1D * matrix2D;
    CHECK(matrixDRes(0, 0) == 9.0f);
    CHECK(matrixDRes(0, 1) == 12.0f);
    CHECK(matrixDRes(0, 2) == 15.0f);
  }
  SUBCASE("Should transpose a matrix") {
    MWP::MatrixD matrixD({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 3, 2);
    matrixD.transpose();
    CHECK(matrixD(0, 0) == 1.0f);
    CHECK(matrixD(0, 1) == 3.0f);
    CHECK(matrixD(0, 2) == 5.0f);
    CHECK(matrixD(1, 0) == 2.0f);
    CHECK(matrixD(1, 1) == 4.0f);
    CHECK(matrixD(1, 2) == 6.0f);
    MWP::MatrixI matrixI({1, 2, 3, 4, 5, 6}, 3, 2);
    MWP::MatrixI matrixIRes = TransposeMatrix(matrixI);
    CHECK(matrixIRes(0, 0) == 1);
    CHECK(matrixIRes(0, 1) == 3);
    CHECK(matrixIRes(0, 2) == 5);
    CHECK(matrixIRes(1, 0) == 2);
    CHECK(matrixIRes(1, 1) == 4);
    CHECK(matrixIRes(1, 2) == 6);
  }
  SUBCASE("Should multiply a matrix by a column vector") {
    MWP::MatrixD matrix1D({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}, 2, 3);
    MWP::VectorD vector1D({3.0f, 2.0f, 1.0f}, 3, 1);
    MWP::VectorD vector1Res = matrix1D * vector1D;
    CHECK(vector1Res[0] == 10.0f);
    CHECK(vector1Res[1] == 28.0f);
  }
  SUBCASE("Should return if a matrix is square") {
    MWP::MatrixD matrix1D({1.0f, 2.0f, 3.0f, 4.0f}, 2, 2);
    CHECK(matrix1D.isSquare());
    MWP::MatrixD matrix2D({1.0f, 2.0f}, 2, 1);
    CHECK(!matrix2D.isSquare());
  }
  SUBCASE("Should return if a matrix is lower triangular") {
    MWP::MatrixD matrix1D({1.0f, 0.0f, 4.0f, 4.0f}, 2, 2);
    CHECK(matrix1D.isLowerTriangular());
    MWP::MatrixD matrix2D({1.0f, 1.0f, 4.0f, 4.0f}, 2, 2);
    CHECK(!matrix2D.isLowerTriangular());
  }
  SUBCASE("Should return if a matrix is upper triangular") {
    MWP::MatrixD matrix1D({1.0f, 2.0f, 0.0f, 4.0f}, 2, 2);
    CHECK(matrix1D.isUpperTriangular());
    MWP::MatrixD matrix2D({1.0f, 1.0f, 4.0f, 4.0f}, 2, 2);
    CHECK(!matrix2D.isUpperTriangular());
  }
  SUBCASE("Should create an identity matrix") {
    SUBCASE("Should not create an identity matrix if the given number of rows "
            "and columns are different") {
      CHECK_THROWS_WITH_AS(IdentityMatrix<double>(1, 2),
                           "An identity matrix should have number of rows "
                           "equal to the number of columns",
                           std::runtime_error);
    }
    MWP::MatrixD identityMatrix = IdentityMatrix<double>(2, 2);
    CHECK(identityMatrix(0, 0) == 1.0f);
    CHECK(identityMatrix(0, 1) == 0.0f);
    CHECK(identityMatrix(1, 0) == 0.0f);
    CHECK(identityMatrix(1, 1) == 1.0f);
  }
  SUBCASE("Should decompose a matrix into LU matrices") {
    SUBCASE("Should not decompose a matrix into LU matrices if the matrix is "
            "not a square matrix") {
      MWP::MatrixI matrix({1, 4}, 1, 2);
      CHECK_THROWS_WITH_AS(
          matrix.LUDecomposition(),
          "The matrix should be square to be decomposed into LU matrices!",
          std::runtime_error);
    }
    MWP::MatrixI matrix({1, 4, -3, -2, 8, 5, 3, 4, 7}, 3, 3);
    std::pair<MWP::MatrixD, MWP::MatrixD> LUdecomposedMatrix =
        matrix.LUDecomposition();
    CHECK(LUdecomposedMatrix.first(0, 0) == 1.0f);
    CHECK(LUdecomposedMatrix.first(0, 1) == 0.0f);
    CHECK(LUdecomposedMatrix.first(0, 2) == 0.0f);
    CHECK(LUdecomposedMatrix.first(1, 0) == -2.0f);
    CHECK(LUdecomposedMatrix.first(1, 1) == 1.0f);
    CHECK(LUdecomposedMatrix.first(1, 2) == 0.0f);
    CHECK(LUdecomposedMatrix.first(2, 0) == 3.0f);
    CHECK(LUdecomposedMatrix.first(2, 1) == -0.5f);
    CHECK(LUdecomposedMatrix.first(2, 2) == 1.0f);
    CHECK(LUdecomposedMatrix.second(0, 0) == 1.0f);
    CHECK(LUdecomposedMatrix.second(0, 1) == 4.0f);
    CHECK(LUdecomposedMatrix.second(0, 2) == -3.0f);
    CHECK(LUdecomposedMatrix.second(1, 0) == 0.0f);
    CHECK(LUdecomposedMatrix.second(1, 1) == 16.0f);
    CHECK(LUdecomposedMatrix.second(1, 2) == -1.0f);
    CHECK(LUdecomposedMatrix.second(2, 0) == 0.0f);
    CHECK(LUdecomposedMatrix.second(2, 1) == 0.0f);
    CHECK(LUdecomposedMatrix.second(2, 2) == 15.5f);
  }
  SUBCASE("Should replace a submatrix") {
    SUBCASE("Should not get a out of bounds submatrix") {
      MWP::MatrixI matrixMajor({1, 4, 3, 5, 2, 1, 7, 8, 9, 1, 2, 5, 6, 2, 1, 7},
                               4, 4);

      CHECK_THROWS_WITH_AS(matrixMajor.subMatrix(2, 5, 0, 2),
                           "Invalid submatrix range", std::out_of_range);
      CHECK_THROWS_WITH_AS(matrixMajor.subMatrix(0, 2, 2, 5),
                           "Invalid submatrix range", std::out_of_range);
      CHECK_THROWS_WITH_AS(matrixMajor.subMatrix(2, 0, 2, 0),
                           "Invalid submatrix range", std::out_of_range);
    }
    MWP::MatrixI matrix({1, 4, -3, -2, 8, 5, 3, 4, 7}, 3, 3);
    MWP::MatrixI subM = matrix.subMatrix(0, 2, 0, 2);
    CHECK(subM(0, 0) == 1);
    CHECK(subM(0, 1) == 4);
    CHECK(subM(1, 0) == -2);
    CHECK(subM(1, 1) == 8);
    CHECK(subM.isSquare() == true);
    CHECK(subM._rows == 2);
    CHECK(subM._columns == 2);

    MWP::MatrixI col = matrix.subMatrix(0, matrix._rows, 1, 2);
    CHECK(col(0, 0) == 4);
    CHECK(col(1, 0) == 8);
    CHECK(col(2, 0) == 4);
    CHECK(col._rows == 3);
    CHECK(col._columns == 1);
  }
  SUBCASE("Should apply Gram-Schmidt process") {
    MWP::MatrixD matrix({1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f},
                        3, 3);
    std::pair<MWP::MatrixD, MWP::MatrixD> GSQRDecomposition = GS(matrix);
    CHECK(GSQRDecomposition.first(0, 0) == doctest::Approx(1 / std::sqrt(2)));
    CHECK(GSQRDecomposition.first(0, 1) == doctest::Approx(1 / std::sqrt(6)));
    CHECK(GSQRDecomposition.first(0, 2) == doctest::Approx(-1 / std::sqrt(3)));
    CHECK(GSQRDecomposition.first(1, 0) == doctest::Approx(1 / std::sqrt(2)));
    CHECK(GSQRDecomposition.first(1, 1) == doctest::Approx(-1 / std::sqrt(6)));
    CHECK(GSQRDecomposition.first(1, 2) == doctest::Approx(1 / std::sqrt(3)));
    CHECK(GSQRDecomposition.first(2, 0) == 0.0f);
    CHECK(GSQRDecomposition.first(2, 1) == doctest::Approx(2 / std::sqrt(6)));
    CHECK(GSQRDecomposition.first(2, 2) == doctest::Approx(1 / std::sqrt(3)));
    CHECK(GSQRDecomposition.second(0, 0) == doctest::Approx(2 / std::sqrt(2)));
    CHECK(GSQRDecomposition.second(0, 1) == doctest::Approx(1 / std::sqrt(2)));
    CHECK(GSQRDecomposition.second(0, 2) == doctest::Approx(1 / std::sqrt(2)));
    CHECK(GSQRDecomposition.second(1, 0) == 0.0f);
    CHECK(GSQRDecomposition.second(1, 1) == doctest::Approx(3 / std::sqrt(6)));
    CHECK(GSQRDecomposition.second(1, 2) == doctest::Approx(1 / std::sqrt(6)));
    CHECK(GSQRDecomposition.second(2, 0) == 0.0f);
    CHECK(GSQRDecomposition.second(2, 1) == 0.0f);
    CHECK(GSQRDecomposition.second(2, 2) == doctest::Approx(2 / std::sqrt(3)));
  }
  SUBCASE("Should transform a valid Matrix object into a Vector object") {
    MWP::MatrixD matrixD({1.0f, 2.0f, 3.0f}, 3, 1);
    MWP::VectorD toVectorMatrixD = toVector(matrixD);
    CHECK(typeid(toVectorMatrixD).name() == typeid(MWP::VectorD).name());
    CHECK(matrixD._rows == toVectorMatrixD._rows);
    CHECK(matrixD._columns == toVectorMatrixD._columns);
  }
}
