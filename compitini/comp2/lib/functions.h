//15.01.24 by Matteo Fava

#pragma once

#include "random.h"
#include "stats.h"
#include "geom.h"
#include "vect_function.h"
#include "diff_eq.h"
#include "gplot++.h"
#include <iostream>
#include <array>
#include <vector>
using namespace std;


/*
Funzione che prese delle variabili calcoli N volte fino a final_t con passo di integrazione h.
Ogni v e' generata come v0 + un random gaussiano con sigma_v. Restituisce la deviazione
standard del vettore delle posizioni finali. Il valore x e' aggiornato per ref
 */
double calc_up_to(RandomGen gen, OscSmorzato osc, double t0, double final_t, array<double,2> &x, double h, double N, double sigma_v){
    vector<double> final_pos(N);
    double t{t0};
    RK4<2> rk;
    array<double, 2> vv{0.,0.}, x0{x};

    for (int n{}; n<N; n++) {
        vv[1] = gen.gauss(0, sigma_v);
        x = x0+vv;
        t = 0;
        while(t<final_t-h){
            x = rk.step(t, h, x, osc);
            t += h;
        }
        double h_adj{final_t-t}; //Calcola h corretto per non superare valore
        x = rk.step(t, h_adj, x, osc); //Compi l'ultimo passo di integrazione
        final_pos.push_back(x[0]);
    }
    return std_dev(final_pos, 1);
}
