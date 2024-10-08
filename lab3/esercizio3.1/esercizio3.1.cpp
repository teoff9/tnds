//08/10/2024 by Matteo Fava

#include <iostream>
#include <vector>
#include <algorithm>
#include "lib3.1/iofunctions.h"
#include "lib3.1/stats.h"
#include "lib3.1/tests.h"
using namespace std;

int main(int argc, char* argv[]) {
    //test delle funzioni statistiche e sorting
    test_statistical_functions();

    //controlla dati di input
    if (argc != 3) {
        cerr << "Wrong inputs: <n_elements> <file_name>\n";
        exit(-1);
    }
    int n_dati = stoi(argv[1]);
    char* file_name = argv[2];

    //carica su un Vect i dati
    int n = count_file_elements<double>(file_name);
    if (n_dati > n) {
        cerr << "Error: number of elements in file is lower than the one requested." << endl;
        return -1;
    }
    vector<double> dati = file_to_vect<double>(file_name, n);
    
    //media, varianza, mediana
    cout << "Media: " << average(dati) << endl;
    cout << "Varianza: " << varianza(dati) << endl;
    cout << "Mediana: " << mediana(dati) << endl;

    //ordina il vettore
    sort(dati.begin(), dati.end());

    //stampa il vettore ordinato su file di output e su terminal
    print(dati);
    print(dati, "output_file.txt");


    return 0;
}