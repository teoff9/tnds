// 08/10/2024 by Matteo Fava
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "lib3.2/iofunctions.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  // controlla v di input
  if (argc != 3) {
    cerr << "Wrong inputs: <n_elements> <file_name>\n";
    exit(-1);
  }
  int n_v = stoi(argv[1]);
  char *file_name = argv[2];

  // crea app root
  TApplication app{"app", 0, 0};

  // leggi v da file
  // carica su un Vect i v
  int n = count_file_elements<double>(file_name);
  if (n_v > n) {
    cerr << "Error: number of elements in file is lower than the one requested."
         << endl;
    return -1;
  }
  vector<double> v{file_to_vect<double>(file_name, n_v)};

  // crea istogramma
  TH1F histo{"histo", "histo", 100, -20, 20};
  histo.StatOverflows(true);

  for (int k{}; k < (int)v.size(); k++) {
    histo.Fill(v[k]);
  }

  // accedi a histo per prendere la media
  cout << "Media dei v caricati: " << histo.GetMean() << endl;

  // disegna
  TCanvas mycanvas{"Histogram", "Histogram"};

  histo.Draw();
  histo.GetXaxis()->SetTitle("Misure");

  app.Run();

  return 0;
}