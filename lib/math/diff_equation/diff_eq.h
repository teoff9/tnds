//12.11.24 by Matteo Fava
//Differential Equations

#pragma once
#include <array>
#include "geom.h"
#include "vect_function.h"
using namespace std;

//FUNZIONE DIFFERENZIALE BASE
template <size_t n> class DiffEquation {
    public:
        virtual array<double, n> step(double, double, array<double, n>&, VectFunction<n>&) const = 0;
};

//EULERO
template <size_t n> class Euler: public DiffEquation<n> {
    public:
        virtual array<double,n> step(double t, double h, array<double, n>&x, VectFunction<n> &f) const override {
            return x + h*f.eval(t,x);
        }
};

//RUNGE KUTTA 4
template <size_t n> class RK4: public DiffEquation<n> {
    public:
        virtual array<double,n> step(double t, double h, array<double, n> &x, VectFunction<n> &f) const override {
            auto k1 = f.eval(t,x);
            auto k2 = f.eval(t + h/2., x + k1*h/2.);
            auto k3 = f.eval(t + h/2., x + k2*h/2.);
            auto k4 = f.eval(t + h, x + k3*h );
            return x + h*( k1 + 2.0*k2 + 2.0*k3 + k4 )/6.0;
        }
};