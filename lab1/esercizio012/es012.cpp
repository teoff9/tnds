//24/09/2024 by Matteo Fava

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "../../lib/stats/stats.h"
#include "../../lib/sorting/sorting.h"

using namespace std;

//conta il numero di elementi in un file
int count_file_elements(const char* file_name);

//file_name n_elements
int main(int argc, char *argv[]){
    
    //gestisci input
    if (argc < 3 ) {
        cerr << "Error: exceeded input variables. n_elements file_name\n";
        return 1;
    }

    //n_dati = numero di dati da analizzare
    int n_dati = stoi(argv[1]);
    const char* file_name = argv[2];
    int real_n = count_file_elements(file_name);

    //load data
    if (n_dati > real_n) {
        cerr << "Error: number of elements in file is lower than the one requested." << endl;
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

    //ordina i dati
    selection_sort_double(dati, n_dati);
    double mediana = mediana_double(dati, n_dati);

    //stampa
    cout << "Analizzati " << n_dati << " dati:\n";
    cout << "Media " << mean << endl;
    cout << "Varianza " << varianza << endl;
    cout << "Devizaione standard " << pow(varianza, 0.5) << endl;
    cout << "Mediana " << mediana << endl;

    delete []dati;
    return 0;
}

//conta il numero di elementi in un file
int count_file_elements(const char* file_name){
    ifstream input(file_name);
    if (!input) {
        cerr << "Error: failed to load file " << file_name << endl;
    }
    int counter = 0;
    double tmp;
    while (!input.eof()) {
        input >> tmp;
        counter ++;
    }
    return counter;
}