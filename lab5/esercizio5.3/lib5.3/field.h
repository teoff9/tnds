// 22.10.24 by Matteo Fava

#pragma once
#include "point.h"
#include <cmath>
#include <iostream>
using namespace std;

class VectorField : public Point3D {
public:
  // constructors
  VectorField();
  VectorField(const Point3D pos);
  VectorField(const Point3D pos, double Fx, double Fy, double Fz);

  // operators
  VectorField &operator+=(const VectorField &v);
  VectorField operator+(const VectorField &v) const;

  // methods
  double get_fx() const;
  double get_fy() const;
  double get_fz() const;
  void set_fx(double);
  void set_fy(double);
  void set_fz(double);
  double module() const;

private:
  double f_x, f_y, f_z;
};

// constructors
VectorField::VectorField() : f_x{0}, f_y{0}, f_z{0}, Point3D{0.0, 0.0, 0.0} {}
VectorField::VectorField(const Point3D pos)
    : f_x{0}, f_y{0}, f_z{0}, Point3D{pos} {}
VectorField::VectorField(const Point3D pos, double Fx, double Fy, double Fz)
    : f_x{Fx}, f_y{Fy}, f_z{Fz}, Point3D{pos} {}

// operators
VectorField &VectorField::operator+=(const VectorField &v) {
  return (*this) = (*this) + v;
}
VectorField VectorField::operator+(const VectorField &v) const {
  if (get_x() != v.get_x() || get_y() != v.get_y() || get_z() != v.get_z()) {
    cerr << "Can't sum two vector fields not in the same point!\n";
    exit(-1);
  }
  VectorField sum{};
  sum.set_fx(get_fx() + v.get_fx());
  sum.set_fy(get_fy() + v.get_fy());
  sum.set_fz(get_fz() + v.get_fz());
  return sum;
}

// methods
double VectorField::get_fx() const { return f_x; }
double VectorField::get_fy() const { return f_y; }
double VectorField::get_fz() const { return f_z; }
double VectorField::module() const {
  return sqrt(pow(f_x, 2) + pow(f_y, 2) + pow(f_z, 2));
}

void VectorField::set_fx(double new_fx) { f_x = new_fx; }
void VectorField::set_fy(double new_fy) { f_y = new_fy; }
void VectorField::set_fz(double new_fz) { f_z = new_fz; }