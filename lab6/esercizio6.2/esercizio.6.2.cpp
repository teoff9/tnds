// 29.10.24 by Matteo Fava

#include "lib6.2/functions.h"
#include "lib6.2/math.h"
#include "lib6.2/tests.h"
#include <cmath>
#include <cstdlib>
#include <format>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  test_zeroes();
  if (argc != 4) {
    cerr << format("Incorrect arguments: <x_min> <x_max> <prec>\n");
    exit(-1);
  }
  double a = stod(argv[1]);
  double b = stod(argv[2]);
  double prec = stod(argv[3]);
  Parabola p{3, 5, -2};
  Bisection solv;
  try {
    double x0 = solv.find_root(p, a, b, prec);
    cout << "Root found: x = " << fixed << setprecision(-log10(prec)) << x0
         << endl;
  } catch (int e) {
    if (e == -1) {
      cout << "Root not found: wrong interval!" << endl;
    } else {
      cout << "Root not found: exceeded max number of iterations!" << endl;
    }
  }

  return 0;
}