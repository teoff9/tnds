//29.10.24 by Matteo Fava

#pragma once
#include <iostream>
#include <cassert>
#include "math.h"
using namespace std;

//Funzione che controlla se un numero n e' a meno di delta da m
bool is_close(double n, double m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}

void test_zeroes() {
    Parabola p{3,5,-2};
    Bisection s;
    assert(is_close(s.find_root(p, -3.0, -1., 1e-8), -2.0));
    assert(is_close(s.find_root(p, -2.0, 0.0, 1e-8), -2.0));
    assert(is_close(s.find_root(p, -4.0, -2.0, 1e-8), -2.0));
    assert(is_close(s.find_root(p, 0.0, 1.0, 1e-8), 1.0/3.0));
    cout << "All tests passed!\n";
    
}