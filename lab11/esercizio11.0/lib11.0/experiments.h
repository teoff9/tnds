// 10.12.24 by Matteo Fava

#pragma once
#include "random.h"
#include <cmath>
#include <iostream>
using namespace std;

// Esperimento Prisma
class Prism {
public:
  Prism(unsigned int seed);
  void exec();    // esegui misure angolari
  void analyze(); // analizza fino a trovare A, B
  double get_alpha() { return alpha; }
  double get_lambda1() { return lambda1; }
  double get_lambda2() { return lambda2; }
  double get_sigma_t() { return sigma_t; }
  double get_A_i() { return A_i; }
  double get_A_m() { return A_m; }
  double get_B_i() { return B_i; }
  double get_B_m() { return B_m; }
  double get_n1_i() { return n1_i; }
  double get_n1_m() { return n1_m; }
  double get_n2_i() { return n2_i; }
  double get_n2_m() { return n2_m; }
  double get_dm1_i() { return dm1_i; }
  double get_dm1_m() { return dm1_m; }
  double get_dm2_i() { return dm2_i; }
  double get_dm2_m() { return dm2_m; }
  double get_th0_i() { return th0_i; }
  double get_th0_m() { return th0_m; }
  double get_th1_i() { return th1_i; }
  double get_th1_m() { return th1_m; }
  double get_th2_i() { return th2_i; }
  double get_th2_m() { return th2_m; }

private:
  RandomGen gen;
  // Fissi
  double alpha, lambda1, lambda2, sigma_t;
  // Input |   Misurato
  double A_i, A_m;
  double B_i, B_m;
  double n1_i, n1_m;
  double n2_i, n2_m;
  double dm1_i, dm1_m;
  double dm2_i, dm2_m;
  double th0_i, th0_m;
  double th1_i, th1_m;
  double th2_i, th2_m;
};

// Init
Prism::Prism(unsigned int seed)
    : gen{seed}, alpha{M_PI / 3.}, lambda1{579.1}, lambda2{404.7},
      sigma_t{0.3e-3}, A_i{2.7}, B_i{60000} {
  n1_i = sqrt(A_i + B_i * pow(lambda1, -2));
  n2_i = sqrt(A_i + B_i * pow(lambda2, -2));
  dm1_i = 2. * asin(n1_i * sin(0.5 * alpha)) - alpha;
  dm2_i = 2. * asin(n2_i * sin(0.5 * alpha)) - alpha;
  th0_i = M_PI / 2.0;
  th1_i = th0_i + dm1_i;
  th2_i = th0_i + dm2_i;
}

// Esegui
void Prism::exec() {
  th0_m = gen.gauss(th0_i, sigma_t);
  th1_m = gen.gauss(th1_i, sigma_t);
  th2_m = gen.gauss(th2_i, sigma_t);
}

// Analizza
void Prism::analyze() {
  dm1_m = th1_m - th0_m;
  dm2_m = th2_m - th0_m;
  n1_m = sin(0.5 * (alpha + dm1_m)) / sin(0.5 * alpha);
  n2_m = sin(0.5 * (alpha + dm2_m)) / sin(0.5 * alpha);
  A_m = (pow(lambda2 * n2_m, 2) - pow(lambda1 * n1_m, 2)) /
        (pow(lambda2, 2) - pow(lambda1, 2));
  B_m = (pow(n2_m, 2) - pow(n1_m, 2)) / (pow(lambda2, -2) - pow(lambda1, -2));
}
