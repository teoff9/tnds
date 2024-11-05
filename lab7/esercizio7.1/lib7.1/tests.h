//05.11.24 by Matteo Fava

#pragma once

#include "integral.h"
#include <cassert>
#include <cmath>
#include <ostream>
#include <numbers>
using namespace std;


//Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}

double f(double x) {
    return x*sin(x);
}

void test_integral() {
    Simpson s;

    assert(is_close(s.integrate(0, numbers::pi/2, 10, f), 0.9999898033639686));
    assert(is_close(s.integrate(0, numbers::pi/2, 100, f), 0.9999999989852724));
    assert(is_close(s.integrate(0, 1, 10, f), 0.3011669731757114));
    assert(is_close(s.integrate(1, 2, 30, f), 1.4404224289997802));




    cout << "Integral tests passed!\n";
}