// 03.12.2024 by Matteo Fava
// Montecarlo integrals

#pragma once

#include "random.h"
#include <functional>
using namespace std;

// classe astratta per Integrale Montecarlo
class IntegralMC {
public:
  IntegralMC(unsigned int seed) : gen{seed}, error{}, N{} {};

  virtual double integrate(function<double(double)> f, double inf, double sup,
                           int N, double f_max) = 0;

  double get_error() const { return error; };

  double get_N() const { return N; };

protected:
  RandomGen gen;
  double error;
  int N;
};

// classe per integrale con il metodo della media
class MC_mean : public IntegralMC {
public:
  MC_mean(unsigned int seed) : IntegralMC{seed} {};

  virtual double integrate(function<double(double)> f, double inf, double sup,
                           int N, double f_max) override {
    double f_i{};
    for (int i{}; i < N; i++) {
      f_i += f(gen.unif(inf, sup));
    }
    return (sup - inf) * f_i / N;
  }
};

// classe per integrale con il metodo hit or miss
class MC_hit_miss : public IntegralMC {
public:
  MC_hit_miss(unsigned int seed) : IntegralMC{seed} {};

  // f_max > max(f){D}
  virtual double integrate(function<double(double)> f, double inf, double sup,
                           int N, double f_max) override {
    int N_tot{}, N_hit{};
    double x, y;
    for (int i{}; i < N; i++) {
      x = gen.unif(inf, sup);
      y = gen.unif(0, f_max);
      if (y <= f(x))
        N_hit++;
      N_tot++;
    }
    return (sup - inf) * f_max * (double)N_hit / N_tot;
  }
};