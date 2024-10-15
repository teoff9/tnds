//14.10.24 by Matteo Fava
//Funzioni di input e output da file

#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

//Count data in a file
template <typename T> int count_file_elements(const char* file_name);

//Load in a vector the first n elements of a file
template <typename T> vector<T> file_to_vect(const char* file_name, int n);

//Print vector to file with precision m
template <typename T> void print(vector<T>& v, const char* file_name, int precision);

//Load all the file to a vect
template <typename T> vector<T> file_to_vect(const char* file_name);

template <typename T> int count_file_elements(const char* file_name){
    ifstream input(file_name);
    if (!input) {
        cerr << "Error: failed to load file " << file_name << endl;
        exit(-1);
    }
    int counter{0};
    T tmp;
    while (!input.eof()) {
        input >> tmp;
        counter ++;
    }
    return counter;
}

template <typename T> vector<T> file_to_vect(const char* file_name, int n) {
    ifstream input(file_name);
    if (!input) {
        cerr << "Error: failed to load file " << file_name << endl;
        exit(-1);
    }
    vector<T> w(n);
    int i{0};
    while (!input.eof() && i < n) {
        input >> w[i];
        i ++;
    }
    return w;
}


template <typename T> void print(vector<T>& v, const char* file_name, int precision){
    ofstream f(file_name);
    for (int i{0}; i<(int)v.size(); i++){f << fixed << setprecision(precision) v[i] << endl;}
    f.close();
}

template <typename T> vector<T> file_to_vect(const char* file_name){
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
        i ++;
    }
    return w;
}