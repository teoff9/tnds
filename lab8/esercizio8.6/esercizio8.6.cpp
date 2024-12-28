//28.12.24 by Matteo Fava

#include "lib8.6/diff_eq.h"
#include "lib8.6/geom.h"
#include "lib8.6/gplot++.h"
#include "lib8.6/test_diff_eq.h"
#include "lib8.6/test_geom.h"
#include "lib8.6/vect_function.h"
#include <array>
#include <format>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    test_array_operations();
    test_rk4();

    array<double, 3> B{0,0, 5e-3}; //Tesla
    array<double, 3> E{0,0,-1000}; //V/m
    Lorentz lor{B, E, -1.60217653e-19, 9.1093826e-31};
    RK4<6> rk;
    array<double, 6> x{0,0,0, 8e6, 0,0};
    Gnuplot plt;
    plt.redirect_to_png("xyz.png", "1600,1200");
    plt.multiplot(2,1);
    double lastx{};
    double t{};
    int c{};
    double h{1e-12};
    vector<double> ts, z;
    double ymin, ymax;

    while ( c<2 ) {
        //cout << format("{} {} {} {} {} {}", lor.eval(t, x)[0], lor.eval(t, x)[1], lor.eval(t, x)[2], lor.eval(t, x)[3], lor.eval(t, x)[4], lor.eval(t, x)[5]) << endl;
        x = rk.step(t, h, x, lor);
        plt.add_point(x[0], x[1]);
        z.push_back(x[2]);
        ts.push_back(t);
    
        if (x[0] * lastx < 0){
            c++;
            if (c==1) ymin = x[1];
            else ymax = x[1];
        }
        lastx = x[0];
        t += h;
    }
    plt.set_xrange(-0.01, 0.01);
    plt.set_yrange(0, 0.02);
    plt.plot();
    plt.show();
    plt.plot(ts, z, "t e z", Gnuplot::LineStyle::LINES);
    plt.show();

    cout << "Diametro " << fabs(ymin-ymax) << endl;
    cout << "Created 'xyz.png'\n";

    return 0;
}