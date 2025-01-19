// 01/10/2024 by Matteo Fava

#include "lib2.2/iofunctions.h"
#include "lib2.2/stats.h"
#include "lib2.2/tests.h"
#include "lib2.2/vect.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  // test delle funzioni statistiche e sorting
  test_sorting();
  test_statistical_functions();

  // controlla dati di input
  if (argc != 3) {
    cerr << "Wrong inputs: <n_elements> <file_name>\n";
    exit(-1);
  }
  int n_dati = stoi(argv[1]);
  char *file_name = argv[2];

  // carica su un Vect i dati
  int n = count_file_elements(file_name);
  if (n_dati > n) {
    cerr << "Error: number of elements in file is lower than the one requested."
         << endl;
    return -1;
  }
  Vect dati = file_to_vect(file_name, n_dati);

  // media, varianza, mediana
  cout << "Media: " << mean(dati) << endl;
  cout << "Varianza: " << varianza(dati) << endl;
  cout << "Mediana: " << mediana(dati) << endl;

  // ordina il vettore
  dati.sort();

  // stampa il vettore ordinato su file di output e su terminal
  print(dati);
  print(dati, "output_file.txt");

  return 0;
}