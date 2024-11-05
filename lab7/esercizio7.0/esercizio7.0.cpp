//05.11.24 by Matteo Fava 

#include "lib7.0/gplot++.h"
#include "lib7.0/integral.h"
#include <ostream>
#include <cmath>
#include <vector>
#include <format>
using namespace std;

const double pi = 3.14159265359;

double g(double x) {
    return x*sin(x);
}

int main() {
    MidPoint m;
    double true_value = 1;
    vector<int> steps = {1,10,100,1000,10000};
    for (int i = 0; i<ssize(steps); i++) {
        double integral = m.integrate(0, 0.5*pi, steps[i], g);
        double err = fabs(integral - true_value);
        cout << format("Steps: {}, Integral {}, Err {}\n", steps[i], integral, err);
    }
    

    return 0;
}