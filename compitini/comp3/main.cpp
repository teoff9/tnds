// 17/01.24 by Matteo Fava
// Esame 3

#include "lib/functions.h"
#include "lib/gplot++.h"
#include "lib/test_diff_eq.h"
#include "lib/test_geom.h"
#include <cassert>
#include <cmath>
#include <format>
#include <iostream>
using namespace std;

int main() {
  // tests
  test_array_operations();
  test_rk4();

  // variabili
  Sistema s{0, 0};
  double h{0.05};
  double T{2 * numbers::pi};
  array<double, 4> x{1, 0, 0, 1};
  cout << format("Passo di integrazione scelto: h={}\n", h);

  // PARTE 1
  cout << "PARTE 1\n";
  double prec{1e-4};
  double real{1};
  calc_up_to(s, 0, 10 * T, x, h, false, "debug.png", false);
  assert(is_cl0se(x[0], real, prec));
  cout << format("abs( x - 1) = {}\n", abs(x[0] - 1));

  // PARTE 2
  cout << "\nPARTE 2\n";
  x = {1.1, 0, 0, 1};
  double n{5};
  s.set_a(2);
  calc_up_to(s, 0, n * T, x, h, true, "a2.png", false);
  double x_f{x[0]};
  s.set_a(-2);
  x = {1.1, 0, 0, 1};
  calc_up_to(s, 0, n * T, x, h, true, "a-2.png", false);
  cout << format("=> Creati 'a2.png' e 'a-2.png'.\n");
  cout << format("a\t\tx_finale\n2\t\t{}\n-2\t\t{}\n", x_f, x[0]);
  cout << format("Diverge il sistema con a = {}", 2);

  // PARTE 3
  cout << "\nPARTE 3\n";
  x = {1.1, 0, 0, 1};
  s.set_b(1);
  s.set_a(2);
  calc_up_to(s, 0, n * T, x, h, true, "a2-b1.png", true);
  cout << format("=> Creato 'a2-b1.png' e 'grafico_r.png'.\n");

  return 0;
}