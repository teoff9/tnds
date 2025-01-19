// 29.10.24 by Matteo Fava

#include "lib6.3/functions.h"
#include "lib6.3/math.h"
#include "lib6.3/tests.h"
#include <format>
#include <iomanip>
#include <numbers>
#include <ostream>
using namespace std;

const double pi = numbers::pi;

int main() {
  test_zeroes();
  TangentX t{};
  Bisection s;

  for (int i = 0; i <= 20; i++) {
    try {
      double n = static_cast<double>(i);
      double x0 = s.find_root(t, n * pi, n * pi + pi / 2.0, 1e-7);
      cout << "Root found in [" << n * pi << ", " << n * pi + pi / 2.0
           << "] : x0 = " << fixed << setprecision(7) << x0 << endl;
    } catch (int e) {
      if (e == -1) {
        cout << "Root not found: wrong interval!" << endl;
      } else {
        cout << "Root not found: exceeded max number of iterations!" << endl;
      }
    }
  }

  return 0;
}