// 19.11.24 by Matteo Fava

#include "lib8.4/diff_eq.h"
#include "lib8.4/geom.h"
#include "lib8.4/gplot++.h"
#include "lib8.4/test_diff_eq.h"
#include "lib8.4/test_geom.h"
#include "lib8.4/vect_function.h"
#include <iomanip>
#include <vector>
using namespace std;

double sgn(double);

double interp(double x0, double y0, double x1, double y1, double y);

void test_interp();

int main() {
  // tests
  test_array_operations();
  test_rk4();
  test_interp();

  // variabili
  double w0{10};
  double w_i{9.};
  double a{1.0 / 30.0};
  double a0{1};
  double h{0.01};
  vector<double> tx, y;
  RK4<2> rk;
  Gnuplot plt;
  // varia w della forzante da 9 a 11
  for (int i{(int)(w_i * 100)}; i < 11 * 100 + 1; i += 5) {
    double w{i * 0.01};
    OscForzato osc{w0, a, a0, w};
    array<double, 2> x{0., 0.};
    double t{};
    // integra fino a regime
    while (t < 300.0) {
      x = rk.step(t, h, x, osc);
      t += h;
    }
    // trova ampiezza
    double v{};
    double sign{sgn(x[1])};
    while (sgn(x[1]) == sign) {
      v = x[1];
      x = rk.step(t, h, x, osc);
      t += h;
    }
    double t_m{interp(t - h, v, t, x[1], 0.0)};
    y.push_back(abs(rk.step(t, t_m - t, x, osc)[0]));
    tx.push_back(w);
  }

  // plot
  plt.plot(tx, y);
  plt.set_title("Ampiezza in funzione di w");
  plt.set_ylabel("A[m]");
  plt.set_xlabel("w[1/s]");
  plt.redirect_to_png("risonanza.png");
  plt.show();
  cout << "Created 'risonanza.png'\n";

  return 0;
}

double sgn(double x) { return x / abs(x); }

//interp lineare
double interp(double x0, double y0, double x1, double y1, double y) {
  return x0 + (x0 - x1) / (y0 - y1) * (y - y0);
}

void test_interp() {
  double p1x{-0.4};
  double p1y{-0.7};
  double p2x{0.5};
  double p2y{0.8};
  assert(is_close(interp(p1x, p1y, p2x, p2y, 0.3), 0.2));
  cout << "Test passed for interp!\n";
}