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

// PENDOLO 1 DIMENSIONALE
//  theta" = -g/l sin(theta)
class Pendulum : public VectFunction<2> {
public:
  Pendulum(double l_) : l{l_} {};
  virtual array<double, 2> eval(double t,
                                const array<double, 2> &x) const override {
    array<double, 2> result{x[1], -g / l * sin(x[0])};
    return result;
  }

private:
  double l;
};

// OSCILLATORE ARMONICO FORZATO 2D
//  x" = -w0^2x - ax' + a0sin(wt)
class OscForzato : public VectFunction<2> {
public:
  OscForzato(double w0_, double a_, double a0_, double w_)
      : w0{w0_}, a{a_}, a0{a0_}, w{w_} {};
  virtual array<double, 2> eval(double t,
                                const array<double, 2> &x) const override {
    array<double, 2> result{x[1], -w0 * w0 * x[0] - a * x[1] + a0 * sin(w * t)};
    return result;
  }

private:
  double w0, a, a0, w;
};

// MOTO DUE CORPI DI CUI UNO MASSIVO FISSO di massa M
// x" = -G * M / r^2
class Gravitation : public VectFunction<4> {
public:
  Gravitation(double _M) : M{_M} {};
  virtual array<double, 4> eval(double t,
                                const array<double, 4> &x) const override {

    double r{sqrt(pow(x[0], 2) + pow(x[1], 2))};

    array<double, 4> result{x[2], x[3], -G * M * x[0] / pow(r, 3),
                            -G * M * x[1] / pow(r, 3)};

    return result;
  }

private:
  double M; // Massa del corpo al centro
};

// MOTO DUE CORPI DI CUI UNO MASSIVO FISSO di massa M con CORREZIONE DEL
// POTENZIALE x" = -G * M / r^2 - a/r^3
class CorrectedGrav : public VectFunction<4> {
public:
  CorrectedGrav(double _M, double correction_alpha)
      : M{_M}, a{correction_alpha} {};
  virtual array<double, 4> eval(double t,
                                const array<double, 4> &x) const override {

    double r{sqrt(pow(x[0], 2) + pow(x[1], 2))};
    double corr{3 * a / pow(r, 5)};
    double fx = -G * M * x[0] * (1 / pow(r, 3) + corr);
    double fy = -G * M * x[1] * (1 / pow(r, 3) + corr);
    array<double, 4> result{x[2], x[3], fx, fy};

    return result;
  }

private:
  double M; // Massa del corpo al centro
  double a; // Termine correttivo a/r^3
};

// MOTO DI UNA PARTICELLA CARICA IN CAMPO MAGNETICO E CAMPO ELETTRICO
//  in 3 Dimensioni
//  mx" = qE + qv x B
class Lorentz : public VectFunction<6> {
public:
  Lorentz(array<double, 3> _B, array<double, 3> _E, double _q, double _m) : B{_B}, E{_E}, q{_q}, m{_m} {};
  virtual array<double, 6> eval(double t, const array<double, 6> &x) const override {
    array<double, 6> result{ x[3], x[4], x[5], 
                              q/m*( B[2]*x[4]-B[1]*x[5] + E[0]), 
                              q/m*( B[0]*x[5]-B[2]*x[3] + E[1]),
                              q/m*( B[1]*x[3]-B[0]*x[4] + E[2])};
    return result;
  }

private:
  array<double, 3> B, E;
  double q;
  double m;
};