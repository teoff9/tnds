// 22.10.24 by Matteo Fava
// Point3D
#pragma once
#include <format>
#include <iostream>
using namespace std;

class Particle {
public:
  // costructors
  Particle();
  Particle(double, double);

  // methods
  double get_mass() const;
  double get_charge() const;
  void print() const;

protected:
  double mass;
  double charge;
};

Particle::Particle() : mass{0.0}, charge{0.0} {}

Particle::Particle(double _mass, double _charge)
    : mass{_mass}, charge{_charge} {}

double Particle::get_mass() const { return mass; }
double Particle::get_charge() const { return charge; }
void Particle::print() const {
  cout << format("Particle: (mass {}, charge {})", mass, charge);
}