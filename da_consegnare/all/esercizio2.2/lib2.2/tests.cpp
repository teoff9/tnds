// 01/10/2024 by Matteo Fava
#include "tests.h"
#include "stats.h"
#include "vect.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

bool is_close(double n, double m, double delta = 1e-7) {
  return (fabs(n - m) < delta);
}

void test_sorting() {
  Vect d(4);
  d[0] = 1.5;
  d[1] = 0.5;
  d[2] = 3;
  d[3] = 0.25;
  d.sort();
  for (int i = 0; i < d.size() - 1; i++) {
    assert(d[i] < d[i + 1]);
  };
  cout << "Test sorting: passed!\n";
}

void test_statistical_functions() {
  Vect d(5);
  for (int i = 0; i < d.size(); i++) {
    d[i] = i + 1;
  }
  // media
  assert(is_close(mean(d), 3));
  // varianza
  assert(is_close(varianza(d), 2));
  // mediana
  assert(is_close(mediana(d), 3));

  cout << "Statistical test: passed!\n";
}
