//29.10.24 by Matteo Fava

#include "functions.h"
#include <iostream>
#include <format>
using namespace std;

int main() {
    Parabola p{1,2,1};
    cout << p(1) << endl;
    p.set_a(2);
    cout << p(5) << endl;
    cout << p.get_vert() << endl;
    return 0;
}