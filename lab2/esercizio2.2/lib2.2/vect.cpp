//01/10/2024 by Matteo Fava
//Libreria di vettore 

#include "vect.h"
#include <iostream>
using namespace std;

//costruttore senza argomenti
Vect::Vect() {
    n = 0;
    v = nullptr;
}

//costruttore con N elementi
Vect::Vect(int N) {
    n = N;
    v = new double[N];
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}

//distruttore della classe Vect
Vect::~Vect() {
    n = 0;
    delete []v;
}

//copy constructor
Vect::Vect(const Vect& V) {
    n = V.size();
    v = new double[n];
    for (int i = 0; i < n; i++){
        v[i] = V.get_element(i);
    }
}

//move constructor
Vect::Vect(Vect &&V) {
    n = V.n;
    v = V.v; //copia indirizzo di memoria
    //pulisci V
    V.n = 0;
    V.v = nullptr;
}

//operator []
double& Vect::operator[](int i) const{
    crash_if_invalid_index(i);
    return v[i];
}

//operator =
Vect& Vect::operator=(const Vect& V){
    n = V.size();
    if (v) delete []v;
    v = new double[n];
    for (int i = 0; i< n; i++){
        v[i] = V.get_element(i);
    }
    return *this;
}

//restituisce n
int Vect::size() const {
    return n;
}

//set di un elemento
void Vect::set_element(int i, double num) {
    crash_if_invalid_index(i);
    v[i] = num;
}

//get element
double Vect::get_element(int i) const {
    crash_if_invalid_index(i);
    return v[i];
}

//swap di elementi di indice i e j
void Vect::swap(int i, int j){
    crash_if_invalid_index(i);
    crash_if_invalid_index(j);
    double tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

//sort di array
void Vect::sort() {
    for (int i = 0; i < n-1; i++){
        int k = pos_of_min(i);
        swap(k,i);
    }
}

int Vect::pos_of_min(int i) const {
    int k = 0;
    double min = v[i];
    for(i; i<n; i++){
        if (v[i]<= min){
            k = i;
            min = v[i];
        }
    }

    return k;
}

//crash if index is not correct
void Vect::crash_if_invalid_index(int i) const {
    if (i < 0 || i > n) {
        cerr << "Vect error: index " << i << " is out of range.\n";
        exit(-1);
    }
}
