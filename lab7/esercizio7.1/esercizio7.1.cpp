//05.11.24 by Matteo Fava 

#include <ostream>
#include <cmath>
#include <vector>
#include <format>
#include <numbers>
#include "lib7.1/integral.h"
#include "lib7.1/tests.h"
using namespace std;

double g(double x) {
    return x*sin(x);
}

int main() {
    test_integral();
    Simpson s;
    double true_value{1};

    vector<int> steps = {10, 50, 100, 500, 1000};
    for (int i = 0; i<ssize(steps); i++) {
        double v{s.integrate(0, numbers::pi/2, steps[i], g)};
        cout << format("Step / Integral / Error : {} | {} | {} \n", steps[i], v, fabs(true_value-v));
    }
    
    return 0;
}