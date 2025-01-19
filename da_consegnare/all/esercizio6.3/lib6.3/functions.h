// 29.10.24 by Matteo Fava

#pragma once
#include <cmath>
using namespace std;

class Function {

public:
  virtual double operator()(double x) const = 0;
};

class Parabola : public Function {
public:
  Parabola() : a{}, b{}, c{} {}
  Parabola(double _a, double _b, double _c) : a{_a}, b{_b}, c{_c} {}
  double operator()(double x) const override { return a * x * x + b * x + c; }
  void set_a(double new_a) { a = new_a; }
  void set_b(double new_b) { b = new_b; }
  void set_c(double new_c) { c = new_c; }
  double get_a() const { return a; }
  double get_b() const { return b; }
  double get_c() const { return c; }
  double get_vert() const { return -b / (2 * a); }

private:
  double a, b, c;
};

// x - a*tan(b*x)
class TangentX : public Function {
public:
  TangentX(){};
  double operator()(double x) const override { return sin(x) - x * cos(x); }
};