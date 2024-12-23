// 05.11.24 by Matteo Fava

#include "lib7.1/gplot++.h"
#include "lib7.1/integral.h"
#include "lib7.1/tests.h"
#include <cmath>
#include <format>
#include <numbers>
#include <ostream>
#include <vector>
using namespace std;

double g(double x) { return x * sin(x); }

int main() {
  // tests
  test_integral();

  // simpson and plot
  Simpson s;
  double true_value{1};
  Gnuplot plt;
  double err{};
  plt.set_logscale(Gnuplot::AxisScale::LOGXY);
  plt.set_title("Errore in funzione dei passi");
  plt.set_xlabel("Passi");
  plt.set_ylabel("Errore");
  plt.redirect_to_png("error.png");

  // esegui per i passi fissati
  vector<int> steps = {10, 50, 100, 500, 1000};
  cout << "Step\t\tIntegral\t\tError\n";
  for (int i = 0; i < ssize(steps); i++) {
    double v{s.integrate(0, numbers::pi / 2, steps[i], g)};
    err = fabs(true_value - v);
    cout << format(" {}\t   {}\t {} \n", steps[i], v, err);
    plt.add_point(steps[i], err);
  }
  plt.plot("Errore in funzione del passo", Gnuplot::LineStyle::LINES);
  plt.show();
  cout << "\n => Created 'error.png'\n";

  return 0;
}