// 08/10/24 by Matteo Fava

#pragma once
#include "stats.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta = 1e-7) {
  return ((double)fabs(n - m) < delta);
}

// Funzione per testare le funzioni statistiche
void test_statistical_functions() {
  vector<int> d(5);
  for (int i = 0; i < (int)d.size(); i++) {
    d[i] = i + 1;
  }
  // media
  assert(is_close<int>(average(d), 3));
  // varianza
  assert(is_close<int>(varianza(d), 2));
  // mediana
  assert(is_close<int>(mediana(d), 3));
  cout << "Statistical test: passed!\n";
}