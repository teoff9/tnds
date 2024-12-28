//28.12.24 by Matteo Fava

#include "lib10.3/gplot++.h"
#include "lib10.3/integral_mc.h"
#include "lib10.3/test_integral_mc.h"
#include "lib10.3/test_random.h"
#include <cmath>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

double f(array<double, 2> x) {
    return 5/(x[0]*x[0])*cos(4*x[1])*sin(7*x[0])+10;
}

int main() {
    test_mc_mean();
    test_random();

    MC_mean_multi<2> i{1};
    array<double, 2> inf{1,1};
    array<double, 2> sup{2,2};
    int N{100000};

    cout << i.integrate(f, inf, sup, N) << endl;

    return 0;
}