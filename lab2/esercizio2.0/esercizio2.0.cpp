//01/10/2024 by Matteo Fava

#include "../esercizio2.2/lib2.2/vect.h"
#include <iostream>
#include <cassert>
using namespace std;

int main () {
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

    cout << "Passed all tests!" << endl;

    return 0;
}