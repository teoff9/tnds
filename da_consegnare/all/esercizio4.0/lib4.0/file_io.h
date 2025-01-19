// 15.10.24 by Matteo Fava
// Funzioni di input e output da file

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Count data in a file
template <typename T> int count_file_elements(string file_name);

// Load all the file to a vector of elements
template <typename T> vector<T> file_to_vect(string file_name);

template <typename T> int count_file_elements(string file_name) {
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

template <typename T> vector<T> file_to_vect(string file_name) {
  int n = count_file_elements<T>(file_name);
  ifstream input(file_name);
  if (!input) {
    cerr << "Error: failed to load file " << file_name << endl;
    exit(-1);
  }
  vector<T> w(n);
  int i{0};
  while (!input.eof() && i < n) {
    input >> w[i];
    i++;
  }
  return w;
}