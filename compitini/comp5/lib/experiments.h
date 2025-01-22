// 10.12.24 by Matteo Fava

#pragma once
#include "random.h"
#include <cmath>
#include <iostream>
using namespace std;

//dati iniziali
double const _V0{12}, _V1{3}, _R{1e5}, _C{2e-6}, err_p{0.03};

//formula per calcolare C
double calc_C(double dt, double R, double V0, double V1) {
  return dt / ( R*log(V0/V1));
}

//formula per calcolare dt
double calc_dt(double C, double R, double V0, double V1) {
  return C*R*log(V0/V1);
}


//Esperimento Capacita' circuito RC
class Capacity {
  public:
    Capacity(unsigned int seed);
    void exec(); //esegui misurazioni
    void analyze(); //esegui analisi dati
    //metodi per accedere ai dati
    double get_C_m() const {return C_m;};
    void set_sigma_dt(double new_s_dt) {sigma_dt = new_s_dt;};
    void set_sigma_R(double new_s_R) {sigma_R = new_s_R;};
    void set_sigma_V0(double new_s_V0) {sigma_V0 = new_s_V0;};
    void set_sigma_V1(double new_s_V1) {sigma_V1 = new_s_V1;};
    double get_dt_i() const {return dt_i;};
    double get_V0_i() const {return V0_i;};
    double get_V1_i() const {return V1_i;};
    double get_R_i() const {return R_i;};

  private:
    RandomGen gen;
    double dt_i, dt_m, sigma_dt;
    double V0_i, V0_m, sigma_V0;
    double V1_i, V1_m, sigma_V1;
    double R_i, R_m, sigma_R;
    double C_i, C_m, sigma_C;
};

Capacity::Capacity(unsigned int seed): gen{seed}, V0_i{_V0}, V1_i{_V1}, R_i{_R}, C_i{_C} {
  //calcola tempo
  dt_i = calc_dt(C_i, R_i, V0_i, V1_i);

  //assegna incertezze (inutile ma comodo)
  sigma_dt = err_p * dt_i;
  sigma_V0 = err_p * V0_i;
  sigma_V1 = err_p * V1_i;
  sigma_R = err_p * R_i;
  sigma_C = err_p * C_i;
}

//esegui misure esperimento
void Capacity::exec() {
  //esegui misurazioni
  dt_m = gen.gauss(dt_i, sigma_dt);
  V0_m = gen.gauss(V0_i, sigma_V0);
  V1_m = gen.gauss(V1_i, sigma_V1);
  R_m = gen.gauss(R_i, sigma_R);
}

//esegui analisi dati
void Capacity::analyze() {
  C_m = calc_C(dt_m, R_m, V0_m, V1_m);
}