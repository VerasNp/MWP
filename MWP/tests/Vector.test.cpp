#include "Vector.hpp"
#include "doctest/doctest.h"

TEST_CASE("Tests the vectos class and its functionalities") {
  SUBCASE("Should create a vector with given components") {
    MWP::VectorD vectorD({1.0f, 2.0f, 3.0f});
    CHECK(vectorD[0] == 1.0f);
    CHECK(vectorD[1] == 2.0f);
    CHECK(vectorD[2] == 3.0f);
    MWP::VectorI vectorI({1, 2, 3});
    CHECK(vectorI[0] == 1);
    CHECK(vectorI[1] == 2);
    CHECK(vectorI[2] == 3);
  }
  SUBCASE("Should return the size of vector") {
    MWP::VectorD vectorD({1.0f, 2.0f, 3.0f});
    CHECK(vectorD.Size() == 3);
  }
  SUBCASE("Should add two vectors") {
    MWP::VectorD vectorD1({1.0f, 2.0f, 3.0f});
    MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f});
    MWP::VectorD vectorDRes1 = vectorD1 + vectorD2;
    CHECK(vectorDRes1[0] == 2.0f);
    CHECK(vectorDRes1[1] == 4.0f);
    CHECK(vectorDRes1[2] == 6.0f);
    MWP::VectorD vectorD3({1.0f, 2.0f, 3.0f});
    MWP::VectorD vectorD4({1.0f, 2.0f, 3.0f});
    vectorD3 += vectorD4;
    CHECK(vectorD3[0] == 2.0f);
    CHECK(vectorD3[1] == 4.0f);
    CHECK(vectorD3[2] == 6.0f);
    MWP::VectorI vectorI1({1, 2, 3});
    MWP::VectorI vectorI2({1, 2, 3});
    MWP::VectorI vectorIRes1 = vectorI1 + vectorI2;
    CHECK(vectorIRes1[0] == 2);
    CHECK(vectorIRes1[1] == 4);
    CHECK(vectorIRes1[2] == 6);
    MWP::VectorI vectorI3({1, 2, 3});
    MWP::VectorI vectorI4({1, 2, 3});
    vectorI3 += vectorI4;
    CHECK(vectorI3[0] == 2);
    CHECK(vectorI3[1] == 4);
    CHECK(vectorI3[2] == 6);
  }
  SUBCASE("Should subtract two vectors") {
    MWP::VectorD vectorD1({2.0f, 3.0f, 4.0f});
    MWP::VectorD vectorD2({1.0f, 2.0f, 3.0f});
    MWP::VectorD vectorDRes1 = vectorD1 - vectorD2;
    CHECK(vectorDRes1[0] == 1.0f);
    CHECK(vectorDRes1[1] == 1.0f);
    CHECK(vectorDRes1[2] == 1.0f);
    MWP::VectorD vectorD3({2.0f, 3.0f, 4.0f});
    MWP::VectorD vectorD4({1.0f, 2.0f, 3.0f});
    vectorD3 -= vectorD4;
    CHECK(vectorD3[0] == 1.0f);
    CHECK(vectorD3[1] == 1.0f);
    CHECK(vectorD3[2] == 1.0f);
    MWP::VectorI vectorI1({2, 3, 4});
    MWP::VectorI vectorI2({1, 2, 3});
    MWP::VectorI vectorIRes1 = vectorI1 - vectorI2;
    CHECK(vectorIRes1[0] == 1);
    CHECK(vectorIRes1[1] == 1);
    CHECK(vectorIRes1[2] == 1);
    MWP::VectorI vectorI3({2, 3, 4});
    MWP::VectorI vectorI4({1, 2, 3});
    vectorI3 -= vectorI4;
    CHECK(vectorI3[0] == 1);
    CHECK(vectorI3[1] == 1);
    CHECK(vectorI3[2] == 1);
  }
  SUBCASE("Should multiply vector by scalar") {
    MWP::VectorD vectorD1({2.0f, 3.0f, 4.0f});
    MWP::VectorD vectorDRes1 = vectorD1 * 3.0f;
    CHECK(vectorDRes1[0] == 6.0f);
    CHECK(vectorDRes1[1] == 9.0f);
    CHECK(vectorDRes1[2] == 12.0f);
    MWP::VectorD vectorD2({2.0f, 3.0f, 4.0f});
    vectorD2 *= 3.0f;
    CHECK(vectorD2[0] == 6.0f);
    CHECK(vectorD2[1] == 9.0f);
    CHECK(vectorD2[2] == 12.0f);
    MWP::VectorI vectorI1({2, 3, 4});
    MWP::VectorI vectorIRes1 = vectorI1 * 3;
    CHECK(vectorIRes1[0] == 6);
    CHECK(vectorIRes1[1] == 9);
    CHECK(vectorIRes1[2] == 12);
    MWP::VectorI vectorI2({2, 3, 4});
    vectorI2 *= 3;
    CHECK(vectorI2[0] == 6);
    CHECK(vectorI2[1] == 9);
    CHECK(vectorI2[2] == 12);
  }
}