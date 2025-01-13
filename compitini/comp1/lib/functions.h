//13.01.24 by Matteo Fava

#pragma once

#include "integral/integral.h"
#include "integral_mc/integral_mc.h"
#include "gplot++.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <format>
using namespace std;

double f(double x) {
    return x*x*x*log(sqrt(numbers::e+x*x));
}

double g_(double x) {
    return 1./sqrt(4-x*x);
}

//Calcola integrale Midpoint, grafico errori con N da 2 a 2^10 in potenze di due
void calc_errors(int part, Gnuplot &plt, Integral& m, double a, double b, double true_v, double &k1, double &k2, function<double(double)> f) {

    vector<double> err;
    int N{1024};

    //stima integrale
    cout << format("Stima integrale N = {} : {}\n", N, m.integrate(a, b, N, f));

    //errori
    cout << "N\t\tErrori:\n";
    double i{};
    for (int j{1}; j<=10; j++){
        N = (int)pow(2, j);
        i = abs(true_v - m.integrate(a, b, N, f));
        plt.add_point(i);
        cout << format("{}\t\t{}\n", N, i);
    }
    //calcola k1, k2
    int n1{2}, n2{1024};
    double e1{abs(true_v - m.integrate(a, b, n1, f))}, 
    e2{abs(true_v - m.integrate(a, b, n2, f))};

    k2 = log(e1/e2)/log(n2/n1);
    k1 = e1 / powf((b-a)/n1, k2);

    //plotta
    plt.plot("Andamento errore midpoint", Gnuplot::LineStyle::LINESPOINTS);
    plt.set_logscale(Gnuplot::AxisScale::LOGXY);
    plt.redirect_to_png(format("errore_{}.png", part));
    plt.show();
    cout << format("=> Created 'errore_{}.png'\n", part);
    plt.reset();
}
