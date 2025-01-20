//20.01.24 by Matteo Fava

#pragma once

#include "gplot++.h"
#include "bisection.h"
#include "integral.h"
#include <iostream>
#include <format>
#include <functional>
#include <format>
#include <string>
using namespace std;


void graph(double x0, double x1, double L, double lambda, string file_name, double prec, double h, double d, double debug_zeroes, double& lw_z){
    Gnuplot plt;
    plt.redirect_to_png(file_name);
    Trapezoid tr;
    double x{x0};
    double i{};
    double zero{};
    lw_z = -1./(1e-10);

    while ( x < x1-h) {
        i = tr.integrate_prec(-d/2, d/2, prec, [=](double t){return 1/d*cos( (sqrt(L*L + (x-t)*(x-t))-sqrt(L*L+x*x))/lambda );});
        plt.add_point(x, i);
        if (abs(i)<1e-3 && abs(zero-x)>h) {
            if (debug_zeroes) cout << format("Possible zero ({}): x={}\n", i, x);zero = x;
            if (abs(x)<abs(lw_z)) lw_z = abs(x);
        }
        x += h; 
    }
    h = x1-x;
    i = tr.integrate_prec(-d/2, d/2, prec, [=](double t){return 1/d*cos( (sqrt(L*L + (x-t)*(x-t))-sqrt(L*L+x*x))/lambda );});
    plt.add_point(x1, i);

    plt.plot("A(x)", Gnuplot::LineStyle::LINES);
    plt.set_xlabel("X"); plt.set_ylabel("A(x)");
    plt.show();
    cout << "Possible lowest zero: " << lw_z << endl;
    cout << format(" => Created '{}'\n", file_name);
}


double find_real_zero(double x0, double x1, double prec, int n_max, double lambda, double L, double d) {
    Bisection bs;
    Trapezoid tr;
    auto A = [&](double x){return tr.integrate_prec(-d/2, d/2, prec, [=](double t){return 1/d*cos( (sqrt(L*L + (x-t)*(x-t))-sqrt(L*L+x*x))/lambda );});};
    return bs.find_root(A, x0, x1, prec, n_max);
}