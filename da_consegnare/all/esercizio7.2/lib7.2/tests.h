// 05.11.24 by Matteo Fava

#pragma once

#include "integral.h"
#include <cassert>
#include <cmath>
#include <numbers>
#include <ostream>
using namespace std;

// Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta = 1e-7) {
  return ((double)fabs(n - m) < delta);
}

double f(double x) { return x * sin(x); }

void test_integral() {
  Trapezoid s;

  assert(is_close(s.integrate(0, numbers::pi / 2, 10, f), 1.0020587067645337));
  assert(is_close(s.integrate(0, numbers::pi / 2, 100, f), 1.0000205619295077));
  assert(is_close(s.integrate(0, 1, 10, f), 0.30232058249393656));
  assert(is_close(s.integrate(1, 2, 30, f), 1.4403016069813432));

  assert((s.integrate_prec(0, numbers::pi / 2, 0.1, f)-1< 0.1));
  assert((s.integrate_prec(0, numbers::pi / 2, 0.001, f)-1< 0.001));
  assert((s.integrate_prec(0, numbers::pi / 2, 1e-5, f)-1 < 1e-5));

  cout << "Integral tests passed!\n";
}