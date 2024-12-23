// 01/10/2024 by Matteo Fava
// funzione per gestire input

#pragma once
#include "vect.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

template <typename T> int count_file_elements(const char *file_name);

template <typename T> Vect<T> file_to_vect(const char *file_name, int n);

// print to terminal
template <typename T> void print(Vect<T> &v);

// print to file
template <typename T> void print(Vect<T> &v, const char *file_name);

template <typename T> int count_file_elements(const char *file_name) {
  ifstream input(file_name);
  if (!input) {
    cerr << "Error: failed to load file " << file_name << endl;
    exit(-1);
  }
  int counter{0};
  T tmp;
  while (!input.eof()) {
    input >> tmp;
    counter++;
  }
  return counter;
}

template <typename T> Vect<T> file_to_vect(const char *file_name, int n) {
  ifstream input(file_name);
  if (!input) {
    cerr << "Error: failed to load file " << file_name << endl;
    exit(-1);
  }
  Vect<T> w(n);
  int i{0};
  while (!input.eof() && i < n) {
    input >> w[i];
    i++;
  }
  return w;
}

// print to terminal
template <typename T> void print(Vect<T> &v) {
  cout << "\nElementi del vect:\n";
  for (int i{0}; i < v.size(); i++) {
    cout << fixed << setprecision(5) << v[i] << endl;
  }
  cout << endl;
}

// print to file
template <typename T> void print(Vect<T> &v, const char *file_name) {
  ofstream f(file_name);
  for (int i{0}; i < v.size(); i++) {
    f << v[i] << endl;
  }
  f.close();
}