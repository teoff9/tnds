//12.11.24 by Matteo Fava

#pragma once

#include "geom.h"
#include <array>
using namespace std;


//FUNZIONE VETTORIALE BASE
template <size_t n> class VectFunction {
    public:
        virtual array<double, n> eval(double, const array<double, n>&) const = 0;
};


//OSCILLATORE ARMONICO 1 DIMENSIONALE
class OscillatoreArmonico : public VectFunction<2> {
    public:
        OscillatoreArmonico(double omega0_) : omega0{omega0_} {};
        virtual array<double, 2> eval(double t, const array<double, 2> &x) const override {
            array<double, 2> result{x[1], -omega0*omega0*x[0]};
            return result;
        }
    
    private:
        double omega0;
};