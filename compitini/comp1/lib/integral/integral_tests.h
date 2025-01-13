//05.11.24 by Matteo Fava

#pragma once
#include "integral.h"
#include <cassert>
#include <ostream>
#include <numbers>
using namespace std;

//Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}

double f_(double x) {
    return x*sin(x);
}

void test_midpoint() {
    MidPoint p;

  assert(is_close(p.integrate(0, numbers::pi / 2., 10, f_),0.9989696941917652));
  assert(is_close(p.integrate(0, numbers::pi / 2., 100, f_),0.999989718940119));
  assert(is_close(p.integrate(numbers::pi / 2., 0, 10, f_),-0.998969694191765));
  assert(is_close(p.integrate(0, 1, 10, f_),0.3005925674684609));
  assert(is_close(p.integrate(1, 2, 30, f_),1.440482828731412));
  cout << "Midpoint integral tests passed.\n";
}

void test_simpson() {
    Simpson s;
    assert(is_close(s.integrate(0, numbers::pi/2, 10, f_), 0.9999898033639686));
    assert(is_close(s.integrate(0, numbers::pi/2, 100, f_), 0.9999999989852724));
    assert(is_close(s.integrate(0, 1, 10, f_), 0.3011669731757114));
    assert(is_close(s.integrate(1, 2, 30, f_), 1.4404224289997802));

    cout << "Simpson integral tests passed!\n";
}

void test_trapezoid() {
    Trapezoid s;

    assert(is_close(s.integrate(0, numbers::pi / 2, 10, f_), 1.0020587067645337));
    assert(is_close(s.integrate(0, numbers::pi / 2, 100, f_), 1.0000205619295077));
    assert(is_close(s.integrate(0, 1, 10, f_), 0.30232058249393656));
    assert(is_close(s.integrate(1, 2, 30, f_), 1.4403016069813432));

    assert((s.integrate_prec(0, numbers::pi / 2, 0.1, f_)-1< 0.1));
    assert((s.integrate_prec(0, numbers::pi / 2, 0.001, f_)-1< 0.001));
    assert((s.integrate_prec(0, numbers::pi / 2, 1e-5, f_)-1 < 1e-5));

    cout << "Trapezoid integral tests passed!\n";
}

void test_all_integrals() {
    //Midpoint
    test_midpoint();
    //Simpson
    test_simpson();
    //Trapezoid
    test_trapezoid();
}