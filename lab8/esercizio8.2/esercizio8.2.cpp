//19.11.24 by Matteo Fava

#include "lib8.2/test_geom.h"
#include "lib8.2/test_diff_eq.h"
#include "lib8.2/gplot++.h"
#include <ostream>
#include <vector>
using namespace std;

int main() {
    test_array_operations();
    test_euler();
    test_rk4();

    //PARTE 1
    //plotta la soluzione per i primi 70s con passo di integrazione h = 1e-1
    //confrontando rk4 con eulero
    Gnuplot plt;
    Euler<2> eul;
    RK4<2> rk;
    OscillatoreArmonico osc{1.0};
    double h{0.1};
    array<double, 2> x_eul{0., 1.};
    array<double, 2> x_rk{0., 1.};
    vector<double> t{};
    vector<double> y_rk{};
    vector<double> y_euler{};
    //Seno con step ridotti
    for (int i = 0; i < (int)70/h; i++) {
            t.push_back(i*h);
            x_eul = eul.step(i*h, h, x_eul, osc);
            x_rk = rk.step(i*h, h, x_rk, osc);
            y_euler.push_back(x_eul[0]);
            y_rk.push_back(x_rk[0]);
    }
    plt.plot(t, y_rk, "RK4", Gnuplot::LineStyle::LINES);
    plt.plot(t, y_euler, "Euler Solution", Gnuplot::LineStyle::LINESPOINTS);
    plt.set_title("RK4 vs Eulero con h=0.1s");
    plt.set_xlabel("t[s]");
    plt.set_ylabel("x[m]");
    plt.redirect_to_png("rk4_vs_euler_plot.png");
    plt.show();
    plt.reset();

    //PARTE 2
    //Confronta errore nella posizione 70 con diversi passi di integrazione RK4 vs Euler
    double real_y{sin(70.0)};
    vector<double> yh_eul;
    vector<double> yh_rk;
    vector<double> xh;
    for (int i = 0; i < 100; i++) {
        h = 10.0 / (round(pow(10, (double)2 + 0.02*i)));
        double n_steps{round(70.0/h)};
        x_eul = {0., 1.};
        x_rk = {0., 1.};
        for (int t = 0; t<n_steps+1; t+=1){
            x_eul = eul.step((double)t*h, h, x_eul, osc);
            x_rk = rk.step((double)t*h, h, x_rk, osc);
        }
        xh.push_back(h);
        yh_eul.push_back(abs(x_eul[0]-real_y));
        yh_rk.push_back(abs(x_rk[0]-real_y));
    }
    plt.plot(xh, yh_eul, "Error Eulero");
    plt.plot(xh, yh_rk, "Error RK4");
    plt.set_title("Error RK4 vs Euler");
    plt.redirect_to_png("err_h_difference_rk_vs_euler.png");
    plt.set_logscale(Gnuplot::AxisScale::LOGXY);
    plt.set_xlabel("h[s]");
    plt.set_ylabel("Error[m]");
    plt.show();

    //PRINT
    cout<< "Generated: \"rk4_vs_euler_plot.png\" and \"err_h_difference_rk_vs_euler.png\"\n";

    return 0;
}