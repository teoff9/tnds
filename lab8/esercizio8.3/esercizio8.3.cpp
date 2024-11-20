//19.11.24 by Matteo Fava

#include "lib8.3/diff_eq.h"
#include "lib8.3/geom.h"
#include "lib8.3/gplot++.h"
#include "lib8.3/test_diff_eq.h"
#include "lib8.3/test_geom.h"
#include "lib8.3/vect_function.h"
#include <vector>
using namespace std;

double interp(double x0, double y0, double x1, double y1, double y);

void test_interp();

int main() {
    //tests
    test_array_operations();
    test_rk4();
    test_interp();

    //variabili
    double theta0{0.1};
    double d_theta{0.1};
    double l{1};
    double h{0.01};
    double t{};
    Pendulum p{l};
    RK4<2> rk;
    double v{};
    vector<double> tx, y;
    Gnuplot plt;

    for (int i{(int)(theta0*10)}; i < 31; i += d_theta*10) {
        double theta{i*0.1};
        array<double, 2> x{theta, 0.};
        t = 0.0;
        while (x[1] <= 0.0){
            v = x[1];
            x = rk.step(t, h, x, p);
            t = t+h;
        }
        t = interp( t-h,v, t, x[1], 0.0);
        tx.push_back(theta);
        y.push_back(2.0*t);
    }

    plt.plot(tx, y);
    plt.set_title("Periodo in funzione di theta 0");
    plt.set_xlabel("theta [rad]");
    plt.set_ylabel("T[s]");
    plt.redirect_to_png("periodo.png");
    plt.show();
    cout << "Created periodo.png\n";

    return 0;
}

double interp(double x0, double y0, double x1, double y1, double y) {
    return x0+(x0-x1)/(y0-y1)*(y-y0);
}

void test_interp() {
    double p1x{-0.4};
    double p1y{-0.7};
    double p2x{0.5};
    double p2y{0.8};
    assert(is_close(interp(p1x, p1y, p2x, p2y, 0.3), 0.2));
    cout << "Test passed for interp!\n";
}