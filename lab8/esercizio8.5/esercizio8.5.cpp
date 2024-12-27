// 23.12.24 by Matteo Fava

#include "lib8.5/diff_eq.h"
#include "lib8.5/geom.h"
#include "lib8.5/gplot++.h"
#include "lib8.5/test_diff_eq.h"
#include "lib8.5/test_geom.h"
#include "lib8.5/vect_function.h"
#include <array>
#include <format>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;


int main() {
  // tests
  test_array_operations();
  test_rk4();

  // variabili
  RK4<4> rk{};
  Gravitation sol{1.988441030e30};
  CorrectedGrav corr{1.988441030e30, 1.5e21};
  array<double, 4> x{1.47098074e11, 0, 0, 3.0287e4};
  Gnuplot plt;
  Gnuplot prt;
  plt.redirect_to_png("revolution.png");
  prt.redirect_to_png("revol_corrected.png");

  double h{0.25*24*3600}; //8h
  double t{};
  int c{};
  double lasty{};
  
  while (c<2) {
    
    x = rk.step(t, h, x, sol);
    plt.add_point(x[0], x[1]);
    t += h;

    if (x[1] * lasty<0) {
        c++;
        if (c <2 ) cout << format("Rapporto perielio / afelio : {}\n", 1.47098074e11/fabs(x[0]));
    }
    lasty = x[1];
  
  }
  plt.plot();
  plt.show();
  
  t=0;
  x = {1.47098074e11, 0, 0, 3.0287e4};
  while (t < 10*365*24*3600) {
    x = rk.step(t, h, x, corr);
    prt.add_point(x[0], x[1]);
    t += h;
  }
  prt.plot();
  prt.show();


  cout << "Created 'revolution.png' and 'revol_corrected.png'\n";

  return 0;
}