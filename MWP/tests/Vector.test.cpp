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
    CHECK(vectorD._vectorFormat == MWP::VectorD::UNDEFINED);
    MWP::VectorI vectorI;
    CHECK(vectorI._columns == 0);
    CHECK(vectorI._rows == 0);
    CHECK(vectorI._size == 0);
    CHECK(vectorI._elements.empty());
    CHECK(vectorI._vectorFormat == MWP::VectorD::UNDEFINED);
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
      CHECK(columnVectorD._vectorFormat == MWP::VectorD::COLUMN_VECTOR);
      CHECK(columnVectorD._size == 3);
      CHECK(columnVectorD._rows == 3);
      CHECK(columnVectorD._columns == 1);
      MWP::VectorD rowVectorD(3, MWP::VectorD::ROW_VECTOR);
      CHECK(rowVectorD[0] == 0.0f);
      CHECK(rowVectorD[1] == 0.0f);
      CHECK(rowVectorD[2] == 0.0f);
      CHECK(rowVectorD._vectorFormat == MWP::VectorD::ROW_VECTOR);
      CHECK(rowVectorD._size == 3);
      CHECK(rowVectorD._rows == 1);
      CHECK(rowVectorD._columns == 3);
      MWP::VectorI columnVectorI(3, MWP::VectorI::COLUMN_VECTOR);
      CHECK(columnVectorI[0] == 0.0f);
      CHECK(columnVectorI[1] == 0.0f);
      CHECK(columnVectorI[2] == 0.0f);
      CHECK(columnVectorI._vectorFormat == MWP::VectorD::COLUMN_VECTOR);
      CHECK(columnVectorI._size == 3);
      CHECK(columnVectorI._rows == 3);
      CHECK(columnVectorI._columns == 1);
      MWP::VectorI rowVectorI(3, MWP::VectorI::ROW_VECTOR);
      CHECK(rowVectorI[0] == 0.0f);
      CHECK(rowVectorI[1] == 0.0f);
      CHECK(rowVectorI[2] == 0.0f);
      CHECK(rowVectorI._vectorFormat == MWP::VectorD::ROW_VECTOR);
      CHECK(rowVectorI._size == 3);
      CHECK(rowVectorI._rows == 1);
      CHECK(rowVectorI._columns == 3);
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
      CHECK_THROWS_WITH_AS(
          MWP::VectorI rowVectorI({1, 2, 3, 4}, 2, MWP::VectorI::ROW_VECTOR),
          "The amount of elements do not match with the vector size!",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          MWP::VectorI columnVectorI({1, 2, 3, 4}, 2,
                                     MWP::VectorI::COLUMN_VECTOR),
          "The amount of elements do not match with the vector size!",
          std::runtime_error);
    }
    SUBCASE("Should init a vector with elements, vector size and vector type") {
      MWP::VectorD rowVectorD({1.0f, 2.0f, 3.0f}, 3, MWP::VectorD::ROW_VECTOR);
      CHECK(rowVectorD[0] == 1.0f);
      CHECK(rowVectorD[1] == 2.0f);
      CHECK(rowVectorD[2] == 3.0f);
      CHECK(rowVectorD._vectorFormat == MWP::VectorD::ROW_VECTOR);
      CHECK(rowVectorD._size == 3);
      CHECK(rowVectorD._rows == 1);
      CHECK(rowVectorD._columns == 3);
      MWP::VectorD columnVectorD({1.0f, 2.0f, 3.0f}, 3,
                                 MWP::VectorD::COLUMN_VECTOR);
      CHECK(columnVectorD[0] == 1.0f);
      CHECK(columnVectorD[1] == 2.0f);
      CHECK(columnVectorD[2] == 3.0f);
      CHECK(columnVectorD._vectorFormat == MWP::VectorD::COLUMN_VECTOR);
      CHECK(columnVectorD._size == 3);
      CHECK(columnVectorD._rows == 3);
      CHECK(columnVectorD._columns == 1);
      MWP::VectorI rowVectorI({1, 2, 3}, 3, MWP::VectorI::ROW_VECTOR);
      CHECK(rowVectorI[0] == 1);
      CHECK(rowVectorI[1] == 2);
      CHECK(rowVectorI[2] == 3);
      CHECK(rowVectorI._vectorFormat == MWP::VectorD::ROW_VECTOR);
      CHECK(rowVectorI._size == 3);
      CHECK(rowVectorI._rows == 1);
      CHECK(rowVectorI._columns == 3);
      MWP::VectorI columnVectorI({1, 2, 3}, 3, MWP::VectorI::COLUMN_VECTOR);
      CHECK(columnVectorI[0] == 1);
      CHECK(columnVectorI[1] == 2);
      CHECK(columnVectorI[2] == 3);
      CHECK(columnVectorI._vectorFormat == MWP::VectorD::COLUMN_VECTOR);
      CHECK(columnVectorI._size == 3);
      CHECK(columnVectorI._rows == 3);
      CHECK(columnVectorI._columns == 1);
    }
  }
  TEST_CASE("Tests the access elements operator for vectors") {
    MWP::VectorD columnVectorD({1.0f}, 1, MWP::VectorD::COLUMN_VECTOR);
    MWP::VectorD rowVectorD({1.0f}, 1, MWP::VectorD::ROW_VECTOR);
    MWP::VectorI columnVectorI({1}, 1, MWP::VectorI::COLUMN_VECTOR);
    MWP::VectorI rowVectorI({1}, 1, MWP::VectorI::ROW_VECTOR);
    SUBCASE("Should not access element of vector if index if out of bounds") {
      CHECK_THROWS_WITH_AS(columnVectorD[1], "Index out of bounds",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(rowVectorD[1], "Index out of bounds",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(columnVectorI[1], "Index out of bounds",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(rowVectorI[1], "Index out of bounds",
                           std::runtime_error);
    }
    SUBCASE("Should access the element of a vector") {
      CHECK(columnVectorD[0] == 1.0f);
      CHECK(rowVectorD[0] == 1.0f);
      CHECK(columnVectorI[0] == 1);
      CHECK(rowVectorI[0] == 1);
    }
  }
  TEST_CASE("Should add two vectors") {
    MWP::VectorD columnVectorD1({1.0f, 2.0f, 3.0f}, 3,
                                MWP::VectorD::COLUMN_VECTOR);
    MWP::VectorD columnVectorD2({4.0f, 5.0f}, 2, MWP::VectorD::COLUMN_VECTOR);
    MWP::VectorD columnVectorD3({4.0f, 5.0f, 6.0f}, 3,
                                MWP::VectorD::COLUMN_VECTOR);
    MWP::VectorI columnVectorI1({1, 2, 3}, 3, MWP::VectorI::COLUMN_VECTOR);
    MWP::VectorI columnVectorI2({4, 5}, 2, MWP::VectorI::COLUMN_VECTOR);
    MWP::VectorI columnVectorI3({4, 5, 6}, 3, MWP::VectorI::COLUMN_VECTOR);
    MWP::VectorD rowVectorD1({1.0f, 2.0f, 3.0f}, 3, MWP::VectorD::ROW_VECTOR);
    MWP::VectorD rowVectorD2({4.0f, 5.0f}, 2, MWP::VectorD::ROW_VECTOR);
    MWP::VectorD rowVectorD3({4.0f, 5.0f, 6.0f}, 3, MWP::VectorD::ROW_VECTOR);
    MWP::VectorI rowVectorI1({1, 2, 3}, 3, MWP::VectorI::ROW_VECTOR);
    MWP::VectorI rowVectorI2({4, 5}, 2, MWP::VectorI::ROW_VECTOR);
    MWP::VectorI rowVectorI3({4, 5, 6}, 3, MWP::VectorI::ROW_VECTOR);
    SUBCASE("Should not add two vectors with different dimensions") {
      CHECK_THROWS_WITH_AS(
          columnVectorD1 + columnVectorD2,
          "Mismatch on vectors dimensions for addition operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          columnVectorI1 + columnVectorI2,
          "Mismatch on vectors dimensions for addition operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          rowVectorD1 + rowVectorD2,
          "Mismatch on vectors dimensions for addition operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          rowVectorI1 + rowVectorI2,
          "Mismatch on vectors dimensions for addition operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          columnVectorD1 + columnVectorI2,
          "Mismatch on vectors dimensions for addition operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          rowVectorD1 + rowVectorI2,
          "Mismatch on vectors dimensions for addition operation",
          std::runtime_error);
    }
    SUBCASE("Should not add two vectors with different formats") {
      CHECK_THROWS_WITH_AS(columnVectorD1 + rowVectorD1,
                           "Mismatch on vectors formats for addition operation",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(columnVectorI1 + rowVectorI1,
                           "Mismatch on vectors formats for addition operation",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(columnVectorI1 + rowVectorD1,
                           "Mismatch on vectors formats for addition operation",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(columnVectorD1 + rowVectorI1,
                           "Mismatch on vectors formats for addition operation",
                           std::runtime_error);
    }
    SUBCASE("Should add two vectors and generate a new one") {
      MWP::VectorD resultColumnVectorD1 = columnVectorD1 + columnVectorD3;
      CHECK(resultColumnVectorD1[0] == 5.0f);
      CHECK(resultColumnVectorD1[1] == 7.0f);
      CHECK(resultColumnVectorD1[2] == 9.0f);
      CHECK(resultColumnVectorD1._vectorFormat == MWP::VectorD::COLUMN_VECTOR);
      CHECK(resultColumnVectorD1._size == 3);
      CHECK(resultColumnVectorD1._rows == 3);
      CHECK(resultColumnVectorD1._columns == 1);
      MWP::VectorD resultRowVectorD1 = rowVectorD1 + rowVectorD3;
      CHECK(resultRowVectorD1[0] == 5.0f);
      CHECK(resultRowVectorD1[1] == 7.0f);
      CHECK(resultRowVectorD1[2] == 9.0f);
      CHECK(resultRowVectorD1._vectorFormat == MWP::VectorD::ROW_VECTOR);
      CHECK(resultRowVectorD1._size == 3);
      CHECK(resultRowVectorD1._rows == 1);
      CHECK(resultRowVectorD1._columns == 3);
      MWP::VectorI resultColumnVectorI1 = columnVectorI1 + columnVectorI3;
      CHECK(resultColumnVectorI1[0] == 5);
      CHECK(resultColumnVectorI1[1] == 7);
      CHECK(resultColumnVectorI1[2] == 9);
      CHECK(resultColumnVectorI1._vectorFormat == MWP::VectorI::COLUMN_VECTOR);
      CHECK(resultColumnVectorI1._size == 3);
      CHECK(resultColumnVectorI1._rows == 3);
      CHECK(resultColumnVectorI1._columns == 1);
      MWP::VectorI resultRowVectorI1 = rowVectorI1 + rowVectorI3;
      CHECK(resultRowVectorI1[0] == 5);
      CHECK(resultRowVectorI1[1] == 7);
      CHECK(resultRowVectorI1[2] == 9);
      CHECK(resultRowVectorI1._vectorFormat == MWP::VectorI::ROW_VECTOR);
      CHECK(resultRowVectorI1._size == 3);
      CHECK(resultRowVectorI1._rows == 1);
      CHECK(resultRowVectorI1._columns == 3);
      MWP::VectorD resultColumnVectorD2 = columnVectorD1 + columnVectorI3;
      CHECK(resultColumnVectorD2[0] == 5.0f);
      CHECK(resultColumnVectorD2[1] == 7.0f);
      CHECK(resultColumnVectorD2[2] == 9.0f);
      CHECK(resultColumnVectorD2._vectorFormat == MWP::VectorD::COLUMN_VECTOR);
      CHECK(resultColumnVectorD2._size == 3);
      CHECK(resultColumnVectorD2._rows == 3);
      CHECK(resultColumnVectorD2._columns == 1);
      MWP::VectorI resultRowVectorI2 = rowVectorI1 + rowVectorD3;
      CHECK(resultRowVectorI2[0] == 5);
      CHECK(resultRowVectorI2[1] == 7);
      CHECK(resultRowVectorI2[2] == 9);
      CHECK(resultRowVectorI2._vectorFormat == MWP::VectorI::ROW_VECTOR);
      CHECK(resultRowVectorI2._size == 3);
      CHECK(resultRowVectorI2._rows == 1);
      CHECK(resultRowVectorI2._columns == 3);
    }
  }
  TEST_CASE("Should subtract two vectors") {
    MWP::VectorD columnVectorD1({1.0f, 2.0f, 3.0f}, 3,
                                MWP::VectorD::COLUMN_VECTOR);
    MWP::VectorD columnVectorD2({4.0f, 5.0f}, 2, MWP::VectorD::COLUMN_VECTOR);
    MWP::VectorD columnVectorD3({4.0f, 5.0f, 6.0f}, 3,
                                MWP::VectorD::COLUMN_VECTOR);
    MWP::VectorI columnVectorI1({1, 2, 3}, 3, MWP::VectorI::COLUMN_VECTOR);
    MWP::VectorI columnVectorI2({4, 5}, 2, MWP::VectorI::COLUMN_VECTOR);
    MWP::VectorI columnVectorI3({4, 5, 6}, 3, MWP::VectorI::COLUMN_VECTOR);
    MWP::VectorD rowVectorD1({1.0f, 2.0f, 3.0f}, 3, MWP::VectorD::ROW_VECTOR);
    MWP::VectorD rowVectorD2({4.0f, 5.0f}, 2, MWP::VectorD::ROW_VECTOR);
    MWP::VectorD rowVectorD3({4.0f, 5.0f, 6.0f}, 3, MWP::VectorD::ROW_VECTOR);
    MWP::VectorI rowVectorI1({1, 2, 3}, 3, MWP::VectorI::ROW_VECTOR);
    MWP::VectorI rowVectorI2({4, 5}, 2, MWP::VectorI::ROW_VECTOR);
    MWP::VectorI rowVectorI3({4, 5, 6}, 3, MWP::VectorI::ROW_VECTOR);
    SUBCASE("Should not subtract two vectors with different dimensions") {
      CHECK_THROWS_WITH_AS(
          columnVectorD1 - columnVectorD2,
          "Mismatch on vectors dimensions for subtraction operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          columnVectorI1 - columnVectorI2,
          "Mismatch on vectors dimensions for subtraction operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          rowVectorD1 - rowVectorD2,
          "Mismatch on vectors dimensions for subtraction operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          rowVectorI1 - rowVectorI2,
          "Mismatch on vectors dimensions for subtraction operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          columnVectorD1 - columnVectorI2,
          "Mismatch on vectors dimensions for subtraction operation",
          std::runtime_error);
      CHECK_THROWS_WITH_AS(
          rowVectorD1 - rowVectorI2,
          "Mismatch on vectors dimensions for subtraction operation",
          std::runtime_error);
    }
    SUBCASE("Should not subtract two vectors with different formats") {
      CHECK_THROWS_WITH_AS(columnVectorD1 - rowVectorD1,
                           "Mismatch on vectors formats for subtraction operation",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(columnVectorI1 - rowVectorI1,
                           "Mismatch on vectors formats for subtraction operation",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(columnVectorI1 - rowVectorD1,
                           "Mismatch on vectors formats for subtraction operation",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(columnVectorD1 - rowVectorI1,
                           "Mismatch on vectors formats for subtraction operation",
                           std::runtime_error);
    }
    SUBCASE("Should subtract two vectors and generate a new one") {
      MWP::VectorD resultColumnVectorD1 = columnVectorD1 - columnVectorD3;
      CHECK(resultColumnVectorD1[0] == -3.0f);
      CHECK(resultColumnVectorD1[1] == -3.0f);
      CHECK(resultColumnVectorD1[2] == -3.0f);
      CHECK(resultColumnVectorD1._vectorFormat == MWP::VectorD::COLUMN_VECTOR);
      CHECK(resultColumnVectorD1._size == 3);
      CHECK(resultColumnVectorD1._rows == 3);
      CHECK(resultColumnVectorD1._columns == 1);
      MWP::VectorD resultRowVectorD1 = rowVectorD1 - rowVectorD3;
      CHECK(resultRowVectorD1[0] == -3.0f);
      CHECK(resultRowVectorD1[1] == -3.0f);
      CHECK(resultRowVectorD1[2] == -3.0f);
      CHECK(resultRowVectorD1._vectorFormat == MWP::VectorD::ROW_VECTOR);
      CHECK(resultRowVectorD1._size == 3);
      CHECK(resultRowVectorD1._rows == 1);
      CHECK(resultRowVectorD1._columns == 3);
      MWP::VectorI resultColumnVectorI1 = columnVectorI1 - columnVectorI3;
      CHECK(resultColumnVectorI1[0] == -3);
      CHECK(resultColumnVectorI1[1] == -3);
      CHECK(resultColumnVectorI1[2] == -3);
      CHECK(resultColumnVectorI1._vectorFormat == MWP::VectorI::COLUMN_VECTOR);
      CHECK(resultColumnVectorI1._size == 3);
      CHECK(resultColumnVectorI1._rows == 3);
      CHECK(resultColumnVectorI1._columns == 1);
      MWP::VectorI resultRowVectorI1 = rowVectorI1 - rowVectorI3;
      CHECK(resultRowVectorI1[0] == -3);
      CHECK(resultRowVectorI1[1] == -3);
      CHECK(resultRowVectorI1[2] == -3);
      CHECK(resultRowVectorI1._vectorFormat == MWP::VectorI::ROW_VECTOR);
      CHECK(resultRowVectorI1._size == 3);
      CHECK(resultRowVectorI1._rows == 1);
      CHECK(resultRowVectorI1._columns == 3);
      MWP::VectorD resultColumnVectorD2 = columnVectorD1 - columnVectorI3;
      CHECK(resultColumnVectorD2[0] == -3.0f);
      CHECK(resultColumnVectorD2[1] == -3.0f);
      CHECK(resultColumnVectorD2[2] == -3.0f);
      CHECK(resultColumnVectorD2._vectorFormat == MWP::VectorD::COLUMN_VECTOR);
      CHECK(resultColumnVectorD2._size == 3);
      CHECK(resultColumnVectorD2._rows == 3);
      CHECK(resultColumnVectorD2._columns == 1);
      MWP::VectorI resultRowVectorI2 = rowVectorI1 - rowVectorD3;
      CHECK(resultRowVectorI2[0] == -3);
      CHECK(resultRowVectorI2[1] == -3);
      CHECK(resultRowVectorI2[2] == -3);
      CHECK(resultRowVectorI2._vectorFormat == MWP::VectorI::ROW_VECTOR);
      CHECK(resultRowVectorI2._size == 3);
      CHECK(resultRowVectorI2._rows == 1);
      CHECK(resultRowVectorI2._columns == 3);
    }
  }
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