//12.11.24 by Matteo Fava
//Differential Equations

#pragma once
#include <array>
#include "geom.h"
#include "vect_function.h"
#include <iostream>
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
        //ATTENZIONE: funziona con sistemi 1d (n=2), modificare all'occorrenza
        array<double, n> evolve_with_prec(double initial_t, double final_t, double prec, array<double, n> &x, VectFunction<n> &f) const {
            double t_m{(final_t-initial_t)/2.0}; //tempo medio
            int N{1000};
            double h{};
            double xi[2];
            double t{};
            array<double, n> x_tmp;
            for (int i{}; i<2; i++) {
                N *= (i+1); //inizialmente N poi 2N
                h = (t_m/2.0)/N; //arriviamo fino al tempo medio con passo relativo ad N
                x_tmp = x;
                t = 0.0;
                for (int j{}; j < N; j++ ){
                    x_tmp = step(t, h, x_tmp, f);
                    cout << x_tmp[0] << endl;
                    t += h;
                }
                cout << endl << i+1 <<" : " << N << ", " << h << ", " << x_tmp[0] << endl; 
                xi[i] = x_tmp[0];
            }
            h = (t_m/(N/2.0))*pow( 15.*prec/16./abs(xi[0]-xi[1]), 0.25);
            cout << h << endl;

            //calcola
            t = 0;
            while (t < final_t) {
                x_tmp = step(t, h, x_tmp, f);
                t += h;
            }
            
            return x_tmp;
        }
};