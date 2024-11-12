//12.11.24 by Matteo Fava
//Algrebra lineare

#include <array>
#include "geom.h"
#include <cassert>
#include <iostream>
using namespace std;

#pragma once

void test_array_operations() {
  // Usiamo solo numeri interi piccoli, così non serve usare
  // are_close perché i calcoli sui double non hanno
  // arrotondamenti

  std::array<double, 3> a{2.0, 4.0, 6.0};
  std::array<double, 3> b{-1.0, 1.0, 4.0};

  // Con "auto" si lascia che sia il compilatore a capire
  // che il tipo di "sum" e "diff" è "std::array<double, 3>"
  auto sum{a + b};

  assert(sum[0] == 1.0);
  assert(sum[1] == 5.0);
  assert(sum[2] == 10.0);

  auto diff{a - b};

  assert(diff[0] == 3.0);
  assert(diff[1] == 3.0);
  assert(diff[2] == 2.0);

  auto prod1{5.0 * a};

  assert(prod1[0] == 10.0);
  assert(prod1[1] == 20.0);
  assert(prod1[2] == 30.0);

  auto prod2{b * 6.0};

  assert(prod2[0] == -6.0);
  assert(prod2[1] == 6.0);
  assert(prod2[2] == 24.0);

  auto ratio{a / 2.0};

  assert(ratio[0] == 1.0);
  assert(ratio[1] == 2.0);
  assert(ratio[2] == 3.0);

  cout << "All tests passed for array operations!\n";
}