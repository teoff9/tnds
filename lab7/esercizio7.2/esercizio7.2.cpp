//05.11.24 by Matteo Fava 

#include <ostream>
#include <cmath>
#include <vector>
#include <format>
#include <numbers>
#include <cstdlib>
#include "lib7.2/integral.h"
#include "lib7.2/tests.h"
using namespace std;

double g(double x) {
    return x*sin(x);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << format("Wrong input: {} <prec> \n", argv[0]);
    }

    test_integral();
    Trapezoid t;
    double a{0};
    double b{numbers::pi};
    double prec{stod(argv[1])};
    int c = -log10(prec);
    cout << format("Integral of x*sinx in [0, {}] with prec {} is: {:.{}f}\n", b, prec, t.integrate_prec(a,b,prec,g), c);
    
    return 0;
}