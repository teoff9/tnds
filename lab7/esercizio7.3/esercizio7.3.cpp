//23.12.24 by Matteo Fava

#include "lib7.3/gplot++.h"
#include "lib7.3/integral.h"
#include "lib7.3/integral_tests.h"
#include <vector>
#include <iostream>
#include <numbers>
using namespace std;

double gaussian(double x);

const double m = 0;
const double sigma = 1;

int main() {
    //test
    test_all_integrals();

    //variabili
    Trapezoid tr;
    double t_max{5};
    double n{100};
    Gnuplot plt;
    double t{}, a{}, b{};
    plt.redirect_to_png("percent.png");
    vector<double> p;
    vector<double> ts;

    for (int i{}; i<=n; i++) {
        t = (double)i*(t_max)/n;
        a = m - t*sigma;
        b = m + t*sigma;
        ts.push_back(t);
        p.push_back(tr.integrate_prec(a, b, 0.0001, gaussian));
    }
    plt.plot(ts, p, "", Gnuplot::LineStyle::LINES);
    plt.show();

}

double gaussian(double x) {
    return pow(numbers::e, -pow(x-m, 2)/(2*sigma*sigma))/sqrt(2*numbers::pi*sigma*sigma);
}