#include "Vector.hpp"
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
    MWP::VectorD vectorD(1, 3);
    CHECK(vectorD[0] == 0.0f);
    CHECK(vectorD[1] == 0.0f);
    CHECK(vectorD[2] == 0.0f);
  }
  SUBCASE("Should create a vector with given components") {
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
}