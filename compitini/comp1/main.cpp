//13.01.24 by Matteo Fava
// AppelloTNDS_1.pdf

#include "lib/integral/integral_tests.h"
#include "lib/integral_mc/test_integral_mc.h"
#include "lib/random/test_random.h"
#include "lib/stats/test_stats.h"
#include "lib/gplot++.h"
#include "lib/functions.h"
#include <iostream>
#include <cmath>
#include <format>
using namespace std;


int main() {
    test_all_integrals();
    test_integrals_mc();
    test_random();
    test_statistical_functions();

    //Variabili
    Gnuplot plt, ppt, nnn;
    double a{0}, b{sqrt(numbers::e)};
    double true_v{3.*numbers::e*numbers::e/16.};
    double k1{}, k2{};

    //Parte 1
    cout << "Part 1\n";
    MidPoint pt;
    calc_errors(1, plt, pt, a, b, true_v, k1, k2, f);

    //Parte 2
    cout << "\nPart 2\n";
    cout << format("err = ({})*h^({})\n", k1, k2);

    //Parte 3
    cout << "\nPart 3\n";
    MidRight tp;
    calc_errors(3, ppt, tp, a, b, true_v, k1, k2, f);

    //Parte 4
    cout << "\nPart 4\n";
    cout << format("err = ({})*h^({})\n", k1, k2);

    //Parte 5
    int M{1000};
    int N{16};
    MC_mean mean{1};
    vector<double> v(M);
    for (int i{}; i<M; i++) {
        v[i] = mean.integrate(f, a, b, N, 0);
    }
    cout << format("\nParte 5\nValore integrale : {}\nErrore : {}\n", average(v), abs(average(v)-true_v));

    //Parte 6
    double err_mid{abs(true_v - pt.integrate(a, b, 16, f))};
    int N_{(int) round(varianza(v)*N/err_mid/err_mid) };
    cout << format("\nParte 6\nSono necessari {} pts per avere integrale con precisione {}.\n", N_, err_mid);
    double result{mean.integrate(f, a, b, N_, 0)};
    cout << format("Infatti -> {} con err {}\n", result, abs(result-true_v));

    //Parte 7
    cout << "\nParte 7\n";
    cout << "Proverei ad impiegare il metodo midpoint perche' il midright divergerebbe!!\n";
    calc_errors(7, nnn, pt, 0, 2, numbers::pi/2., k1, k2, g_);
    cout << format("err = ({})*h^({})\n", k1, k2);
    




    return 0;
}