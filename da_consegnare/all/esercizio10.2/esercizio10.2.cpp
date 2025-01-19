// 03.12.2024 by Matteo Fava

// QUESTO MAIN GENERA I DATI
//  successivamente eseguire 'make histograms' per generare i png degli
//  istogrammi

#include "lib10.2/gplot++.h"
#include "lib10.2/integral_mc.h"
#include "lib10.2/test_integral_mc.h"
#include "lib10.2/test_random.h"
#include <cmath>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// x*sin(x)
double f(double x);

int main() {
  test_random();
  test_integrals_mc();

  // variabili
  IntegralMC *m;
  ofstream out;
  int M = 10000; // 10k iterazioni
  int cases[6] = {100, 500, 1000, 5000, 10000, 50000};
  auto file_name = format("");
  auto name = "";

  // per i cases calcola M volte l'integrale
  for (int k{}; k < 2; k++) {
    // PRIMA ITERAZIONE = MEAN
    if (k == 0) {
      m = new MC_mean{1};
      name = "MEAN";
      // SECONDA ITERAZIONE = HIT OR MISS
    } else {
      m = new MC_hit_miss{1};
      name = "HIT_MISS";
    }
    cout << endl << name << ":\n";
    for (int i{}; i < 6; i++) {
      file_name = format("data/histo_N{}_{}.txt", cases[i], name);
      out.open(file_name);
      for (int j{}; j < M; j++) {
        out << m->integrate(f, 0, M_PI / 2, cases[i], M_PI / 2 + 0.1) << endl;
      }
      out.close();
      cout << format(" => N={} DONE, created : {}", cases[i], file_name)
           << endl;
    }
    delete m;
  }

  cout << "\n => All files generated: type 'make histo' to generate the "
          "png(s)\n";

  return 0;
}

double f(double x) { return x * sin(x); }