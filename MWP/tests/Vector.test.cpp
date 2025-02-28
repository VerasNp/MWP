#include "Vector.hpp"
#include "Matrix.hpp"
#include "doctest/doctest.h"
#include <stdexcept>

TEST_SUITE("Tests the vectos class and its functionalities") {
  TEST_CASE("Should init a vector with default values, 0 dimension (columns "
            "and rows) and no component") {
    MWP::VectorD vectorD;
    CHECK(vectorD._columns == 0);
    CHECK(vectorD._rows == 0);
    CHECK(vectorD._size == 0);
    CHECK(vectorD._elements.empty());
    MWP::VectorI vectorI;
    CHECK(vectorI._columns == 0);
    CHECK(vectorI._rows == 0);
    CHECK(vectorI._size == 0);
    CHECK(vectorI._elements.empty());
  }
  TEST_CASE("Tests the creation of a vector with with given size of rows or "
            "columns") {
    SUBCASE("Should not create a vector with given number of rows or column "
            "if the column or row attribute are zero") {
      CHECK_THROWS_WITH_AS(MWP::VectorD rowVectorD(0, MWP::VectorD::ROW_VECTOR),
                           "The row or column attribute cannot be zero",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(
          MWP::VectorD columnVectorD(0, MWP::VectorD::COLUMN_VECTOR),
          "The row or column attribute cannot be zero", std::runtime_error);
      CHECK_THROWS_WITH_AS(MWP::VectorI rowVectorI(0, MWP::VectorI::ROW_VECTOR),
                           "The row or column attribute cannot be zero",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(
          MWP::VectorI columnVectorI(0, MWP::VectorI::COLUMN_VECTOR),
          "The row or column attribute cannot be zero", std::runtime_error);
    }
    SUBCASE("Should create a vector with given size of rows or column") {
      MWP::VectorD columnVectorD(3, MWP::VectorD::COLUMN_VECTOR);
      CHECK(columnVectorD[0] == 0.0f);
      CHECK(columnVectorD[1] == 0.0f);
      CHECK(columnVectorD[2] == 0.0f);
      MWP::VectorD rowVectorD(3, MWP::VectorD::ROW_VECTOR);
      CHECK(rowVectorD[0] == 0.0f);
      CHECK(rowVectorD[1] == 0.0f);
      CHECK(rowVectorD[2] == 0.0f);
      MWP::VectorI columnVectorI(3, MWP::VectorI::COLUMN_VECTOR);
      CHECK(columnVectorI[0] == 0.0f);
      CHECK(columnVectorI[1] == 0.0f);
      CHECK(columnVectorI[2] == 0.0f);
      MWP::VectorI rowVectorI(3, MWP::VectorI::ROW_VECTOR);
      CHECK(rowVectorI[0] == 0.0f);
      CHECK(rowVectorI[1] == 0.0f);
      CHECK(rowVectorI[2] == 0.0f);
    }
  }
  TEST_CASE("Test the init of a vector with given elements, vector size and "
            "vector type") {
    SUBCASE("Should not init a vector with elements, vector size and vector "
            "type if the size of vector is equal to zero") {
      CHECK_THROWS_WITH_AS(
          MWP::VectorD rowVectorD({1.0f}, 0, MWP::VectorD::ROW_VECTOR),
          "The row or column attribute cannot be zero!", std::runtime_error);
      CHECK_THROWS_WITH_AS(
          MWP::VectorD columnVectorD({1.0f}, 0, MWP::VectorD::COLUMN_VECTOR),
          "The row or column attribute cannot be zero!", std::runtime_error);
      CHECK_THROWS_WITH_AS(
          MWP::VectorI rowVectorI({1}, 0, MWP::VectorI::ROW_VECTOR),
          "The row or column attribute cannot be zero!", std::runtime_error);
      CHECK_THROWS_WITH_AS(
          MWP::VectorI columnVectorI({1}, 0, MWP::VectorI::COLUMN_VECTOR),
          "The row or column attribute cannot be zero!", std::runtime_error);
    }
    SUBCASE("Should not init a vector with elements, vector size and vector "
            "type if the amount of elements is different "
            "of vector size") {
      CHECK_THROWS_WITH_AS(
          MWP::VectorD rowVectorD({1.0f, 2.0f, 3.0f, 4.0f}, 2,
                                  MWP::VectorD::ROW_VECTOR),
          "The amount of elements do not match with the vector size!",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          MWP::VectorD columnVectorD({1.0f, 2.0f, 3.0f, 4.0f}, 2,
                                     MWP::VectorD::COLUMN_VECTOR),
          "The amount of elements do not match with the vector size!",
          std::runtime_error);
    }
    SUBCASE("Should init a vector with elements, vector size and vector type") {
      MWP::VectorD vectorD({1.0f, 2.0f, 3.0f}, 3,
                           MWP::Vector<double>::ROW_VECTOR);
      CHECK(vectorD[0] == 1.0f);
      CHECK(vectorD[1] == 2.0f);
      CHECK(vectorD[2] == 3.0f);
    }
  }
  // SUBCASE("Should access an element in the vector") {
  //   MWP::VectorD vectorD({1.0f}, 1, 1);
  //   SUBCASE("Should not access element of vector if index if out of bounds")
  //   {
  //     CHECK_THROWS_WITH_AS(vectorD[1], "Index out of bounds",
  //                          std::runtime_error);
  //   }
  //   CHECK(vectorD[0] == 1.0f);
  // }
  // SUBCASE("Should add two vectors") {
  //   SUBCASE("Should not add two vectors with different dimensions") {
  //     MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f}, 3, 1);
  //     MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f}, 1, 3);
  //     CHECK_THROWS_WITH_AS(vectorD1 + vectorD2,
  //                          "Invalid vectors dimensions for addition
  //                          operation", std::runtime_error);
  //   }
  //   MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f}, 3, 1);
  //   MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f}, 3, 1);
  //   MWP::VectorD vectorDRes1 = vectorD1 + vectorD2;
  //   CHECK(vectorDRes1[0] == 2.0f);
  //   CHECK(vectorDRes1[1] == 4.0f);
  //   CHECK(vectorDRes1[2] == 6.0f);
  // }
  // SUBCASE("Should subtract two vectors") {
  //   SUBCASE("Should not subtract two vectors with different dimensions") {
  //     MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f}, 3, 1);
  //     MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f}, 1, 3);
  //     CHECK_THROWS_WITH_AS(
  //         vectorD1 - vectorD2,
  //         "Invalid vectors dimensions for subtraction operation",
  //         std::runtime_error);
  //   }
  //   MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f}, 3, 1);
  //   MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f}, 3, 1);
  //   MWP::VectorD vectorDRes1 = vectorD1 - vectorD2;
  //   CHECK(vectorDRes1[0] == 0.0f);
  //   CHECK(vectorDRes1[1] == 0.0f);
  //   CHECK(vectorDRes1[2] == 0.0f);
  // }
  // SUBCASE("Should multiply vector by scalar") {
  //   MWP::VectorD vectorD1({2.0f, 3.0f, 4.0f}, 3, 1);
  //   MWP::VectorD vectorDRes1 = vectorD1 * 3.0f;
  //   CHECK(vectorDRes1[0] == 6.0f);
  //   CHECK(vectorDRes1[1] == 9.0f);
  //   CHECK(vectorDRes1[2] == 12.0f);
  //   MWP::VectorI vectorI1({2, 3, 4}, 1, 3);
  //   MWP::VectorI vectorIRes1 = vectorI1 * 3;
  //   CHECK(vectorIRes1[0] == 6);
  //   CHECK(vectorIRes1[1] == 9);
  //   CHECK(vectorIRes1[2] == 12);
  // }
  // SUBCASE("Should multiply a vector by another vector") {
  //   SUBCASE("Should not multiply a vector by another vector with incompatible
  //   "
  //           "dimensions for multiplication operation") {
  //     MWP::VectorD vector1D({1.0f, 2.0f}, 1, 2);
  //     MWP::VectorD vector2D({1.0f}, 1, 1);
  //     CHECK_THROWS_WITH_AS(
  //         vector1D * vector2D,
  //         "Invalid dimensions for vector-vector multiplication",
  //         std::runtime_error);
  //   }
  //   MWP::VectorD vector1D({1.0f, 2.0f, 3.0f}, 1, 3);
  //   MWP::VectorD vector2D({1.0f, 2.0f, 3.0f}, 3, 1);
  //   MWP::VectorD vectorDRes = vector1D * vector2D;
  //   CHECK(vectorDRes[0] == 14.0f);
  // }
  // SUBCASE("Should project a vector onto another vector") {
  //   SUBCASE("Should not project a vector onto another vector if the current "
  //           "vector have number of column different from 1") {
  //     MWP::VectorD vectorD1({4.0f, 3.0f}, 2, 1);
  //     MWP::VectorD vectorD2({2.0f, 8.0f}, 1, 2);
  //     CHECK_THROWS_WITH_AS(
  //         vectorD1.projectedOnto(vectorD2),
  //         "Invalid vectors dimensions for projection operation",
  //         std::runtime_error);
  //   }
  //   MWP::VectorD vectorD1({4.0f, 3.0f}, 2, 1);
  //   MWP::VectorD vectorD2({2.0f, 8.0f}, 2, 1);
  //   MWP::VectorD vectorDRes = vectorD1.projectedOnto(vectorD2);
  //   CHECK(vectorDRes[0] == (double)16 / 17);
  //   CHECK(vectorDRes[1] == (double)64 / 17);
  // }
  // SUBCASE("Should return the norm 2 of a vector") {
  //   MWP::VectorD vectorD({4.0f, 3.0f}, 2, 1);
  //   double norm2D = vectorD.norm2();
  //   CHECK(norm2D == 5.0f);
  //   MWP::VectorI vectorI({4, 3}, 2, 1);
  //   double norm2I = vectorI.norm2();
  //   CHECK(norm2I == 5.0f);
  // }
  // SUBCASE("Should calculate the dot product between two vectors") {
  //   MWP::VectorD vectorD1({4.0f, 3.0f}, 1, 2);
  //   MWP::VectorD vectorD2({4.0f, 3.0f}, 2, 1);
  //   double dotProduct = Dot(vectorD1, vectorD2);
  //   CHECK(dotProduct == 25.0f);
  // }
  // SUBCASE("Should transform a valid Vector object into a Matrix object") {
  //   MWP::VectorD vectorD({1.0f, 2.0f, 3.0f}, 3, 1);
  //   MWP::MatrixD toMatrixVectorD = toMatrix(vectorD);
  //   CHECK(typeid(toMatrixVectorD).name() == typeid(MWP::MatrixD).name());
  //   CHECK(vectorD._rows == toMatrixVectorD._rows);
  //   CHECK(vectorD._columns == toMatrixVectorD._columns);
  // }
  // SUBCASE("Test the column vector generation with random elements") {
  //   SUBCASE("Should not generate a column vector if the number of rows is "
  //           "equal to zero") {
  //     CHECK_THROWS_WITH_AS(randomColumnVector<double>(0),
  //                          "The row or column attribute cannot be zero",
  //                          std::runtime_error);
  //   }
  //   SUBCASE("Should generate a column vector") {
  //     MWP::VectorD columnVector = randomColumnVector<double>(4);
  //     CHECK(columnVector._size == 4);
  //     CHECK(columnVector._rows == 4);
  //     CHECK(columnVector._columns == 1);
  //   }
  // }
  // SUBCASE("Test the row vector generation with random elements") {
  //   SUBCASE("Should not generate a row vector if the number of columns is "
  //           "equal to zero") {
  //     CHECK_THROWS_WITH_AS(randomRowVector<double>(0),
  //                          "The row or column attribute cannot be zero",
  //                          std::runtime_error);
  //   }
  //   SUBCASE("Should generate a row vector") {
  //     MWP::VectorD columnVector = randomRowVector<double>(4);
  //     CHECK(columnVector._size == 4);
  //     CHECK(columnVector._rows == 1);
  //     CHECK(columnVector._columns == 4);
  //   }
  // }
}