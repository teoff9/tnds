//22.10.24 by Matteo Fava
//Point3D
#pragma once
#include "particle.h"
#include <iostream>
#include <format>
using namespace std;

class Electron : public Particle {
    public: 
        //costructors
        Electron() : Particle{9.1093826e-31, -1.60217653e-19} {};
        //methods
        void print() const ;

};

void Electron::print() const { cout << format("Electron: (mass {}, charge {})", mass, charge);}