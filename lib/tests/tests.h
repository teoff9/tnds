//08/10/24 by Matteo Fava

#pragma once
#include <cmath>
using namespace std;


//Funzione che controlla se un numero n e' a meno di delta da m
template <typename T> bool is_close(T n, T m, double delta=1e-7){
    return ((double)fabs(n-m) < delta);
}