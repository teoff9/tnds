//29.12.24 by Matteo Fava

#include "lib11.1/experiments.h"
#include "lib11.1/gplot++.h"
#include "lib11.1/test_random.h"
#include "lib11.1/test_stats.h"
#include <cassert>
#include <format>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//parametri
double const rho = 2700;
double const rho0 = 1250;
double const g = 9.81;
double const n = 0.83;
double const x0 = 0.2;
double const x1 = 0.6;
double const R2 = 0.005;
double const R1 = 0.01;
double const sigma_t = 0.01;
double const sigma_x = 0.001;
double const sigma_r = 0.0001;
int const N = 1000;
unsigned int const seed = 1;

void print_n(vector<double> ns, double r, Viscos &v) {
    cout << format("R = {}, st = {}, sx = {}, sR = {} => n = {} , std =  {}\n", r, v.get_sigma_t(), v.get_sigma_x(), v.get_sigma_r(), average(ns), std_dev(ns, 1));
}

void exec_exp(vector<double> &ns, Viscos &v) {
    for (int i{}; i<N; i++) {
            v.exec();
            v.analyze();
            ns.push_back( v.get_n_m() );
        }
}

int main() {
    test_random();
    test_statistical_functions();
    
    //variabili
    double R[2] = {R1, R2};
    Viscos v{seed, rho, rho0, g, n, R1, x0, x1, sigma_t, sigma_x, sigma_r };
    Gnuplot plt;
    vector<double> ns;
    int n_bins = 75;

    //crea istogramma con R1 e R2
    plt.redirect_to_png("histo.png", "1600,900");
    plt.multiplot(2,1);
    for (double r : R) {
        v.set_R(r);
        exec_exp(ns, v);
        print_n(ns, r, v);
        if (r == R1) plt.histogram(ns, n_bins, "n con 0.01");
        else plt.histogram(ns, n_bins, "n con 0.005");
        plt.show();
        ns.clear();
    }
    cout << "Created 'histo.png'\n";

    //stima degli errori
    for (double r : R) {
        v.set_R(r);

        //sigma R
        v.set_sigma_r(sigma_r);
        v.set_sigma_t(0);
        v.set_sigma_x(0);
        exec_exp(ns, v);
        print_n(ns, r, v);
        ns.clear();

        //sigma t
        v.set_sigma_r(0);
        v.set_sigma_t(sigma_t);
        v.set_sigma_x(0);
        exec_exp(ns, v);
        print_n(ns, r, v);
        ns.clear();

        //sigma x
        v.set_sigma_r(0);
        v.set_sigma_t(0);
        v.set_sigma_x(sigma_x);
        exec_exp(ns, v);
        print_n(ns, r, v);
        ns.clear();
    }

    return 0;
}