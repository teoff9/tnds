//12.11.24 by Matteo Fava
//Algrebra lineare

#include <array>
using namespace std;

#pragma once

//SOMMA COMPONENTE PER COMPONENTE
template <typename T, size_t n> inline array<T, n> operator+(const array<T,n> &a, const array<T,n> &b){
    array<T,n> result{};
    for (int i = 0; i< (int)a.size(); i++) {
        result[i] = a[i] + b[i];
    }
    return result;
}

//SOMMA +=
template <typename T, size_t n> inline array<T, n> operator+=(array<T,n> &a, const array<T,n> &b){
    for (int i = 0; i< (int)a.size(); i++) {
        a[i] += b[i];
    }
    return a;
}

//DIFFERENZA COMPONENTE PER COMPONENTE
template <typename T, size_t n> inline array<T, n> operator-(const array<T,n> &a, const array<T,n> &b){
    array<T,n> result{};
    for (int i = 0; i< (int)a.size(); i++) {
        result[i] = a[i] - b[i];
    }
    return result;
}

//DIFFERENZA -=
template <typename T, size_t n> inline array<T, n> operator-=(array<T,n> &a, const array<T,n> &b){
    for (int i = 0; i< (int)a.size(); i++) {
        a[i] -= b[i];
    }
    return a;
}

//SCALARE PER ARRAY 
template <typename T, size_t n> inline array<T, n> operator*(T c, const array<T,n> &b){
    array<T,n> result{};
    for (int i = 0; i< (int)b.size(); i++) {
        result[i] = b[i] * c; 
    }
    return result;
}

//PRODOTTO PER SCALARE
template <typename T, size_t n> inline array<T, n> operator*(const array<T,n> &b, T c){
    array<T,n> result{};
    for (int i = 0; i< (int)b.size(); i++) {
        result[i] = b[i] * c; 
    }
    return result;
}


//DIVISIONE PER SCALARE
template <typename T, size_t n> inline array<T, n> operator/(const array<T,n> &b, T c){
    array<T,n> result{};
    for (int i = 0; i< (int)b.size(); i++) {
        result[i] = b[i] / c; 
    }
    return result;
}

//PRODOTTO SCALARE
template <typename T, size_t n> inline array<T, n> operator*(const array<T,n> &a, const array<T,n> &b){
    array<T,n> result{};
    for (int i = 0; i< (int)a.size(); i++) {
        result[i] = a[i] * b[i];
    }
    return result;
}
