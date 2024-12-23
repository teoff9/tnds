// 23.12.24 by Matteo Fava

#include "lib5.5/field.h"
#include "lib5.5/gplot++.h"
#include "lib5.5/mat_point.h"
#include "lib5.5/particle.h"
#include "lib5.5/physics.h"
#include "lib5.5/point.h"
#include "lib5.5/tests.h"
#include <format>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // test
  test_coordinates();

  // variabili
  double earth_mass{5.9726e24};
  double density{3000}; // kg/m^{3}
  double mountain_mass{4. * pi * pow(1000, 3) / 3. * density};
  int n_montagne{100};     // numero di montagne
  double r_montagne{1000}; // raggio montagne
  double step{10 * 1000};  // passi da 10km
  double R{6378 * 1000};   // raggio terra
  double d{250 * 1000};    // distanza satellite dal suolo
  vector<MaterialPoint> world;
  double x{}, y{}, z{};
  Gnuplot plt;
  plt.redirect_to_png("g.png");

  // genera il mondo
  MaterialPoint earth{earth_mass, 0.0, 0., 0., 0.}; // earth in 0,0,0

  // genera la catena montuosa
  double r{R + r_montagne};
  double theta{pi/2};
  double d_theta{r_montagne/(2*pi*R)};
  for (int i{}; i < n_montagne; i++) {
    theta += d_theta;
    x = r * cos(theta);
    y = r * sin(theta);
    MaterialPoint mountain{mountain_mass, 0., x, y, z};
    world.push_back(mountain);
  }


  // calcola g
  r = R + d;
  int n_steps{(int)round(2 * pi * (r) / step)};
  theta = 0;
  double g{};
  vector<double> g1;
  vector<double> g2;
  vector<double> ang;
  for (int i{}; i < n_steps; i++) {
    theta = (2 * pi * i) / n_steps;
    // aggiorna la pos
    x = r * cos(theta);
    y = r * sin(theta);
    
    // salva angolo
    ang.push_back(theta);
    
    // calcola g solo da terra
    g1.push_back(acc_radiale(earth, Point3D{x, y, z}));
    
    // calcola da terra + altri corpi
    Point3D pp{x,y,z};
    VectorField tmp{acc(earth, pp)};
    for (int j{}; j < n_montagne; j++) {
        tmp += acc(world[j], pp);
    }
    g2.push_back((tmp.module() - g1[i]) / g1[i]);
  }

  //plot
  plt.plot(ang, g2, "g earth + mountains", Gnuplot::LineStyle::LINES);
  plt.set_logscale(Gnuplot::AxisScale::LOGXY);
  plt.show();
}
