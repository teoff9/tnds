//22.10.24 by Matteo Fava

#include "point.h"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
using  namespace std;

//Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Error using program:" << argv[0]  << " x y z\n";
        exit(-1);
    }

    double x{stod(argv[1])};
    double y{stod(argv[2])};
    double z{stod(argv[3])};

    Point3D p{x,y,z};

    assert(is_close(x, p.get_x()));
    assert(is_close(y, p.get_y()));
    assert(is_close(z, p.get_z()));
    Point3D zero{0.0,0.0,0.0};
    assert(is_close(p.get_r(), p.distance_from(zero)));
    assert(is_close(p.get_rho() * p.get_rho(), p.get_x()*p.get_x() + p.get_y() * p.get_y()));
    assert(is_close(p.get_phi(), atan2(p.get_y(), p.get_x())));
    assert(is_close(p.get_theta(), acos(p.get_z() / p.get_r())));


    return 0;
}