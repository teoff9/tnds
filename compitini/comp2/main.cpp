//15/01.24 by Matteo Fava
//Esame 2

#include "lib/test_diff_eq.h"
#include "lib/random.h"
#include "lib/test_geom.h"
#include "lib/test_stats.h"
#include "lib/test_random.h"
#include "lib/gplot++.h"
#include "lib/functions.h"
#include "lib/diff_eq.h"
#include <iostream>
#include <format>
#include <cmath>
#include <array>
using namespace std;

int main() {
    //tests
    test_array_operations();
    test_random();
    test_rk4();
    test_statistical_functions();

    //Variabili
    double w0{1.15}, a{0.01};
    array<double, 2> x0{1., 0.}, x{x0};
    double final_t{43};
    OscSmorzato osc{w0, a};
    double h{0.05};
    RK4<2> rk;
    RandomGen gen{1};

    //PARTE 1
    cout << "Parte 1\n";
    calc_up_to(gen, osc, 0, final_t, x, h, 1, 0.);
    cout << format("Posizione finale a t=43.0s  con h={}: {}\n", h, x[0]);

    //PARTE 2
    cout << "\nParte 2\n";
    double tmp{x[0]};
    x = x0;
    calc_up_to(gen, osc, 0, final_t, x, h/2., 1, 0.);
    cout << format("Errore a t=43.0s con h={}: {}\n",h,16.*abs( tmp-x[0])/15.);
    x = x0;

    //PARTE 3
    cout << "\nParte 3\n";
    double prec{5e-5}; //50 micro-m
    rk.evolve_with_prec(0, final_t, prec, x, osc, h);
    cout << format("Passo di integrazione necessario per avere err={}  : {}",prec, h);
    cout << "\n";
    x = x0;

    //PARTE 4
    cout << "\nParte 4\n";
    double sigma_v{3e-3}; // 3 mm/s
    int N{10000};
    double err{calc_up_to(gen, osc, 0, final_t, x, h, N, sigma_v)};
    cout << format("Errore introdotto medio (N=10k) : {}\n", err);
    x = x0;

    //PARTE 5
    cout << "\nParte 5\n";
    double sigma_vs[5] = {3, 5,8,12,15}; 
    Gnuplot plt;
    double tmp_{};
    cout << format("sigma_v\t\terr\n");
    for (int j{}; j<5; j++) {
        x = x0;
        tmp = calc_up_to(gen, osc, 0, final_t, x, h, N, 0.001*sigma_vs[j]);
        plt.add_point(sigma_vs[j], tmp);
        cout << format("{}\t{}\n", 0.001*sigma_vs[j], tmp);
    }
    plt.redirect_to_png("err.png");
    plt.plot("", Gnuplot::LineStyle::LINESPOINTS);
    plt.show();
    cout << format("=> Created 'err.png'\n", err);

    return 0;
}