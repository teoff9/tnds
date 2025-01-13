//23.12.24 by Matteo Fava

#pragma once

#include "interp.h"
#include <cassert>
#include <iostream>
using namespace std;

// Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool are_close_(T n, T m, double delta = 1e-7) {
  return ((double)fabs(n - m) < delta);
}


void test_interp() {
  double p1x{-0.4};
  double p1y{-0.7};
  double p2x{0.5};
  double p2y{0.8};
  assert(are_close_(interp(p1x, p1y, p2x, p2y, 0.3), 0.2));
  cout << "Test passed for interp!\n";
}