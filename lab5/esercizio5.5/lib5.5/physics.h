// 22.10.24 by Matteo Fava

#pragma once
#include "field.h"
#include "mat_point.h"

const double epsilon_zero = 8.8541878188e-12;
const double pi = 3.14159265359;
const double G = 6.67e-11;

VectorField electric_field(MaterialPoint &mp, Point3D pos) {
  double f = mp.get_charge() /
             (4 * pi * epsilon_zero * pow(pos.distance_from(Point3D{mp}), 3));

  return VectorField{pos, f * (pos.get_x() - mp.get_x()),
                     f * (pos.get_y() - mp.get_y()),
                     f * (pos.get_z() - mp.get_z())};
}

//g radiale
double acc_radiale(MaterialPoint &mp, Point3D pos){
  double f = mp.get_mass()*G/(pow(pos.distance_from(Point3D{mp}), 2));
  return f;
}

VectorField acc(MaterialPoint &mp, const Point3D &pos) {
    double dist = pos.distance_from(Point3D{mp});
    double f = mp.get_mass() * G / pow(dist, 3); // Gravitational force per unit mass
    return VectorField{pos, 
                       f * (pos.get_x() - mp.get_x()),
                       f * (pos.get_y() - mp.get_y()),
                       f * (pos.get_z() - mp.get_z())};
}
