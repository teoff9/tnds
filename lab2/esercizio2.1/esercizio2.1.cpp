//01/10/2024 by Matteo Fava

#include "../esercizio2.2/lib2.2/vect.h"
#include "iostream"
#include "cassert"
using namespace std;

Vect prova();

int main () {
    //ES 2.0
    Vect vnull;
    cout << "Vettore nullo " << vnull.size() << endl;
    //vnull.get_element(0); //this should crash and it does
    Vect v1(10);
    assert(v1.size() == 10);
    for (int i = 0; i < v1.size();  ++i) {
        cout << "Elem di v1 " << v1[i] << endl;
    }
    cout << "\n";
    v1.set_element(9, 100);
    assert(v1.get_element(9) == 100);
    Vect* v2 = new Vect(10);
    cout << "Dimensione v2 " << v2->size() << endl;
    delete v2;

    //ES2.1
    Vect v(10);
    for (int i = 0; i < v.size(); i++) {
        v.set_element(i, i);
    }
    Vect w(100);
    for (int i = 0; i < w.size(); i++) {
        w.set_element(i, 2*i+1);
    }

    w = v;
    assert(w.size() == v.size());
    for (int k = 0; k < w.size(); k++) {cout << w.get_element(k) << " ";}
    cout << endl;

    v.set_element(4, 99);
    assert(v.get_element(4) != w.get_element(4));
    v.swap(1,4);
    cout << v.get_element(1) << endl;
    assert(v[1] == 99 && v[4] != 99);
    cout << v.get_element(1) << endl;

    Vect z = v;
    cout << z.size() << endl;
    for (int k = 0; k < z.size(); k++) {
        cout << z.get_element(k) << " ";
    }
    cout << endl;
    v.set_element(3, 5);
    assert(z.get_element(3) != v.get_element(3));

    v[0] = 5;
    assert(v[0] == 5);

    Vect a;
    a = prova();
    assert(a.size() == 5);
    


    return 0;
}

Vect prova(){
    Vect n(5);
    return n;
}