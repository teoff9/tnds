//12.11.24 by Matteo Fava

#pragma once

#include "geom.h"
#include <cmath>
#include <array>
using namespace std;

const double g = 9.81;


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


//PENDOLO 1 DIMENSIONALE
// theta" = -g/l sin(theta)
class Pendulum : public VectFunction<2> {
    public:
        Pendulum(double l_) : l{l_} {};
        virtual array<double, 2> eval(double t, const array<double, 2> &x) const override {
            array<double, 2> result{x[1], -g/l*sin(x[0])};
            return result;
        }
    
    private:
        double l;
};

//OSCILLATORE ARMONICO FORZATO 2D
// x" = -w0^2x - ax' + a0sin(wt)
class OscForzato : public VectFunction<2> {
    public:
        OscForzato(double w0_, double a_, double a0_, double w_) : w0{w0_}, a{a_}, a0{a0_}, w{w_} {};
        virtual array<double, 2> eval(double t, const array<double, 2> &x) const override {
            array<double, 2> result{x[1], -w0*w0*x[0] - a*x[1] + a0*sin(w*t)};
            return result;
        }
    
    private:
        double w0, a, a0, w;
};