//03.12.24 by Matteo Fava

#pragma once

#include "stats.h"
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

//Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool _is_close(T n, T m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}

void test_statistical_functions() {
    vector<double> d(5);
    for (int i = 0; i < d.size(); i++) {d[i]=i+1;}
    //media
    assert(_is_close<double>(average(d), 3.0));
    //varianza
    assert(_is_close<double>(varianza(d), 2));
    //mediana
    assert(_is_close<double>(mediana(d), 3));

    //with stride
    vector<double> v{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    assert(_is_close<double>(std_dev(v, 1), 1.707825127659933));
    assert(_is_close<double>(std_dev(v, 2), 1.632993161855452));
    assert(_is_close<double>(std_dev(v, 3), 1.5));

    cout << "Statistical test: passed!\n";
}