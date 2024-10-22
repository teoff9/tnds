//22.10.24 by Matteo Fava

#include "lib5.3/field.h"
#include "lib5.3/mat_point.h"
#include "lib5.3/particle.h"
#include "lib5.3/point.h"
#include "lib5.3/tests.h"
#include "lib5.3/atom.h"
#include "lib5.3/gplot++.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

//constants
const double d{1.e-10};

int main(int argc, char* argv[]) {
    //test
    test_coordinates();
    test_electric_field();
    
    //input
    if (argc != 4) {
      cout << format("Usage: {} <x> <y> <z>\n", argv[0]);
      exit(-1);
    }

    //init variables
    double x{stod(argv[1])};
    double y{stod(argv[2])};
    double z{stod(argv[3])};
    Point3D pp{x,y,z};
    Electron e_tmp; //tmp
    Proton p_tmp; //tmp
    MaterialPoint e{0.0, 0.0, d/2, e_tmp};
    MaterialPoint p{0.0, 0.0, -d/2, p_tmp};
    Gnuplot plt;
    vector<double> dist;
    vector<double> e_field;

    //Nel punto P inserito da linea di comando
    VectorField v{electric_field(e, pp) + electric_field(p, pp)};
    cout << format("Campo elettrico nel punto ({}, {}, {}) : E = ({}, {}, {}) N/C\n", 
                    x, y, z, v.get_fx(), v.get_fy(), v.get_fz());
    
    //Loop per generare il campo lungo z 
    for (int i{100}; i <= 1000; i+=10) {
      double r = (double) i*d;
      double f = (electric_field(e, Point3D{0,0,r})+electric_field(p, Point3D{0,0,r})).module();
      dist.push_back(r*1e9);
      e_field.push_back(f);
    }

    //Crea grafico con GnuPlot
    plt.redirect_to_png("esercizio5.3.png");
    plt.set_logscale(Gnuplot::AxisScale::LOGXY);
    plt.set_xlabel("Distance [nm]");
    plt.set_ylabel("Electric Field [N/C]");
    plt.plot(dist, e_field);
    plt.show();
    cout << format("Created: esercizio5.3.png \n");


    return 0;
}