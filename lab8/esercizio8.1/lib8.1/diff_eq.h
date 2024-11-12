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