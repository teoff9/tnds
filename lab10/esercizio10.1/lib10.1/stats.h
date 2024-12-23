// 15/10/24 by Matteo Fava

#pragma once
#include <iostream>
#include <vector>
using namespace std;

// calcola la media di vector
template <typename T> double average(vector<T> &V) {
  if (V.size() == 0)
    return 0;
  double m{0};
  for (int i{0}; i < (int)V.size(); i++) {
    m = (i * m + V[i]) / (T)(i + 1);
  }
  return m;
}

// calcola la varianza di  vector
template <typename T> double varianza(vector<T> &V) {
  if (V.size() == 0)
    return 0;
  double result{0};
  double m{average(V)};
  for (int i{0}; i < (int)V.size(); i++) {
    result = (result * (T)i + (V[i] - m) * (V[i] - m)) / (T)(i + 1);
  }
  return result;
}

// calcola la media di vector
template <typename T> T mediana(vector<T> &V) {
  if (V.size() == 0) {
    cerr << "Empty array" << endl;
    exit(-1);
  };
  // riordina vettore (creando una copia)
  vector<T> w{V};
  sort(w.begin(), w.end());
  // seleziona la meta
  if (w.size() % 2 != 0)
    return w[(w.size() - 1) / 2];
  else
    return (V[V.size() / 2] + V[V.size() / 2 - 1]) / 2;
}

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

// calcola la varianza di  vector with stride n
template <typename T> double varianza(vector<T> &V, int stride) {
  if (V.size() == 0)
    return 0;
  double result{0};
  double m{average(V), stride};
  for (int i{}, s{}; s < (int)V.size(); s += stride, i++) {
    result = (result * (T)i + (V[s] - m) * (V[s] - m)) / (T)(i + 1);
  }
  return result;
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