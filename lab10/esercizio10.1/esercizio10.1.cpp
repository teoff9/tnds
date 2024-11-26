//26.11.2024 by Matteo Fava

#include "lib10.1/gplot++.h"
#include "lib10.1/random.h"
#include "lib10.1/test_random.h"
#include "lib10.1/stats.h"
#include <iostream>
#include <vector>
#include <format>
using namespace std;

double gen_sum(int N, RandomGen& rn);

int main() {
    //tests
    test_random();

    //variables
    Gnuplot plt, var;
    RandomGen gen;
    int N_max{12};
    int v_max{14000};
    vector<double> v(v_max);
    int n_bins{100};

    //setup plot(s) 
    plt.redirect_to_png("histograms.png","1280,1024");
    plt.multiplot(3,4, "Verifica Teorema Limite centrale");
    var.redirect_to_png("errors.png");
    var.set_title("Deviazioni standard");
    var.set_xlabel("N");
    var.set_ylabel("Dev. Std");
    var.set_xrange(1,12);
    var.set_yrange(0.2,1.5);

    //calcola serie
    for (int n{1}; n<=N_max; n++) {
        for (int j{}; j<v_max; j++) {
            v[j] = gen_sum(n, gen);
        }
        plt.histogram(v,n_bins, format("N={}", n));
        plt.set_yrange(0, NAN);
        plt.show();
        var.add_point(n, sqrt(varianza(v)));
    }
    var.set_logscale(Gnuplot::AxisScale::LOGXY);
    var.plot("Dev. Std.", Gnuplot::LineStyle::LINESPOINTS);
    var.show();

    cout << "Created \"histograms.png\" and \"errors.png\".png\n";

    return 0;
}

double gen_sum(int N, RandomGen& rn){
    double acc{};
    for (int i{}; i<N; i++) {
        acc += rn.rand();
    }
    return acc;
}