#include "funzioni.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double mediana_double(double data[], int used){
    if (used%2 != 0){
        return data[(used-1)/2];
    } else {
        return (data[used/2] + data[used/2 - 1])/2;
    }
}

double devstd_double(double data[], int used){
    if (used == 0) return 0;
    double var = 0;
    double m = media_double(data, used);
    for (int i = 0; i < used; i++) {
        var = ((double)i*var + pow(data[i]-m, 2))/(double)(i+1);
    }
    return sqrt(var);
}


double media_double(double data[], int used){
    if (used == 0) return 0;
    double m = 0;
    for (int i = 0; i < used; i++){
        m = ((double)i * m + data[i])/(double)(i+1);
    }
    return m;
}

int pos_of_min_double(double data[], int i, int j){
    int k = 0;
    double min = data[i];
    for(i; i<=j; i++){
        if (data[i]<= min){
            k = i;
            min = data[i];
        }
    }

    return k;
}

void selection_sort_double(double data[], int used){
    for (int i = 0; i < used -1; i++){
        int k = pos_of_min_double(data, i, used-1);
        double tmp = data[k];
        data[k] = data[i];
        data[i] = tmp;
    }

}

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


void print(const char* file_name, double* data, int n_dati){
    ofstream output(file_name);
    for (int i = 0; i<n_dati; i++){
        output << fixed << setprecision(5) << data[i] << endl;
    }
    output.close();
}

void print(const double * dati, int n_dati){
    for (int i = 0; i<n_dati; i++){
        cout << fixed << setprecision(5) << dati[i] << endl;
    }
}