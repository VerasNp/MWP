#include "Vector.hpp"
#include "Matrix.hpp"
#include "doctest/doctest.h"
#include <stdexcept>

TEST_CASE("Tests the vectos class and its functionalities") {
  SUBCASE("Should init a vector with default values, 0 dimension (columns and "
          "rows) and no component") {
    MWP::VectorD vectorD;
    CHECK(vectorD._columns == 0);
    CHECK(vectorD._rows == 0);
    CHECK(vectorD._size == 0);
    CHECK(vectorD._elements.empty());
  }
  SUBCASE("Should create a vector with given number of rows and column") {
    SUBCASE("Should not create a vector with given number of rows and column "
            "if the column or row attribute are zero") {
      CHECK_THROWS_WITH_AS(MWP::VectorD vectorD(0, 1),
                           "The row or column attribute cannot be zero",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(MWP::VectorD vectorD(1, 0),
                           "The row or column attribute cannot be zero",
                           std::runtime_error);
    }
    SUBCASE("Should not create a vector with given number of rows and column "
            "if both column and row size are different from 1") {
      CHECK_THROWS_WITH_AS(MWP::VectorD vectorD(2, 2),
                           "Both rows and columns cannot be different from 1",
                           std::runtime_error);
    }
    MWP::VectorD vectorD(1, 3);
    CHECK(vectorD[0] == 0.0f);
    CHECK(vectorD[1] == 0.0f);
    CHECK(vectorD[2] == 0.0f);
  }
  SUBCASE("Should create a vector with given components") {
    SUBCASE("Should not create a vector with given number of rows and column "
            "if the column or row attribute are zero") {
      CHECK_THROWS_WITH_AS(MWP::VectorD vectorD({1.0f}, 0, 1),
                           "The row or column attribute cannot be zero",
                           std::runtime_error);
      CHECK_THROWS_WITH_AS(MWP::VectorD vectorD({1.0f}, 1, 0),
                           "The row or column attribute cannot be zero",
                           std::runtime_error);
    }
    SUBCASE("Should not create a vector with given number of rows and column "
            "if both column and row size are different from 1") {
      CHECK_THROWS_WITH_AS(MWP::VectorD vectorD({1.0f, 2.0f, 3.0f, 4.0f}, 2, 2),
                           "Both rows and columns cannot be different from 1",
                           std::runtime_error);
    }
    MWP::VectorD vectorD({1.0f, 2.0f, 3.0f}, 3, 1);
    CHECK(vectorD[0] == 1.0f);
    CHECK(vectorD[1] == 2.0f);
    CHECK(vectorD[2] == 3.0f);
  }
  SUBCASE("Should access an element in the vector") {
    MWP::VectorD vectorD({1.0f}, 1, 1);
    SUBCASE("Should not access element of vector if index if out of bounds") {
      CHECK_THROWS_WITH_AS(vectorD[1], "Index out of bounds",
                           std::runtime_error);
    }
    CHECK(vectorD[0] == 1.0f);
  }
  SUBCASE("Should add two vectors") {
    SUBCASE("Should not add two vectors with different dimensions") {
      MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f}, 3, 1);
      MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f}, 1, 3);
      CHECK_THROWS_WITH_AS(vectorD1 + vectorD2,
                           "Invalid vectors dimensions for addition operation",
                           std::runtime_error);
    }
    MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f}, 3, 1);
    MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f}, 3, 1);
    MWP::VectorD vectorDRes1 = vectorD1 + vectorD2;
    CHECK(vectorDRes1[0] == 2.0f);
    CHECK(vectorDRes1[1] == 4.0f);
    CHECK(vectorDRes1[2] == 6.0f);
  }
  SUBCASE("Should subtract two vectors") {
    SUBCASE("Should not subtract two vectors with different dimensions") {
      MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f}, 3, 1);
      MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f}, 1, 3);
      CHECK_THROWS_WITH_AS(
          vectorD1 - vectorD2,
          "Invalid vectors dimensions for subtraction operation",
          std::runtime_error);
    }
    MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f}, 3, 1);
    MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f}, 3, 1);
    MWP::VectorD vectorDRes1 = vectorD1 - vectorD2;
    CHECK(vectorDRes1[0] == 0.0f);
    CHECK(vectorDRes1[1] == 0.0f);
    CHECK(vectorDRes1[2] == 0.0f);
  }
  SUBCASE("Should multiply vector by scalar") {
    MWP::VectorD vectorD1({2.0f, 3.0f, 4.0f}, 3, 1);
    MWP::VectorD vectorDRes1 = vectorD1 * 3.0f;
    CHECK(vectorDRes1[0] == 6.0f);
    CHECK(vectorDRes1[1] == 9.0f);
    CHECK(vectorDRes1[2] == 12.0f);
    MWP::VectorI vectorI1({2, 3, 4}, 1, 3);
    MWP::VectorI vectorIRes1 = vectorI1 * 3;
    CHECK(vectorIRes1[0] == 6);
    CHECK(vectorIRes1[1] == 9);
    CHECK(vectorIRes1[2] == 12);
  }
  SUBCASE("Should multiply a vector by another vector") {
    SUBCASE("Should not multiply a vector by another vector with incompatible "
            "dimensions for multiplication operation") {
      MWP::VectorD vector1D({1.0f, 2.0f}, 1, 2);
      MWP::VectorD vector2D({1.0f}, 1, 1);
      CHECK_THROWS_WITH_AS(
          vector1D * vector2D,
          "Invalid dimensions for vector-vector multiplication",
          std::runtime_error);
    }
    MWP::VectorD vector1D({1.0f, 2.0f, 3.0f}, 1, 3);
    MWP::VectorD vector2D({1.0f, 2.0f, 3.0f}, 3, 1);
    MWP::VectorD vectorDRes = vector1D * vector2D;
    CHECK(vectorDRes[0] == 14.0f);
  }
  SUBCASE("Should project a vector onto another vector") {
    SUBCASE("Should not project a vector onto another vector if the current "
            "vector have number of column different from 1") {
      MWP::VectorD vectorD1({4.0f, 3.0f}, 2, 1);
      MWP::VectorD vectorD2({2.0f, 8.0f}, 1, 2);
      CHECK_THROWS_WITH_AS(
          vectorD1.projectedOnto(vectorD2),
          "Invalid vectors dimensions for projection operation",
          std::runtime_error);
    }
    MWP::VectorD vectorD1({4.0f, 3.0f}, 2, 1);
    MWP::VectorD vectorD2({2.0f, 8.0f}, 2, 1);
    MWP::VectorD vectorDRes = vectorD1.projectedOnto(vectorD2);
    CHECK(vectorDRes[0] == (double)16 / 17);
    CHECK(vectorDRes[1] == (double)64 / 17);
  }
  SUBCASE("Should return the norm 2 of a vector") {
    MWP::VectorD vectorD({4.0f, 3.0f}, 2, 1);
    double norm2D = vectorD.norm2();
    CHECK(norm2D == 5.0f);
    MWP::VectorI vectorI({4, 3}, 2, 1);
    double norm2I = vectorI.norm2();
    CHECK(norm2I == 5.0f);
  }
  SUBCASE("Should calculate the dot product between two vectors") {
    MWP::VectorD vectorD1({4.0f, 3.0f}, 1, 2);
    MWP::VectorD vectorD2({4.0f, 3.0f}, 2, 1);
    double dotProduct = Dot(vectorD1, vectorD2);
    CHECK(dotProduct == 25.0f);
  }
  SUBCASE("Should transform a valid Vector object into a Matrix object") {
    MWP::VectorD vectorD({1.0f, 2.0f, 3.0f}, 3, 1);
    MWP::MatrixD toMatrixVectorD = toMatrix(vectorD);
    CHECK(typeid(toMatrixVectorD).name() == typeid(MWP::MatrixD).name());
    CHECK(vectorD._rows == toMatrixVectorD._rows);
    CHECK(vectorD._columns == toMatrixVectorD._columns);
  }
}