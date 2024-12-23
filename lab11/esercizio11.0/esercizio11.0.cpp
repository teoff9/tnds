// 10.12.24 by Matteo Fava

#include "lib11.0/experiments.h"
#include "lib11.0/gplot++.h"
#include "lib11.0/test_random.h"
#include "lib11.0/test_stats.h"
#include <cassert>
#include <format>
#include <iostream>
#include <vector>
using namespace std;

double corr(vector<double> &x, vector<double> &y);

template <typename T>
inline vector<T> operator*(const vector<T> &a, const vector<T> &b) {
  vector<T> result(ssize(a));
  assert(a.size() == b.size());
  for (int i = 0; i < (int)a.size(); i++) {
    result[i] = a[i] * b[i];
  }
  return result;
}

int main() {
  test_random();
  test_statistical_functions();

  // Variabili
  Prism p{1};
  int N = 10000;
  Gnuplot plt;
  vector<double> th0(N), th1(N), th2(N), dm1(N), dm2(N), n1(N), n2(N), A(N),
      B(N);

  // Esegui N volte l'esperimento e salva i dati
  for (int i{}; i < N; i++) {
    p.exec();
    p.analyze();
    th0[i] = p.get_th0_m() - p.get_th0_i();
    th1[i] = p.get_th1_m() - p.get_th1_i();
    th2[i] = p.get_th2_m() - p.get_th2_i();
    dm1[i] = p.get_dm1_m() - p.get_dm1_i();
    dm2[i] = p.get_dm2_m() - p.get_dm2_i();
    n1[i] = p.get_n1_m() - p.get_n1_i();
    n2[i] = p.get_n2_m() - p.get_n2_i();
    A[i] = p.get_A_m() - p.get_A_i();
    B[i] = p.get_B_m() - p.get_B_i();
  }

  // Setup gnuplot
  plt.redirect_to_png("histograms.png", "2400,1600");
  plt.multiplot(4, 3);
  int nbins = 100;

  // Theta 0
  plt.histogram(th0, nbins, "Distribuzione di theta_0");
  plt.show();
  cout << format("\n\nTheta0 medio: {:.4f} +- {:.4f}\n",
                 average(th0) + p.get_th0_i(), std_dev(th0, 1));

  // Theta 1
  plt.histogram(th1, nbins, "Distribuzione di theta_1");
  plt.show();
  cout << format("Theta1 medio: {:.4f} +- {:.4f}\n",
                 average(th1) + p.get_th1_i(), std_dev(th1, 1));

  // Theta 2
  plt.histogram(th2, nbins, "Distribuzione di theta_2");
  plt.show();
  cout << format("Theta2 medio: {:.4f} +- {:.4f}\n\n",
                 average(th2) + p.get_th2_i(), std_dev(th2, 1));

  // Dm1
  plt.histogram(dm1, nbins, "Distribuzione di dm1");
  plt.show();
  cout << format("Dm1 medio: {:.4f} +- {:.4f}\n", average(dm1) + p.get_dm1_i(),
                 std_dev(dm1, 1));

  // Dm2
  plt.histogram(dm2, nbins, "Distribuzione di dm2");
  plt.show();
  cout << format("Dm2 medio: {:.4f} +- {:.4f}\n", average(dm2) + p.get_dm2_i(),
                 std_dev(dm2, 1));

  // Scatter dm1 dm2
  plt.plot(dm1, dm2, "Residui 2D", Gnuplot::LineStyle::DOTS);
  plt.show();
  cout << format("Correlazione: {:.4f}%\n\n", corr(dm1, dm2));

  // N1
  plt.histogram(n1, nbins, "Distribuzione di n1");
  plt.show();
  cout << format("n1 medio: {:.4f} +- {:.4f}\n", average(n1) + p.get_n1_i(),
                 std_dev(n1, 1));

  // N2
  plt.histogram(n2, nbins, "Distribuzione di n2");
  plt.show();
  cout << format("n2 medio: {:.4f} +- {:.4f}\n", average(n2) + p.get_n2_i(),
                 std_dev(n2, 1));

  // Scatter n1 n2
  plt.plot(n1, n2, "Residui n1 n2", Gnuplot::LineStyle::DOTS);
  plt.show();
  cout << format("Correlazione: {:.4f}%\n\n", corr(n1, n2));

  // A
  plt.histogram(A, nbins, "Distribuzione di A");
  plt.show();
  cout << format("A medio: {:.5f} +- {:.5f}\n", average(A) + p.get_A_i(),
                 std_dev(A, 1));

  // B
  plt.histogram(B, nbins, "Distribuzione di B");
  plt.show();
  cout << format("B medio: {:.0f} +- {:.0f}\n", average(B) + p.get_B_i(),
                 std_dev(B, 1));

  // Scatter A B
  plt.plot(A, B, "Residui A B", Gnuplot::LineStyle::DOTS);
  plt.show();
  cout << format("Correlazione: {:.0f}%\n\n", corr(A, B));

  cout << " => Created 'histograms.png'\n";
  return 0;
}

double corr(vector<double> &x, vector<double> &y) {
  vector<double> xy = x * y;
  return 100. * (average(xy) - average(x) * average(y)) /
         (std_dev(x, 1) * std_dev(y, 1));
}