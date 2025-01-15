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
        array<double, n> evolve_with_prec(double initial_t, double final_t, double prec, array<double, n> &x, VectFunction<n> &f, double &wh) const {
            int N{100};
            double h{};
            double xi[2];
            double t{};
            array<double, n> x_0 = x;
            //esegui le due iterazioni
            for (int i{}; i<2; i++) {
                N *= (i+1); //inizialmente N poi 2N
                h = (final_t-initial_t)/N; //arriviamo fino al tempo medio con passo relativo ad N
                x = x_0;
                t = initial_t;
                while(t<final_t-h){
                    x = step(t, h, x, f);
                    t += h;
                }
                h = final_t-t;
                x = step(t, h, x, f);
                xi[i] = x[0];
            }
            //calcola h ottimale
            N = N/2;
            h = ((final_t-initial_t)/N) * pow( 15.0*prec/(16.0* abs(xi[0]-xi[1])) , 0.25);

            wh = h;

            //calcola fino a t tale che non superi t_finale
            t = initial_t;
            x = x_0;
            while (t < final_t-h) {
                x = step(t, h, x, f);
                t += h;
            }
            //compi l'ultimo passo di integrazione
            h = final_t-t;
            x = step(t, h, x, f);
            
            return x;
        }
};