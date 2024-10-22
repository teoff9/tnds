//22.10.24 by Matteo Fava

#include "lib5.1/particle.h"
#include "lib5.1/electron.h"
#include <iostream>
#include <cstdlib>
#include <format>
#include <cmath>
using  namespace std;

//Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}

int main(int argc, char* argv[]) {
    double c{1.6e-19};
    double m{1};

    Particle p{m,c};
    cout << format("Particle mass and charge: {} {}\n", p.get_mass(), p.get_charge());

    p.print();
    cout << "\n";

    Electron *e = new Electron{};
    e->print();
    cout << "\n";
    cout << e->get_charge() << endl;

    Particle z{*e};

    


    return 0;
}