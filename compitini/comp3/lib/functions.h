// 17.01.24 by Matteo Fava

#pragma once

#include "diff_eq.h"
#include "geom.h"
#include "gplot++.h"
#include "vect_function.h"
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Integra fino a final_t modificanto by ref x
 */
void calc_up_to(Sistema s, double t0, double final_t, array<double, 4> &x,
                double h, float debug, string file_name, float grafico_r) {
  double t{t0};
  RK4<4> rk;
  Gnuplot plt, gpl;

  while (t < final_t - h) {
    x = rk.step(t, h, x, s);
    if (debug)
      plt.add_point(x[0], x[1]);
    if (grafico_r)
      gpl.add_point(t, sqrt(x[0] * x[0] + x[1] * x[1]));
    t += h;
  }
  double h_adj{final_t - t};   // Calcola h corretto per non superare valore
  x = rk.step(t, h_adj, x, s); // Compi l'ultimo passo di integrazione
  t = final_t;
  if (debug) {
    plt.add_point(x[0], x[1]);
    plt.plot();
    plt.redirect_to_png(file_name);
    plt.show();
  }
  if (grafico_r) {
    gpl.add_point(t, sqrt(x[0] * x[0] + x[1] * x[1]));
    gpl.plot();
    gpl.redirect_to_png("grafico_r.png");
    gpl.show();
  }
}
