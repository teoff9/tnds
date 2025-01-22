//23/01.24 by Matteo Fava

#include "lib/functions.h"
#include "lib/gplot++.h"
#include "lib/test_random.h"
#include "lib/test_stats.h"
#include "lib/experiments.h"
#include <iostream>
#include <format>
#include <cmath>
using namespace std;

int main() {
    //tests
    test_random();
    test_statistical_functions();

    //variabili
    Capacity cp{1};
    int N_exp{1000};
    double initial_p{0.02}, final_p{0.07};
    double steps{50};
    double m{}, q{};

    //PARTE 1
    cout << "\nPARTE 1\n";
    double sigma_C{};
    double C{exec_exp(N_exp, cp, sigma_C, true, "histo_C_3.png", 100, false)};
    cout << format("Con incertezze del 3% ({} volte): C= {:.5} +- {:.5} | err_per = {:.3}%\n", N_exp, C, sigma_C, 100*sigma_C/C );

    //PARTE 2
    cout << "\nPARTE 2\n";
    int max_sigma{stima_err(N_exp, cp)};
    cout << format("Sembra influire maggiormente: ");
    determina_err(max_sigma);

    //PARTE 3
    cout << "\nPARTE 3\n";
    cp.set_sigma_dt(err_p*cp.get_dt_i());
    cp.set_sigma_R(err_p*cp.get_R_i());
    graph(N_exp*100, cp, initial_p, final_p, steps, m, q);

    //PARTE 4
    cout << "\nPARTE 3\n";
    cout << format("Parametri retta err=m*x+q : m = {:.3} | q = {:.3}\n", m, q);
    cout << format("Per ottenere incertezza su C {:.2}% => x = {:.3}%\n", final_p*100, 100*(final_p-q)/m);


    return 0;
}