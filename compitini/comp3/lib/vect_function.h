// 12.11.24 by Matteo Fava

#pragma once

#include "geom.h"
#include <array>
#include <cmath>
using namespace std;

const double g = 9.81;
const double G = 6.6742e-11; // costante gravitazionale

// FUNZIONE VETTORIALE BASE
template <size_t n> class VectFunction {
public:
  virtual array<double, n> eval(double, const array<double, n> &) const = 0;
};

// OSCILLATORE ARMONICO 1 DIMENSIONALE
class OscillatoreArmonico : public VectFunction<2> {
public:
  OscillatoreArmonico(double omega0_) : omega0{omega0_} {};
  virtual array<double, 2> eval(double t,
                                const array<double, 2> &x) const override {
    array<double, 2> result{x[1], -omega0 * omega0 * x[0]};
    return result;
  }

private:
  double omega0;
};

// MOTO DUE CORPI DI CUI UNO MASSIVO FISSO di massa M
// B(r) = r^(-a)+b
class Sistema : public VectFunction<4> {
public:
  Sistema(double _a, double _b) : a{_a}, b{_b} {};
  virtual array<double, 4> eval(double t,
                                const array<double, 4> &x) const override {

    double r{sqrt(pow(x[0], 2) + pow(x[1], 2))};
    double B{pow(r, -a) + b};

    array<double, 4> result{x[2], x[3], -B * x[3], B * x[2]};

    return result;
  }
  void set_a(double new_a) { a = new_a; }
  void set_b(double new_b) { b = new_b; }

private:
  double a, b;
};