// 05.11.24 by Matteo Fava

#include "lib7.2/integral.h"
#include "lib7.2/tests.h"
#include <cmath>
#include <cstdlib>
#include <format>
#include <numbers>
#include <ostream>
#include <vector>
using namespace std;

//funzione
double g(double x) { return x * sin(x); }

int main(int argc, char *argv[]) {
  //controlla input
  if (argc != 2) {
    cerr << "Wrong input: <prec> \n";
    return -1;
  }

  //test integral
  test_integral();

  Trapezoid t;
  double a{0};
  double b{numbers::pi};
  double prec{stod(argv[1])};
  int c = -log10(prec);
  cout << format("Integral of x*sinx in [0, {}] with prec {} is: {:.{}f}\n", b,
                 prec, t.integrate_prec(a, b, prec, g), c);

  return 0;
}