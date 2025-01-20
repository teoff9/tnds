//20/01.24 by Matteo Fava
//Esame 4

#include "lib/bisection_tests.h"
#include "lib/integral_tests.h"
#include "lib/functions.h"
#include <iostream>
#include <format>
#include <cmath>
using namespace std;

int main() {
    //tests
    test_trapezoid();
    test_zeroes();

    //variabili
    double d{100e-6}, L{1};
    double lambda{500e-9};
    double zero{};

    //PARTE 1
    cout << "\nPARTE 1\n";
    graph(-0.1, 0.1, L, lambda, "500nm.png", 1e-4, 0.00001, d, false, zero);

    //PARTE 2
    cout << "\nPARTE 2\n";
    double real_z{ find_real_zero(zero-0.01, zero+0.01, 1e-6, 100, lambda, L, d) };
    cout << format("lambda = {} min|x| t.c. A(x)=0 : {:.6}\n", lambda, real_z);

    //PARTE 3
    cout << "\nPARTE 3\n";
    double lambdas[2] = {400e-9, 450e-9};
    for (int i{}; i<2; i++) {
        lambda = lambdas[i];
        graph(-0.1, 0.1, L, lambda, format("{}nm.png", lambda*1e9), 1e-4, 0.00001, d, false, zero);
        double real_z{ find_real_zero(zero-0.01, zero+0.01, 1e-6, 100, lambda, L, d) };
        cout << format("lambda = {} min|x| t.c. A(x)=0 : {:.6}\n", lambda, real_z);
    }
    



    return 0;
}