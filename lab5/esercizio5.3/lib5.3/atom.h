// 22.10.24 by Matteo Fava
// Point3D
#pragma once
#include "particle.h"
#include <format>
#include <iostream>
using namespace std;

class Electron : public Particle {
public:
  // costructors
  Electron() : Particle{9.1093826e-31, -1.60217653e-19} {};
  // methods
  void print() const;
};

class Proton : public Particle {
public:
  // costructors
  Proton() : Particle{1.67262192595e-27, 1.60217653e-19} {};
  // methods
  void print() const;
};

void Proton::print() const {
  cout << format("Proton: (mass {}, charge {})", mass, charge);
}

void Electron::print() const {
  cout << format("Electron: (mass {}, charge {})", mass, charge);
}