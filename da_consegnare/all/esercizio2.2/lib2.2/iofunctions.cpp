// 01/10/2024 by Matteo Fava

#include "iofunctions.h"
#include "vect.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int count_file_elements(const char *file_name) {
  ifstream input(file_name);
  if (!input) {
    cerr << "Error: failed to load file " << file_name << endl;
    exit(-1);
  }
  int counter = 0;
  double tmp;
  while (!input.eof()) {
    input >> tmp;
    counter++;
  }
  return counter;
}

Vect file_to_vect(const char *file_name, int n) {
  ifstream input(file_name);
  if (!input) {
    cerr << "Error: failed to load file " << file_name << endl;
    exit(-1);
  }
  Vect w(n);
  int i = 0;
  while (!input.eof() && i < n) {
    input >> w[i];
    i++;
  }
  return w;
}

// print to terminal
void print(Vect &v) {
  cout << "\nElementi del vect:\n";
  for (int i = 0; i < v.size(); i++) {
    cout << fixed << setprecision(5) << v[i] << endl;
  }
  cout << endl;
}

// print to file
void print(Vect &v, const char *file_name) {
  ofstream f(file_name);
  for (int i = 0; i < v.size(); i++) {
    f << v[i] << endl;
  }
  f.close();
}