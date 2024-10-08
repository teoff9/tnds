//08/10/24 by Matteo Fava

#pragma once
#include <cassert>
#include <cmath>
#include <iostream>
#include "vect.h"
#include "stats.h"
using namespace std;

//Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}

//Funzione per testare la classe Vect
void test_vect(){
    {
        Vect<int> v;
        assert(v.size() == 0);
    }
    {
        Vect<int> v{5};
        v.set_element(4, 3);
        assert(v.get_element(4) == 3);
    }
    {
        Vect<int> v{5};
        v.set_element(4, 3);
        v.set_element(3, 4);
        v.swap(3,4);
        assert(v.get_element(3) == 3);
    }
    cout << "Vect tests: passed!\n";
}

//Funzione per testare le funzioni statistiche
void test_statistical_functions() {
    Vect<int> d(5);
    for (int i = 0; i < d.size(); i++) {d[i]=i+1;}
    //media
    assert(is_close<int>(average(d), 3));
    //varianza
    assert(is_close<int>(varianza(d), 2));
    //mediana
    assert(is_close<int>(mediana(d), 3));
    cout << "Statistical test: passed!\n";
}