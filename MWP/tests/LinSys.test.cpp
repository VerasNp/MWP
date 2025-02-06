#include "LinSys.hpp"
#include "doctest/doctest.h"
#include <stdexcept>

TEST_CASE("Tests the LinSys class") {
  SUBCASE("Should init a linear system with given coefficient matrix and "
          "constant vector") {
    MWP::MatrixD coefficientMatrix({2.0f, 3.0f, 5.0f, -1.0f}, 2, 2);
    SUBCASE("Should not init a linear system with given coefficient matrix and "
            "constant vector if the coefficient matrix has diffent amount of "
            "rows from constant vector") {
      MWP::VectorD constantVector({8.0f, 2.0f, 1.0f}, 3, 1);
      CHECK_THROWS_WITH_AS(
          MWP::LinSysD linearSystem(coefficientMatrix, constantVector),
          "Incompatible dimension of coefficient matrix with the constants "
          "vector",
          std::runtime_error);
    }
    SUBCASE("Should not init a linear system with given coefficient matrix and "
            "constant vector if the column size of the constant vector is "
            "greater than one") {
      MWP::MatrixD coefficientMatrix({2.0f}, 1, 1);
      MWP::VectorD constantVector({8.0f, 2.0f}, 1, 2);
      CHECK_THROWS_WITH_AS(
          MWP::LinSysD linearSystem(coefficientMatrix, constantVector),
          "Incompatible constants vector dimension", std::runtime_error);
    }
    MWP::VectorD constantVector({8.0f, 2.0f}, 2, 1);
    MWP::LinSysD linearSystem(coefficientMatrix, constantVector);
    CHECK(linearSystem.coefficients._size == coefficientMatrix._size);
    CHECK(linearSystem.variables._rows == constantVector._rows);
    CHECK(linearSystem.constants._size == constantVector._size);
  }
}