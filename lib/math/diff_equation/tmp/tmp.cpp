#include "vect_function.h"
#include "geom.h"
#include "diff_eq.h"
#include <iostream>
using namespace std;

int main() {
    OscillatoreArmonico osc{1.0};
    array<double, 2> x = {0., 1.0};
    double prec{0.0001};
    double final_t{10.};
    RK4<2> rk;
    x = rk.evolve_with_prec(0,final_t,prec,x,osc);
    cout << abs(sin(final_t)-x[0]) << endl;

    return 0;
}