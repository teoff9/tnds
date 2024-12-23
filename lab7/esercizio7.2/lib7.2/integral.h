// 05.11.24 by Matteo Fava

#pragma once
#include <cstdlib>
#include <functional>
#include <iostream>
#include <cmath>
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
  // Metodi da fare override
  virtual double calculate(int, function<double(double)>) = 0;

  double a, b;
  double sign;
  double h;
};

// Trapezi
class Trapezoid : public Integral {
public:
  Trapezoid() : Integral(){};
  double integrate_prec(double _a, double _b, double prec,
                        function<double(double)> f) {
    check_interval(_a, _b);
    // stima N
    double N{2};
    prev_approx = (f(a) + f(b)) / 2;
    approx = prev_approx + f(a + (b - a) / 2);
    while (4.0 * fabs(approx - prev_approx) / 3.0 > prec) {
      N *= 2;
      prev_approx = approx;
      approx = calculate(N, f);
    }

    // calcola integrale
    return sign * approx;
  }

private:
  virtual double calculate(int N, function<double(double)> f) override {
    h = (b - a) / N;
    double acc{0.5 * (f(a) + f(b))};
    for (int i = 1; i < N; i++) {
      acc += f(a + i * h);
    }
    return h * acc;
  }
  double prev_approx, approx;
};