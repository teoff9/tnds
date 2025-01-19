// 15/10/24 by Matteo Fava

#pragma once
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// calcola la media di vect with stride n
template <typename T> double average(vector<T> &V, int stride) {
  if (V.size() == 0)
    return 0;
  double m{0};
  for (int i{}, s{}; s < (int)V.size(); s += stride, i++) {
    m = (i * m + V[s]) / (T)(i + 1);
  }
  return m;
}

// calcola la deviazione standard di  vector with stride n
template <typename T> double std_dev(vector<T> &V, int stride) {
  if (V.size() == 0)
    return 0;
  double result{0};
  double m{average(V, stride)};
  for (int i{}, s{}; s < (int)V.size(); s += stride, i++) {
    result = (result * (T)i + (V[s] - m) * (V[s] - m)) / (T)(i + 1);
  }
  return sqrt(result);
}