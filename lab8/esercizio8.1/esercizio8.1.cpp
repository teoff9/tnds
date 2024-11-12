//12.11.24 by Matteo Fava

#include "lib8.1/test_geom.h"
#include "lib8.1/test_diff_eq.h"
#include "lib8.1/gplot++.h"
#include <ostream>
#include <vector>
using namespace std;

int main() {
    //tests
    test_array_operations();
    test_euler();

    //PARTE 1
    //plotta la soluzione per i primi 70s con passo di integrazione h = 1e-3
    //confrontandola con la soluzione
    Gnuplot plt;
    Euler<2> solver;
    OscillatoreArmonico osc{1.0};
    double h{0.1};
    array<double, 2> x{0., 1.};
    vector<double> t{};
    vector<double> y{};
    vector<double> y_euler{};
    //Seno con step ridotti
    for (int i = 0; i < (int)70/h; i++) {
            t.push_back(i*h);
            y.push_back(sin(i*h));
            x = solver.step(i*h, h, x, osc);
            y_euler.push_back(x[0]);
    }
    plt.plot(t, y, "Sine Function", Gnuplot::LineStyle::LINES);
    plt.plot(t, y_euler, "Euler Solution", Gnuplot::LineStyle::LINESPOINTS);
    // Save the plot to a PNG file and display it
    plt.redirect_to_png("real_vs_euler_plot.png");
    plt.show();
    plt.reset();

    //PARTE 2
    //Confronta errore nella posizione 70 con diversi passi di integrazione
    double real_y{sin(70.0)};
    vector<double> yh;
    vector<double> xh;
    for (int i = 0; i < 100; i++) {
        h = 10 / (round(pow(10, (double)2 + 0.02*i)));
        x = {0., 1.};
        for (int t = 0; t<(int)70/h; t+=1){
            x = solver.step((double)t*h, h, x, osc);
        }
        xh.push_back(h);
        yh.push_back(abs(x[0]-real_y));
    }
    plt.plot(xh, yh, "Error from h");
    plt.redirect_to_png("error_h_difference.png");
    plt.set_logscale(Gnuplot::AxisScale::LOGXY);
    plt.set_xlabel("h");
    plt.set_ylabel("Error");
    plt.show();

    //PRINT
    cout<< "Generated: \"real_vs_euler_plot.png\" and \"error_h_difference.png\"\n";



    return 0;
}

