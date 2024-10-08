//08/10/24 by Matteo Fava

#include <iostream>
#include <cstdlib>
#include "lib3.0/vect.h"
#include "lib3.0/tests.h"
#include "lib3.0/stats.h"
#include "lib3.0/iofunctions.h"
using namespace std;

int main(int argc, char* argv[]) {

    //test delle funzioni statistiche e sorting
    test_vect();
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
    Vect<double> dati = file_to_vect<double>(file_name, n);
    
    //media, varianza, mediana
    cout << "Media: " << average(dati) << endl;
    cout << "Varianza: " << varianza(dati) << endl;
    cout << "Mediana: " << mediana(dati) << endl;

    //ordina il vettore
    dati.sort();

    //stampa il vettore ordinato su file di output e su terminal
    print(dati);
    print(dati, "output_file.txt");

    return 0;
}