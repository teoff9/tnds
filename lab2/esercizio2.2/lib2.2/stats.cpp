//01/10/2024 by Matteo Fava
//Dichiarazioni delle funzioni di statistica

#include "stats.h"
#include "vect.h"
#include <iostream>
using namespace std;

//calcola la media di un array di double Vect
double mean(Vect& V){
    if (V.size() == 0) return 0; 
    double m = 0;
    for (int i=0; i < V.size(); i++){
        m = (i*m+V[i]) / (double)(i+1);
    }
    return m;
}

//calcola la varianza di un array di double Vect
double varianza(Vect& V){
    if (V.size() == 0) return 0;
    double result = 0;
    double m = mean(V);
    for (int i = 0; i < V.size(); i++) {
        result = (result * (double) i + (V[i]-m)*(V[i]-m)) / (double) (i+1);
    }
    return result;
}

//calcola la media di un array di double Vect
double mediana(Vect& V) {
    if (V.size() == 0) {cerr << "Empty array" << endl; exit(-1);};
    //riordina vettore (creando una copia)
    Vect w(V);
    w.sort();
    //seleziona la meta
    if (w.size()%2 != 0 ) return w[(w.size()-1)/2];
    else return (V[V.size()/2] + V[V.size()/2 - 1])/2;
}

