// 03.12.2024 by Matteo Fava

#pragma once
#include "integral_mc.h"
#include "random.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

double f__(double x) { return x * sin(x); }

// Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close_(T n, T m, double delta = 1e-4) {
  return ((double)fabs(n - m) < delta);
}

void test_mc_mean() {
  MC_mean m{1};
  assert(is_close_(m.integrate(f__, 0, M_PI / 2, 100, M_PI / 2), 1.10443));
}

void test_mc_hit_miss() {
  MC_hit_miss m{1};
  assert(is_close_(m.integrate(f__, 0, M_PI / 2, 100, M_PI / 2), 0.937612));
}

void test_integrals_mc() {
  test_mc_hit_miss();
  test_mc_mean();
  cout << "All integral MC tests passed !!\n";
}
