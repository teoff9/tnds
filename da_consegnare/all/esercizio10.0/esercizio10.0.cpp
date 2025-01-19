// 26.11.2024 by Matteo Fava

#include "lib10.0/gplot++.h"
#include "lib10.0/random.h"
#include "lib10.0/test_random.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // tests
  test_random();

  // Variable
  vector<double> v(10000);
  Gnuplot plt;
  RandomGen gen{1};
  const int n_bins{100};
  plt.redirect_to_png("distributions.png");
  plt.multiplot(2, 2, "Distribuzioni");

  // Uniform
  for (int i{0}; i < 10000; i++) {
    v[i] = gen.unif(5, 10);
  }
  plt.histogram(v, n_bins);
  plt.set_title("Uniform (5,10)");
  plt.set_xrange(4, 11);
  plt.set_yrange(0, NAN);
  plt.show();

  // Exponential
  for (int i{0}; i < 10000; i++) {
    v[i] = gen.expo(5);
  }
  plt.histogram(v, n_bins);
  plt.set_title("Exponential 5");
  plt.set_yrange(0, NAN);
  plt.set_xrange(-NAN, NAN);
  plt.show();

  // Gaussian Box-Muller
  for (int i{0}; i < 10000; i++) {
    v[i] = gen.gauss(0, 1);
  }
  plt.histogram(v, n_bins);
  plt.set_title("Gaussian Box-Muller m=0,s=1");
  plt.set_yrange(0, NAN);
  plt.set_xrange(-10, 10);
  plt.show();

  // Gaussian aer
  for (int i{0}; i < 10000; i++) {
    v[i] = gen.gauss_aer(0, 1);
  }
  plt.histogram(v, n_bins);
  plt.set_title("Gaussian A&R m=0,s=1");
  plt.set_yrange(0, NAN);
  plt.set_xrange(-10, 10);
  plt.show();

  cout << "Created \"distributions.png\"\n";

  return 0;
}