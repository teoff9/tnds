//03.12.24 by Matteo Fava
//Genera gli istogrammi

#include <iostream>
#include <fstream>
#include <vector>
#include <format>
#include <cmath>
#include <string>
#include "lib10.2/stats.h"
#include "lib10.2/gplot++.h"
using namespace std;


int main() {
    ifstream inp;
    int M{10000};
    vector<double> v(M);
    string names[2] = {"MEAN", "HIT_MISS"};
    int cases[6] = {100, 500, 1000, 5000, 10000, 50000};
    vector<double> err[2];
    double k[2];


    //Genera i due istogrammi e riempi il vettore degli errori nel frattempo
    for (int i{}; i<2; i++) {
        //Gnuplot multiplot
        Gnuplot plt;
        plt.redirect_to_png(format("histo_{}.png", names[i]));
        plt.multiplot(3,2);

        for (int j{}; j<6; j++) {
            inp.open(format("data/histo_N{}_{}.txt", cases[j], names[i]));
            //load data
            for (int k{}; k<M; k++) {
                inp >> v[k];
            }
            inp.close();
            //calcola errore
            err[i].push_back(sqrt(varianza(v)));

            //aggiungi histo
            plt.histogram(v, 20, format("N={}", cases[j]));
            plt.set_xrange(0.8,1.2);
            plt.show();

            //calcola errore se N = 50000
            if (j == 5) {
                k[i] = sqrt(100*varianza(v));
            }
        }
    }

    //Genera il grafico degli errori
    Gnuplot plt;
    plt.redirect_to_png("errors.png");
    vector<int> c(cases, cases+6);
    for (int i{}; i<2; i++) {
        plt.plot(c, err[i], format("Error {}", names[i]), Gnuplot::LineStyle::LINESPOINTS);
        plt.set_logscale(Gnuplot::AxisScale::LOGXY);
    }
    plt.show();

    //Calcola passi necessari per avere errore 1e-3
    cout << "K (mean) " << k[0] << endl; 
    cout << "K (hit or miss) " << k[1] << endl;
    cout << "N (mean) " << round(pow((k[0]/0.001), 2)) << endl;
    cout << "N (hit or miss) " << round(pow((k[1]/0.001), 2)) << endl;

}