//15.10.24 by Matteo Fava

#pragma once
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include "stats.h"
using namespace std;

//Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool are_close(T n, T m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}

void test_statistics_with_stride() {
  vector<double> v{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  assert(are_close(average(v, 1), 3.5));
  assert(are_close(average(v, 2), 3.0));
  assert(are_close(average(v, 3), 2.5));

  assert(are_close(std_dev(v, 1), 1.707825127659933));
  assert(are_close(std_dev(v, 2), 1.632993161855452));
  assert(are_close(std_dev(v, 3), 1.5));

  cerr << "All the tests have passed. Hurrah! 🥳\n";
}