// 26.11.2024 by Matteo Fava

#pragma once
#include "random.h"
#include <cassert>
#include <iostream>
using namespace std;

// Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta = 1e-7) {
  return ((double)fabs(n - m) < delta);
}

void test_random() {
  RandomGen gen{1};
  // rand
  double r[5] = {0.47291105054318905, 0.7385413474403322, 0.008484064601361752,
                 0.40976652735844254, 0.10108725726604462};
  for (int i{0}; i < 5; i++)
    assert(is_close<double>(r[i], gen.rand()));
  gen.reset_seed(1);

  // exp
  double re[5] = {0.6403859601352556, 1.3414791243855002, 0.008520259140710315,
                  0.5272371040158115, 0.10656930958385337};
  for (int i{0}; i < 5; i++)
    assert(is_close<double>(re[i], gen.expo(1)));
  gen.reset_seed(1);

  // gauss Box-Muller
  double res[5] = {1.9119660920460757, -0.6053171651252578, 1.8526405678280609,
                   2.8326279901403026, 1.5348644738998436};
  for (int i{0}; i < 5; i++)
    assert(is_close<double>(res[i], gen.gauss(2, 1)));
  gen.reset_seed(1);

  // gauss Accept&Reject
  double resu[5] = {1.7291105054318905, 2.4952592495828867, 2.009022830054164,
                    0.6520544346421957, 1.318840131163597};
  for (int i{0}; i < 5; i++)
    assert(is_close<double>(resu[i], gen.gauss_aer(2, 1)));

  cout << "All RandomGen tests passed!\n";
}