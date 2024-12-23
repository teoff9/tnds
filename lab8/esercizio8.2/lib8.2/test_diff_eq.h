// 12.11.24 by Matteo Fava

#pragma once
#include "diff_eq.h"
#include "geom.h"
#include "vect_function.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

// Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta = 1e-7) {
  return ((double)fabs(n - m) < delta);
}

void test_euler() {
  Euler<2> my_euler{};

  OscillatoreArmonico osc{1.};

  const double tmax{0.91};
  const double h{0.1};
  array<double, 2> x{0., 1.};
  double t{};

  const int num_of_steps{(int)lround(tmax / h)};

  for (int s{}; s < num_of_steps; s++) {
    x = my_euler.step(t, h, x, osc);
    t = t + h;
  }

  assert(is_close(x[0], 0.817256, 1e-6));
  assert(is_close(x[1], 0.652516, 1e-6));
  cout << "All tests passed for Euler!\n";
}

void test_rk4() {
  RK4<2> my_rk;
  OscillatoreArmonico osc{1.0};
  const double tmax{70.00};
  // 0.00912409
  const double h{0.01};
  array<double, 2> x{0., 1.};
  double t{};

  const int num_of_steps{(int)lround(tmax / h)};

  for (int s{}; s < num_of_steps; s++) {
    x = my_rk.step(t, h, x, osc);
    t = t + h;
  }

  assert(is_close(x[0], sin(70.0), 1e-6));
  assert(is_close(x[1], cos(70.), 1e-6));
  cout << "All tests passed for RK4!\n";
}