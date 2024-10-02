#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cassert>
#include "lib1.3/funzioni.h"

using namespace std;

//file_name n_elements
int main(int argc, char *argv[]){
    
    //gestisci input
    if (argc < 3 ) {
        cerr << "Error: wrong input! <n_elements> <file_name>\n";
        return 1;
    }

    //n_dati = numero di dati da analizzare
    int n_dati = stoi(argv[1]);
    const char* file_name = argv[2];
    int real_n = count_file_elements(file_name);

    //load data
    if (n_dati > real_n) {
        cerr << "Error: number of elements in file is lower than the one requested." << endl;
        return 1;
    }
    double* dati = new double[n_dati];
    ifstream input(file_name);
    int i = 0;
    while (!input.eof() && i < n_dati) {
        input >> dati[i];
        i ++;
    }

    //calcola media e varianza
    double mean = media_double(dati, n_dati);
    double varianza = pow(devstd_double(dati, n_dati),2);

    //crea una copia dei dati
    double* new_dati = new double[n_dati];
    for (int i = 0; i<n_dati; i++){
        new_dati[i] = dati[i];
    }

    //ordina i dati
    selection_sort_double(new_dati, n_dati);
    double mediana = mediana_double(new_dati, n_dati);

    //stampa
    cout << "Analizzati " << n_dati << " dati:\n";
    cout << "Media " << mean << endl;
    cout << "Varianza " << varianza << endl;
    cout << "Devizaione standard " << pow(varianza, 0.5) << endl;
    cout << "Mediana " << mediana << "\n\n";

    //stampa su file i dati ordinati
    print("output_file.txt", new_dati, n_dati);
    
    //stampa dati su schermo (function overloading)
    print(new_dati, n_dati);

    //elimina i vettori
    delete []dati;
    delete []new_dati;

    return 0;
}