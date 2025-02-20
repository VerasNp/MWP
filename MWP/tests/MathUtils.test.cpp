#include "MathUtils.hpp"
#include "doctest/doctest.h"
#include <stdexcept>

TEST_CASE("Test some functions of math utils") {
  SUBCASE("Test the resolution of quadratic equation") {
    SUBCASE("Should not solve a quadratic equation if the first constant term "
            "is equal to zero") {
      CHECK_THROWS_WITH_AS(MWP::solveQuadraticEquation(0.0f, 1.3f, 1.8f),
                           "Not a valid quadratic equation",
                           std::runtime_error);
    }
    SUBCASE("Should solve a quadratic equation in the form of ax2+bx+c with "
            "two different real roots") {
      MWP::QuadraticEquationReturn<int> result =
          MWP::solveQuadraticEquation(1, 3, -4);
      CHECK(result.delta == 25);
      CHECK(result.firstRootReal == 1);
      CHECK(result.secondRootReal == -4);
    }
    SUBCASE("Should solve a quadratic equation in the form of ax2+c with "
            "two equal real roots") {
      MWP::QuadraticEquationReturn<double> result =
          MWP::solveQuadraticEquation(2.0, 0.0, -6.0);
      CHECK(result.delta == 48);
      CHECK(result.firstRootReal == doctest::Approx(1.73205));
      CHECK(result.secondRootReal == doctest::Approx(-1.73205));
    }
    SUBCASE("Should solve a quadratic equation in the form of ax2+bx+c with "
            "two imaginary roots") {
      MWP::QuadraticEquationReturn<double> result =
          MWP::solveQuadraticEquation(3.0, 2.0, 1.0);
      CHECK(result.delta == -8);
      CHECK(result.firstRootReal == doctest::Approx(-0.333333));
      CHECK(result.secondRootReal == doctest::Approx(-0.333333));
      CHECK(result.firstRootImag == doctest::Approx(0.471405));
      CHECK(result.secondRootImag == doctest::Approx(-0.471405));
    }
  }
}