//23.01.2024 by Matteo Fava
//Questo file contiene le funzioni create per l'esame

#pragma once

#include "gplot++.h"
#include "experiments.h"
#include "stats.h"
#include <iostream>
#include <format>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
using namespace std;


//funzione per eseguire N volte esperimento, generare grafico
//stampare a video i primi 5 e ultimi 5 valori e restituire media C e per ref sigma
double exec_exp(int N, Capacity &cp, double &sigma_C, bool histo, string file_name, int n_bins, bool debug) {
    vector<double> capacities(N);
    for (int i{}; i<N; i++) {
        cp.exec();
        cp.analyze();
        capacities[i] = cp.get_C_m();
    }
    //media e dev_std
    sigma_C = std_dev(capacities, 1);
    double mean{average(capacities)};

    //debug
    if (debug) {
        int n{5};
        cout << format("Output di debug:\nPRIMI {} valori di C: \n", n);
        for (int j{}; j<n; j++) {
            cout << capacities[j] << endl;
        }
        cout << format("Ultimi {} valori di C\n", n);
        for (int j{N-1}; j>N-n-1; j--) {
            cout << capacities[j] << endl;
        }
    }
    //grafico
    if (histo) {
        Gnuplot plt;
        plt.redirect_to_png(file_name);
        plt.histogram(capacities, n_bins, "Histogramma valori C con sigma 3%");
        plt.show();
        cout << format(" => Created '{}'\n", file_name);
    }

    return mean;
}


//funzione per stimare errore max
// 0=dt, 1=V0, 2=V1, 3=R
int stima_err(int N, Capacity &cp) {
    double sigma_C{}, C{}, prev_s_p{}, s_p{};
    int max_sigma{};
    cout << "Sigma\t\tErr\t\tErr %\n";
    for (int i{}; i<4; i++) {
        if (i==0) { //dt
            cp.set_sigma_V0(0);
            cp.set_sigma_V1(0);
            cp.set_sigma_R(0);
            C=exec_exp(N, cp, sigma_C, false, "", 0, false);
            
            s_p = 100*sigma_C/C;
            
            cout << format("dt\t\t{:.3}\t{:.3}\n", sigma_C,s_p );
            
            if (s_p>prev_s_p) max_sigma=i;
            prev_s_p = s_p;
        } else if (i == 1) { //V0
            cp.set_sigma_dt(0);
            cp.set_sigma_V0(err_p*cp.get_V0_i());
            C=exec_exp(N, cp, sigma_C, false, "", 0, false);
            
            s_p = 100*sigma_C/C;
            
            cout << format("V0\t\t{:.3}\t\t{:.3}\n", sigma_C,s_p );
            
            if (s_p>prev_s_p) max_sigma=i;
            prev_s_p = s_p;
        } else if (i == 2) { //V1
            cp.set_sigma_V0(0);
            cp.set_sigma_V1(err_p*cp.get_V1_i());
            C=exec_exp(N, cp, sigma_C, false, "", 0, false);
            
            s_p = 100*sigma_C/C;
            
            cout << format("V1\t\t{:.3}\t{:.3}\n", sigma_C,s_p );
            
            if (s_p>prev_s_p) max_sigma=i;
            prev_s_p = s_p;
        } else if (i == 3) { //R
            cp.set_sigma_V1(0);
            cp.set_sigma_R(err_p*cp.get_R_i());
            C=exec_exp(N, cp, sigma_C, false, "", 0, false);
            
            s_p = 100*sigma_C/C;
            
            cout << format("R\t\t{:.3}\t{:.3}\n", sigma_C,s_p );
            if (s_p>prev_s_p) max_sigma=i;
            prev_s_p = s_p;
        } 
    }

    return max_sigma;
}

void determina_err(int code) {
    switch (code)
    {
    case 0:
        cout << "dt\n";
        break;
    
    case 1:
        cout << "V0\n";
        break;
    
    case 2:
        cout << "V1\n";
        break;
    
    case 3:
        cout << "R\n";
        break;
    
    default:
        cerr << "Error in punto 2 stima err!\n";
        exit (-1);
        break;
    }
}


//funzione per fare grafico incertezza e determina parametri y = mx+q
void graph(int N, Capacity &cp, double initial_p, double final_p, int steps, double &m, double &q){
    Gnuplot plt;
    plt.redirect_to_png("graph_incertezza.png");
    double p{initial_p};
    double sigma_C{};
    double x1{initial_p}, x2{final_p}, y1{}, y2{}, C{};
    int s{};
    double h{(final_p-initial_p)/steps};
    double y{};

    while ( s < steps) {
        cp.set_sigma_V0(p*cp.get_V0_i());
        cp.set_sigma_V1(p*cp.get_V1_i());
        C=exec_exp(N, cp, sigma_C, false, "", 0, false);
        y = sigma_C/C;
        plt.add_point(p*100, 100*y);
        if (s==0) y1=y; 
        if (s==steps-1) y2=y;
        p += h;
        s ++;
    }

    plt.plot("Andamento incertezza", Gnuplot::LineStyle::LINESPOINTS);
    plt.show();
    cout << " => Created 'graph_incertezza.png'\n";

    //stima parametri come diff primo e ultimo punto
    m = (y2-y1)/(x2-x1);
    q = ((y2-m*x2)+(y1-m*x1))/2;
}