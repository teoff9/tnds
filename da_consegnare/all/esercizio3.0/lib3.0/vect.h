// 08/10/24 by Matteo Fava

#pragma once
#include <iostream>
using namespace std;

// classe vettore di T: n = size vettore, v = array allocato dinamicamente
template <typename T> class Vect {
public:
  Vect();             // costruttore "vuoto"
  Vect(int);          // costruttore
  ~Vect();            // distruttore
  Vect(const Vect &); // costruttore da elemento
  Vect(Vect &&V);     // move constructor

  T &operator[](int i) const;
  Vect &operator=(const Vect &);
  Vect &operator=(Vect &&); // move assignement

  int size() const;         // restituisce n
  void set_element(int, T); // set di un elemento index, element
  T get_element(int) const; // restituisci un elemento
  void swap(int, int);      // swap di due elementi
  void sort();              // sorta array

private:
  int n;                                  // size di v
  T *v;                                   // array allocato dinamicamente
  void crash_if_invalid_index(int) const; // check per validita di un index
  int pos_of_min(
      int) const; // trova indice del minore elemento a partire da indice i
};

// costruttore senza argomenti
template <typename T> Vect<T>::Vect() {
  n = 0;
  v = nullptr;
}

// costruttore con N elementi
template <typename T> Vect<T>::Vect(int N) {
  n = N;
  v = new T[N];
  for (int i = 0; i < n; i++) {
    v[i] = 0;
  }
}

// distruttore della classe Vect
template <typename T> Vect<T>::~Vect() {
  n = 0;
  delete[] v;
}

// copy constructor
template <typename T> Vect<T>::Vect(const Vect &V) {
  n = V.size();
  v = new T[n];
  for (int i = 0; i < n; i++) {
    v[i] = V.get_element(i);
  }
}

// move constructor
template <typename T> Vect<T>::Vect(Vect &&V) {
  n = V.n;
  v = V.v; // copia indirizzo di memoria
  // pulisci V
  V.n = 0;
  V.v = nullptr;
}

// operator []
template <typename T> T &Vect<T>::operator[](int i) const {
  crash_if_invalid_index(i);
  return v[i];
}

// operator =
template <typename T> Vect<T> &Vect<T>::operator=(const Vect &V) {
  n = V.size();
  if (v)
    delete[] v;
  v = new T[n];
  for (int i = 0; i < n; i++) {
    v[i] = V.get_element(i);
  }
  return *this;
}

template <typename T> Vect<T> &Vect<T>::operator=(Vect &&V) {
  n = V.size();
  v = V.v;
  V.n = 0;
  V.v = nullptr;
  return *this;
}

// restituisce n
template <typename T> int Vect<T>::size() const { return n; }

// set di un elemento
template <typename T> void Vect<T>::set_element(int i, T num) {
  crash_if_invalid_index(i);
  v[i] = num;
}

// get element
template <typename T> T Vect<T>::get_element(int i) const {
  crash_if_invalid_index(i);
  return v[i];
}

// swap di elementi di indice i e j
template <typename T> void Vect<T>::swap(int i, int j) {
  crash_if_invalid_index(i);
  crash_if_invalid_index(j);
  T tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

// sort di array
template <typename T> void Vect<T>::sort() {
  for (int i = 0; i < n - 1; i++) {
    int k = pos_of_min(i);
    swap(k, i);
  }
}

template <typename T> int Vect<T>::pos_of_min(int i) const {
  int k = 0;
  T min = v[i];
  for (; i < n; i++) {
    if (v[i] <= min) {
      k = i;
      min = v[i];
    }
  }

  return k;
}

// crash if index is not correct
template <typename T> void Vect<T>::crash_if_invalid_index(int i) const {
  if (i < 0 || i > n) {
    cerr << "Vect error: index " << i << " is out of range.\n";
    exit(-1);
  }
}