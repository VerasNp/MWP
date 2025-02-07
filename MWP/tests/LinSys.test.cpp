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
    SUBCASE(
        "Should not init a linear system with given coefficient matrix and "
        "constant vector if the number of rows in the coefficient matrix is "
        "equal to one") {
      MWP::MatrixD coefficientMatrix({2.0f, 3.0f}, 1, 2);
      MWP::VectorD constantVector({8.0f, 2.0f}, 2, 1);
      CHECK_THROWS_WITH_AS(
          MWP::LinSysD linearSystem(coefficientMatrix, constantVector),
          "Incompatible coefficient matrix dimension", std::runtime_error);
    }
    MWP::VectorD constantVector({8.0f, 2.0f}, 2, 1);
    MWP::LinSysD linearSystem(coefficientMatrix, constantVector);
    CHECK(linearSystem.coefficients._size == coefficientMatrix._size);
    CHECK(linearSystem.variables._rows == constantVector._rows);
    CHECK(linearSystem.constants._size == constantVector._size);
  }
  SUBCASE("Should solve a linear system of equations with the forward "
          "substitition algorithm") {
    SUBCASE(
        "Should not solve a linear system of equations with the forward "
        "substitition algorithm if the system is not a lower triangular linear "
        "system of equations") {
      MWP::MatrixD coefficientMatrix({2.0f, 3.0f, 5.0f, -1.0f, 4.0f, 8.0f}, 3,
                                     2);
      MWP::VectorD constantVector({8.0f, 2.0f}, 2, 1);
      MWP::LinSysD linearSystem(coefficientMatrix, constantVector);
      CHECK_THROWS_WITH_AS(
          linearSystem.solveForwardSubstitution(),
          "The given linear system is not a lower triangular linear "
          "system of equations",
          std::runtime_error);
    }

    MWP::MatrixD coefficientMatrix({2.0f, 0.0f, 0.0f, 0.0f, 3.0f, 5.0f, 0.0f,
                                    0.0f, 1.0f, -6.0f, 8.0f, 0.0f, -1.0f, 4.0f,
                                    -3.0f, 9.0f},
                                   4, 4);
    MWP::VectorD constantVector({4.0f, 1.0f, 48.0f, 6.0f}, 4, 1);
    MWP::LinSysD linearSystem(coefficientMatrix, constantVector);
    linearSystem.solveForwardSubstitution();
    CHECK(linearSystem.variables[0] == 2.0f);
    CHECK(linearSystem.variables[1] == -1.0f);
    CHECK(linearSystem.variables[2] == 5.0f);
    CHECK(linearSystem.variables[3] == 3.0f);
  }
  SUBCASE("Should solve a linear system of equations with the back "
          "substitition algorithm") {
    SUBCASE("Should not solve a linear system of equations with the back "
            "substitition algorithm if the system is not an upper triangular "
            "linear system of equations") {
      MWP::MatrixD coefficientMatrix({2.0f, 3.0f, 5.0f, -1.0f, 4.0f, 8.0f}, 3,
                                     2);
      MWP::VectorD constantVector({8.0f, 2.0f}, 2, 1);
      MWP::LinSysD linearSystem(coefficientMatrix, constantVector);
      CHECK_THROWS_WITH_AS(
          linearSystem.solveBackSubstitution(),
          "The given linear system is not an upper triangular linear "
          "system of equations",
          std::runtime_error);
    }
    MWP::MatrixD coefficientMatrix({5.0f, -2.0f, 6.0f, 1.0f, 0.0f, 3.0f, 7.0f,
                                    -4.0f, 0.0f, 0.0f, 4.0f, 5.0f, 0.0f, 0.0f,
                                    0.0f, 2.0f},
                                   4, 4);
    MWP::VectorD constantVector({1.0f, -2.0f, 28.0f, 8.0f}, 4, 1);
    MWP::LinSysD linearSystem(coefficientMatrix, constantVector);
    linearSystem.solveBackSubstitution();
    CHECK(linearSystem.variables[0] == -3.0f);
    CHECK(linearSystem.variables[1] == 0.0f);
    CHECK(linearSystem.variables[2] == 2.0f);
    CHECK(linearSystem.variables[3] == 4.0f);
  }
}