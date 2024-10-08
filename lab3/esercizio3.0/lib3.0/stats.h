//08/10/24 by Matteo Fava
//Funzioni di statisticha riguardo alla classe Vect definita

#pragma once
#include "vect.h"
#include <iostream>
using namespace std;

//calcola la media di Vect
template <typename T> double average(Vect<T>& V){
    if (V.size() == 0) return 0; 
    double m{0};
    for (int i{0}; i < V.size(); i++){
        m = (i*m+V[i]) / (T)(i+1);
    }
    return m;
}

//calcola la varianza di  Vect
template <typename T> double varianza(Vect<T>& V){
    if (V.size() == 0) return 0;
    double result{0};
    double m{average(V)};
    for (int i{0}; i < V.size(); i++) {
        result = (result * (T) i + (V[i]-m)*(V[i]-m)) / (T) (i+1);
    }
    return result;
}

//calcola la media di Vect
template <typename T> T mediana(Vect<T>& V){
    if (V.size() == 0) {cerr << "Empty array" << endl; exit(-1);};
    //riordina vettore (creando una copia)
    Vect<T> w{V};
    w.sort();
    //seleziona la meta
    if (w.size()%2 != 0 ) return w[(w.size()-1)/2];
    else return (V[V.size()/2] + V[V.size()/2 - 1])/2;
}