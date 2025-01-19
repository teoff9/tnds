// 05.11.24 by Matteo Fava

#pragma once
#include <cstdlib>
#include <functional>
#include <iostream>
using namespace std;

// Classe virtuale Integral
class Integral {
public:
  Integral() : a{0}, b{0}, h{0}, sign{0} {};
  double integrate(double _a, double _b, int n_steps,
                   function<double(double)> f) {
    check_interval(_a, _b);
    return sign * calculate(n_steps, f);
  }

protected:
  void check_interval(double _a, double _b) {
    a = min(_a, _b);
    b = max(_a, _b);
    if (_a < _b)
      sign = 1;
    else
      sign = -1;
  }
  // Metodo da fare override
  virtual double calculate(int, function<double(double)>) = 0;

  double a, b;
  double sign;
  double h;
};

// Integrale Simpson
class Simpson : public Integral {
public:
  Simpson() : Integral(){};

private:
  virtual double calculate(int N, function<double(double)> f) {
    // FUNZIONA SOLO CON N PARI
    if (N % 2 == 1)
      N = N + 1;

    h = (b - a) / N;
    double acc{f(a) + f(b)};
    for (int i = 1; i < N; i++) {
      acc += 2.0 * (1.0 + i % 2) * f(a + i * h);
    }
    return h * acc / 3.0;
  }
};